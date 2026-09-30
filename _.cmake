


set(RELEASE_WITH_DEBUG FALSE)

if(${RELEASE_WITH_DEBUG})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g")
   set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g")
endif()

endif()


if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

   error("This file is designed to be used only for linux systems...")

endif ()

add_compile_options(-Wno-literal-suffix)


#list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

#message(STATUS "CMAKE_SYSTEM_NAME is ${CMAKE_SYSTEM_NAME}")

#FIND_PACKAGE(PkgConfig)

#include(FindPkgConfig)

#IF(PKG_CONFIG_FOUND)
# use pkg_check_modules()
#ENDIF(PKG_CONFIG_FOUND)
set(FREEBSD FALSE)
set(DEBIAN FALSE)
set(FEDORA FALSE)
set(UBUNTU FALSE)
set(MANJARO FALSE)
set(ARCH_LIKE FALSE)
set(USE_PKGCONFIG TRUE)
set(CURL_NANO_HTTP TRUE)
set(HAS_WAYLAND TRUE)
set(HAS_X11 TRUE)
set(TOOL_RELEASE_NAME "linux")
if(EXISTS "${CMAKE_SOURCE_DIR}/raspberrypios.txt")
   set(MAIN_STORE_SLASHED_OPERATING_SYSTEM "raspi")
else()
   set(MAIN_STORE_SLASHED_OPERATING_SYSTEM "linux")
endif()
set(OPERATING_SYSTEM_TOOL_FOLDER "tool-linux")

set(HAS_SYSTEM_JPEG TRUE)
add_compile_definitions(HAS_SYSTEM_JPEG)
add_compile_definitions(__FREEDESKTOP__)


add_compile_definitions(TOOL_FOLDER_OPERATING_SYSTEM_NAME="${TOOL_RELEASE_NAME}")

add_compile_definitions(__LINUX__)


#set(APPLICATION_BUILD_HELPER_BINARY $ENV{HOME}/bin/application_build_helper)


if ("${CMAKE_BUILD_TYPE}" STREQUAL "")

   set(CMAKE_BUILD_TYPE Debug)

endif ()


message(STATUS "------------------------------------------")
message(STATUS "                                          ")
message(STATUS "  Finding PkgConfig                       ")
message(STATUS "                                          ")
message(STATUS "CMAKE_INCLUDE_PATH is ${CMAKE_INCLUDE_PATH}")
message(STATUS "CMAKE_LIBRARY_PATH is ${CMAKE_LIBRARY_PATH}")
message(STATUS "ENV{PKG_CONFIG_PATH} is $ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)
message(STATUS "PKG_CONFIG_EXECUTABLE is ${PKG_CONFIG_EXECUTABLE}")

#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#
#   message(STATUS "GNU Compiler")
#
#   string(APPEND CMAKE_CXX_FLAGS "-fPIC -fexceptions -fnon-call-exceptions -frtti")
#
#   #set(EXTRA_CXX_TARGET_COMPILER_OPTIONS "-ansi")
#
#else()
#
#   #set(EXTRA_CXX_TARGET_COMPILER_OPTIONS "")
#
#endif ()


set(DONT_USE_PKG_CONFIG NOT PKG_CONFIG_FOUND)



set(UNDERSCORE_OPERATING_SYSTEM $ENV{__SYSTEM_UNDERSCORE_OPERATING_SYSTEM})
set(SLASHED_OPERATING_SYSTEM $ENV{__SYSTEM_SLASHED_OPERATING_SYSTEM})
set(DISTRO $ENV{__SYSTEM})
set(DISTRO_RELEASE $ENV{__SYSTEM_RELEASE})


string(TOLOWER ${CMAKE_BUILD_TYPE} tolower_cmake_build_type)


message(STATUS "tolower_cmake_build_type = ${tolower_cmake_build_type}")


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
   set(CMAKE_CXX_EXTENSIONS OFF)
   add_compile_options(-fmax-errors=10)
endif()


if (${tolower_cmake_build_type} STREQUAL "debug")

   message(STATUS "Debug Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "relwithdebinfo")

   message(STATUS "RelWithDebInfo Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "release")

   message(STATUS "Release Build!!")

   add_compile_definitions(NDEBUG)

   message(STATUS "NDEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "minsizerel")

   message(STATUS "MinSizeRel Build!!")

   add_compile_definitions(NDEBUG)

   message(STATUS "NDEBUG compile definition set!!")

else ()

   message(STATUS "\"${CMAKE_BUILD_TYPE}\" Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

endif ()


SET(CMAKE_SKIP_BUILD_RPATH FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#if(${DESKTOP_AMBIENT})
## DESKTOP_AMBIENT are dependant just on linux kernel version and glib version?
#if(${DISTRO} STREQUAL "linuxmint")
#   set(DISTRO "ubuntu")
#   set(LINUX_MINT TRUE)
#   if(${DISTRO_RELEASE} LESS_EQUAL 20)
#      set(DISTRO_RELEASE "20.04")
#   elseif(${DISTRO_RELEASE} LESS_EQUAL 21)
#      set(DISTRO_RELEASE "22.04")
#   else()
#      set(DISTRO_RELEASE "24.04")
#   endif()
#endif()
#
#endif()


set(LINUX TRUE)
set(FREEBSD FALSE)
set(OPERATING_SYSTEM_NAME "linux")
set(OPERATING_SYSTEM_LOWERED_NAME "linux")
set(OPERATING_SYSTEM_POSIX TRUE)
set(FILE_SYSTEM_INOTIFY TRUE)
set(POSIX_SPAWN TRUE)
set(WITH_X11 TRUE)
set(WITH_XCB TRUE)
set(USE_OPENSSL TRUE)
set(PTHREAD TRUE)
set(PLATFORM_NAME "linux")
#set(BUILD_GPU_BASED_APPLICATIONS TRUE)

message(STATUS "__OPERATING_SYSTEM is ${__OPERATING_SYSTEM}")

if (${__OPERATING_SYSTEM} STREQUAL "ubuntu")

   set(UBUNTU TRUE)

   set(DEBIAN_LIKE TRUE)

   add_compile_definitions(UBUNTU_LINUX)

#   add_compile_definitions(DEBIAN_LIKE_LIBUILD_GPU_BASED_APPLICATIONSNUX)

   message(STATUS "UBUNTU has been set TRUE")

   #set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   set(MPG123_PKG_MODULE "libmpg123")

   set(HAS_SYSTEM_UNAC TRUE)

elseif (${__OPERATING_SYSTEM} STREQUAL "debian")

   set(DEBIAN TRUE)

   add_compile_definitions(DEBIAN_LINUX)

   add_compile_definitions(DEBIAN_LIKE_LINUX)

   message(STATUS "DEBIAN has been set TRUE")

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   set(MPG123_PKG_MODULE "libmpg123")

   add_compile_options("$<$<CONFIG:Debug>:-gdwarf-4>")

   set(HAS_SYSTEM_UNAC TRUE)

elseif (${__OPERATING_SYSTEM} STREQUAL "opensuse-leap"
   OR ${__OPERATING_SYSTEM} STREQUAL "opensuse-tumbleweed"
   OR ${__OPERATING_SYSTEM} STREQUAL "opensuse")

   set(SUSE TRUE)

   add_compile_definitions(SUSE_LINUX)

   message(STATUS "SUSE has been set TRUE")

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   set(MPG123_PKG_MODULE "libmpg123")

elseif (${__OPERATING_SYSTEM} STREQUAL "fedora")

   set(FEDORA TRUE)

   add_compile_definitions(FEDORA_LINUX)

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   message(STATUS "FEDORA has been set TRUE")

elseif (${__OPERATING_SYSTEM} STREQUAL "linuxmint")

   set(LINUXMINT TRUE)

   add_compile_definitions(MINT_LINUX)

   set(DEBIAN_LIKE TRUE)

   set(UBUNTU_LIKE TRUE)

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   message(STATUS "LINUX_MINT has been set TRUE")

   message(STATUS "MINT_LINUX compile definition")

   message(STATUS "DEBIAN_LIKE has been set TRUE")

   message(STATUS "UBUNTU_LIKE has been set TRUE")

elseif ("${__OPERATING_SYSTEM}" STREQUAL "raspbian")

   set(RASPBIAN TRUE)

   set(DEBIAN_LIKE TRUE)

   add_compile_definitions(RASPBERRYPIOS)

   add_compile_definitions(DEBIAN_LIKE_LINUX)

   set(DONT_USE_PKG_CONFIG FALSE)

   set(HAS_SYSTEM_UNAC TRUE)

   set(HAS_WAYLAND FALSE)

   set(NO_PRECOMPILED_HEADER TRUE)

   message(STATUS "RASPBERRYPIOS defined!!")

elseif (${__OPERATING_SYSTEM} STREQUAL "manjaro"
   OR ${__OPERATING_SYSTEM} STREQUAL "manjarolinux")

   set(MANJARO TRUE)

   set(ARCH_LIKE TRUE)

   add_compile_definitions(MANJARO_LINUX)

   add_compile_definitions(__ARCH_LINUX__)

   message(STATUS "MANJARO has been set TRUE")

   #set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   set(MPG123_PKG_MODULE "libmpg123")

   set(HAS_SYSTEM_UNAC FALSE)

else ()

   set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

   set(MPG123_PKG_MODULE "mpg123")

endif ()

if(${ARCH_LIKE})

   set(USE_PORT_JPEG FALSE)
   set(USE_PORT_PNG FALSE)
   set(USE_PORT_FREEIMAGE TRUE)
   #add_compile_definitions(USE_PORT_JPEG)
   #add_compile_definitions(USE_PORT_PNG)
   add_compile_definitions(USE_PORT_FREEIMAGE)

endif()


message(STATUS "DISTRO_RELEASE is ${DISTRO_RELEASE}")

include("operating_system/operating_system-posix/_desktop_ambient_1.cmake")

set(MIDI TRUE)
set(ALSA_MIDI TRUE)
set(INTERPROCESS_COMMUNICATION_SYSTEM_5 TRUE)


add_compile_definitions(WITH_X11)
add_compile_definitions(WITH_XCB)
if(${HAS_WAYLAND})
   add_compile_definitions(HAS_WAYLAND)
endif()
link_libraries(pthread)
include(FindPkgConfig)


if (EXISTS $ENV{HOME}/__config/xfce.txt)

   set(LINUX_XFCE TRUE)
   message(STATUS "Adding Xfce/X11 dependency.")

endif ()


set(copy_libraries_dependency "")


set(default_draw2d "draw2d_cairo")
set(default_imaging "imaging_freeimage")
set(default_write_text "write_text_pango")
set(default_audio "audio_alsa")
set(default_input "input_libinput")
set(default_music_midi "music_midi_alsa")
set(default_node "node_linux")
set(default_audio_mixer "audio_mixer_alsa")
set(default_gpu "gpu_opengl")
set(default_networking "networking_bsd")
set(default_acme "acme_linux")
set(default_apex "apex_linux")
set(default_nano_graphics "nano_graphics_cairo")
#add_compile_definitions(default_draw2d=draw2d_cairo)
#add_compile_definitions(default_imaging=imaging_freeimage)
#add_compile_definitions(default_write_text=write_text_pango)
#add_compile_definitions(default_audio=audio_alsa)
#add_compile_definitions(default_music_midi=music_midi_alsa)
#add_compile_definitions(default_node=node_linux)


set(LINUX TRUE)




list(APPEND acme_libraries
   acme
   acme_posix
   acme_linux)


list(APPEND static_acme_libraries
   static_acme
   static_acme_posix
   static_acme_linux)


list(APPEND apex_libraries
   ${acme_libraries}
   apex
   apex_posix
   apex_linux
)

list(APPEND aura_libraries
   ${apex_libraries}
   aura
   aura_posix
   aura_linux
   node_linux
)


set(default_nano_graphics nano_graphics_cairo)

include("operating_system/operating_system-posix/_desktop_ambient_2.cmake")

   #set(static_acme_extra_pkgconfig cairo xcb x11 xkbcommon xcb-render xcb-aux x11-xcb)
#set(static_aura_posix_pkgconfig libstartup-notification-1.0)
#
#set(static_acme_pkgconfig freetype2 libidn ${static_acme_extra_pkgconfig} ncurses dbus-glib-1)
#set(static_apex_pkgconfig libcrypto libssl libarchive)
#set(static_database_cairo_pkgconfig freetype2 pango cairo pangocairo)
#set(static_database_sqlite3_pkgconfig sqlite3)
#set(static_mpg123_pkgconfig ${MPG123_PKG_MODULE})
#set(static_desktop_environment_gnome_pkgconfig glib-2.0 gtk+-3.0 gdk-3.0 ${APPINDICATOR_PKG_MODULE})
#set(static_desktop_environment_kde_pkgconfig Qt5X11Extras Qt5Core Qt5UiTools)

#if (KDE_DESKTOP)
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_kde_pkgconfig})
#elseif (GTK_BASED_DESKTOP)
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_gnome_pkgconfig})
#else ()
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_gnome_pkgconfig})
#endif()
#




set(LIBCXX_TARGETING_MSVC OFF)


add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

list(APPEND app_common_dependencies ${default_node})

#list(APPEND app_common_dependencies _console_application_build_helper)


#set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/output")
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/output")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/output")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/output")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/output")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/output")

link_directories(${LIBRARY_OUTPUT_PATH})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/library/${TARGET_ARCH}/basis)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/${TARGET_ARCH}/basis)


#include_directories(${WORKSPACE_FOLDER})
#include_directories($ENV{HOME}/__config)
#include_directories(${WORKSPACE_FOLDER}/source)
#include_directories(${WORKSPACE_FOLDER}/source/app)
#include_directories(${WORKSPACE_FOLDER}/source/app/include)
#include_directories(${WORKSPACE_FOLDER}/source/include)
#include_directories(${WORKSPACE_FOLDER}/port/_)
#include_directories(${WORKSPACE_FOLDER}/port/include)
#include_directories(${WORKSPACE_FOLDER}/operating_system)
if (OPERATING_SYSTEM_POSIX)
   include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix)
   include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/include)
endif ()
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include)
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include/configuration_selection/${CMAKE_BUILD_TYPE})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${SLASHED_OPERATING_SYSTEM})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${DISTRO})

set(INCLUDE_DRAW2D_CAIRO TRUE)
set(INCLUDE_IMAGING_FREEIMAGE TRUE)


set(STORE_FOLDER $ENV{HOME}/store/${SLASHED_OPERATING_SYSTEM})






if("${APPINDICATOR_PKG_MODULE}" STREQUAL "")
   message(STATUS "APPINDICATOR_PKG_MODULE is (Empty)")
else ()
   message(STATUS "APPINDICATOR_PKG_MODULE is ${APPINDICATOR_PKG_MODULE}")
endif()
