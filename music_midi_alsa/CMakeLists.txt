cmake_minimum_required(VERSION 3.17)
project(music_midi_alsa CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")


if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
   set(LINUX TRUE)
   set(PLATFORM_NAME "linux")
   include(FindPkgConfig)
elseif (WIN32)
   set(PLATFORM_NAME "windows")
endif ()


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


list(APPEND audio_alsa_source
   _.h
   _.cpp
   midi.cpp
   midi.h
   out.cpp
   out.h
   factory_exchange.cpp
   factory_exchange.h
   translation.cpp
   translation.h
   factory_exchange.cpp
   factory_exchange.h
   framework.cpp
   framework.h
   message_out.cpp
   message_out.h
   translation.cpp
   translation.h
   )


list(APPEND library_references
   acme
   apex
   aqua
   aura
   veriwell_multimedia
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
else ()
   set(LIBCXX_TARGETING_MSVC OFF)
endif ()


add_library(music_midi_alsa SHARED ${audio_alsa_source})

target_precompile_headers(music_midi_alsa PRIVATE framework.h)

set_target_properties(music_midi_alsa PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(music_midi_alsa PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(music_midi_alsa PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(music_midi_alsa PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(music_midi_alsa PRIVATE ${library_references})
   add_dependencies(music_midi_alsa draw2d_gdiplus)
elseif (LINUX)
   target_compile_options(music_midi_alsa PRIVATE -fpermissive)
   target_link_options(music_midi_alsa PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(music_midi_alsa PRIVATE ${library_references})
   target_link_libraries(music_midi_alsa PRIVATE asound)
   target_link_options(music_midi_alsa PRIVATE -Wl,-z,defs)
   add_dependencies(music_midi_alsa draw2d_cairo)
endif ()


add_dependencies(music_midi_alsa experience_core)


target_link_directories(music_midi_alsa PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(music_midi_alsa PRIVATE .)
target_include_directories(music_midi_alsa PRIVATE $ENV{HOME}/__config)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(music_midi_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(music_midi_alsa PRIVATE _MUSIC_MIDI_ALSA_LIBRARY)
target_compile_definitions(music_midi_alsa PRIVATE UNICODE)
target_compile_definitions(music_midi_alsa PRIVATE _UNICODE)



