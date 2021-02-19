//
// Created by camilo on 17/02/2021. 00:32 BRT <3TBS_!!
//
#include "framework.h"
#ifdef WITH_SN
#include "sn.h"
#include "windowing_x11.h"

//
//#ifndef RASPBIAN

SnLauncheeContext* g_psncontext = nullptr;

//void x_display_error_trap_push(SnDisplay * sndisplay, Display * display);
//
//void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);


//
//void sn_start_context()
//{
//
//
//   Display * dpy = x11_get_display();
//
//   SnDisplay * pd = sn_display_new(dpy, &x_display_error_trap_push, &x_display_error_trap_pop);
//
//   int iScreen = DefaultScreen(dpy);
//
//   g_psncontext = sn_launchee_context_new(pd, iScreen, ::g_pappcore->m_strProgName);
//
//}
//
//
//#endif // !RASPBIAN

int g_iIgnoreXDisplayError = 0;


void x_display_error_trap_push(SnDisplay * sndisplay, Display * display)
{

   g_iIgnoreXDisplayError++;

}


void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display)
{

   synchronization_lock sl(x11_mutex());

   g_iIgnoreXDisplayError--;

   if(g_iIgnoreXDisplayError == 0)
   {

      XSync(display, false);

   }

}


namespace windowing_x11
{

   void windowing::_libsn_start_context()
   {

      Display *dpy = m_pdisplay->Display();

      SnDisplay *pd = sn_display_new(dpy, &x_display_error_trap_push, &x_display_error_trap_pop);

      int iScreen = DefaultScreen(dpy);

      m_pSnLauncheeContext = sn_launchee_context_new(pd, iScreen, System.m_strProgName);

   }


} // namespace windowing_x11




#endif



