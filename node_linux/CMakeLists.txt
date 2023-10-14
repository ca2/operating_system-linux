cmake_minimum_required(VERSION 3.16)
project(node_linux CXX)


list(APPEND library_source
    _.cpp
    _.h
    _factory.cpp
    )


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


list(APPEND library_references
   acme
   acme_posix
   acme_linux
   apex_posix
   apex_linux
   aura_posix
   aura_linux
   )


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)



target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(node_linux PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)


    target_compile_options(node_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(node_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(node_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/node_linux.lib")
    target_link_options(node_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/node_linux.def")
    target_link_libraries(node_linux PRIVATE ${library_references})


elseif(LINUX)




    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    list(APPEND system_libraries z dl pthread)


    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${system_libraries})
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${system_libraries})



    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)



endif()


add_dependencies(${PROJECT_NAME} ${default_desktop_environment})



list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(node_linux PRIVATE _NODE_LINUX_LIBRARY)
