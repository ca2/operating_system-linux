cmake_minimum_required(VERSION 3.17)
project(desktop_environment_gnome CXX)


list(APPEND library_source
   _.cpp
   _.h
   _desktop_environment_gnome.h
   _factory.cpp
   framework.cpp
   framework.h
   node.cpp
   node.h
   )


list(APPEND library_references
   acme
   acme_posix
   acme_linux
   apex
   apex_posix
   apex_linux
   aqua
   aura
   aura_posix
   aura_linux
   windowing_x11
   node_gtk
   node_gnome
   )



add_library(desktop_environment_gnome SHARED ${library_source})

target_precompile_headers(desktop_environment_gnome PRIVATE framework.h)

set_target_properties(desktop_environment_gnome PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(desktop_environment_gnome PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(desktop_environment_gnome PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(desktop_environment_gnome PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(desktop_environment_gnome PRIVATE ${library_references})
elseif (LINUX)
   pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator3-0.1)
   target_compile_options(desktop_environment_gnome PRIVATE -fpermissive)
   target_compile_options(desktop_environment_gnome PRIVATE ${PKGCONFIG_CFLAGS})
   #target_link_options(desktop_environment_gnome PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(desktop_environment_gnome PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   target_link_options(desktop_environment_gnome PRIVATE -Wl,-z,defs)
endif ()

add_dependencies(desktop_environment_gnome node_linux)


target_include_directories(desktop_environment_gnome PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(desktop_environment_gnome PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(desktop_environment_gnome PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(desktop_environment_gnome PRIVATE _desktop_environment_gnome_LIBRARY)
target_compile_definitions(desktop_environment_gnome PRIVATE UNICODE)
target_compile_definitions(desktop_environment_gnome PRIVATE _UNICODE)



