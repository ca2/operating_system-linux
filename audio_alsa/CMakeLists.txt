cmake_minimum_required(VERSION 3.17)
project(audio CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
    set(PLATFORM_NAME "linux")
    include(FindPkgConfig)
elseif(WIN32)
    set(PLATFORM_NAME "windows")
endif()


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


list(APPEND audio_source
        _.h
        application.cpp
        application.h
        framework.cpp
        framework.h)


if (MSVC)
    set(LIBCXX_TARGETING_MSVC ON)
else()
    set(LIBCXX_TARGETING_MSVC OFF)
endif()


add_executable(audio ${audio_source})

target_precompile_headers(audio PRIVATE framework.h)

set_target_properties(audio PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(audio PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(audio PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(audio PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(audio PRIVATE acme apex aqua aura axis base)
    add_dependencies(audio draw2d_gdiplus)
elseif(LINUX)
    target_compile_options(audio PRIVATE -fpermissive)
    target_link_options(audio PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(audio PRIVATE acme apex aqua aura axis base)
    target_link_options(audio PRIVATE -Wl,-z,defs)
    add_dependencies(audio draw2d_cairo)
endif()

add_dependencies(audio experience_core)


target_link_directories(audio PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(audio PRIVATE .)
target_include_directories(audio PRIVATE $ENV{HOME}/__config)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(audio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(audio PRIVATE _audio_LIBRARY)
target_compile_definitions(audio PRIVATE UNICODE)
target_compile_definitions(audio PRIVATE _UNICODE)






