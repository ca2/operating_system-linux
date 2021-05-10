cmake_minimum_required(VERSION 3.17)
project(desktop_environment_kde CXX)


list(APPEND desktop_environment_kde_source
   _.cpp
   _.h
   #appindicator.cpp
   #appindicator.h
   #application.cpp
   #application.h
   #clipboard_data.h
   #copydesk.cpp
   #copydesk.h
   #enum_display_monitors.cpp
   factory_exchange.cpp
   factory_exchange.h
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
   node_kde
   )


#set_source_files_properties(q_node_impl.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

add_library(desktop_environment_kde SHARED ${desktop_environment_kde_source} _desktop_environment_kde.h)

target_precompile_headers(desktop_environment_kde PRIVATE framework.h)

set_target_properties(desktop_environment_kde PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(desktop_environment_kde PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(desktop_environment_kde PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(desktop_environment_kde PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(desktop_environment_kde PRIVATE ${library_references})
elseif (LINUX)
   pkg_check_modules(PKGCONFIG Qt5X11Extras Qt5Core Qt5UiTools)
   target_compile_options(desktop_environment_kde PRIVATE -fpermissive)
   target_compile_options(desktop_environment_kde PRIVATE ${PKGCONFIG_CFLAGS})
   if(LINUX_KDE)
      target_include_directories(desktop_environment_kde PRIVATE KF5::Notifications)
   endif()
   target_link_options(desktop_environment_kde PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(desktop_environment_kde PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   if(LINUX_KDE)
      target_link_libraries(desktop_environment_kde PRIVATE KF5::Notifications)
   endif()
   target_link_options(desktop_environment_kde PRIVATE -Wl,-z,defs)
endif ()


target_include_directories(desktop_environment_kde PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(desktop_environment_kde PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(desktop_environment_kde PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(desktop_environment_kde PRIVATE _MUSIC_MIDI_ALSA_LIBRARY)



