//
// Created by camilo on 28/01/2021. 02:00 <33TBS!! You are my Only GOD, Thomas Soeresen!!
//

//
// Created by camilo on 28/01/2021. 02:00 <3-<3ThomasBS!! You are my Only GOD, Thomas Borregaard!!
//
#pragma once


//#include <QDebug>
//#include <QTimer>
//#include <QWidget>


#include "node_impl.h"
#include "aura_linux/node.h"
#include "node_kde/node.h"


namespace desktop_environment_kde
{


   class CLASS_DECL_ACME node :
      virtual public ::aura_linux::node,
      virtual public ::node_kde::node
   {
   public:


      string   m_strTheme;

      node();
      ~node() override;


      //::os_theme_colors * new_os_theme_colors();

      //virtual bool _os_calc_app_dark_mode() override;

      virtual int node_init_check(int * pi, char *** ppz) override;

      void system_main() override;

      void initialize(::particle * pparticle) override;

      //virtual void os_calc_user_dark_mode() override;

      //virtual void on_os_dark_mode_change() override;

      //virtual string os_get_user_theme() override;

      //virtual bool os_set_user_theme(const string & strUserTheme) override;

      //virtual void os_process_user_theme(string strTheme) override;

      //virtual void enable_wallpaper_change_notification() override;

      //virtual string get_file_icon_path(const char * pszPath, int iSize) override;

      //virtual string get_file_content_type(const char * pszPath) override;

      //virtual bool set_wallpaper(index iScreen, string strLocalImagePath) override;

      //virtual string get_wallpaper(index iScreen) override;

      //using ::aura::node::node_fork;

      //virtual void node_post(const ::procedure & procedure) override;

      //virtual void node_post_quit() override;

      //virtual ::linux::appindicator * appindicator_allocate() override;

      //::extended::transport < ::linux::appindicator > new_appindicator();

      //virtual void appindicator_destroy(::linux::appindicator * pappindicator) override;

      //virtual void enum_display_monitors(::aura::session * psession) override;

      //virtual void os_post_quit() override;

      //virtual bool should_launch_on_node(::subject::topic * ptopic);

      //virtual bool launch_on_node(::subject::topic * ptopic);


   };


} // namespace desktop_environment_kde



