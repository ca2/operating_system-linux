#pragma once


namespace node_gnome
{


   ::user::enum_desktop get_edesktop();

   bool gsettings_set(const char * pszSchema, const char * pszKey, const char * pszValue);

   bool gsettings_sync();

   char * gsettings_get_malloc(const char * pszSchema, const char * pszKey);

   bool g_enable_wallpaper_change_notification(const char * pszSchema, const char * pszKey);

   void initialize_edesktop();

   ::user::enum_desktop calc_edesktop();

   void g_defer_init();

   void g_defer_term();

   void os_calc_dark_mode();

   void initialize_edesktop();


} // namespace node_gnome


void gdk_branch(matter * prunnable, e_priority epriority = priority_normal);



