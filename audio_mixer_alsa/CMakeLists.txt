cmake_minimum_required(VERSION 3.16)
project(audio_mixer_alsa CXX)


list(APPEND library_source
   _.h
   #_library.h
   _factory.cpp
   audio_mixer.cpp
   audio_mixer.h
   callback.cpp
   callback.h
   control.cpp
   control.h
   framework.cpp
   framework.h
   destination.cpp
   destination.h
   device.cpp
   device.h
   line_info.cpp
   line_info.h
   source.cpp
   source.h
   )


list(APPEND library_references
   acme
   apex
   aqua
   aura
   axis
   base
   bred
   core
   audio
   multimedia
   )


add_library(audio_mixer_alsa SHARED ${library_source} )


target_precompile_headers(audio_mixer_alsa PRIVATE framework.h)


set_target_properties(audio_mixer_alsa PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)


   target_compile_options(audio_mixer_alsa PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(audio_mixer_alsa PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(audio_mixer_alsa PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(audio_mixer_alsa PRIVATE ${library_references})


elseif(LINUX OR FREEBSD)


   if(NOT DONT_USE_PKG_CONFIG)
      pkg_check_modules(PKGCONFIG alsa)
   endif()
   target_compile_options(audio_mixer_alsa PRIVATE -fpermissive)
   target_compile_options(audio_mixer_alsa PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(audio_mixer_alsa PRIVATE ${PKGCONFIG_LDFLAGS})
   target_link_libraries(audio_mixer_alsa PRIVATE ${PKGCONFIG_LIBRARIES})
   target_link_libraries(audio_mixer_alsa PRIVATE ${library_references})
   target_link_options(audio_mixer_alsa PRIVATE -Wl,-z,defs)


endif()



list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})





target_compile_definitions(audio_mixer_alsa PRIVATE _AUDIO_MIXER_ALSA_LIBRARY)



