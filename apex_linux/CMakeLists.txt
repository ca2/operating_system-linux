cmake_minimum_required(VERSION 3.17)
project(apex_linux CXX)


list(APPEND library_source
    _.cpp
    _.h
    crypto.cpp
    crypto.h
    dir_context.cpp
    dir_context.h
    dir_system.cpp
    dir_system.h
    factory_exchange.cpp
    factory_exchange.h
    file_context.cpp
    file_context.h
    file_system.cpp
    file_system.h
    framework.cpp
    framework.h
    interprocess_communication.cpp
    interprocess_communication.h
    ip_enum.cpp
    ip_enum.h
    launcher.cpp
    launcher.h
    node.cpp
    node.h
    os_context.cpp
    os_context.h
    service_handler.cpp
    service_handler.h
    )


list(APPEND library_references
   acme
   apex
   acme_posix
   acme_linux
   apex_posix)

add_library(apex_linux SHARED ${library_source})

target_precompile_headers(apex_linux PRIVATE framework.h)

set_target_properties(apex_linux PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(apex_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(apex_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(apex_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/apex_linux.lib")
    target_link_options(apex_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/apex_linux.def")
    target_link_libraries(apex_linux PRIVATE acme apex aqua aura Gdiplus)
elseif(LINUX)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    #pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    target_compile_options(apex_linux PRIVATE ${PKGCONFIG_CFLAGS})
    #target_compile_options(apex_linux PRIVATE -std=c++14)
    #target_link_options(apex_linux PRIVATE ${GTK_LDFLAGS})
    #target_link_options(apex_linux PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(apex_linux PRIVATE ${PKGCONFIG_LIBRARIES})
    target_link_libraries(apex_linux PRIVATE ${library_references})
    target_link_options(apex_linux PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()


target_include_directories(apex_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(apex_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(apex_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(apex_linux PRIVATE _APEX_LINUX_LIBRARY)



