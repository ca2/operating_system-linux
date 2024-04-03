cmake_minimum_required(VERSION 3.16)
project(desktop_environment_kde CXX)


list(APPEND library_source
        _.cpp
        _.h
        #_library.h
        _factory.cpp
        #appindicator.cpp
        #appindicator.h
        #application.cpp
        #application.h
        #clipboard_data.h
        #copydesk.cpp
        #copydesk.h
        #enum_display_monitors.cpp
        #framework.cpp
        #framework.h
        #gdk.cpp
        #gdk.h
        #gnome_direct.cpp
        #gtk_clipboard.cpp
        node.cpp
        node.h
        #node_impl.cpp
        #node_impl.h
        #q_node_impl.cpp
        #q_node_impl.h
        )


list(APPEND library_references
        acme
        acme_posix
        acme_linux
        apex
        apex_posix
        apex_linux
        aqua
        aura
        aura_posix
        aura_linux
        windowing_xcb
        )

if(${HAS_KDE6})

    list(APPEND library_references
            node_kde6)

elseif(${HAS_KDE5})

    list(APPEND library_references
            node_kde5)

endif()


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


if(${HAS_KDE6})

list(APPEND system_libraries
        Qt6::Core
        Qt6::Widgets
        )

elseif(${HAS_KDE5})

    list(APPEND system_libraries
            Qt5::Core
            Qt5::Widgets
    )

endif()

#set_source_files_properties(q_node_impl.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(desktop_environment_kde PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(desktop_environment_kde PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(desktop_environment_kde PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(desktop_environment_kde PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(desktop_environment_kde PRIVATE ${library_references})
elseif (LINUX)

    #
    #   if(USE_PKGCONFIG)
    #      pkg_check_modules(PKGCONFIG Qt5X11Extras Qt5Core Qt5UiTools)
    #   endif()


    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})

    #target_link_options(desktop_environment_kde PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${system_libraries} ${PKGCONFIG_LIBRARIES})
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${system_libraries} ${PKGCONFIG_LIBRARIES})

    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)

endif ()


#add_dependencies(desktop_environment_kde node_linux)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(desktop_environment_kde PRIVATE _MUSIC_MIDI_ALSA_LIBRARY)



