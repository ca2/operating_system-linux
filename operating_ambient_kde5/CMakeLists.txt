cmake_minimum_required(VERSION 3.16)
project(operating_ambient_kde5 CXX)


list(APPEND library_source
   _.cpp
   _.h
   _factory.cpp
   #_library.h
   framework.cpp
   framework.h
   node.cpp
   node.h
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
   #windowing_x11
    #    node_gdk
   #node_gtk_based
   node_q
   )


if(${HAS_KDE6})
   list(APPEND library_references node_kde6)
elseif(${HAS_KDE5})
   list(APPEND library_references node_kde5)
endif()


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)



list(APPEND this_system_libraries
   KF5::ConfigWidgets
   KF5::IconThemes
   KF5::KIOCore
   KF5::KIOGui
   KF5::KIOWidgets
   KF5::Notifications
   PW::KWorkspace
   Qt5::Core
   Qt5::Widgets
   Qt5::X11Extras
   Qt5::GuiPrivate
)

if (${FREEBSD} OR ${DEBIAN})
   list(APPEND this_system_libraries
      KF5Package
   )
else ()
   list(APPEND this_system_libraries
      KF5::Plasma
      KF5::PlasmaQuick
   )
endif ()


if (MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif (LINUX)


   if(${HAS_GTK4})
      #pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk4)
      pkg_check_modules(${PROJECT_NAME}_PKGCONFIG gtk4)
   elseif(${HAS_GTK3})
      pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0)
   endif()


   target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


   target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
   target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})

   #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${this_system_libraries} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
   target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${this_system_libraries} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})

   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
   target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)

endif ()




list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)
target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE)



