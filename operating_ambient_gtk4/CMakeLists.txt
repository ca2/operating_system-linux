cmake_minimum_required(VERSION 3.16)
project(operating_ambient_gtk4 CXX)


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
   )


if(${HAS_GTK4})
   list(APPEND library_references node_gtk4)
elseif(${HAS_GTK3})
   list(APPEND library_references node_gtk3)
endif()


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


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
elseif (LINUX)


   if(${HAS_GTK4})
      #pkg_check_modules(PKGCONFIG glib-2.0 gtk4)
      pkg_check_modules(PKGCONFIG gtk4)
   elseif(${HAS_GTK3})
      pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0)
   endif()


   target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


   target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
   target_compile_options(static_${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})

   #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${PKGCONFIG_LIBRARIES})

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



