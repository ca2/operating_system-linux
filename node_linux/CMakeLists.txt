cmake_minimum_required(VERSION 3.17)
project(node_linux CXX)


list(APPEND library_source
    _.cpp
    _.h
    factory_exchange.cpp
    )




add_library(node_linux SHARED ${library_source})

list(APPEND library_references
   acme
   )


target_precompile_headers(node_linux PRIVATE framework.h)

set_target_properties(node_linux PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(node_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(node_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(node_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/node_linux.lib")
    target_link_options(node_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/node_linux.def")
    target_link_libraries(node_linux PRIVATE ${library_references})
elseif(LINUX)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    #pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    target_compile_options(node_linux PRIVATE ${PKGCONFIG_CFLAGS})
    #target_compile_options(node_linux PRIVATE -std=c++14)
    #target_link_options(node_linux PRIVATE ${GTK_LDFLAGS})
    #target_link_options(node_linux PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(node_linux PRIVATE z dl pthread ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(node_linux PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()

target_include_directories(node_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(node_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(node_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(node_linux PRIVATE _NODE_LINUX_LIBRARY)
