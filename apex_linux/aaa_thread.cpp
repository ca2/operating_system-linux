#include "framework.h"
#include "apex/operating_system.h"


//void CLASS_DECL_APEX_LINUX __init_thread()
//{
//
//   //if(t_hHookOldMsgFilter == nullptr)
//   //{
//
//   //   t_hHookOldMsgFilter = ::SetWindowsHookEx(WH_MSGFILTER,__message_filter_hook,nullptr,::GetCurrentThreadId());
//
//   //}
//
//}
//
//
//void CLASS_DECL_APEX_LINUX __term_thread()
//{
//
//
//}


//namespace linux
//{
//

//thread::thread(::particle * pparticle):
//   ::object(pparticle),
//   ::thread_impl(pparticle)
//{

//      m_happeningFinish.set_happening();
//      m_pThreadParams = nullptr;
//      m_pfnThreadProc = nullptr;

//      CommonConstruct();

//}

//void thread::construct(__THREADPROC pfnThreadProc,LPVOID pParam)
//{
//   m_happeningFinish.set_happening();
//   m_pfnThreadProc = pfnThreadProc;
//   m_pThreadParams = pParam;

//   CommonConstruct();
//}


__STATIC bool CLASS_DECL_APEX_LINUX IsHelpKey(LPMSG pMsg)

// return true only for non-repeat F1 keydowns.
{
   return pMsg->message == e_message_key_down &&

          pMsg->wParam == VK_F1 &&

          !(HIWORD(pMsg->lParam) & KF_REPEAT) &&

          GetKeyState(VK_SHIFT) >= 0 &&
          GetKeyState(VK_CONTROL) >= 0 &&
          GetKeyState(VK_MENU) >= 0;
}

__STATIC inline bool IsEnterKey(LPMSG pMsg)

{
   return pMsg->message == e_message_key_down && pMsg->wParam == VK_RETURN;

}

__STATIC inline bool IsButtonUp(LPMSG pMsg)

{
   return pMsg->message == e_message_left_button_up;

}



void __term_threading()
{

   //if(t_hHookOldMsgFilter != nullptr)
   //{
   //   ::UnhookWindowsHookEx(t_hHookOldMsgFilter);
   //   t_hHookOldMsgFilter = nullptr;
   //}

}



bool __node_init_thread(::thread * pthread)
{

   try
   {

      pthread->::exception::translator::attach();

   }
   catch(...)
   {

      return false;

   }

   return true;

}




bool __node_term_thread(::thread * pthread)
{

   bool bOk1 = false;

   try
   {

      if(pthread != nullptr)
      {

         pthread->::exception::translator::detach();

      }

      bOk1 = true;

   }
   catch(...)
   {

   }

   return bOk1;

}




