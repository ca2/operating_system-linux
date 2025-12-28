cmake_minimum_required(VERSION 3.16)
project(operating_ambient_lxq1 CXX)


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
   node_lxq1
   )




list(APPEND this_system_libraries
#   KF6::ConfigWidgets
#   KF6::IconThemes
#   KF6::KIOCore
#   KF6::KIOGui
#   KF6::KIOWidgets
#   KF6::Notifications
#   KF6::StatusNotifierItem
#   PW::KWorkspace
   Qt5::Core
   Qt5::Widgets
   #Qt6::X11Extras
   Qt5::Gui
   Qt5::GuiPrivate
)

if (${FREEBSD} OR ${DEBIAN} OR ${SUSE} OR ${FEDORA} OR ${UBUNTU})
   list(APPEND this_system_libraries
      #KF6Package
   )
   #elseif (${UBUNTU})
   #    list(APPEND this_system_libraries
   #  KF6::Plasma
   #)
else()
   list(APPEND this_system_libraries
      #KF6::Plasma
      #KF6::PlasmaQuick
   )
endif ()

#Qt5::Core
#Qt5::UiTools
#Qt5::X11Extras
#KF5::Notifications
#KF5::ConfigWidgets
#KF5::IconThemes
#KF5::KIOCore
#KF5::KIOFileWidgets
#KF5::KIOWidgets
#KF5::KIONTLM
#PW::KWorkspace

list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if(${WIN32})
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif (${LINUX} OR ${__BSD__})


#   if(${HAS_GTK4})
#      #pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk4)
#      pkg_check_modules(${PROJECT_NAME}_PKGCONFIG gtk4)
#   elseif(${HAS_GTK3})
#      pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0)
#   endif()
#

   target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


   target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
   target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})

   #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(${PROJECT_NAME} PRIVATE ${this_system_libraries} ${library_references} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
   target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})

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



