cmake_minimum_required(VERSION 3.16)
project(desktop_environment_gnome CXX)


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
   windowing_x11
   node_gtk
   node_gnome
   )



add_library(${PROJECT_NAME} SHARED ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif (LINUX)

   if(NOT DONT_USE_PKG_CONFIG)
      pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0)
   endif()
   target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
   target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
   #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
endif ()

add_dependencies(${PROJECT_NAME} node_linux)
add_dependencies(${PROJECT_NAME} node_gtk)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(${PROJECT_NAME} PRIVATE _desktop_environment_gnome_LIBRARY)
target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE)



