//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"


//void x11_kick_idle();
//
//void gtk_settings_gtk_theme_name_callback(GObject* object, GParamSpec* pspec, gpointer data)
//{
//
//   node_kde::node * pnode = (node_kde::node *) data;
//
//   if(pnode)
//   {
//
//      gchar *theme_name = nullptr;
//
//      g_object_get(pnode->m_pGtkSettingsDefault, "gtk-theme-name", &theme_name, NULL);
//
//      pnode->m_strTheme = theme_name;
//
//      g_free(theme_name);
//
//   }
//
//   System.process_subject(id_os_user_theme);
//
//}


//const char * linux_g_direct_get_file_icon_path(const char * pszPath, int iSize);
//
//
//const char * linux_g_direct_get_file_content_type(const char * pszPath);
//
//
//void aaa_x11_add_idle_source();
//
//
//void x11_add_filter();
//

//void x11_main();
//
//
//::particle * user_synchronization();


//gboolean node_gnome_source_func(gpointer pUserdata);


//namespace node_kde{
//
//   class appindicator;
//
//   void appindicator_destroy(appindicator * pindicator);
//
//} // namespace node_kde
//
//
//
//void os_post_quit();
//
//void apex_application_run(const char * pszAppName, const char * pszProgName);

namespace desktop_environment_kde
{


   CLASS_DECL_ACME void _os_process_user_theme(string strTheme);


   node::node()
   {

      m_pNodeDesktopEnvironmentKDE = this;

      m_qpalette = QApplication::palette();

   }


   node::~node()
   {

//      if (m_pGtkSettingsDefault)
//      {
//
//         g_object_unref(m_pGtkSettingsDefault);
//
//      }

//      if(m_pnodeimpl)
//      {
//
//         del_node_impl(m_pnodeimpl);
//
//         m_pnodeimpl = nullptr;
//
//      }

   }


   int node::node_init_check(int *pi, char ***ppz)
   {

#if defined(HAS_KDE6)
      auto iResult = ::node_kde6::node::node_init_check(pi, ppz);
#elif defined(HAS_KDE5)
      auto iResult = ::node_kde5::node::node_init_check(pi, ppz);
#endif

//      m_pnodeimpl = new_node_impl(*pi, *ppz);
//
//      if(!m_pnodeimpl)
//      {
//
//         return 0;
//
//      }

      return iResult;

   }


//   ::os_theme_colors * node::new_os_theme_colors()
//   {
//
//      auto pthemecolors = m_pnodeimpl->new_os_theme_colors();
//
//      return pthemecolors;
//
//   }


//   bool node::_os_calc_app_dark_mode()
//   {
//
//      auto pthemecolors = ::user::os_get_theme_colors();
//
//      if(!pthemecolors)
//      {
//
//         pthemecolors = new_os_theme_colors();
//
//         ::user::os_set_theme_colors(pthemecolors);
//
//      }
//
//      ::color::color colorBack(pthemecolors->m_colorBack);
//
//      auto dLuminance = colorBack.get_luminance();
//
//      return dLuminance < 0.5;
//
//   }


//
//   void node::on_os_dark_mode_change()
//   {
//
//      //x11_kick_idle();
//
//   }


   void node::system_main()
   {

#if defined(HAS_KDE6)
      ::node_kde6::node::system_main();
#elif defined(HAS_KDE5)
      ::node_kde5::node::system_main();
#endif

   }


   void node::initialize(::particle * pparticle)
   {

      information() << "desktop_environment_kde::node initialize";

#if defined(HAS_KDE6)
      ::node_kde6::node::initialize(pparticle);
#elif defined(HAS_KDE5)
      ::node_kde5::node::initialize(pparticle);
#endif

   }


   void node::reboot()
   {

#if defined(HAS_KDE6)
      ::node_kde6::node::reboot();
#elif defined(HAS_KDE5)
      ::node_kde5::node::reboot();
#endif
   }

//
//   string node::os_get_user_theme()
//   {
//
//      return m_strTheme;
//
//   }
//
//
//
//
//   bool node::os_set_user_theme(const ::scoped_string & scopedstrUserTheme)
//   {
//
//      // https://ubuntuforums.org/showthread.php?t=2140488
//      // gsettings set org.gnome.desktop.interface gtk-theme your_theme
//
//      // indirect wall-changer sourceforge.net contribution
//
//      auto edesktop = System->get_edesktop();
//
//      switch (edesktop)
//      {
//
//         case ::user::e_operating_ambient_gnome:
//         case ::user::e_operating_ambient_ubuntu_gnome:
//         case ::user::e_operating_ambient_unity_gnome:
//         {
//
//            bool bOk1 = ::node_kde::aaa_gsettings_set("org.gnome.desktop.interface", "gtk-theme", strUserTheme);
//
//            bool bOk2 = true;
//
//            //if(::file::system_short_name().case_insensitive_contains("manjaro"))
//            {
//
//               bOk2 = ::node_kde::aaa_gsettings_set("org.gnome.desktop.wm.preferences", "theme", strUserTheme);
//
//            }
//
//            sleep(300_ms);
//
//            ::node_kde::gsettings_sync();
//
//            sleep(300_ms);
//
//            return
//               bOk1 && bOk2;
//
//         }
//
//         case ::user::e_operating_ambient_mate:
//
//            //return ::user::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//         case ::user::e_operating_ambient_lxde:
//
//            //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//            break;
//
//         case ::user::e_operating_ambient_xfce:
//         {
//            //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
//            //          if(entry.contains("image-path") || entry.contains("last-image")){
//            //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
//            //      }
//            //}
//
//         }
//
//            //break;
//
//         default:
//
//            information(
//               "Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//            return false;
//
//      }
//
//      return true;
//
//   }


//   void node::os_process_user_theme(string strTheme)
//   {
//
//      _os_process_user_theme(strTheme);
//
//   }
//
//
//   bool node::set_wallpaper(::collection::index iScreen, string strLocalImagePath)
//   {
//
//      // wall-changer sourceforge.net contribution
//
//      auto pnode = Node;
//
//      auto edesktop = System->get_edesktop();
//
//      switch (edesktop)
//      {
//
//         case ::user::e_operating_ambient_gnome:
//         case ::user::e_operating_ambient_ubuntu_gnome:
//         case ::user::e_operating_ambient_unity_gnome:
//
//            return ::node_kde::aaa_gsettings_set("org.gnome.desktop.background", "picture-uri",
//                                               "file://" + strLocalImagePath);
//
//         case ::user::e_operating_ambient_mate:
//
//            return ::node_kde::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//         case ::user::e_operating_ambient_lxde:
//
//            call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//            break;
//
//         case ::user::e_operating_ambient_xfce:
//         {
//            //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
//            //          if(entry.contains("image-path") || entry.contains("last-image")){
//            //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
//            //      }
//            //}
//
//         }
//
//            //break;
//
//         default:
//
//            information(
//               "Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//            return false;
//
//      }
//
//      return true;
//
//   }

//
//   void node::enable_wallpaper_change_notification()
//   {
//
//      auto edesktop = System->get_edesktop();
//
//      switch (edesktop)
//      {
//
//         case ::user::e_operating_ambient_gnome:
//         case ::user::e_operating_ambient_ubuntu_gnome:
//         case ::user::e_operating_ambient_unity_gnome:
//
//            ::node_kde::g_enable_wallpaper_change_notification("org.gnome.desktop.background", "picture-uri");
//
//            break;
//
//         case ::user::e_operating_ambient_mate:
//
//            ::node_kde::g_enable_wallpaper_change_notification("org.mate.background", "picture-filename");
//
//            break;
//
//         case ::user::e_operating_ambient_lxde:
//
//            //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//            break;
//
//         case ::user::e_operating_ambient_xfce:
//         {
//            //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
//            //          if(entry.contains("image-path") || entry.contains("last-image")){
//            //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
//            //      }
//            //}
//
//         }
//
//            break;
//         default:
//
//            information(
//               "Failed to get wallpaper setting. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//            //return "";
//
//      }
//
//   }

//
//   string node::get_file_icon_path(const char *pszPath, int iSize)
//   {
//
//      return ::linux_g_direct_get_file_icon_path(scopedstrPath, iSize);
//
//   }


//   string node::get_file_content_type(const char *pszPath)
//   {
//
//      return ::linux_g_direct_get_file_content_type(scopedstrPath);
//
//   }
//

//   string node::get_wallpaper(::collection::index iScreen)
//   {
//
//      return "";
//
//   }


//   void node::node_fork(const ::procedure &routine)
//   {
//
//      kde_branch(routine);
//
//   }


//   void node::node_post_quit()
//   {
//
//      os_post_quit();
//
//   }
//

//   ::node_linux::appindicator *node::appindicator_allocate()
//   {
//
//      return ___new ::node_kde::appindicator();
//
//   }
//
//
//   void node::appindicator_destroy(::linux::appindicator *pappindicator)
//   {
//
//      //::linux::appindicator_destroy(pappindicator);
//
//      delete pappindicator;
//
//   }

//
//   void node::enum_display_monitors(::aura::session *psession)
//   {
//
//      node_fork(__routine([psession]
//                          {
//
//                             synchronous_lock sl(user_synchronization());
//
//                             xdisplay d(x11_get_display());
//
//                             GdkDisplay *pdisplay = gdk_display_get_default();
//
//                             if (pdisplay == nullptr)
//                             {
//
//                                return;
//
//                             }
//
//                             synchronous_lock slSession(psession->synchronization());
//
//                             ::collection::count iMonitorCount = gdk_display_get_n_monitors(pdisplay);
//
//                             psession->m_rectaWorkspace.set_size(iMonitorCount);
//
//                             psession->m_rectaMonitor.set_size(iMonitorCount);
//
//                             for (::collection::index iMonitor = 0; iMonitor < iMonitorCount; iMonitor++)
//                             {
//
//                                GdkMonitor *pmonitor = gdk_display_get_monitor(pdisplay, iMonitor);
//
//                                auto &rectWorkspace = psession->m_rectaWorkspace[iMonitor];
//
//                                auto &rectMonitor = psession->m_rectaMonitor[iMonitor];
//
//                                if (pmonitor == nullptr)
//                                {
//
//                                   rectWorkspace.Null();
//
//                                   rectMonitor.Null();
//
//                                   continue;
//
//                                }
//
//                                GdkRectangle rect;
//
//                                zero(rect);
//
//                                gdk_monitor_get_workarea(pmonitor, &rect);
//
//                                __copy(rectWorkspace, rect);
//
//                                zero(rect);
//
//                                gdk_monitor_get_geometry(pmonitor, &rect);
//
//                                __copy(rectMonitor, rect);
//
//                             }
//
//                          }));
//
//   }


//   void node::os_post_quit()
//   {
//
//   }


//   void * node::node_wrap_window(void * pvoidDisplay, long long window)
//   {
//
//      Display * pdisplay = (Display *) pvoidDisplay;
//
//      GdkDisplay * pd = gdk_x11_lookup_xdisplay (pdisplay);
//
//      auto pwindow = gdk_x11_window_foreign_new_for_display(GDK_DISPLAY(pd), (Window) window);
//
//      return pwindow;
//
//   }

//   bool node::should_launch_on_node(::subject::subject *psubject)
//   {
//
//      if (::is_null(psubject))
//      {
//
//         return false;
//
//      }
//
//      if (ptopic->id() == id_os_dark_mode)
//      {
//
//         return false;
//
//      }
//
//      return false;
//
//   }

//
//   bool node::launch_on_node(::subject::subject *psubject)
//   {
//
//      ::matter *pmatter = psubject;
//
////      node_fork([pmatter]()
////                {
////
////                   auto ret = g_timeout_add(300, (GSourceFunc) &node_gnome_source_func, pmatter);
////
////                   printf("ret %d", ret);
////
////                   printf("ret %d", ret);
////
//////      g_idle_add(&node_gnome_source_func, pmatter);
////
////                });
//
//   }
//
//

//   os_theme_colors * node::new_os_theme_colors()
//   {
//
//      auto pthemecolors = ::new_os_theme_colors();
//
//      pthemecolors->m_colorBack.color32 = m_qpalette.color(QPalette::Window).rgba();
//      pthemecolors->m_colorFore.color32 = m_qpalette.color(QPalette::WindowText).rgba();
//      pthemecolors->m_colorFace.color32 = m_qpalette.color(QPalette::Button).rgba();
//
//      return pthemecolors;
//
//   }
//
//
//   bool node::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
//   {
//
//      if(eventType == "xcb_generic_event_t")
//      {
//
//         xcb_generic_event_t * pevent = (xcb_generic_event_t *) message;
//
//         if(xcb_on_event(pevent))
//         {
//
//            return true;
//
//         }
//
//      }
//
//      return false;
//
//   }
//
//
//   void node::exec()
//   {
//
//
//      m_qapplication.installNativeEventFilter(this);
//
//
//      m_qapplication.exec();
//
//
//   }


} // namespace desktop_environment_kde


