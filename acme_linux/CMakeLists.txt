cmake_minimum_required(VERSION 3.17)
project(acme_linux CXX)


list(APPEND library_source
        _.cpp
        _.h
   _acme_linux.h
   acme_dir.cpp
        acme_dir.h
        acme_path.cpp
        acme_path.h
   console.cpp
   console.h
   console_ncurses.cpp
        factory_exchange.cpp
        factory_exchange.h
   file.cpp
   file.h
        framework.cpp
        framework.h
        node.cpp
        node.h
   stdio_file.cpp
   stdio_file.h
    )



add_library(acme_linux SHARED ${library_source})

set_source_files_properties(console_ncurses.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

list(APPEND library_references acme acme_posix node_linux)


target_precompile_headers(acme_linux PRIVATE framework.h)


set_target_properties(acme_linux PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(acme_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(acme_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(acme_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/acme_linux.lib")
    target_link_options(acme_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/acme_linux.def")
    target_link_libraries(acme_linux PRIVATE acme apex aqua aura Gdiplus)
elseif(LINUX)
    target_link_options(acme_linux PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(acme_linux PRIVATE dl ncurses ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(acme_linux PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()


target_include_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(acme_linux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(acme_linux PRIVATE _ACME_LINUX_LIBRARY)



