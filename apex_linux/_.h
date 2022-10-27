#pragma once


#include "apex/_.h"
#include "acme_linux/_.h"
#include "apex_posix/_.h"


#if defined(_APEX_LINUX_LIBRARY)
#define CLASS_DECL_APEX_LINUX  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APEX_LINUX  CLASS_DECL_IMPORT
#endif


namespace apex_linux
{


   class dir_context;
   class dir_system;
   class file_context;
   class file_system;


   class os_context;


   class ip_enum;


   class node;


   class launcher;


} // namespace apex_linux


//::e_status gdiplus_draw_text(::draw2d::graphics * pgraphics, ::draw2d::path * ppath, const string & str, rectangle_f64 & rectParam, const ::e_align & ealign, const ::e_draw_text & edrawtext, ::write_text::font * pfont, double dFontWidth, ::draw2d::brush * pbrush = nullptr, bool bMeasure = false);


//inline auto gdiplus_color(const ::color::color& color)
//{
//   return Gdiplus::Color(color.m_iA, color.m_iR, color.m_iG, color.m_iB);
//}
//
//
//
//#define __graphics(pgraphics) ((::draw2d_gdiplus::graphics *) pgraphics->m_pthis)
//#define __pen(ppen) ((::draw2d_gdiplus::pen *) ppen->m_pthis)
//#define __brush(pbrush) ((::draw2d_gdiplus::brush *) pbrush->m_pthis)
//#define __font(pfont) ((::draw2d_gdiplus::font *) pfont->m_pthis)
//#define __graphics_path(ppath) ((::draw2d_gdiplus::path *) ppath->m_pthis)
//
//
//
//
//class g_keep
//{
//
//public:
//
//   Gdiplus::Graphics* point_i32;
//   Gdiplus::GraphicsState s;
//
//   g_keep(Gdiplus::Graphics* point1)
//   {
//
//      point = point1;
//
//      s = point_i32->Save();
//
//   }
//
//   ~g_keep()
//   {
//
//      point_i32->Restore(s);
//
//   }
//
//};


//#include "tts_speaker.h"



//#include "apex.h"



//namespace linux
//{
//
//
//   class thread;
//
//   //class linux
//   //{
//   //   i32 function();
//   //};
//
//   //CLASS_DECL_APEX_LINUX HINSTANCE   load_library(const char* psz);
//
//   //CLASS_DECL_APEX_LINUX bool        shell_get_special_folder_path(HWND hwnd, ::file::path& str, i32 csidl, bool fCreate);
//   //CLASS_DECL_APEX_LINUX::file::path  shell_get_special_folder_path(i32 csidl, bool fCreate = true, ::windowing::window* pwindow = nullptr);
//   //CLASS_DECL_APEX_LINUX::u32       get_file_attributes(const char* pFileName);
//
//   //CLASS_DECL_APEX_LINUX::u32       get_current_directory(string& str);
//   //CLASS_DECL_APEX_LINUX::u32       get_temp_path(string& str);
//   //CLASS_DECL_APEX_LINUX::i32        reg_query_value(HKEY hkey, const char* pszSubKey, string& str);
//
//   //CLASS_DECL_APEX_LINUX HICON       extract_icon(HINSTANCE hInst, const char* pszExeFileName, ::u32 nIconIndex);
//
//   //CLASS_DECL_APEX_LINUX bool        delete_file(const char* pFileName);
//
//   //CLASS_DECL_APEX_LINUX i32     get_menu_string(HMENU hMenu, ::u32 uDItem, string& str, ::u32 flags);
//   //CLASS_DECL_APEX_LINUX void        time_to_file_time(::particle * pparticle, const ::earth::time& time, LPFILETIME pFileTime);
//
//   ////CLASS_DECL_APEX_LINUX ::file::path get_known_folder(REFKNOWNFOLDERID kfid);
//
//} // namespace linux


//#include "dir_system.h"
//#include "file_context.h"
//#include "inteprocess_channel.h"


//#include "os_context.h"


//#include "node.h"



