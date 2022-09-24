cmake_minimum_required(VERSION 3.16)
project(node_linux CXX)


list(APPEND library_source
    _.cpp
    _.h
    _factory.cpp
    )


add_library(${PROJECT_NAME} SHARED ${library_source})


list(APPEND library_references
   acme
   acme_posix
   acme_linux
   apex_posix
   apex_linux
   aura_posix
   aura_linux
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


    target_link_libraries(node_linux PRIVATE z dl pthread ${library_references})
    target_link_options(node_linux PRIVATE -Wl,-z,defs)


endif()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(node_linux PRIVATE _NODE_LINUX_LIBRARY)
