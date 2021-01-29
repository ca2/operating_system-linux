// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#include "framework.h"


namespace windowing
{

   windowing::windowing()
   {


   }


   windowing::~windowing()
   {


   }


   HCURSOR windowing::load_default_cursor(e_cursor ecursor)
   {

      int iCursor = 0;

      if(ecursor == cursor_size_top_left)
      {

         iCursor = XC_top_left_corner;

      }
      else if(ecursor == cursor_size_top_right)
      {

         iCursor = XC_top_right_corner;

      }
      else if(ecursor == cursor_size_top)
      {

         iCursor = XC_top_side;

      }
      else if(ecursor == cursor_size_right)
      {

         iCursor = XC_right_side;

      }
      else if(ecursor == cursor_size_left)
      {

         iCursor = XC_left_side;

      }
      else if(ecursor == cursor_size_bottom)
      {

         iCursor = XC_bottom_side;

      }
      else if(ecursor == cursor_size_bottom_left)
      {

         iCursor = XC_bottom_left_corner;

      }
      else if(ecursor == cursor_size_bottom_right)
      {

         iCursor = XC_bottom_right_corner;

      }
      else if(ecursor == cursor_arrow)
      {

         iCursor = XC_arrow;

      }

      if(iCursor == 0)
      {

         return 0;

      }

      sync_lock sl(x11_mutex());

      windowing_output_debug_string("\n::x11_GetWindowRect 1");

      xdisplay d(x11_get_display());

      if(d.is_null())
      {

         windowing_output_debug_string("\n::x11_GetWindowRect 1.1");

         return 0;

      }

      HCURSOR hcursor = XCreateFontCursor(d.display(), iCursor);

      return hcursor;


   }


   int_bool application::window_set_mouse_cursor(window * pwindow, HCURSOR hcursor)
   {

      if(::is_null(window))
      {

         return FALSE;

      }

      if(window->m_hcursorLast == hcursor)
      {

         return TRUE;

      }

      sync_lock sl(x11_mutex());

      windowing_output_debug_string("\n::SetCursor 1");

      xdisplay d(window->display());

      if(d.is_null())
      {

         windowing_output_debug_string("\n::SetCursor 1.1");

         return FALSE;

      }

      XDefineCursor(d, window->window(), hcursor);

      window->m_hcursorLast = hcursor;

      return TRUE;

   }

   bool windowing::sn_start_context()
   {


      Display * dpy = get();

      SnDisplay * pd = sn_display_new(dpy, &x_display_error_trap_push, &x_display_error_trap_pop);

      int iScreen = DefaultScreen(dpy);

      g_psncontext = sn_launchee_context_new(pd, iScreen, ::g_pappcore->m_strProgName);

      return true;

   }

   bool windowing::set_window_icon(window * pwindow, const ::file::path & path)
   {


      xdisplay
      d(oswindow->display());

      Atom net_wm_icon = XInternAtom(oswindow->display(), "_BAMF_DESKTOP_FILE", False);

      Atom cardinal = XInternAtom(oswindow->display(), "STRING", False);

      int ixa = XA_STRING;

      int status = XChangeProperty(
         oswindow->display(),
         oswindow->window(),
         net_wm_icon,
         ixa,
         8,
         PropModeReplace,
         (const unsigned char *) (const char *) path,
         path.get_length());

      output_debug_string("\nlinux::interaction_impl::bamf_set_icon END");

      fflush(stdout);

      if (status != 0)
      {

         return false;

      }

      return true;

   }


   int windowing::message_box(const char* pszMessage, const char* pszTitle, const ::e_message_box & emessagebox)
   {

      return x11_message_box(pszMessage, pszTitle, emessagebox);

   }


   ::windowing::window windowing::new_message_window(::user::interaction_impl * pimpl)
   {



      return pwindow;

   }



} // namespace windowing



