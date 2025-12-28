cmake_minimum_required(VERSION 3.16)
project(aura_linux CXX)


list(APPEND library_source
   hardware/device_group.cpp
   hardware/device_group.h
   hardware/devices.cpp
   hardware/devices.h
   hardware/udev.cpp
   hardware/udev.h
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
add_library(static_${PROJECT_NAME} STATIC ${library_source})


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

list(APPEND static_library_references ${library_references})

list(TRANSFORM static_library_references PREPEND static_)



target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(aura_linux PROPERTIES LINKER_LANGUAGE CXX)


if(${WIN32})


    target_compile_options(aura_linux PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(aura_linux PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(aura_linux PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/aura_linux.lib")
    target_link_options(aura_linux PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/aura_linux.def")
    target_link_libraries(aura_linux PRIVATE acme apex aqua aura Gdiplus)


elseif(${LINUX})


    if(${USE_PKGCONFIG})
        pkg_check_modules(${PROJECT_NAME}_PKGCONFIG libudev)
    endif()


    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)

    target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_link_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_LDFLAGS})
    target_link_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_LDFLAGS})
    #target_link_options(video_input_video_for_linux PRIVATE -Wl,-rpath=$ORIGIN)
    #target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})

    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references})


    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)



endif()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)



target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)
