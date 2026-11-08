# Prebuilt CEF setup for Linux

Downloads the Linux x86_64 **Standard Distribution** from the CEF automated
builds service, verifies the archive against its published SHA-1, and stages
both Debug and Release configurations. Chromium and `libcef.so` are prebuilt.
Only CEF's `libcef_dll_wrapper.a` is compiled locally, from the matching SDK.

The pinned default is CEF `156.0.26+g8ea0c73+chromium-156.0.8078.88`.
This is a modern CEF SDK; older CEF application code may require API changes.

## Requirements

- Linux x86_64, Python 3.12+, CMake 3.21+, Ninja, and a C++20 compiler.
- To build/run the upstream sample, also install the SDK's Linux dependencies,
  including GTK3 for `cefclient`. See its `README.txt` and `CMakeLists.txt`.
- Several GB of disk space for the SDK, build outputs, and staged runtimes.

## Setup

From the main workspace:

```sh
./operating_system/operating_system-linux/tools/cefclient/setup.sh
```

The default destination is the sibling `operating_system/storage-linux` under
the workspace's parent directory. In this checkout that is
`/home/camilo/code/operating_system/storage-linux`.
The default download/build cache is `~/.cache/ca2/cefclient`.

```text
storage-linux/
  include/cef/include/        matching CEF headers, including wrapper headers
  x64/
    Debug/
      binary/                Debug libcef.so, helper binaries, resources, locales
      library/
        libcef.so            relative symlink to ../binary/libcef.so
        libcef_dll_wrapper.a  Debug static C++ wrapper
      cef-manifest.json
      CEF-LICENSE.txt
      CEF-README.txt
    Release/                 equivalent Release layout
```

Linux uses the shared object for linking, so there is no Windows-style import
library. Compile includes such as `include/cef_client.h` with the include path
`storage-linux/include/cef`. Link the wrapper archive and `libcef.so` for the
same configuration, following the SDK's CMake compiler/linker requirements.
Keep the matching resources and locales beside the application's runtime.
This setup does not alter the main application's build or make its CEF API
usage compatible automatically.

The script merges files into the destination without deleting unrelated
files. Use a fresh `--storage-root` when switching CEF versions to avoid
obsolete runtime files left by an older SDK. It records the source SDK,
version, header location, wrapper build, and runtime files in each manifest.
It does not run `sudo` or change sandbox permissions. The sample ran with
default sandboxing on this Manjaro system; other systems may require the
sandbox setup described by CEF.

## Options and existing SDKs

```sh
./operating_system/operating_system-linux/tools/cefclient/setup.sh --help
./operating_system/operating_system-linux/tools/cefclient/setup.sh \
  --sdk /path/to/cef_binary_VERSION_linux64 \
  --version VERSION \
  --storage-root /path/to/storage-linux \
  --jobs 4
```

`--sdk` trusts an existing extraction and skips download/checksum verification;
its headers must report the requested version. Optional `--debug-build-dir`
and `--release-build-dir` allow reuse of existing Ninja build directories for
that same SDK and configuration. Otherwise, builds are separated by version
and configuration in the cache.

The first run in this checkout reused the already verified SDK and Release
wrapper from the standalone sample:

```sh
./operating_system/operating_system-linux/tools/cefclient/setup.sh \
  --sdk /home/camilo/code/cef-sample/cef_binary_156.0.26+g8ea0c73+chromium-156.0.8078.88_linux64 \
  --release-build-dir /home/camilo/code/cef-sample/build
```

References: [CEF automated builds](https://cef-builds.spotifycdn.com/),
[CEF usage documentation](https://chromiumembedded.github.io/cef/general_usage).

## Verified on this checkout

Both configurations were staged successfully on Manjaro with GCC 16.2.1.
Their runtime dependencies resolved, their wrapper archives were readable, and
their resources/locales and relative library links were checked. The unmodified
upstream `cefclient` loaded a local test page using the staged Release
`libcef.so`, confirmed through Chromium's debugging endpoint and process maps,
with default sandboxing enabled. Debug runtime startup was not tested.

## Main workspace build dependency

On Linux, `source/app-core/cefclient/CMakeLists.txt` now routes to
`linux.cmake`. The old copied sample listed missing sources and invoked CEF
macros without loading the SDK. The Linux target instead uses the complete
sample shipped with the selected SDK, preserving its source unchanged.
It builds in an isolated CMake project under the main build tree, using the
staged `libcef.so`, static wrapper, and runtime resources. This is the upstream
sample; the older Windows-oriented embedded framework application is not
ported or compiled by this target.

```sh
cmake -S . -B cmake-build-release
cmake --build cmake-build-release --target cefclient -j 4
cd cmake-build-release/output/cefclient
./cefclient --url=https://example.com
```

`cefclient` depends on `cef_prebuilt_setup`. Setup downloads/extracts the SDK
when absent, builds the wrappers, and stages the runtimes before the sample
is configured. A completed setup is reused using its output manifests.
The sample stays out of the default build and does not become a dependency
of unrelated applications such as Store. Its output is kept in its own
directory to preserve CEF's runtime layout.

Main-project cache settings:

- `CA2_CEF_VERSION`: exact SDK version.
- `CA2_CEF_SDK_ROOT`: complete Standard Distribution; defaults to an existing
  setup manifest's SDK or the expected download cache location.
- `CA2_CEF_STORAGE_ROOT`: staged SDK destination.
- `CA2_CEF_CACHE_DIR`: download/wrapper cache.
- `CA2_CEF_JOBS`: parallel jobs for the isolated CEF builds (default 4).

Use `cmake --build cmake-build-release --target cef_prebuilt_setup` to stage
the SDK without building the sample. Debug main builds select Debug CEF;
other main configurations select Release CEF. The recipe currently targets
native Linux x86_64 with a single-configuration generator.

Verified the main Release `cefclient` target end to end, including an incremental
build that performed no compilation or SDK setup. Its deployed executable loaded
a local test page with sandboxing enabled; process maps confirmed that its own
deployed `libcef.so` was loaded. Main Release configuration and the Store dry-run
build plan also passed; Store's full compilation was not run.
