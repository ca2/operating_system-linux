#!/usr/bin/env python3
"""Stage a prebuilt Linux x86_64 CEF SDK; compile only its C++ wrapper."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import tarfile
import urllib.request

VERSION = "156.0.26+g8ea0c73+chromium-156.0.8078.88"
CDN = "https://cef-builds.spotifycdn.com/"


def run(*args):
    subprocess.run([str(arg) for arg in args], check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--version", default=VERSION)
    parser.add_argument("--sdk", type=Path, help="Use an already extracted Standard Distribution")
    parser.add_argument("--storage-root", type=Path,
                        default=Path(__file__).resolve().parents[5] / "operating_system/storage-linux")
    parser.add_argument("--cache-dir", type=Path,
                        default=Path.home() / ".cache/ca2/cefclient")
    parser.add_argument("--release-build-dir", type=Path)
    parser.add_argument("--debug-build-dir", type=Path)
    parser.add_argument("--jobs", type=int, default=min(4, os.cpu_count() or 1))
    args = parser.parse_args()
    if platform.system() != "Linux" or platform.machine() not in ("x86_64", "AMD64"):
        parser.error("This recipe requires Linux x86_64 and a native x86_64 toolchain")
    if args.jobs < 1:
        parser.error("--jobs must be positive")
    for tool in ("cmake", "ninja", "c++"):
        if not shutil.which(tool):
            parser.error(f"Required tool missing: {tool}")
    cache = args.cache_dir.expanduser().resolve()
    cache.mkdir(parents=True, exist_ok=True)
    archive_name = f"cef_binary_{args.version}_linux64.tar.bz2"
    sdk = args.sdk.expanduser().resolve() if args.sdk else cache / archive_name.removesuffix(".tar.bz2")
    if not args.sdk:
        with urllib.request.urlopen(CDN + "index.json") as response:
            index = json.load(response)
        release = next((v for v in index["linux64"]["versions"]
                        if v["cef_version"] == args.version), None)
        if release is None:
            parser.error(f"CEF version not in the build index: {args.version}")
        entry = next(f for f in release["files"] if f["type"] == "standard")
        archive = cache / entry["name"]
        if not archive.exists():
            partial = archive.with_suffix(archive.suffix + ".part")
            print(f"Downloading {entry['name']}", flush=True)
            urllib.request.urlretrieve(CDN + entry["name"], partial)
            partial.replace(archive)
        with archive.open("rb") as stream:
            digest = hashlib.file_digest(stream, "sha1").hexdigest()
        if digest != entry["sha1"]:
            raise RuntimeError(f"Checksum mismatch; remove {archive} and retry")
        marker = sdk / ".ca2-extraction-complete"
        if not marker.exists():
            print("Extracting verified SDK", flush=True)
            with tarfile.open(archive) as bundle:
                bundle.extractall(cache, filter="data")
            marker.touch()
    for required in ("CMakeLists.txt", "cmake/FindCEF.cmake", "include/cef_version.h",
                     "Debug/libcef.so", "Release/libcef.so", "Resources/icudtl.dat"):
        if not (sdk / required).is_file():
            parser.error(f"Incomplete Standard Distribution: {sdk / required}")
    version_header = (sdk / "include/cef_version.h").read_text()
    if f'#define CEF_VERSION "{args.version}"' not in version_header:
        parser.error("SDK version differs from --version; specify its exact version")
    storage = args.storage_root.expanduser().resolve()
    headers = storage / "include/cef"
    shutil.copytree(sdk / "include", headers / "include", dirs_exist_ok=True)
    for config, override in (("Debug", args.debug_build_dir), ("Release", args.release_build_dir)):
        build = override.expanduser().resolve() if override else cache / "build" / args.version / config
        run("cmake", "-S", sdk, "-B", build, "-G", "Ninja", f"-DCMAKE_BUILD_TYPE={config}")
        run("cmake", "--build", build, "--target", "libcef_dll_wrapper", "-j", args.jobs)
        wrapper = build / "libcef_dll_wrapper/libcef_dll_wrapper.a"
        if not wrapper.is_file():
            raise RuntimeError(f"Wrapper archive missing: {wrapper}")
        destination = storage / "x64" / config
        binary, library = destination / "binary", destination / "library"
        binary.mkdir(parents=True, exist_ok=True)
        library.mkdir(parents=True, exist_ok=True)
        staged = []
        for folder in (sdk / config, sdk / "Resources"):
            for source in folder.iterdir():
                target = binary / source.name
                if source.is_dir():
                    shutil.copytree(source, target, dirs_exist_ok=True)
                else:
                    shutil.copy2(source, target)
                staged.append(source.name)
        # Linux links against the shared object itself, rather than an import library.
        link = library / "libcef.so"
        if link.is_symlink():
            link.unlink()
        elif link.exists():
            raise RuntimeError(f"Refusing to replace existing regular file: {link}")
        link.symlink_to("../binary/libcef.so")
        shutil.copy2(wrapper, library / wrapper.name)
        for license_file in ("LICENSE.txt", "README.txt"):
            shutil.copy2(sdk / license_file, destination / ("CEF-" + license_file))
        (destination / "cef-manifest.json").write_text(json.dumps({
            "cef_version": args.version, "configuration": config, "sdk": str(sdk),
            "headers": str(headers), "wrapper_build": str(build),
            "runtime_files": sorted(staged), "sandbox_permissions_changed": False,
        }, indent=2) + "\n")
        print(f"Staged CEF {config}: {destination}", flush=True)


if __name__ == "__main__":
    main()
