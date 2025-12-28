cmake_minimum_required(VERSION 3.16)
project(apex_linux CXX)


list(APPEND library_source
        _.cpp
        _.h
        _factory.cpp
        app_launcher.cpp
        app_launcher.h
        #crypto.cpp
        #crypto.h
#        dir_context.cpp
#        dir_context.h
#        dir_system.cpp
#        dir_system.h
#        file_context.cpp
#        file_context.h
#        file_system.cpp
#        file_system.h
        framework.cpp
        framework.h
        #interprocess_communication.cpp
        #interprocess_communication.h
        ip_enum.cpp
        ip_enum.h
        launcher.cpp
        launcher.h
        node.cpp
        node.h
        #os_context.cpp
        #os_context.h
        service_handler.cpp
        service_handler.h
        )


list(APPEND library_references
        acme
        apex
        acme_posix
        acme_linux
        apex_posix)


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)



add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(apex_linux PROPERTIES LINKER_LANGUAGE CXX)


if(${WIN32})


    target_compile_options(apex_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(apex_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(apex_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/apex_linux.lib")
    target_link_options(apex_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/apex_linux.def")
    target_link_libraries(apex_linux PRIVATE acme apex aqua aura Gdiplus)


elseif (LINUX)




    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references})


    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)



endif ()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)



