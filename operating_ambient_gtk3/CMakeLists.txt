cmake_minimum_required(VERSION 3.16)
project(operating_ambient_gtk3 CXX)


list(APPEND library_source
        _.cpp
        _.h
        #_${PROJECT_NAME}.h
        #appindicator.cpp
        #appindicator.h
        #application.cpp
        #application.h
        #clipboard_data.h
        #copydesk.cpp
        #copydesk.h
        #display.cpp
        #display.h
        #enum_display_monitors.cpp
        _factory.cpp
        framework.cpp
        framework.h
        #gdk.cpp
        #gdk.h
        #xfce_direct.cpp
        #gtk_clipboard.cpp
        #monitor.cpp
        #monitor.h
        node.cpp
        node.h
        #notify_icon.cpp
        #windowing.cpp
        #windowing.h
)


list(APPEND library_references
        acme
        acme_posix
        acme_linux
   nano_graphics_cairo
        acme_windowing_gtk3
        apex
        apex_posix
        apex_linux
        innate_ui_gtk3
        aqua
        aura
        aura_posix
        aura_linux
        windowing_gtk3
        #windowing_x11
        #node_gdk
        node_gtk3
        #node_xfce
)


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif (${LINUX})

    if (${USE_PKGCONFIG})
        pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 ${APPINDICATOR_PKG_MODULE})
    endif ()


    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)

endif ()


#add_dependencies(${PROJECT_NAME} node_linux)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)



