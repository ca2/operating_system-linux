cmake_minimum_required(VERSION 3.17)
project(aura_linux CXX)


list(APPEND draw2d_gdiplus_source
    _.cpp
    _.h
    _const.h
   appindicator.cpp
   appindicator.h
    factory_exchange.cpp
    node.cpp
    node.h
    ../platform/x_window.cpp
    )


if (MSVC)
    set(LIBCXX_TARGETING_MSVC ON)
else()
    set(LIBCXX_TARGETING_MSVC OFF)
endif()


add_library(aura_linux SHARED ${draw2d_gdiplus_source})

list(APPEND library_references
   acme
   apex
   aqua
   aura
   acme_posix
   acme_linux
   apex_posix
   apex_linux
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
    pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    target_compile_options(aura_linux PRIVATE ${PKGCONFIG_CFLAGS})
    #target_compile_options(aura_linux PRIVATE -std=c++14)
    #target_link_options(aura_linux PRIVATE ${GTK_LDFLAGS})
    target_link_options(aura_linux PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(aura_linux PRIVATE z dl pthread ncurses ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(aura_linux PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()

target_link_directories(aura_linux PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(aura_linux PRIVATE $ENV{HOME}/__config)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(aura_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(aura_linux PRIVATE _DRAW2D_GDIPLUS_LIBRARY)
target_compile_definitions(aura_linux PRIVATE UNICODE)
target_compile_definitions(aura_linux PRIVATE _UNICODE)
