



#message(STATUS "CMAKE_SYSTEM_NAME is ${CMAKE_SYSTEM_NAME}")

#FIND_PACKAGE(PkgConfig)

#include(FindPkgConfig)

#IF(PKG_CONFIG_FOUND)
# use pkg_check_modules()
#ENDIF(PKG_CONFIG_FOUND)
set(FREEBSD FALSE)
set(DEBIAN FALSE)
set(FEDORA FALSE)
set(USE_PKGCONFIG TRUE)
set(CURL_NANO_HTTP TRUE)
set(HAS_WAYLAND TRUE)
set(HAS_X11 TRUE)
set(TOOL_RELEASE_NAME "linux")
set(MAIN_STORE_SLASHED_OPERATING_SYSTEM "linux")
set(OPERATING_SYSTEM_TOOL_FOLDER "tool-linux")


add_compile_definitions(TOOL_FOLDER_OPERATING_SYSTEM_NAME="${TOOL_RELEASE_NAME}")


execute_process(COMMAND uname -m OUTPUT_VARIABLE __SYSTEM_ARCHITECTURE)
string(STRIP ${__SYSTEM_ARCHITECTURE} __SYSTEM_ARCHITECTURE)
message(STATUS "__SYSTEM_ARCHITECTURE is ${__SYSTEM_ARCHITECTURE}")


execute_process(COMMAND lsb_release -is OUTPUT_VARIABLE __OPERATING_SYSTEM)
string(STRIP ${__OPERATING_SYSTEM} __OPERATING_SYSTEM)
string(TOLOWER ${__OPERATING_SYSTEM} __OPERATING_SYSTEM)
message(STATUS "__OPERATING_SYSTEM is ${__OPERATING_SYSTEM}")




if ("${CMAKE_BUILD_TYPE}" STREQUAL "")

   set(CMAKE_BUILD_TYPE Debug)

endif ()


if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

   error("This file is designed to be used only for linux systems...")

endif ()


#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#
#   message(STATUS "GNU Compiler")
#
#   string(APPEND CMAKE_CXX_FLAGS "-fPIC -fexceptions -fnon-call-exceptions -frtti")
#
#   #set(EXTRA_CXX_TARGET_COMPILER_OPTIONS "-ansi")
#
#else()
#
#   #set(EXTRA_CXX_TARGET_COMPILER_OPTIONS "")
#
#endif ()


set(DONT_USE_PKG_CONFIG NOT PKG_CONFIG_FOUND)



set(UNDERSCORE_OPERATING_SYSTEM $ENV{__SYSTEM_UNDERSCORE_OPERATING_SYSTEM})
set(SLASHED_OPERATING_SYSTEM $ENV{__SYSTEM_SLASHED_OPERATING_SYSTEM})
set(DISTRO $ENV{__SYSTEM_DISTRO})
set(DISTRO_RELEASE $ENV{__SYSTEM_DISTRO_RELEASE})


string(TOLOWER ${CMAKE_BUILD_TYPE} tolower_cmake_build_type)


message(STATUS "tolower_cmake_build_type = ${tolower_cmake_build_type}")


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
   set(CMAKE_CXX_EXTENSIONS OFF)
   add_compile_options(-fmax-errors=10)
endif()


if (${tolower_cmake_build_type} STREQUAL "debug")

   message(STATUS "Debug Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "relwithdebinfo")

   message(STATUS "RelWithDebInfo Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "release")

   message(STATUS "Release Build!!")

   add_compile_definitions(NDEBUG)

   message(STATUS "NDEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "minsizerel")

   message(STATUS "MinSizeRel Build!!")

   add_compile_definitions(NDEBUG)

   message(STATUS "NDEBUG compile definition set!!")

else ()

   message(STATUS "\"${CMAKE_BUILD_TYPE}\" Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

endif ()


SET(CMAKE_SKIP_BUILD_RPATH FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#if(${DESKTOP_AMBIENT})
## DESKTOP_AMBIENT are dependant just on linux kernel version and glib version?
#if(${DISTRO} STREQUAL "linuxmint")
#   set(DISTRO "ubuntu")
#   set(LINUX_MINT TRUE)
#   if(${DISTRO_RELEASE} LESS_EQUAL 20)
#      set(DISTRO_RELEASE "20.04")
#   elseif(${DISTRO_RELEASE} LESS_EQUAL 21)
#      set(DISTRO_RELEASE "22.04")
#   else()
#      set(DISTRO_RELEASE "24.04")
#   endif()
#endif()
#
#endif()


set(LINUX TRUE)
set(FREEBSD FALSE)
set(OPERATING_SYSTEM_NAME "linux")
set(OPERATING_SYSTEM_POSIX TRUE)
set(FILE_SYSTEM_INOTIFY TRUE)
set(POSIX_SPAWN TRUE)
set(WITH_X11 TRUE)
set(WITH_XCB TRUE)
set(USE_OPENSSL TRUE)
set(PTHREAD TRUE)
set(PLATFORM_NAME "linux")


if(${DESKTOP_AMBIENT})


   set(CURRENT_DESKTOP_ENVIRONMENT $ENV{XDG_CURRENT_DESKTOP})


   if (${CURRENT_DESKTOP_ENVIRONMENT} STREQUAL "KDE")

      set(KDE_DESKTOP TRUE)
      message(STATUS "System is KDE")
      set(DESKTOP_ENVIRONMENT_NAME "kde")

   elseif (${CURRENT_DESKTOP_ENVIRONMENT} STREQUAL "ubuntu:GNOME")

      set(GNOME_DESKTOP TRUE)
      set(GTK_BASED_DESKTOP TRUE)
      message(STATUS "System is GNOME")
      set(DESKTOP_ENVIRONMENT_NAME "gnome")

   elseif (${CURRENT_DESKTOP_ENVIRONMENT} STREQUAL "GNOME")

      set(GNOME_DESKTOP TRUE)
      set(GTK_BASED_DESKTOP TRUE)
      message(STATUS "System is GNOME")
      set(DESKTOP_ENVIRONMENT_NAME "gnome")

   elseif (${CURRENT_DESKTOP_ENVIRONMENT} STREQUAL "LXDE")

      set(LXDE_DESKTOP TRUE)
      set(GTK_BASED_DESKTOP TRUE)
      message(STATUS "System is LXDE")
      set(DESKTOP_ENVIRONMENT_NAME "lxde")

   elseif (${CURRENT_DESKTOP_ENVIRONMENT} STREQUAL "XFCE")

      set(XFCE_DESKTOP TRUE)
      set(GTK_BASED_DESKTOP TRUE)
      set(HAS_WAYLAND FALSE)
      message(STATUS "System is XFCE")
      set(DESKTOP_ENVIRONMENT_NAME "xfce")

   elseif (${CURRENT_DESKTOP_ENVIRONMENT} STREQUAL "X-Cinnamon")

      set(XCINNAMON_DESKTOP TRUE)
      set(GTK_BASED_DESKTOP TRUE)
      set(HAS_WAYLAND FALSE)
      message(STATUS "System is X-Cinnamon")
      set(DESKTOP_ENVIRONMENT_NAME "xcinnamon")

   endif ()


   if(${KDE_DESKTOP})

      include(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/_kde_desktop.cmake)

   elseif(${GTK_BASED_DESKTOP})

      include(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/_gtk_based_desktop.cmake)

   endif()


   message(STATUS "DESKTOP_ENVIRONMENT_NAME is ${DESKTOP_ENVIRONMENT_NAME}")

   # DESKTOP_AMBIENT are dependant just on linux kernel version and glib version?

   if (${__OPERATING_SYSTEM} STREQUAL "ubuntu")

      set(UBUNTU TRUE)

      set(DEBIAN_LIKE TRUE)

      add_compile_definitions(UBUNTU_LINUX)

      add_compile_definitions(DEBIAN_LIKE_LINUX)

      message(STATUS "UBUNTU has been set TRUE")

      set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

      set(MPG123_PKG_MODULE "libmpg123")

      set(HAS_SYSTEM_UNAC TRUE)

   elseif (${__OPERATING_SYSTEM} STREQUAL "debian")

      set(DEBIAN TRUE)

      add_compile_definitions(DEBIAN_LINUX)

      add_compile_definitions(DEBIAN_LIKE_LINUX)

      message(STATUS "DEBIAN has been set TRUE")

      set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

      set(MPG123_PKG_MODULE "libmpg123")

      add_compile_options("$<$<CONFIG:Debug>:-gdwarf-4>")

      set(HAS_SYSTEM_UNAC TRUE)

   elseif (${__OPERATING_SYSTEM} STREQUAL "opensuse-leap" OR ${__OPERATING_SYSTEM} STREQUAL "opensuse-tumbleweed")

      set(SUSE TRUE)

      add_compile_definitions(SUSE_LINUX)

      message(STATUS "SUSE has been set TRUE")

      set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

      set(MPG123_PKG_MODULE "libmpg123")

   elseif (${__OPERATING_SYSTEM} STREQUAL "fedora")

      set(FEDORA TRUE)

      add_compile_definitions(FEDORA_LINUX)

      set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

      message(STATUS "FEDORA has been set TRUE")

   elseif (${__OPERATING_SYSTEM} STREQUAL "linuxmint")

      set(LINUXMINT TRUE)

      add_compile_definitions(MINT_LINUX)

      set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

      message(STATUS "LINUX_MINT has been set TRUE")

      message(STATUS "MINT_LINUX compile definition")

   elseif ("${__OPERATING_SYSTEM}" STREQUAL "raspbian")

      set(RASPBIAN TRUE)

      set(DEBIAN_LIKE TRUE)

      add_compile_definitions(RASPBERRYPIOS)

      add_compile_definitions(DEBIAN_LIKE_LINUX)

      set(DONT_USE_PKG_CONFIG FALSE)

      set(HAS_SYSTEM_UNAC TRUE)

      set(HAS_WAYLAND FALSE)

      message(STATUS "RASPBERRYPIOS defined!!")

   elseif (${__OPERATING_SYSTEM} STREQUAL "manjaro")

         set(MANJARO TRUE)

         set(ARCH_LIKE TRUE)

         add_compile_definitions(ARCH_LIKE_LINUX)

         message(STATUS "MANJARO has been set TRUE")

         set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

         set(MPG123_PKG_MODULE "libmpg123")

         set(HAS_SYSTEM_UNAC FALSE)

   else ()

      set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

      set(MPG123_PKG_MODULE "mpg123")

   endif ()

   message(STATUS "DISTRO_RELEASE is ${DISTRO_RELEASE}")

endif()

set(MIDI TRUE)
set(ALSA_MIDI TRUE)
set(INTERPROCESS_COMMUNICATION_SYSTEM_5 TRUE)


add_compile_definitions(WITH_X11)
add_compile_definitions(WITH_XCB)
if(${HAS_WAYLAND})
   add_compile_definitions(HAS_WAYLAND)
endif()
link_libraries(pthread)
include(FindPkgConfig)


if (EXISTS $ENV{HOME}/__config/xfce.txt)

   set(LINUX_XFCE TRUE)
   message(STATUS "Adding Xfce/X11 dependency.")

endif ()


set(copy_libraries_dependency "")


set(default_draw2d "draw2d_cairo")
set(default_imaging "imaging_freeimage")
set(default_write_text "write_text_pango")
set(default_audio "audio_alsa")
set(default_input "input_libinput")
set(default_music_midi "music_midi_alsa")
set(default_node "node_linux")
set(default_audio_mixer "audio_mixer_alsa")
set(default_gpu "gpu_opengl")
set(default_networking "networking_bsd")
set(default_acme "acme_linux")
set(default_apex "apex_linux")
set(default_nano_graphics "nano_graphics_cairo")
#add_compile_definitions(default_draw2d=draw2d_cairo)
#add_compile_definitions(default_imaging=imaging_freeimage)
#add_compile_definitions(default_write_text=write_text_pango)
#add_compile_definitions(default_audio=audio_alsa)
#add_compile_definitions(default_music_midi=music_midi_alsa)
#add_compile_definitions(default_node=node_linux)


set(LINUX TRUE)




list(APPEND acme_libraries
   acme
   acme_posix
   acme_linux)


list(APPEND static_acme_libraries
   static_acme
   static_acme_posix
   static_acme_linux)


list(APPEND apex_libraries
   ${acme_libraries}
   apex
   apex_posix
   apex_linux
)

list(APPEND aura_libraries
   ${apex_libraries}
   aura
   aura_posix
   aura_linux
   node_linux
)

set(default_nano_graphics nano_graphics_cairo)



if(${DESKTOP_AMBIENT})


   # DESKTOP_AMBIENT are dependant just on linux kernel version and glib version?


   if (${KDE_DESKTOP})


      if(${HAS_KDE6})
         set(WITH_XCB TRUE)
         add_compile_definitions(WITH_XCB=1)



         set(KF_MIN_VERSION "6.6.0")
         set(QT_MIN_VERSION "6.6.0")

         find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)
         set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)


         #if(UNIX AND NOT APPLE)
         find_package(KF6Package REQUIRED)
         #         if (WITH_PULSEAUDIO)
         #            find_package(KF6PulseAudioQt REQUIRED)
         #         endif()
         #         find_package(QtWaylandScanner REQUIRED)
         #         find_package(Wayland 1.9 REQUIRED Client)
         #         find_package(Qt6 REQUIRED COMPONENTS WaylandClient)
         #         find_package(WaylandProtocols REQUIRED)
         #         pkg_check_modules(XkbCommon IMPORTED_TARGET xkbcommon)
         #         find_package(PkgConfig QUIET REQUIRED)
         #         pkg_check_modules(DBus REQUIRED IMPORTED_TARGET dbus-1)
         ##endif()
         # apt install libkf5notifications-dev
         # dnf install kf5-knotifications-devel

         #include(KDEInstallDirs)
         #include(KDECMakeSettings)
         #include(KDECompilerSettings NO_POLICY_SCOPE)
         #    find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
         # CoreAddons      # KAboutData
         #          I18n            # KLocalizedString
         #         WidgetsAddons   # KMessageBox
         #      Notifications
         #     )
         #include(FeatureSummary)

         # Find Qt modules
         #find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
         #  Core    # QCommandLineParser, QStringLiteral
         #  Widgets # QApplication
         #  )

         list(APPEND kf6_component_list
            CoreAddons
            Notifications
            ConfigWidgets
            KIO
            IconThemes
            StatusNotifierItem
            #Plasma
         )

         if(NOT ${DEBIAN} AND NOT ${SUSE} AND NOT ${DEBIAN_LIKE})
            list(APPEND kf6_component_list
               PlasmaQuick

            )

         endif()


         find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
            # CoreAddons      # KAboutData
            #          I18n            # KLocalizedString
            #         WidgetsAddons   # KMessageBox
            ${kf6_component_list}
         )

         find_package(LibKWorkspace CONFIG REQUIRED)

         find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS
            Core
            DBus
            UiTools
            #X11Extras
            Gui
         )

         find_package(Qt6Gui ${QT_MIN_VERSION} CONFIG REQUIRED Private)

         # Find KDE modules

         #feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
         #        find_package(KDE5 REQUIRED)
         message(STATUS "Adding KDE/xcb dependency.")
         #        file (STRINGS $ENV{HOME}/__config/knotifications/cflags.txt knotifications_cflags)
         #        file (STRINGS $ENV{HOME}/__config/knotifications/libs.txt knotifications_libs)
         #        if(knotifications_cflags STREQUAL "")
         #            set(knotifications_cflags -I/usr/include/KF5/KNotifications)
         #        endif()
         #        if(knotifications_libs STREQUAL "")
         #            set(knotifications_cflags -I/usr/include/KF5/KNotifications)
         #        endif()

      elseif(${HAS_KDE5})

         set(WITH_XCB TRUE)
         add_compile_definitions(WITH_XCB=1)



         set(QT_MIN_VERSION "5.3.0")
         set(KF5_MIN_VERSION "5.2.0")

         # apt install extra-cmake-modules
         # dnf install extra-cmake-modules
         find_package(ECM 1.0.0 REQUIRED NO_MODULE)
         set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

         # apt install libkf5notifications-dev
         # dnf install kf5-knotifications-devel

         #include(KDEInstallDirs)
         #include(KDECMakeSettings)
         #include(KDECompilerSettings NO_POLICY_SCOPE)
         #    find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
         # CoreAddons      # KAboutData
         #          I18n            # KLocalizedString
         #         WidgetsAddons   # KMessageBox
         #      Notifications
         #     )
         #include(FeatureSummary)

         # Find Qt modules
         #find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
         #  Core    # QCommandLineParser, QStringLiteral
         #  Widgets # QApplication
         #  )

         list(APPEND kf5_component_list
            CoreAddons
            Notifications
            ConfigWidgets
            KIO
            IconThemes
            Plasma
         )

         if(NOT ${DEBIAN})
            list(APPEND kf5_component_list
               PlasmaQuick

            )

         endif()


         find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
            # CoreAddons      # KAboutData
            #          I18n            # KLocalizedString
            #         WidgetsAddons   # KMessageBox
            ${kf5_component_list}
         )

         find_package(LibKWorkspace CONFIG REQUIRED)

         find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS
            Core
            DBus
            UiTools
            X11Extras
            Gui
         )

         find_package(Qt5Gui ${QT_MIN_VERSION} CONFIG REQUIRED Private)

         # Find KDE modules

         #feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
         #        find_package(KDE5 REQUIRED)
         message(STATUS "Adding KDE/xcb dependency.")
         #        file (STRINGS $ENV{HOME}/__config/knotifications/cflags.txt knotifications_cflags)
         #        file (STRINGS $ENV{HOME}/__config/knotifications/libs.txt knotifications_libs)
         #        if(knotifications_cflags STREQUAL "")
         #            set(knotifications_cflags -I/usr/include/KF5/KNotifications)
         #        endif()
         #        if(knotifications_libs STREQUAL "")
         #            set(knotifications_cflags -I/usr/include/KF5/KNotifications)
         #        endif()
         #list(APPEND app_common_dependencies nano_graphics_cairo nano_user_kde5)
      endif()


      #    list(APPEND static_app_common_dependencies
      #            static_desktop_environment_kde
      #            static_node_kde
      #            static_windowing_xcb
      #            KF5::Notifications
      #            KF5::ConfigWidgets
      #            KF5::IconThemes
      #            KF5::KIOCore
      #            KF5::KIOFileWidgets
      #            KF5::KIOWidgets
      #            KF5::KIONTLM
      #            PW::KWorkspace
      #            )


      if(${HAS_KDE5})

      set(default_operating_ambient operating_ambient_kde5)
      list(APPEND app_common_dependencies operating_ambient_kde5)
      add_compile_definitions(DESKTOP_ENVIRONMENT_KDE=5)
      add_compile_definitions(default_windowing=windowing_kde5)
      set(default_windowing "windowing_kde5")
      elseif(${HAS_KDE6})

      set(default_operating_ambient operating_ambient_kde6)
      list(APPEND app_common_dependencies operating_ambient_kde6)
      add_compile_definitions(DESKTOP_ENVIRONMENT_KDE=6)
      add_compile_definitions(default_windowing=windowing_kde6)
      set(default_windowing "windowing_kde6")
      endif()





   elseif (${LXDE_DESKTOP})

      message(STATUS "LXDE Desktop (2)")

      #list(APPEND app_common_dependencies operating_ambient_gtk_based)

      list(APPEND app_common_dependencies operating_ambient_gtk3)

      list(APPEND static_app_common_dependencies static_operating_ambient_gtk3)

      #    list(APPEND static_app_common_dependencies
      #            static_desktop_environment_gnome
      #            static_node_gnome
      #            static_node_gtk
      #            static_windowing_x11)

      #set(default_windowing "windowing_x11")

      set(default_windowing "windowing_gtk3")

      #set(default_operating_ambient operating_ambient_gtk_based)

      set(default_operating_ambient operating_ambient_gtk3)

      #add_compile_definitions(DESKTOP_ENVIRONMENT_GTK_BASED)

      add_compile_definitions(DESKTOP_ENVIRONMENT_LXDE)

      #add_compile_definitions(default_windowing=windowing_x11)

      add_compile_definitions(default_windowing=windowing_gtk3)

   elseif (${XFCE_DESKTOP})

      list(APPEND app_common_dependencies operating_ambient_gtk3)

      list(APPEND static_app_common_dependencies static_operating_ambient_gtk3)

      set(default_windowing "windowing_gtk3")

      set(default_operating_ambient operating_ambient_gtk3)

      add_compile_definitions(DESKTOP_ENVIRONMENT_XFCE)

      add_compile_definitions(default_windowing=windowing_gtk3)

   elseif (${GTK_BASED_DESKTOP})


      list(APPEND static_app_common_dependencies
         static_operating_ambient_gtk4
         static_node_gnome
         static_node_gtk
         static_node_linux)

      set(default_common_windowing common_gtk)

      if(${HAS_GTK4})

         message(STATUS "Setting up GTK4 dependencies.")

         set(default_acme_windowing acme_windowing_gtk4)

         set(default_innate_ui innate_ui_gtk4)

         set(default_windowing_common windowing_posix)

         set(default_windowing windowing_gtk4)

         set(default_operating_ambient operating_ambient_gtk4)

         set(default_node node_gtk4)

      elseif (${HAS_GTK3})

         message(STATUS "Setting up GTK3 dependencies.")

         set(default_acme_windowing acme_windowing_gtk3)

         set(default_innate_ui innate_ui_gtk3)

         set(default_windowing_common windowing_posix)

         set(default_windowing windowing_gtk3)

         set(default_operating_ambient operating_ambient_gtk3)

         set(default_node node_gtk3)


      else()

         message(STATUS "Adding GNOME/X11 dependency.")

         list(APPEND app_common_dependencies nano_graphics_cairo operating_ambient_gtk_based)

         list(APPEND static_app_common_dependencies
            static_desktop_environment_gnome
            static_node_gnome
            static_node_gtk
            static_node_linux
            static_windowing_x11)

         set(default_windowing "windowing_x11")

         set(default_operating_ambient operating_ambient_gtk_based)

         add_compile_definitions(DESKTOP_ENVIRONMENT_GTK_BASED)

      endif()

      add_compile_definitions(DESKTOP_ENVIRONMENT_GNOME)

   endif()


   list(APPEND acme_windowing_libraries
      ${default_nano_graphics}
      ${default_acme_windowing}
   )


   list(APPEND innate_ui_libraries
      ${acme_windowing_libraries}
      ${default_innate_ui}
   )


   list(APPEND operating_ambient_libraries
      ${innate_ui_libraries}
      ${default_common_windowing}
      ${default_windowing_common}
      ${default_windowing}
      ${default_node}
      ${default_operating_ambient}
   )


   list(APPEND app_common_dependencies
      ${aura_libraries}
      ${operating_ambient_libraries}
   )


endif()


   #set(static_acme_extra_pkgconfig cairo xcb x11 xkbcommon xcb-render xcb-aux x11-xcb)
#set(static_aura_posix_pkgconfig libstartup-notification-1.0)
#
#set(static_acme_pkgconfig freetype2 libidn ${static_acme_extra_pkgconfig} ncurses dbus-glib-1)
#set(static_apex_pkgconfig libcrypto libssl libarchive)
#set(static_database_cairo_pkgconfig freetype2 pango cairo pangocairo)
#set(static_database_sqlite3_pkgconfig sqlite3)
#set(static_mpg123_pkgconfig ${MPG123_PKG_MODULE})
#set(static_desktop_environment_gnome_pkgconfig glib-2.0 gtk+-3.0 gdk-3.0 ${APPINDICATOR_PKG_MODULE})
#set(static_desktop_environment_kde_pkgconfig Qt5X11Extras Qt5Core Qt5UiTools)

#if (KDE_DESKTOP)
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_kde_pkgconfig})
#elseif (GTK_BASED_DESKTOP)
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_gnome_pkgconfig})
#else ()
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_gnome_pkgconfig})
#endif()
#




set(LIBCXX_TARGETING_MSVC OFF)


add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

list(APPEND app_common_dependencies ${default_node})

#list(APPEND app_common_dependencies _console_application_build_helper)


#set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)


link_directories(${LIBRARY_OUTPUT_PATH})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis)


include_directories(${WORKSPACE_FOLDER})
include_directories($ENV{HOME}/__config)
include_directories(${WORKSPACE_FOLDER}/source)
include_directories(${WORKSPACE_FOLDER}/source/app)
include_directories(${WORKSPACE_FOLDER}/source/app/include)
include_directories(${WORKSPACE_FOLDER}/source/include)
include_directories(${WORKSPACE_FOLDER}/port/_)
if (NOT ${HAS_SYSTEM_UNAC})
   include_directories(${WORKSPACE_FOLDER}/port/base/unac/include)
endif ()
include_directories(${WORKSPACE_FOLDER}/port/include)
include_directories(${WORKSPACE_FOLDER}/operating_system)
if (OPERATING_SYSTEM_POSIX)
   include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix)
   include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/include)
endif ()
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include)
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include/configuration_selection/${CMAKE_BUILD_TYPE})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${SLASHED_OPERATING_SYSTEM})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${DISTRO})

set(INCLUDE_DRAW2D_CAIRO TRUE)
set(INCLUDE_IMAGING_FREEIMAGE TRUE)


set(STORE_FOLDER $ENV{HOME}/store/${SLASHED_OPERATING_SYSTEM})





if(${HAS_GTK4})
message(STATUS "HAS_GTK4 is true, deactivating APPINDICATOR_PKG_MODULE")
set(APPINDICATOR_PKG_MODULE "")
endif()




add_compile_definitions(HAS_GTK3)


if(${HAS_GTK4})

   unset(HAS_GTK3)
   message(STATUS "HAS_GTK4 is TRUE")
   add_compile_definitions(HAS_GTK4)
   set(default_acme_windowing acme_windowing_gtk4)
   set(default_innate_ui innate_ui_gtk4)

endif()


if(${HAS_GTK3})

   unset(HAS_GTK4)
   message(STATUS "HAS_GTK3 is TRUE")
   add_compile_definitions(HAS_GTK3)
   set(default_acme_windowing acme_windowing_gtk3)
   set(default_innate_ui innate_ui_gtk3)

endif()



if(${HAS_KDE5})

   message(STATUS "HAS_KDE5 had been set")
   add_compile_definitions(HAS_KDE5)
   set(default_acme_windowing acme_windowing_kde5)
   set(default_innate_ui innate_ui_kde5)

   message(STATUS "HAS_KDE5 is true, deactivating APPINDICATOR_PKG_MODULE")
   set(APPINDICATOR_PKG_MODULE "")

endif()



if(${HAS_KDE6})

   message(STATUS "HAS_KDE6 had been set")
   add_compile_definitions(HAS_KDE6)
   set(default_acme_windowing acme_windowing_kde6)
   set(default_innate_ui innate_ui_kde6)

   message(STATUS "HAS_KDE6 is true, deactivating APPINDICATOR_PKG_MODULE")
   set(APPINDICATOR_PKG_MODULE "")


endif()



