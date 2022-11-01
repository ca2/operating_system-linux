//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"
#include "acme/constant/id.h"
#include "acme/platform/system.h"
#include "apex/platform/system.h"
#include "aura/platform/session.h"
#include "aura/user/user/user.h"
#include "aura/windowing/windowing.h"
#include "windowing_x11/windowing_x11.h"


void gdk_branch(const ::procedure & procedure);
CLASS_DECL_ACME void set_main_user_itask(itask_t itask);

namespace desktop_environment_gnome
{


   CLASS_DECL_ACME void _os_process_user_theme_color(string strTheme);


   node::node()
   {

      m_pNodeDesktopEnvironmentGnome = this;

      defer_initialize_x11();

      m_pGtkSettingsDefault = nullptr;

   }


   node::~node()
   {

      if(m_pGtkSettingsDefault)
      {

         g_object_unref(m_pGtkSettingsDefault);

      }

   }


   int node::node_init_check(int *pi, char ***ppz)
   {

      auto iResult = gtk_init_check(pi, ppz);

      return iResult;

   }


   void node::defer_notify_startup_complete()
   {

      auto psystem = acmesystem()->m_papexsystem;

      string strApplicationServerName = psystem->get_application_server_name();

      gdk_notify_startup_complete_with_id (strApplicationServerName);

      gdk_notify_startup_complete();

   }


   void node::start_node()
   {

      //auto estatus =
      //
      node_gnome::node::start_node();

      //return estatus;

//      auto psystem = acmesystem()->m_papexsystem;
//
//      if (psystem->m_bGtkApp)
//      {
//
//         apex_application_run(psystem->m_XstrAppId, psystem->m_strProgName);
//
//      }
//      else
//      {
//
//         //g_set_application_name(System.m_XstrAppId);
//
//         //g_set_prgname(System.m_strProgName);
//      ////
//      ////      //auto idle_source = g_idle_source_new();
//      ////
//      ////      //g_source_set_callback(idle_source, &linux_start_system, (::apex::system *) acmesystem(), nullptr);
//      ////
//      ////      //g_source_attach(idle_source, g_main_context_default());
//      ////
//      ////      //int c = 2;
//      ////
//      ////      //const char * argv[]={"app", "--g-fatal-warnings"};
//      ////
//      ////#if !defined(__SANITIZE_ADDRESS__)
//      ////
//      ////      gtk_init_check(&psystem->m_argc, &psystem->m_argv);
//      ////
//      ////#endif
//
//            node_fork([this]()
//            {
//
//             // This seems not to work with "foreign" windows
//             // (X11 windows not created with Gdk)
//             //x11_add_filter();
//
//
//             auto pgtksettingsDefault = gtk_settings_get_default();
//
//             if(pgtksettingsDefault)
//             {
//
//
//                m_pGtkSettingsDefault = G_OBJECT(pgtksettingsDefault);
//
//                g_object_ref (m_pGtkSettingsDefault);
//
//                gchar *theme_name = nullptr;
//
//                g_object_get(m_pGtkSettingsDefault, "gtk-theme-name", &theme_name, NULL);
//
//                m_strTheme = theme_name;
//
//                g_free(theme_name);
//
//                auto preturn = g_signal_connect_data(
//                   m_pGtkSettingsDefault,
//                   "notify::gtk-theme-name",
//                   G_CALLBACK(gtk_settings_gtk_theme_name_callback),
//                   this,
//                   NULL,
//                   G_CONNECT_AFTER);
//
//                //g_object_ref(preturn);
//
//                //printf("return %" PRIiPTR, preturn);
//
//                //printf("return %" PRIiPTR, preturn);
//
//             }
//
//            x11_add_idle_source(this);
//
//             auto psystem = acmesystem()->m_papexsystem;
//
//               psystem->on_start_system();
//
//
//         });
//
//
//         //x11_add_filter();
////
////         System.fork([this]()
////         {
////
////            //m_pwindowing->windowing_main();
////
////         });
//
//         //x11_add_idle_source(this);
//
//         //x11_add_idle_source(this);
//
//         gtk_main();
//
//         //x11_main();
//
//      }
//      //
//      //::parallelization::post_quit_and_wait(get_context_system(), one_minute());
//
//      return ::success;

   }


   void node::initialize(::particle * pparticle)
   {

      //::node_gnome::g_defer_init();

      //auto estatus =
      //
      ::aura_linux::node::initialize(pparticle);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }

      //estatus =
      //
      ::node_gnome::node::initialize(pparticle);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;

   }


   bool node::windowing_message_loop_step()
   {

      set_main_user_itask(get_current_itask());

      //if(get_main_user_itask() != get_current_itask())
      //{



      //}

      auto psession = get_session();

      if(::is_null(psession))
      {

         return false;

      }

      auto paurasession = psession->m_paurasession;

      if(::is_null(paurasession))
      {

         return false;

      }

      auto puser = paurasession->user();

      if(::is_null(puser))
      {

         return false;

      }

      auto pwindowing = puser->windowing1();

      if(::is_null(pwindowing))
      {

         return false;

      }

      bool bRet = pwindowing->message_loop_step();

      return bRet;

   }


//   string node::os_get_user_theme()
//   {
//
//      return m_strTheme;
//
//   }
//
//
//   bool node::os_set_user_theme(const ::string &strUserTheme)
//   {
//
//      // https://ubuntuforums.org/showthread.php?t=2140488
//      // gsettings set org.gnome.desktop.interface gtk-theme your_theme
//
//      // indirect wall-changer sourceforge.net contribution
//
//      auto psystem = acmesystem()->m_papexsystem;
//
//      auto pnode = psystem->node();
//
//      auto edesktop = pnode->get_edesktop();
//
//      switch (edesktop)
//      {
//
//      case ::user::e_desktop_gnome:
//      case ::user::e_desktop_ubuntu_gnome:
//      case ::user::e_desktop_unity_gnome:
//      {
//
//      bool bOk1 = ::node_gnome::aaa_gsettings_set("org.gnome.desktop.interface", "gtk-theme", strUserTheme);
//
//      bool bOk2 = true;
//
//      //if(::file::system_short_name().contains_ci("manjaro"))
//      {
//
//         bOk2 = ::node_gnome::aaa_gsettings_set("org.gnome.desktop.wm.preferences", "theme", strUserTheme);
//
//      }
//
//      sleep(300_ms);
//
//      ::node_gnome::gsettings_sync();
//
//      sleep(300_ms);
//
//      return
//      bOk1 &&bOk2;
//
//      }
//
//      case ::user::e_desktop_mate:
//
//      //return ::user::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//      case ::user::e_desktop_lxde:
//
//      //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//      break;
//
//      case ::user::e_desktop_xfce:
//      {
//      //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
//      //          if(entry.contains("image-path") || entry.contains("last-image")){
//      //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
//      //      }
//      //}
//
//      }
//
//      //break;
//
//      default:
//
//      output_debug_string("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//      return false;
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


//   bool node::set_wallpaper(index iScreen, string strLocalImagePath)
//   {
//
//      // wall-changer sourceforge.net contribution
//
//      auto psystem = acmesystem()->m_papexsystem;
//
//      auto pnode =  psystem->node();
//
//      auto edesktop = pnode->get_edesktop();
//
//      switch (edesktop)
//      {
//
//         case ::user::e_desktop_gnome:
//         case ::user::e_desktop_ubuntu_gnome:
//         case ::user::e_desktop_unity_gnome:
//
//            return ::node_gnome::aaa_gsettings_set("org.gnome.desktop.background", "picture-uri", "file://" + strLocalImagePath);
//
//         case ::user::e_desktop_mate:
//
//            return ::node_gnome::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//         case ::user::e_desktop_lxde:
//
//            call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//            break;
//
//         case ::user::e_desktop_xfce:
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
//            output_debug_string("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//            return false;
//
//      }
//
//      return true;
//
//   }
//
//
//
//
//   string node::get_file_icon_path(const ::string & strPath, int iSize)
//   {
//
//      string str = ::node_gnome::node::get_file_icon_path(strPath, iSize);
//
//      return str;
//
//      //return ::linux_g_direct_get_file_icon_path(pszPath, iSize);
//
//   }
//
//
//   string node::get_file_content_type(const ::string & strPath)
//   {
//
//      string str = ::node_gnome::node::get_file_content_type(strPath);
//
//      return str;
//
//   }
//
//
//   string node::get_wallpaper(index iScreen)
//   {
//
//      return "";
//
//   }


   void node::handle(::topic * ptopic, ::context * pcontext)
   {

      if(ptopic->m_atom == ::id_operating_system_user_theme_change)
      {

         _os_process_user_theme_color(m_strTheme);

      }

      ::node_gnome::node::handle(ptopic, pcontext);

   }


   bool node::should_launch_on_node(::topic * ptopic)
   {

      if(::is_null(ptopic))
      {

         return false;

      }

      if(ptopic->m_atom == id_operating_system_user_color_change)
      {

         return false;

      }

      return false;

   }


   bool node::launch_on_node(::topic * ptopic)
   {

      auto bOk = ::node_gnome::node::launch_on_node(ptopic);

      return bOk;

   }


} // namespace desktop_environment_gnome



