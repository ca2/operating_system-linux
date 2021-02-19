// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#include "framework.h"
#include "windowing_x11.h"
#include <X11/cursorfont.h>


//extern ::app_core * g_pappcore;
//void x11_main();
//void os_post_quit();
//Display * x11_get_display();

//CLASS_DECL_AURA i32 ca2_main();




//#ifndef RASPBIAN
//
//SnLauncheeContext* g_psncontext = nullptr;
//
//void x_display_error_trap_push(SnDisplay * sndisplay, Display * display);
//
//void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);
////
////namespace aura
////{
////
//
////   ::e_status system::os_application_system_run()
////   {
////
////
////
////      auto estatus = ::apex::system::os_application_system_run();
////
////      if(!estatus)
////      {
////
////         return estatus;
////
////      }
////
////      return estatus;
////
////   }
//
//
//
//#endif // !RASPBIAN


//::e_status app_core::system_start()
//{
//
//   ::e_status estatus = system_pre_run();
//
//   if (!estatus)
//   {
//
//      return estatus;
//
//   }
//
//   auto psystem = get_context_system();
//
//   psystem->add_ref(OBJ_REF_DBG_ARGS);
//
//   if (m_pmainstruct->m_bConsole)
//   {
//
//      psystem->get_context_session()->set_context_app(psystem->m_papplicationStartup);
//
//      psystem->set_context_app(psystem->m_papplicationStartup);
//
//      psystem->get_context_session()->set_context(psystem->m_papplicationStartup);
//
//      psystem->set_context(psystem->m_papplicationStartup);
//
//   }
//
//
//
//   return estatus;
//
//}
//#ifdef LINUX
i32 _c_XErrorHandler(Display * display, XErrorEvent * perrorevent);
//#endif


//void x11_add_gdk_filter();


namespace windowing_x11
{


   windowing::windowing()
   {


   }


   windowing::~windowing()
   {


   }


   ::windowing::window * windowing::new_window(::user::interaction_impl * pimpl)
   {

      auto pwindow = __create < ::windowing_x11::window >();

      pwindow->m_pimpl = pimpl;

      return pwindow;

   }


    ::e_status windowing::remove_window(::windowing::window * pwindow)
   {

      return m_pdisplay->remove_window(pwindow);

   }


   ::e_status windowing::initialize(::layered *pobjectContext)
   {

      auto estatus = ::windowing::windowing::initialize(pobjectContext);

      if(!estatus)
      {

         return estatus;

      }

      auto pdisplay = __create < ::windowing::display >();

      if(!pdisplay)
      {

         return pdisplay.status();

      }

      m_pdisplay = pdisplay;

      if(!pdisplay)
      {

         return error_no_interface;

      }

      return ::success;

   }


   ::e_status windowing::os_application_system_run()
   {

      if (System.m_bUser)
      {

         if (!XInitThreads())
         {

            return false;

         }

         XSetErrorHandler(_c_XErrorHandler);

      }

      auto pnode = Node;

      if(pnode)
      {

         pnode->os_application_system_run();

      }
      else
      {

         x11_main();

      }

      //x11_main();
//      if (m_bGtkApp)
//      {
//
//         apex_application_run(m_strAppId, m_strProgName);
//
//      }
//      else
//      {
//
//         //      g_set_application_name(psystem->m_strAppId);
//         //
//         //      g_set_prgname(psystem->m_strProgName);
//         //
//         //      //auto idle_source = g_idle_source_new();
//         //
//         //      //g_source_set_callback(idle_source, &linux_start_system, (::aura::system *) m_psystem, nullptr);
//         //
//         //      //g_source_attach(idle_source, g_main_context_default());
//         //
//         //      //int c = 2;
//         //
//         //      //const char * argv[]={"app", "--g-fatal-warnings"};
//         //
//         //#if !defined(__SANITIZE_ADDRESS__)
//         //
//         //      gtk_init_check(&psystem->m_argc, &psystem->m_argv);
//         //
//         //#endif
//         //x11_add_gdk_filter();
//         //gtk_main();
//
//      }

      //::parallelization::post_quit_and_wait(get_context_system(), one_minute());

      return ::success;

   }


   ::windowing::display * windowing::display()
   {

      //__throw(interface_only_exception());

      return m_pdisplay;

   }


   ::windowing_x11::window * windowing::_window(Window window)
   {

      if (!m_pdisplay)
      {

         return nullptr;

      }

      auto pwindow = m_pdisplay->_window(window);

      return pwindow;

   }


   __pointer(::windowing::cursor) windowing::load_default_cursor(enum_cursor ecursor)
   {

      synchronization_lock synchronizationlock(mutex());

      if (m_pcursorset.is_null())
      {

         auto estatus = __construct_new(m_pcursorset);

         if (!estatus)
         {

            return nullptr;

         }

      }

      auto & pcursor = m_pcursorset->m_cursormap[ecursor];

      if(pcursor)
      {

         return pcursor;

      }

      int iCursor = 0;

      if(ecursor == e_cursor_size_top_left)
      {

         iCursor = XC_top_left_corner;

      }
      else if(ecursor == e_cursor_size_top_right)
      {

         iCursor = XC_top_right_corner;

      }
      else if(ecursor == e_cursor_size_top)
      {

         iCursor = XC_top_side;

      }
      else if(ecursor == e_cursor_size_right)
      {

         iCursor = XC_right_side;

      }
      else if(ecursor == e_cursor_size_left)
      {

         iCursor = XC_left_side;

      }
      else if(ecursor == e_cursor_size_bottom)
      {

         iCursor = XC_bottom_side;

      }
      else if(ecursor == e_cursor_size_bottom_left)
      {

         iCursor = XC_bottom_left_corner;

      }
      else if(ecursor == e_cursor_size_bottom_right)
      {

         iCursor = XC_bottom_right_corner;

      }
      else if(ecursor == e_cursor_arrow)
      {

         iCursor = XC_arrow;

      }

      if(iCursor == 0)
      {

         return nullptr;

      }

      synchronization_lock sl(x11_mutex());

      windowing_output_debug_string("\n::x11_GetWindowRect 1");

      display_lock lock(m_pdisplay);

      auto cursor = XCreateFontCursor(m_pdisplay->Display(), iCursor);

      auto pcursorX11 = __create < ::windowing_x11::cursor >();

      pcursor = pcursorX11;

      pcursorX11->m_cursor = cursor;

//      if(lock)
//      {
//
//         windowing_output_debug_string("\n::x11_GetWindowRect 1.1");
//
//         return 0;
//
//      }

      return pcursor;

   }




//   bool windowing::_libsn_start_context()
//   {
//
//      Display * dpy = get();
//
//      SnDisplay * pd = sn_display_new(dpy, &x_display_error_trap_push, &x_display_error_trap_pop);
//
//      int iScreen = DefaultScreen(dpy);
//
//      g_psncontext = sn_launchee_context_new(pd, iScreen, ::g_pappcore->m_strProgName);
//
//      return true;
//
//   }
//
//


//   int windowing::message_box(const char* pszMessage, const char* pszTitle, const ::e_message_box & emessagebox)
//   {
//
//      return x11_message_box(pszMessage, pszTitle, emessagebox);
//
//   }


//   ::windowing::window * windowing::new_message_window(::user::interaction_impl * pimpl)
//   {
//
//      auto pwindowNew = __create < ::windowing_x11::window > ();
//
//      auto & pwindow = m_pdisplay->m_windowmap[pimpl->get_oswindow()];
//
//      if(pwindow.)
//
//
//
//      return pwindow;
//
//   }


   void windowing::_message_handler(void * p)
   {

      XEvent * pevent = (XEvent *) p;

   }

//
//   SnLauncheeContext* g_psncontext = nullptr;
//
//   void x_display_error_trap_push(SnDisplay * sndisplay, Display * display);
//
//   void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);
//
//



   ::windowing::window * windowing::get_keyboard_focus(::thread *)
   {

      if(!m_pdisplay)
      {

         return nullptr;

      }

      display_lock lock(m_pdisplay);

      auto pwindow = m_pdisplay->get_keyboard_focus();

      return pwindow;

   }


} // namespace windowing



