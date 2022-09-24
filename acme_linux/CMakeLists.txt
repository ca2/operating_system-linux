cmake_minimum_required(VERSION 3.16)
project(acme_linux CXX)


list(APPEND library_source
   _.cpp
   _.h
   _acme_linux.h
   _factory.cpp
   acme_directory.cpp
   acme_directory.h
   acme_file.cpp
   acme_file.h
   acme_path.cpp
   acme_path.h
   console.cpp
   console.h
   console_ncurses.cpp
   file.cpp
   file.h
   framework.cpp
   framework.h
   node.cpp
   node.h
   #stdio_file.cpp
   #stdio_file.h
   )


add_library(${PROJECT_NAME} SHARED ${library_source})


set_source_files_properties(console_ncurses.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)


list(APPEND library_references
   acme
   acme_posix)


target_precompile_headers(acme_linux PRIVATE framework.h)


set_target_properties(acme_linux PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)


    target_compile_options(acme_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(acme_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(acme_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/acme_linux.lib")
    target_link_options(acme_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/acme_linux.def")
    target_link_libraries(acme_linux PRIVATE acme apex aqua aura Gdiplus)


elseif(LINUX)


    target_link_libraries(acme_linux PRIVATE dl ncurses ${library_references})
    target_link_options(acme_linux PRIVATE -Wl,-z,defs)


endif()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(acme_linux PRIVATE _ACME_LINUX_LIBRARY)



