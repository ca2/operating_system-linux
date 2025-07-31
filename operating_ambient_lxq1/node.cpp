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
//CLASS_DECL_ACME void set_main_user_itask(itask itask);


namespace operating_ambient_lxq1
{


   //CLASS_DECL_ACME void _os_process_user_theme_color(string strTheme);


   node::node()
   {

      //m_pNodeDesktopEnvironmentGtkBased = this;

//      defer_initialize_x11();

      ///m_pGtkSettingsDeposthemecolorsfault = nullptr;

   }


   node::~node()
   {

//      if(m_pGtkSettingsDefault)
//      {
//
//         g_object_unref(m_pGtkSettingsDefault);
//
//      }

   }



//   void node::start_node()
//   {
//
//      node_gnome::node::start_node();
//
//   }


   void node::initialize(::particle * pparticle)
   {

      ::aura_linux::node::initialize(pparticle);

      ::node_lxq1::node::initialize(pparticle);

   }


//   bool node::aaa_windowing_message_loop_step()
//   {
//
//      set_main_user_itask(current_itask());
//
//      //if(main_user_itask() != current_itask())
//      //{
//
//
//
//      //}
//
//      auto psession = session();
//
//      if(::is_null(psession))
//      {
//
//         return false;
//
//      }
//
//      auto paurasession = psession;
//
//      if(::is_null(paurasession))
//      {
//
//         return false;
//
//      }
//
//      auto puser = paurasession->user();
//
//      if(::is_null(puser))
//      {
//
//         return false;
//
//      }
//
//      auto pwindowing = system()->windowing();
//
//      if(::is_null(pwindowing))
//      {
//
//         return false;
//
//      }
//
//      bool bRet = pwindowing->aaa_message_loop_step();
//
//      return bRet;
//
//   }


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
//      auto psystem = system();
//
//      auto pnode = psystem->node();
//
//      auto edesktop = pnode->get_edesktop();
//
//      switch (edesktop)
//      {
//
//      case ::user::e_operating_ambient_gnome:
//      case ::user::e_operating_ambient_ubuntu_gnome:
//      case ::user::e_operating_ambient_unity_gnome:
//      {
//
//      bool bOk1 = ::node_gnome::aaa_gsettings_set("org.gnome.desktop.interface", "gtk-theme", strUserTheme);
//
//      bool bOk2 = true;
//
//      //if(::file::system_short_name().case_insensitive_contains("manjaro"))
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
//      case ::user::e_operating_ambient_mate:
//
//      //return ::user::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//      case ::user::e_operating_ambient_lxde:
//
//      //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//      break;
//
//      case ::user::e_operating_ambient_xfce:
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
//      informationf("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
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


//   bool node::set_wallpaper(::collection::index iScreen, string strLocalImagePath)
//   {
//
//      // wall-changer sourceforge.net contribution
//
//      auto psystem = system();
//
//      auto pnode =  psystem->node();
//
//      auto edesktop = pnode->get_edesktop();
//
//      switch (edesktop)
//      {
//
//         case ::user::e_operating_ambient_gnome:
//         case ::user::e_operating_ambient_ubuntu_gnome:
//         case ::user::e_operating_ambient_unity_gnome:
//
//            return ::node_gnome::aaa_gsettings_set("org.gnome.desktop.background", "picture-uri", "file://" + strLocalImagePath);
//
//         case ::user::e_operating_ambient_mate:
//
//            return ::node_gnome::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
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
//            informationf("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
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
//   string node::get_file_icon_path(const ::scoped_string & scopedstrPath, int iSize)
//   {
//
//      string str = ::node_gnome::node::get_file_icon_path(strPath, iSize);
//
//      return str;
//
//      //return ::linux_g_direct_get_file_icon_path(scopedstrPath, iSize);
//
//   }
//
//
//   string node::get_file_content_type(const ::scoped_string & scopedstrPath)
//   {
//
//      string str = ::node_gnome::node::get_file_content_type(strPath);
//
//      return str;
//
//   }
//
//
//   string node::get_wallpaper(::collection::index iScreen)
//   {
//
//      return "";
//
//   }


//   void node::handle(::topic * ptopic, ::handler_context * phandlercontext)
//   {
//
////      if(ptopic->id() == ::id_operating_system_user_theme_change)
////      {
////
////         //_os_process_user_theme_color(m_strTheme);
////
////      }
//
//      ::node_gnome::node::handle(ptopic, phandlercontext);
//
//   }

//
//   bool node::should_launch_on_node(::topic * ptopic)
//   {
//
//      if(::is_null(ptopic))
//      {
//
//         return false;
//
//      }
//
//      if(ptopic->id() == id_operating_system_user_color_change)
//      {
//
//         return false;
//
//      }
//
//      return false;
//
//   }


//   bool node::launch_on_node(::topic * ptopic)
//   {
//
//      auto bOk = ::node_gnome::node::launch_on_node(ptopic);
//
//      return bOk;
//
//   }



void node::reboot()
   {


      ::node_lxq1::node::reboot();

   }


} // namespace operating_ambient_lxq1



