cmake_minimum_required(VERSION 3.17)
project(aura_linux CXX)


list(APPEND aura_linux_source
    _.cpp
    _.h
    _aura_linux.h
    _const.h
    #appindicator.cpp
    #appindicator.h
    factory_exchange.cpp
    interaction_impl.cpp
    interaction_impl.h
    node.cpp
    node.h
    )


add_library(aura_linux SHARED ${aura_linux_source})


list(APPEND library_references
   acme
   apex
   aqua
   aura
   acme_posix
   acme_linux
   apex_posix
   apex_linux
   aura_posix
   )


target_precompile_headers(aura_linux PRIVATE framework.h)

set_target_properties(aura_linux PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(aura_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(aura_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(aura_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/aura_linux.lib")
    target_link_options(aura_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/aura_linux.def")
    target_link_libraries(aura_linux PRIVATE acme apex aqua aura Gdiplus)
elseif(LINUX)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    #pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    target_compile_options(aura_linux PRIVATE ${PKGCONFIG_CFLAGS})
    #target_compile_options(aura_linux PRIVATE -std=c++14)
    #target_link_options(aura_linux PRIVATE ${GTK_LDFLAGS})
    target_link_options(aura_linux PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(aura_linux PRIVATE ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(aura_linux PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()

target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(aura_linux PRIVATE _AURA_LINUX_LIBRARY)
