cmake_minimum_required(VERSION 3.21)
project(ca2_cef_sample LANGUAGES C CXX)

if(NOT CEF_ROOT OR NOT CA2_CEF_STORAGE_ROOT)
  message(FATAL_ERROR "CEF_ROOT and CA2_CEF_STORAGE_ROOT are required")
endif()
list(APPEND CMAKE_MODULE_PATH "${CEF_ROOT}/cmake")
find_package(CEF REQUIRED)

# Use the complete upstream sample with our staged runtime and wrapper.
# Isolate CEF compiler flags and GTK3 dependencies from the framework's GTK4 build.
set(CEF_BINARY_DIR_DEBUG "${CA2_CEF_STORAGE_ROOT}/x64/Debug/binary")
set(CEF_BINARY_DIR_RELEASE "${CA2_CEF_STORAGE_ROOT}/x64/Release/binary")
set(CEF_BINARY_DIR "${CA2_CEF_STORAGE_ROOT}/x64/${CMAKE_BUILD_TYPE}/binary")
set(CEF_RESOURCE_DIR "${CEF_BINARY_DIR}")
set(CEF_LIB_DEBUG "${CEF_BINARY_DIR_DEBUG}/libcef.so")
set(CEF_LIB_RELEASE "${CEF_BINARY_DIR_RELEASE}/libcef.so")
add_library(libcef_dll_wrapper STATIC IMPORTED GLOBAL)
set_target_properties(libcef_dll_wrapper PROPERTIES
  IMPORTED_LOCATION "${CA2_CEF_STORAGE_ROOT}/x64/${CMAKE_BUILD_TYPE}/library/libcef_dll_wrapper.a"
  INTERFACE_INCLUDE_DIRECTORIES "${CEF_ROOT}")
add_subdirectory("${CEF_ROOT}/tests/cefclient" client)
