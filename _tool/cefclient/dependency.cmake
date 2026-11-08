include_guard(GLOBAL)

get_property(_cef_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(CMAKE_CROSSCOMPILING OR _cef_multi_config OR NOT CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64)$")
  message(FATAL_ERROR "The Linux CEF recipe requires native x86_64 and a single-configuration generator")
endif()

get_filename_component(_cef_workspace "${CMAKE_SOURCE_DIR}/.." ABSOLUTE)
set(CA2_CEF_VERSION "156.0.26+g8ea0c73+chromium-156.0.8078.88" CACHE STRING "Prebuilt CEF version")
set(CA2_CEF_STORAGE_ROOT "${_cef_workspace}/operating_system/storage-linux" CACHE PATH "CEF storage root")
set(CA2_CEF_CACHE_DIR "$ENV{HOME}/.cache/ca2/cefclient" CACHE PATH "CEF download and wrapper build cache")
set(CA2_CEF_JOBS 4 CACHE STRING "Parallel CEF build jobs")
set(_cef_tools "${CMAKE_SOURCE_DIR}/operating_system/operating_system-linux/_tool/cefclient")

# Existing setup manifests preserve the SDK location used by setup.sh --sdk.
set(_cef_manifest "${CA2_CEF_STORAGE_ROOT}/x64/Release/cef-manifest.json")
set(_cef_default_sdk "${CA2_CEF_CACHE_DIR}/cef_binary_${CA2_CEF_VERSION}_linux64")
if(EXISTS "${_cef_manifest}")
  file(STRINGS "${_cef_manifest}" _cef_version_line REGEX "\"cef_version\":")
  string(FIND "${_cef_version_line}" "\"${CA2_CEF_VERSION}\"" _cef_version_match)
  file(STRINGS "${_cef_manifest}" _cef_sdk_line REGEX "\"sdk\":")
  string(REGEX REPLACE "^[^:]*: *\"([^\"]*)\".*$" "\\1" _cef_existing_sdk "${_cef_sdk_line}")
  if(NOT _cef_version_match EQUAL -1 AND EXISTS "${_cef_existing_sdk}/cmake/FindCEF.cmake")
    set(_cef_default_sdk "${_cef_existing_sdk}")
  endif()
endif()
set(CA2_CEF_SDK_ROOT "${_cef_default_sdk}" CACHE PATH "Complete CEF Standard Distribution")
set(_cef_setup_args --version "${CA2_CEF_VERSION}" --storage-root "${CA2_CEF_STORAGE_ROOT}"
  --cache-dir "${CA2_CEF_CACHE_DIR}" --jobs "${CA2_CEF_JOBS}")
if(EXISTS "${CA2_CEF_SDK_ROOT}/cmake/FindCEF.cmake")
  list(APPEND _cef_setup_args --sdk "${CA2_CEF_SDK_ROOT}")
elseif(NOT CA2_CEF_SDK_ROOT STREQUAL "${CA2_CEF_CACHE_DIR}/cef_binary_${CA2_CEF_VERSION}_linux64")
  message(FATAL_ERROR "CA2_CEF_SDK_ROOT does not contain a CEF Standard Distribution: ${CA2_CEF_SDK_ROOT}")
endif()

set(_cef_manifests)
set(_cef_products)
foreach(_config Debug Release)
  set(_base "${CA2_CEF_STORAGE_ROOT}/x64/${_config}")
  list(APPEND _cef_manifests "${_base}/cef-manifest.json")
  list(APPEND _cef_products "${_base}/binary/libcef.so" "${_base}/library/libcef_dll_wrapper.a")
endforeach()
add_custom_command(OUTPUT ${_cef_manifests}
  BYPRODUCTS ${_cef_products}
  COMMAND "${_cef_tools}/setup.sh" ${_cef_setup_args}
  DEPENDS "${_cef_tools}/setup.sh" "${_cef_tools}/setup.py"
  COMMENT "Setting up prebuilt CEF runtimes and matching C++ wrappers"
  USES_TERMINAL VERBATIM)
add_custom_target(cef_prebuilt_setup DEPENDS ${_cef_manifests})


add_library(ca2_cef_runtime SHARED IMPORTED)
add_library(ca2_cef_wrapper STATIC IMPORTED)
foreach(_config Debug Release)
  string(TOUPPER "${_config}" _upper)
  set_property(TARGET ca2_cef_runtime PROPERTY IMPORTED_LOCATION_${_upper}
    "${CA2_CEF_STORAGE_ROOT}/x64/${_config}/binary/libcef.so")
  set_property(TARGET ca2_cef_wrapper PROPERTY IMPORTED_LOCATION_${_upper}
    "${CA2_CEF_STORAGE_ROOT}/x64/${_config}/library/libcef_dll_wrapper.a")
endforeach()
set_target_properties(ca2_cef_runtime ca2_cef_wrapper PROPERTIES
  IMPORTED_CONFIGURATIONS "Debug;Release"
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release MAP_IMPORTED_CONFIG_MINSIZEREL Release)
add_dependencies(ca2_cef_runtime cef_prebuilt_setup)
add_dependencies(ca2_cef_wrapper cef_prebuilt_setup)

