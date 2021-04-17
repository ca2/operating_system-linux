cmake_minimum_required(VERSION 3.17)
project(acme_linux CXX)


list(APPEND acme_linux_source
        _.cpp
        _.h
        acme_dir.cpp
        acme_dir.h
        acme_path.cpp
        acme_path.h
        factory_exchange.cpp
        factory_exchange.h
        framework.cpp
        framework.h
        node.cpp
        node.h
    )


if (MSVC)
    set(LIBCXX_TARGETING_MSVC ON)
else()
    set(LIBCXX_TARGETING_MSVC OFF)
endif()


add_library(acme_linux SHARED ${acme_linux_source})


list(APPEND library_references acme acme_posix)


target_precompile_headers(acme_linux PRIVATE framework.h)


set_target_properties(acme_linux PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(acme_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(acme_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(acme_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/acme_linux.lib")
    target_link_options(acme_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/acme_linux.def")
    target_link_libraries(acme_linux PRIVATE acme apex aqua aura Gdiplus)
elseif(LINUX)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    #pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    #target_compile_options(acme_linux PRIVATE ${PKGCONFIG_CFLAGS})
    #target_compile_options(acme_linux PRIVATE -std=c++14)
    #target_link_options(acme_linux PRIVATE ${GTK_LDFLAGS})
    target_link_options(acme_linux PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(acme_linux PRIVATE ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(acme_linux PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()


target_link_directories(acme_linux PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(acme_linux PRIVATE $ENV{HOME}/__config)
target_include_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(acme_linux PRIVATE _ACME_LINUX_LIBRARY)
target_compile_definitions(acme_linux PRIVATE UNICODE)
target_compile_definitions(acme_linux PRIVATE _UNICODE)



