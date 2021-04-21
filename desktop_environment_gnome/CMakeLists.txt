cmake_minimum_required(VERSION 3.17)
project(desktop_environment_gnome CXX)


list(APPEND desktop_environment_gnome_source
   _.cpp
   _.h
        #appindicator.cpp
        #appindicator.h
        #application.cpp
        #application.h
        #clipboard_data.h
        #copydesk.cpp
        #copydesk.h
        #display.cpp
        #display.h
        #enum_display_monitors.cpp
   factory_exchange.cpp
   factory_exchange.h
   framework.cpp
   framework.h
        #gdk.cpp
        #gdk.h
        #gnome_direct.cpp
        #gtk_clipboard.cpp
        #monitor.cpp
        #monitor.h
   node.cpp
   node.h
        #notify_icon.cpp
        #windowing.cpp
        #windowing.h
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
   node_gnome
   )



add_library(desktop_environment_gnome SHARED ${desktop_environment_gnome_source} )

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
   target_link_options(desktop_environment_gnome PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(desktop_environment_gnome PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   target_link_options(desktop_environment_gnome PRIVATE -Wl,-z,defs)
endif ()


target_include_directories(desktop_environment_gnome PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(desktop_environment_gnome PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(desktop_environment_gnome PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(desktop_environment_gnome PRIVATE _desktop_environment_gnome_LIBRARY)
target_compile_definitions(desktop_environment_gnome PRIVATE UNICODE)
target_compile_definitions(desktop_environment_gnome PRIVATE _UNICODE)



