cmake_minimum_required(VERSION 3.16)
project(aura_linux CXX)


list(APPEND library_source
   _.cpp
   _.h
   #_aura_linux.h
   _const.h
   _factory.cpp
   interaction_impl.cpp
   interaction_impl.h
   node.cpp
   node.h
   )


add_library(${PROJECT_NAME} SHARED ${library_source})


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


    target_link_libraries(aura_linux PRIVATE ${library_references})
    target_link_options(aura_linux PRIVATE -Wl,-z,defs)


endif()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)



target_compile_definitions(aura_linux PRIVATE _AURA_LINUX_LIBRARY)
