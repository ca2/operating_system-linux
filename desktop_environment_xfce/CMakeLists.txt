cmake_minimum_required(VERSION 3.16)
project(desktop_environment_xfce CXX)


list(APPEND library_source
   _.cpp
   _.h
        _desktop_environment_xfce.h
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
   framework.cpp
   framework.h
        #gdk.cpp
        #gdk.h
        #xfce_direct.cpp
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
   node_gtk
   node_xfce
   )



add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(desktop_environment_xfce PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(desktop_environment_xfce PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(desktop_environment_xfce PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(desktop_environment_xfce PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(desktop_environment_xfce PRIVATE ${library_references})
elseif (LINUX)

   if(NOT DONT_USE_PKG_CONFIG)
      pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 ${APPINDICATOR_PKG_MODULE})
   endif()


   target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
   target_compile_options(static_${PROJECT_NAME} PRIVATE -fpermissive)
   target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


   target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
target_compile_options(static_${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
   #target_link_options(desktop_environment_xfce PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(desktop_environment_xfce PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)

endif ()


add_dependencies(desktop_environment_xfce node_linux)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(desktop_environment_xfce PRIVATE _desktop_environment_xfce_LIBRARY)



