cmake_minimum_required(VERSION 3.17)
project(audio_alsa CXX)


list(APPEND audio_alsa_source
        _.h
        audio_mmsystem_wave_in.h
        factory_exchange.cpp
        factory_exchange.h
        framework.cpp
        framework.h
        snd_pcm.cpp
        snd_pcm.h
        translation.cpp
        translation.h
        wave_in.cpp
        wave_in.h
        wave_out.cpp
        wave_out.h
        )


list(APPEND library_references
   acme
   apex
   aqua
   audio
   )


add_library(audio_alsa SHARED ${audio_alsa_source})

target_precompile_headers(audio_alsa PRIVATE framework.h)

set_target_properties(audio_alsa PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(audio_alsa PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(audio_alsa PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(audio_alsa PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(audio_alsa PRIVATE ${library_references})
elseif(LINUX)
    target_compile_options(audio_alsa PRIVATE -fpermissive)
    target_link_options(audio_alsa PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(audio_alsa PRIVATE ${library_references})
    target_link_libraries(audio_alsa PRIVATE asound)
    target_link_options(audio_alsa PRIVATE -Wl,-z,defs)
endif()

add_dependencies(audio_alsa ${default_draw2d} ${default_imaging} ${default_write_text})
add_dependencies(audio_alsa ${default_audio})
add_dependencies(audio_alsa experience_core)


target_link_directories(audio_alsa PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(audio_alsa PRIVATE .)
target_include_directories(audio_alsa PRIVATE $ENV{HOME}/__config)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(audio_alsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(audio_alsa PRIVATE _AUDIO_ALSA_LIBRARY)
target_compile_definitions(audio_alsa PRIVATE UNICODE)
target_compile_definitions(audio_alsa PRIVATE _UNICODE)






