#include "framework.h"
// #include "interaction_impl.h"
// #include "acme/constant/message.h"
// #include "acme/platform/keep.h"
// #include "aura/windowing/window.h"
// #include "aura/windowing/windowing.h"
// #include "aura/message/user.h"
// #include "aura/platform/session.h"
// #include "aura/user/user/user.h"
// #include "aura/windowing/display.h"
// #include "aura/graphics/draw2d/graphics.h"
//
//
// #define TEST 0
//
//
// namespace aura_linux
// {
//
//
//    long long g_iMouseMove = 0;
//
// //   class x11data :
// //      virtual public object
// //   {
// //   public:
// //
// //      XWindowAttributes             m_attr;
// //      XVisualInfo                   m_visualinfo;
// //      // GdkWindow *                   m_pgdkwindow;
// //      void *                        m_pgdkwindow;
// //
// //   };
//
//
//    interaction_impl::interaction_impl()
//    {
//
//       linux_interaction_impl_common_construct();
//
//    }
//
//
// //   interaction_impl::interaction_impl()
// //   {
// //
// //      linux_interaction_impl_common_construct();
// //
// //   }
//
//
//    void interaction_impl::linux_interaction_impl_common_construct()
//    {
//
//       //set_os_data(nullptr);
//
//       m_bExposing    = false;
//       m_bEnabled     = true;
//       m_bMoveEvent   = false;
//       m_bSizeEvent   = false;
//
//    }
//
//
//    interaction_impl::~interaction_impl()
//    {
//
//    }
//
//
//    ::windowing::window * interaction_impl::from_os_data(void * pdata)
//    {
//
//       return from_handle((::oswindow) pdata);
//
//    }
//
//
// //   void * interaction_impl::get_os_data() const
// //   {
// //
// //      return m_oswindow;
// //
// //   }
//
//
// //   const MESSAGE* PASCAL interaction_impl::GetCurrentMessage()
// //   {
// //
// //      return nullptr;
// //
// //   }
// //
//
// //   LRESULT interaction_impl::Default()
// //   {
// //
// //      return 0;
// //
// //   }
//
//
//    ::windowing::window * interaction_impl::from_handle(::oswindow oswindow)
//    {
//
//       if(::is_null(oswindow))
//       {
//
//          return nullptr;
//
//       }
//
//       if(::is_null(oswindow->m_pwindow))
//       {
//
//          return nullptr;
//
//       }
//
//       return oswindow->m_pwindow;
//
//    }
//
//
//    ::windowing::window * interaction_impl::FromHandlePermanent(::oswindow oswindow)
//    {
//
//       if(oswindow->m_pwindow == nullptr)
//       {
//
//          return nullptr;
//
//       }
//
//       return oswindow->m_pwindow;
//
//    }
//
//
//    bool interaction_impl::Attach(::oswindow hWndNew)
//    {
//
//       ASSERT(get_os_data() == nullptr);
//
//       if (hWndNew == nullptr)
//       {
//
//          return false;
//
//       }
//
//       //set_os_data(hWndNew);
//
//       return true;
//
//    }
//
//
//    oswindow interaction_impl::Detach()
//    {
//
// //      oswindow hwnd = (oswindow) get_os_data();
// //
// //      if (hwnd != nullptr)
// //      {
// //
// //         set_os_data(nullptr);
// //
// //      }
//
//       //return hwnd;
//
//       auto oswindow = this->oswindow();
//
//       m_pwindow->set_oswindow(nullptr);
//
//       return oswindow;
//
//    }
//
//
//    void interaction_impl::pre_subclass_window()
//    {
//
//
//    }
//
//
// //   void interaction_impl::native_create_host()
// //   {
// //
// //
// //      ::windowing::window::native_create_host();
// //
// ////      ::pointer<::user::system>pusersystem;
// ////
// ////      if(m_puserinteraction->m_pusersystem)
// ////      {
// ////
// ////         pusersystem = m_puserinteraction->m_pusersystem;
// ////
// ////      }
// ////      else
// ////      {
// ////
// ////         pusersystem = __allocate ::user::system();
// ////
// ////      }
// ////
// //////      ENSURE_ARG(pusersystem->m_createstruct.lpszName == nullptr || is_string_ok(pusersystem->m_createstruct.lpszName));
// //////
// ////      if (!m_puserinteraction->pre_create_window(pusersystem))
// ////      {
// ////
// ////         //return false;
// ////
// ////         throw ::exception(error_failed);
// ////
// ////      }
// ////
// ////      __refer(m_puserinteraction->m_pthreadUserInteraction, ::get_task());
// ////
// ////      //m_pthreadUserImpl = m_puserinteraction->m_pthreadUserInteraction;
// ////
// ////      install_message_routing(m_puserinteraction);
// ////
// ////      bool bOk = true;
// ////
// //////      if(pusersystem->m_createstruct.hwndParent == (oswindow) MESSAGE_WINDOW_PARENT)
// //////      {
// //////
// //////         auto pwindowing = m_pwindowwindowing();
// //////
// //////         m_oswindow = pwindowing->new_message_window(this);
// //////
// //////         m_puserinteraction->m_bMessageWindow = true;
// //////
// //////         //send_message(e_message_create, 0, (LPARAM) &cs);
// //////
// //////      }
// //////      else
// ////      {
// ////
// ////         m_puserinteraction->m_bMessageWindow = false;
// ////
// ////         
// ////
// ////         auto puser = user();
// ////
// ////         auto pwindowing = system()->windowing();
// ////
// ////         pwindowing->windowing_send([&]()
// ////         {
// ////
// ////            
// ////
// ////            auto puser = user();
// ////
// ////            auto pwindowing = system()->windowing();
// ////
// ////            m_pwindow = pwindowing->new_window(this);
// ////
// ////            if(m_pwindow)
// ////            {
// ////
// ////               informationf("window created");
// ////
// ////            }
// ////            else
// ////            {
// ////
// ////               informationf("window not created");
// ////
// ////            }
// ////
// ////         });
// ////
// ////      }
// ////
// //////      if(bOk)
// //////      {
// //////
// //////         m_puserinteraction->send_message(e_message_create, 0, (lparam) &pusersystem->m_createstruct);
// //////
// //////         m_puserinteraction->m_ewindowflag |= e_window_flag_window_created;
// //////
// //////      }
// ////
// ////      if(!bOk)
// ////      {
// ////
// ////         throw ::exception(error_failed);
// ////
// ////      }
// ////
// ////
// ////
// //
// //   }
//
//
//    bool interaction_impl::pre_create_window(::user::system * pusersystem)
//    {
//
//       return true;
//
//    }
//
//
//    void interaction_impl::install_message_routing(::channel * pchannel)
//    {
//
//       //m_pbuffer->InstallMessageHandling(pinterface);
//
//       ::windowing::window::last_install_message_routing(pchannel);
//
//       ::windowing::window::install_message_routing(pchannel);
//
//       if(!m_puserinteraction->m_bMessageWindow)
//       {
//
//          MESSAGE_LINK(e_message_paint, pchannel, this,&interaction_impl::_001OnPaint);
// //         MESSAGE_LINK(WM_PRINT, pchannel, this,&interaction_impl::_001OnPrint);
//
//       }
//
//       m_puserinteraction->install_message_routing(pchannel);
//
//       MESSAGE_LINK(e_message_create, pchannel, this,&interaction_impl::on_message_create);
//
//       if(!m_puserinteraction->m_bMessageWindow)
//       {
//
//          MESSAGE_LINK(e_message_set_cursor, pchannel, this,&interaction_impl::_001OnSetCursor);
//          //MESSAGE_LINK(e_message_erase_background, pchannel, this,&interaction_impl::_001OnEraseBkgnd);
//          //MESSAGE_LINK(e_message_size, pchannel, this,&interaction_impl::_001OnSize);
//          //MESSAGE_LINK(e_message_nccalcsize, pchannel, this,&interaction_impl::_001OnNcCalcSize);
//
//          // linux
//          MESSAGE_LINK(e_message_reposition, pchannel, this, &interaction_impl::_001OnMove);
//          MESSAGE_LINK(e_message_size, pchannel, this, &interaction_impl::_001OnSize);
//          MESSAGE_LINK(e_message_show_window, pchannel, this, &interaction_impl::_001OnShowWindow);
//
//          //MESSAGE_LINK(e_message_window_position_changing, pchannel, this,&interaction_impl::_001OnWindowPosChanging);
//          //MESSAGE_LINK(e_message_window_position_changed, pchannel, this,&interaction_impl::_001OnWindowPosChanged);
//          //MESSAGE_LINK(WM_GETMINMAXINFO, pchannel, this,&interaction_impl::_001OnGetMinMaxInfo);
//          //MESSAGE_LINK(e_message_set_focus, pchannel, this,&interaction_impl::_001OnSetFocus);
//          //MESSAGE_LINK(e_message_kill_focus, pchannel, this,&interaction_impl::_001OnKillFocus);
// //         MESSAGE_LINK(ca2m_PRODEVIAN_SYNCH, pchannel, this,&interaction_impl::_001OnProdevianSynch);
//          ::windowing::window::prio_install_message_routing(pchannel);
//
//       }
//
//       MESSAGE_LINK(e_message_destroy, pchannel, this,&interaction_impl::_001OnDestroy);
//
//    }
//
//
//    void interaction_impl::defer_delayed_placement()
//    {
//
//       if(!m_puserinteraction->layout().is_changing())
//       {
//
//          if(m_bMoveEvent || m_bSizeEvent)
//          {
//
//             defer_branch("delayed_placement", [this]()
//             {
//
//                _thread_delayed_placement();
//
//             });
//
//          }
//
//       }
//
//    }
//
//
//    void interaction_impl::_thread_delayed_placement()
//    {
//
//       while(m_timeLastPlacementEvent.elapsed() < 40_ms || m_puserinteraction->layout().is_changing())
//       {
//
//          if(!task_sleep(10_ms))
//          {
//
//             return;
//
//          }
//
//       }
//
//       if(!task_get_run())
//       {
//
//          return;
//
//       }
//
//       bool bMove = m_bMoveEvent && m_puserinteraction->const_layout().sketch().origin() != m_pointLastMove;
//
//       m_bMoveEvent = false;
//
//       if (bMove)
//       {
//
//          information() << "linux::interaction_impl Window Manager Move ("<<m_pointLastMove.x()<<", "<<m_pointLastMove.y()<<")";
//
//          m_puserinteraction->set_position(m_pointLastMove);
//
//          m_puserinteraction->set_reposition();
//
//       }
//
//       bool bSize = m_bSizeEvent && m_puserinteraction->const_layout().sketch().size() != m_sizeLastSize;
//
//       m_bSizeEvent = false;
//
//       if (bSize)
//       {
//
//          informationf("linux::interaction_impl Window Manager Size (%d, %d)", m_sizeLastSize.cx(), m_sizeLastSize.cy());
//
//          m_puserinteraction->set_size(m_sizeLastSize);
//
//          m_puserinteraction->set_need_layout();
//
//       }
//
//       if(bMove || bSize)
//       {
//
//          m_puserinteraction->display();
//
//          m_puserinteraction->set_need_redraw();
//
//          m_puserinteraction->post_redraw();
//
//       }
//
//    }
//
//
//    void interaction_impl::_001OnMove(::message::message * pmessage)
//    {
//
// //      ::pointer<::message::size>psize(pmessage);
// //
// //      if (m_bDestroyImplOnly)
// //      {
// //
// //         return;
// //
// //      }
// //
// //      if (m_puserinteraction->layout().m_eflag)
// //      {
// //
// //         pmessage->m_bRet = true;
// //
// //         return;
// //
// //      }
//
// //      ::pointer<::message::transfer>pmove(pmessage);
// //
// //      m_puserinteraction->layout().origin() = pmove->m_point;
// //
// //      m_puserinteraction->layout().screen_origin() = pmove->m_point;
// //
// //      if(m_puserinteraction->layout().window().origin() != m_puserinteraction->layout().sketch().origin())
// //      {
// //
// //         m_puserinteraction->move_to(pmove->m_point);
// //
// //         m_puserinteraction->set_reposition();
// //
// //         m_puserinteraction->post_redraw();
// //
// //      }
//
//    }
//
//
//    void interaction_impl::_001OnSize(::message::message * pmessage)
//    {
//
// //      if (m_bDestroyImplOnly)
// //      {
// //
// //         return;
// //
// //      }
// //
// //      if (m_puserinteraction->layout().m_eflag)
// //      {
// //
// //         pmessage->m_bRet = true;
// //
// //         return;
// //
// //      }
// //
// //      ::pointer<::message::size>psize(pmessage);
//
// //      m_puserinteraction->window_state3().m_size = psize->m_size;
// //
// //      if(m_puserinteraction->window_state3().m_size != m_puserinteraction->layout().sketch().m_size)
// //      {
// //
// //         m_puserinteraction->set_size(psize->m_size);
// //
// //         m_puserinteraction->set_need_layout();
// //
// //         m_puserinteraction->post_redraw();
// //
// //      }
//
//    }
//
//
//    void interaction_impl::_001OnShowWindow(::message::message * pmessage)
//    {
//
//       ::pointer<::message::show_window>pshowwindow(pmessage);
//
//       if(!m_puserinteraction)
//       {
//
//          return;
//
//       }
//
//       if(pshowwindow->m_bShow)
//       {
//
//          information() << "linux::interaction_impl::_001OnShowWindow VISIBLE edisplay=" << ::as_string(m_puserinteraction->const_layout().design().display().m_eenum);
//
//          //m_puserinteraction->ModifyStyle(0, WS_VISIBLE);
//
//          //m_puserinteraction->m_bScreenVisible = true;
//
//          if(m_puserinteraction->const_layout().design().display() == ::e_display_iconic && !m_pwindow->is_iconic())
//          {
//
//             m_puserinteraction->hide();
//
//             if(m_puserinteraction->window_previous_display() == ::e_display_iconic)
//             {
//
//                m_puserinteraction->_001OnDeiconify(::e_display_normal);
//
//             }
//             else
//             {
//
//                m_puserinteraction->_001OnDeiconify(m_puserinteraction->window_previous_display());
//
//             }
//
//          }
//
//          m_puserinteraction->set_need_redraw();
//
//          m_puserinteraction->post_redraw();
//
//          //x11_defer_check_configuration(m_oswindow);
//
//       }
//       else
//       {
//
//          //m_puserinteraction->ModifyStyle(WS_VISIBLE, 0, 0);
//          //m_puserinteraction->m_bVisible = false;
//
//       }
//
//    }
//
//
//    void interaction_impl::on_start_layout_experience(enum_layout_experience elayout)
//    {
//
//       //child_post_quit("delayed_placement");
//
//       ::windowing::window::on_start_layout_experience(elayout);
//
//    }
//
//
//    void interaction_impl::on_end_layout_experience(enum_layout_experience elayout)
//    {
//
//       defer_delayed_placement();
//
//    }
//
//
//    void interaction_impl::on_layout(::draw2d::graphics_pointer & pgraphics)
//    {
//
//       ::windowing::window::on_layout(pgraphics);
//
//    }
//
//
//    void interaction_impl::_001OnDestroy(::message::message * pmessage)
//    {
//
// //      __UNREFERENCED_PARAMETER(pmessage);
// //
// //      {
// //
// //         single_lock synchronouslock(get_app() == nullptr ? nullptr : get_app()->mutex(), true);
// //
// //         auto ptask = ::get_task();
// //
// //         if (::is_null(ptask))
// //         {
// //
// //            if (pthread->get_active_ui() == m_puserinteraction)
// //            {
// //
// //               pthread->set_active_ui(nullptr);
// //
// //            }
// //
// //         }
// //
// //      }
//
// //      ::parallelization::post_quit_and_wait(m_pthreadProDevian, seconds(10));
//
// //      if (m_puserinteraction->m_pthread != nullptr)
// //      {
// //
// //         synchronous_lock synchronouslock(m_puserinteraction->m_pthread->synchronization());
// //
// //         if(m_puserinteraction->m_pthread->m_puiptra != nullptr)
// //         {
// //
// //            m_puserinteraction->m_pthread->m_puiptra->erase(m_puserinteraction);
// //
// //         }
// //
// //      }
//
//       //Default();
//
//    }
//
//
//    void interaction_impl::post_non_client_destroy()
//    {
//
//       //clear_os_data();
//
//       if (m_pwindow)
//       {
//
//          m_pwindow->post_non_client_destroy();
//
//       }
//
//       ::windowing::window::post_non_client_destroy();
//
//    }
//
//
//    void interaction_impl::on_final_release()
//    {
//
//       if (get_os_data() != nullptr)
//       {
//
//          start_destroying_window();
//
//       }
//       else
//       {
//
//          post_non_client_destroy();
//
//       }
//
//    }
//
//
// //   void interaction_impl::assert_ok() const
// //   {
// //
// //      if (get_os_data() == nullptr)
// //      {
// //
// //         return;
// //
// //      }
// //
// //   }
// //
// //
// //   void interaction_impl::dump(dump_context & dumpcontext) const
// //   {
// //
// //      ::object::dump(dumpcontext);
// //
// //      dumpcontext << "\nm_hWnd = " << (void *)((interaction_impl *) this)->get_os_data();
// //
// //      /*
// //
// //      if (get_handle() == nullptr || get_handle() == oswindow_BOTTOM ||
// //               get_handle() == oswindow_TOPMOST || get_handle() == oswindow_NOTOPMOST)
// //      {
// //
// //         // not a normal interaction_impl - nothing more to dump
// //            return;
// //
// //      }
// //
// //      */
// //
// //      /*
// //
// //      if (!::is_window((oswindow) get_handle()))
// //      {
// //
// //         // not a valid interaction_impl
// //         dumpcontext << " (illegal oswindow)";
// //         return; // don't do anything more
// //
// //      }
// //
// //      */
// //
// //      ::pointer<::windowing::window>pWnd = (::windowing::window *) this;
// //      if (pWnd.m_p != this)
// //         dumpcontext << " (Detached or temporary interaction_impl)";
// //      else
// //         dumpcontext << " (permanent interaction_impl)";
// //
// //      char szBuf [64];
// //
// //      ::int_rectangle rectangle;
// //      ((::windowing::window *) this)->m_puserinteraction->window_rectangle(&rectangle);
// //      dumpcontext << "\nrect = " << rectangle;
// //      dumpcontext << "\nparent ::pointer<::interaction_impl>= " << (void *)((::windowing::window *) this)->get_parent();
// //
// ////      dumpcontext << "\nstyle = " << (void *)(dword_ptr)::GetWindowLong(get_handle(), GWL_STYLE);
// //      //    if (::GetWindowLong(get_handle(), GWL_STYLE) & WS_CHILD)
// //      //     dumpcontext << "\nid = " << __get_dialog_control_id(get_handle());
// //
// //      dumpcontext << "\n";
// //   }
//
//
//    void interaction_impl::start_destroying_window()
//    {
//
//       ::windowing::window::start_destroying_window();
//
// //      if(!m_pwindow)
// //      {
// //
// //         //return true;
// //
// //         return;
// //
// //      }
// //
// ////      if(m_oswindow->m_bMessageOnlyWindow)
// ////      {
// ////
// ////         ::user::interaction * pinteraction = m_puserinteraction;
// ////
// ////         send_message(e_message_destroy, 0, 0);
// ////
// ////         send_message(e_message_ncdestroy, 0, 0);
// ////
// ////         auto pwindowing = ::auraacmesystem()->windowing();
// ////
// ////         pwindowing->erase_window(this);
// ////
// ////         return true;
// ////
// ////      }
// //
// //      bool bResult = false;
// //
// //      oswindow window = get_oswindow();
// //
// //      if (window != nullptr)
// //      {
// //
// //         m_pwindow->destroy_window();
// //
// //         //Detach();
// //
// //      }
// //
// //      //return bResult;
//
//    }
//
//
//    /////////////////////////////////////////////////////////////////////////////
//    // Default interaction_impl implementation
//
//
//    void interaction_impl::default_window_procedure(::message::message * pmessage)
//    {
//
//       /*  if (m_pfnSuper != nullptr)
//            return ::callWindowProc(m_pfnSuper, get_handle(), nMsg, wparam, lparam);
//
//         WNDPROC pfnWndProc;
//         if ((pfnWndProc = *GetSuperWndProcaddr()) == nullptr)
//         {
//
//            return ::default_window_procedure(get_handle(), nMsg, wparam, lparam);
//
//          }
//         else
//         {
//
//            return ::callWindowProc(pfnWndProc, get_handle(), nMsg, wparam, lparam);
//
//            }
//            */
//
//
// //      return 0;
//    }
//
//    /*
//       WNDPROC* interaction_impl::GetSuperWndProcaddr()
//       {
//          // Note: it is no longer necessary to override GetSuperWndProcaddr
//          //  for each control class with a different WNDCLASS.
//          //  This implementation now uses instance data, such that the previous
//          //  WNDPROC can be anything.
//
//          return &m_pfnSuper;
//       }
//    */
//    void interaction_impl::pre_translate_message(::message::message * pmessage)
//    {
//       __UNREFERENCED_PARAMETER(pmessage);
//       // no default processing
//    }
//
//
// //   void interaction_impl::get_window_text(string & rectString)
// //   {
// //
// //      rectString = m_strWindowText;
// //
// //   }
//
//    /*
//       int interaction_impl::GetDlgItemText(int nID, string & rectString) const
//       {
//          ASSERT(::is_window((oswindow) get_handle()));
//          rectString = "";    // is_empty without deallocating
//
//          oswindow hWnd = ::GetDlgItem(get_handle(), nID);
//          if (hWnd != nullptr)
//          {
//             int nLen = ::GetWindowTextLength(hWnd);
//             ::GetWindowText(hWnd, rectString.get_buffer(nLen), nLen+1);
//             rectString.ReleaseBuffer();
//          }
//
//          return (int)rectString.get_length();
//       }
//    */
//
// //   bool interaction_impl::GetWindowPlacement(WINDOWPLACEMENT* puserinteractionpl)
// //
// //   {
// //      /*    ASSERT(::is_window((oswindow) get_handle()));
// //          puserinteractionpl->length = sizeof(WINDOWPLACEMENT);
// //
// //          return ::GetWindowPlacement(get_handle(), puserinteractionpl) != false;*/
// //
// //      return false;
// //   }
// //
// //   bool interaction_impl::SetWindowPlacement(const WINDOWPLACEMENT* puserinteractionpl)
// //
// //   {
// //      /*      ASSERT(::is_window((oswindow) get_handle()));
// //            ((WINDOWPLACEMENT*)puserinteractionpl)->length = sizeof(WINDOWPLACEMENT);
// //
// //            return ::SetWindowPlacement(get_handle(), puserinteractionpl) != false;*/
// //
// //      return false;
// //   }
//
//    /////////////////////////////////////////////////////////////////////////////
//    // interaction_impl will delegate owner draw messages to self drawing controls
//
//    // Drawing: for all 4 control types
// // /*   void interaction_impl::OnDrawItem(int /*nIDCtl*/, LPDRAWITEMSTRUCT pDrawItemStruct)
//
//    // {
//
//    // reflect notification to child interaction_impl control
//    //  if (ReflectLastMsg(pDrawItemStruct->hwndItem))
//
//    //   return;     // eat it
//
//    // not handled - do default
// //      Default();
//    // }
//
//    // Drawing: for all 4 control types
// //   int interaction_impl::OnCompareItem(int /*nIDCtl*/, LPCOMPAREITEMSTRUCT pCompareItemStruct)
//
//    // {
//    //  // reflect notification to child interaction_impl control
//    //LRESULT lResult;
// //      if (ReflectLastMsg(pCompareItemStruct->hwndItem, &lResult))
//
//    //       return (int)lResult;        // eat it
//
//    // not handled - do default
//    //  return (int)Default();
// //   }
//
//    // void interaction_impl::OnDeleteItem(int /*nIDCtl*/, LPDELETEITEMSTRUCT pDeleteItemStruct)
//
//    //{
//    // reflect notification to child interaction_impl control
//    // if (ReflectLastMsg(pDeleteItemStruct->hwndItem))
//
//    //  return;     // eat it
//    // not handled - do default
// //      Default();
//    // }
//
// //   bool interaction_impl::_EnableToolTips(bool bEnable, unsigned int nFlag)
// //   {
// //      __UNREFERENCED_PARAMETER(bEnable);
// //      __UNREFERENCED_PARAMETER(nFlag);
// //      return false;
// //   }
//
// //   LRESULT interaction_impl::OnNTCtlColor(wparam wparam, lparam lparam)
// //
// //   {
// //      return 0;
// //   }
// //
// //
// //   void interaction_impl::PrepareForHelp()
// //   {
// //   }
//
//
//    void interaction_impl::route_command(::message::command * pcommand, bool bRouteKeyToDescendants)
//    {
//
//       channel::route_command(pcommand, bRouteKeyToDescendants);
//
//    }
//
//
// //   void interaction_impl::on_control_event(::user::control_event * pevent)
// //   {
// //
// //      __UNREFERENCED_PARAMETER(pevent);
// //
// //   }
//
//
// //   void interaction_impl::_002OnDraw(::image::image *pimage)
// //   {
// //
// //   }
// //
//
//
//    void interaction_impl::show_software_keyboard(::user::element * pelement)
//    {
//
//
//    }
//
//
//    void interaction_impl::hide_software_keyboard(::user::element * pelement)
//    {
//
//
//    }
//
//
// //   class ::time     timeDebugmessage_handlerTime;
// //   int            iDebugmessage_handlerTime;
// //   class ::time     timeLastMouseMove;
// //   class ::time     timeLastPaint;
//
//
// //   void interaction_impl::aaa_message_handler(::message::message * pmessage)
// //   {
// //
// //      ::windowing::window::aaa_message_handler(pmessage);
// //
// //   }
//
//
// //   void interaction_impl::aaa_message_handler(::message::message * pmessage)
// //   {
// //
// //      bool bKeyMessage = false;
// //
// //      ::message::key * pkey = nullptr;
// //
// //      if (m_puserinteraction->pre_message_handler(pkey, bKeyMessage, pmessage))
// //      {
// //
// //         return;
// //
// //      }
// //
// //      if(pmessage->m_emessage == e_message_timer)
// //      {
// //
// //         //m_pthread->step_timer();
// //
// //      }
// //      else if(pmessage->m_emessage == e_message_left_button_down)
// //      {
// //
// //         informationf("linux::interaction_impl::e_message_left_button_down");
// //
// //      }
// //      else if(pmessage->m_emessage == e_message_left_button_up)
// //      {
// //
// //         informationf("linux::interaction_impl::e_message_left_button_up");
// //
// //      }
// //      else if(pmessage->m_emessage == e_message_mouse_move)
// //      {
// //
// //         g_iMouseMove++;
// //
// //         //informationf("linux::interaction_impl::message_handler e_message_mouse_move");
// //         //printf("g_iMouseMove = %d\n", g_iMouseMove);
// //
// //      }
// //      else if(pmessage->m_emessage == e_message_paint)
// //      {
// //
// //      }
// //      else if(pmessage->m_emessage == e_message_left_button_up)
// //      {
// //
// //         informationf("e_message_left_button_up (0)");
// //
// //      }
// //
// ////      if(::is_set(m_puserinteraction))
// ////      {
// ////
// ////         m_puserinteraction->pre_translate_message(pmessage);
// ////
// ////      }
// //
// ////      if(tickDebugmessage_handlerTime.timeout(1))
// ////      {
// ////
// ////         iDebugmessage_handlerTime = 0;
// ////
// ////      }
// ////      else
// ////      {
// ////
// ////         if(iDebugmessage_handlerTime > 20)
// ////         {
// ////
// ////            informationf("interaction_impl::message handler flooded?\n");
// ////
// ////         }
// ////         else
// ////         {
// ////
// ////            iDebugmessage_handlerTime++;
// ////
// ////         }
// ////
// ////      }
// //
// //      if(m_puserinteraction != nullptr)
// //      {
// //
// //         if (m_puserinteraction->layout().is_moving())
// //         {
// //            //informationf("moving: skip pre translate message");
// //         }
// //         else if (m_puserinteraction->layout().is_sizing())
// //         {
// //            //informationf("sizing: skip pre translate message");
// //         }
// //         else
// //         {
// //
// //            //m_puserinteraction->pre_translate_message(pmessage);
// //
// //            //if (pmessage->m_bRet)
// //            //{
// //
// //              // return;
// //
// //            //}
// //
// //            //pmessage->m_uiMessageFlags |= 1;
// //
// //         }
// //
// //      }
// //
// //
// //
// ////      if(bKeyMessage)
// ////      {
// ////
// ////         
// ////
// ////         auto puser = user();
// ////
// ////         auto pwindowing = system()->windowing();
// ////
// ////         ::pointer<::message::key>pkey = pmessage;
// ////
// ////         //pwindowing->set(pkey, get_oswindow(), m_pwindow, pkey->m_emessage, pkey->m_wparam, pkey->m_lparam);
// ////
// //////         if(pmessage->m_emessage == e_message_key_down)
// //////         {
// //////
// //////            try
// //////            {
// //////
// //////               psession->set_key_pressed(pkey->m_ekey, true);
// //////
// //////            }
// //////            catch(...)
// //////            {
// //////
// //////            }
// //////
// //////         }
// //////         else if(pmessage->m_emessage == e_message_key_up)
// //////         {
// //////
// //////            try
// //////            {
// //////
// //////               psession->set_key_pressed(pkey->m_ekey, false);
// //////
// //////            }
// //////            catch(...)
// //////            {
// //////
// //////            }
// //////
// //////         }
// ////
// ////      }
// //
// //      pmessage->m_lresult = 0;
// //
// //      if(pmessage->m_emessage == e_message_mouse_leave)
// //      {
// //
// //         _000OnMouseLeave(pmessage);
// //
// //         return;
// //
// //      }
// //
// //      if(pmessage->m_emessage == e_message_left_button_down ||
// //            pmessage->m_emessage == e_message_left_button_up ||
// //            pmessage->m_emessage == e_message_middle_button_down ||
// //            pmessage->m_emessage == e_message_middle_button_up ||
// //            pmessage->m_emessage == e_message_right_button_down ||
// //            pmessage->m_emessage == e_message_right_button_up ||
// //            pmessage->m_emessage == e_message_mouse_move ||
// //            pmessage->m_emessage == e_message_mouse_move ||
// //         pmessage->m_emessage == e_message_mouse_wheel)
// //      {
// //
// //         if(::is_set(m_puserinteraction) && !m_puserinteraction->m_bUserElementOk)
// //         {
// //
// //            return;
// //
// //         }
// //
// //         ::pointer<::message::mouse>pmouse = pmessage;
// //
// //         
// //
// //         //if(pmouse)
// //         //{
// //
// //            if (psession != nullptr)
// //            {
// //
// //               psession->on_ui_mouse_message(pmouse);
// //
// //               psession->m_pointCursor = pmouse->m_pointAbsolute;
// //
// //            }
// //
// ////         if(m_puserinteraction != nullptr && m_puserinteraction->get_session()  != nullptr && m_puserinteraction->get_session() != get_session())
// ////         {
// ////
// ////            auto psystem = system();
// ////
// ////            auto psession = psystem->node();
// ////
// ////            psession->m_pointCursor = pmouse->m_point;
// ////
// ////         }
// //
// //            //if (m_bTranslateMouseMessageCursor && !pmouse->m_bTranslated)
// ////            if(false)
// ////            {
// ////               //pmouse->m_bTranslated = true;
// ////               ::int_rectangle rectWindow;
// //////            if(m_bScreenRelativeMouseMessagePosition)
// //////            {
// //////
// //////               INFO("Screen Relative Mouse Message Position");
// //////
// //////               ::int_rectangle rectWindow32;
// //////
// //////               ::window_rectangle((oswindow) get_handle(), &rectWindow32);
// //////
// //////               ::copy(rectWindow, rectWindow32);
// //////
// //////            }
// //////            else
// ////               {
// ////                  m_puserinteraction->window_rectangle(rectWindow);
// ////               }
// ////
// ////               auto puser = user();
// ////
// ////               auto pwindowing = system()->windowing();
// ////
// ////               auto pdisplay = pwindowing->display();
// ////
// ////               if (pdisplay->get_monitor_count() > 0)
// ////               {
// ////
// ////                  ::int_rectangle rcMonitor;
// ////
// ////                  pdisplay->get_monitor_rectangle(0, rcMonitor);
// ////
// ////                  if (rectWindow.left() >= rcMonitor.left())
// ////                  {
// ////
// ////                     pmouse->m_point.x() += (int) rectWindow.left();
// ////
// ////                  }
// ////
// ////                  if (rectWindow.top() >= rcMonitor.top())
// ////                  {
// ////
// ////                     pmouse->m_point.y() += (int) rectWindow.top();
// ////
// ////                  }
// ////
// ////               }
// ////               else
// ////               {
// ////
// ////                  if (rectWindow.left() >= 0)
// ////                  {
// ////
// ////                     pmouse->m_point.x() += (int) rectWindow.left();
// ////
// ////                  }
// ////
// ////                  if (rectWindow.top() >= 0)
// ////                  {
// ////
// ////                     pmouse->m_point.y() += (int) rectWindow.top();
// ////
// ////                  }
// ////
// ////               }
// ////
// ////            }
// //
// //         //}
// //
// //         auto puser = user();
// //
// //         auto pwindowing = system()->windowing();
// //
// //         pwindowing->set(pmouse, oswindow(), m_pwindow, pmouse->m_emessage, pmouse->m_wparam, pmouse->m_lparam);
// //
// //         if(pmessage->m_emessage == e_message_mouse_move)
// //         {
// //
// //            // We are at the message handler routine.
// //            // mouse messages originated from message handler and that are mouse transfer happenings should end up with the correct cursor.
// //            // So the routine starts by setting to the default cursor,
// //            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
// //            // handler has set it to another one.
// //
// //            m_puserinteraction->m_pinteractionimpl->_on_mouse_move_step(pmouse->m_pointAbsolute);
// //
// //         }
// //
// //         //_008OnMouse(pmouse);
// //
// //         ::user::interaction * puserinteractionMouse = nullptr;
// //
// //         if(m_puserinteractionMouseCapture)
// //         {
// //
// ////            if(g_puserinteractionMouseCapture123 == nullptr)
// ////            {
// ////
// ////               g_puserinteractionMouseCapture123 = m_puserinteractionCapture;
// ////
// ////            }
// ////            else if(g_puserinteractionMouseCapture123 != m_puserinteractionCapture)
// ////            {
// ////
// ////               informationf("different capture (1)");
// ////
// ////            }
// //
// //            puserinteractionMouse = m_puserinteractionMouseCapture;
// //
// //         }
// //
// ////         if(g_puserinteractionMouseCapture123 != nullptr)
// ////         {
// ////
// ////            if(g_puserinteractionMouseCapture123 != puserinteractionMouse)
// ////            {
// ////
// ////               informationf("different capture (2)");
// ////
// ////            }
// ////
// ////         }
// ////         else
// ////         {
// ////
// ////
// ////
// ////         }
// //
// //         if(pmouse->m_emessage == e_message_left_button_down)
// //         {
// //
// //
// //            informationf("left_button_down (A)");
// //
// //         }
// //
// //         if(!puserinteractionMouse)
// //         {
// //
// //            puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_pointAbsolute);
// //
// //         }
// //
// //         if(pmouse->m_emessage == e_message_left_button_down)
// //         {
// //
// //
// //            informationf("left_button_down");
// //
// //         }
// //         else if(pmouse->m_emessage == e_message_left_button_up)
// //         {
// //
// //
// //            informationf("left_button_up");
// //
// //         }
// //
// ////         string strUserInteractionType(::is_null(puserinteractionMouse) ? "(null)" : ::type(puserinteractionMouse).name());
// ////
// ////         if(pmouse->m_emessage == e_message_mouse_move)
// ////         {
// ////
// ////            static int s_iMotionNotify = 0;
// ////
// ////            s_iMotionNotify++;
// ////
// ////            if (strUserInteractionType.case_insensitive_contains("button"))
// ////            {
// ////
// ////               informationf("mouse_move::userinteraction=button");
// ////
// ////            }
// ////            else
// ////            {
// ////
// ////
// ////               puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_point);
// ////
// ////
// ////
// ////            }
// ////
// ////         }
// //
// //         if(puserinteractionMouse)
// //         {
// //
// //            do
// //            {
// //
// //               puserinteractionMouse->route_message(pmouse);
// //
// //               if(pmouse->m_bRet)
// //               {
// //
// //                  break;
// //
// //               }
// //
// //               puserinteractionMouse = puserinteractionMouse->get_parent();
// //
// //            }while(puserinteractionMouse != nullptr);
// //
// //         }
// //
// //         return;
// //
// //      }
// ///*      else if(pmessage->m_emessage == e_message_key_down ||
// //              pmessage->m_emessage == e_message_key_up ||
// //              pmessage->m_emessage == e_message_char)*/
// //      else if(bKeyMessage)
// //      {
// //
// //         ::pointer<::user::interaction>puiFocus =  aaa_m_pacmeuserinteractionKeyboardFocus;
// //
// //         if(puiFocus)
// //         {
// //
// //            puiFocus->route_message(pkey);
// //
// //         }
// //         else
// //         {
// //
// //             m_puserinteraction->route_message(pkey);
// //
// //         }
// //
// //         if(pmessage->m_bRet)
// //         {
// //
// //            return;
// //
// //         }
// //
// //         default_window_procedure(pmessage);
// //
// //         return;
// //
// //      }
// //
// //      if(pmessage->m_emessage == e_message_subject)
// //      {
// //
// //         if(m_puserinteraction != nullptr)
// //         {
// //
// //            m_puserinteraction->handle((::topic *) pmessage->m_lparam.m_lparam, nullptr);
// //
// //         }
// ////         else
// ////         {
// ////
// ////            on_control_event((::user::control_event *) pmessage->m_lparam.m_lparam);
// ////
// ////         }
// //
// //         return;
// //
// //      }
// //
// //      if(::is_set(m_puserinteraction))
// //      {
// //
// //         m_puserinteraction->route_message(pmessage);
// //
// //      }
// //      else
// //      {
// //
// //         route_message(pmessage);
// //
// //      }
// //
// //      if(pmessage->m_bRet)
// //      {
// //
// //         return;
// //
// //      }
// //
// //      default_window_procedure(pmessage);
// //
// //   }
//
//
// //   bool interaction_impl::OnCommand(wparam wparam, lparam lparam)
// //   {
// //
// //      __UNREFERENCED_PARAMETER(wparam);
// //      __UNREFERENCED_PARAMETER(lparam);
// //
// //      return false;
// //
// //   }
// //
// //
// //   bool interaction_impl::OnNotify(WPARAM, lparam lparam, LRESULT* pResult)
// //   {
// //
// //      return false;
// //
// //   }
//
//
// //   ::user::interaction * interaction_impl::get_parent()
// //   {
// //
// //      if(!::is_window((oswindow) get_handle()))
// //      {
// //
// //         return nullptr;
// //
// //      }
// //
// //      if(get_handle() == nullptr)
// //      {
// //
// //         return nullptr;
// //
// //      }
// //
// //      //return ::linux::interaction_impl::from_handle(::get_parent(get_handle()));
// //
// //      return nullptr;
// //
// //   }
//
//
// //   ::user::interaction * interaction_impl::get_top_level()
// //   {
// //
// //      if(!::is_window((oswindow) get_handle()))
// //         return nullptr;
// //
// //      if(get_handle() == nullptr)
// //         return nullptr;
// //
// //      return m_puserinteraction;
// //
// //   }
//
//
//    /*
//       ::user::interaction * interaction_impl::GetTopLevelOwner()
//       {
//          if (get_handle() == nullptr) // no oswindow attached
//             return nullptr;
//
//          ASSERT_VALID(this);
//
//    //      oswindow hWndOwner = get_handle();
//      //    oswindow hWndT;
//        //  while ((hWndT = ::GetWindow(hWndOwner, GW_OWNER)) != nullptr)
//          //   hWndOwner = hWndT;
//
//    //      return ::linux::interaction_impl::from_handle(hWndOwner);
//            return nullptr;
//       }
//
//       ::user::interaction * interaction_impl::GetParentOwner()
//       {
//          if (get_handle() == nullptr) // no oswindow attached
//             return nullptr;
//
//          ASSERT_VALID(this);
//
//    //         oswindow hWndParent = get_handle();
//    //         oswindow hWndT;
//    //         while ((::GetWindowLong(hWndParent, GWL_STYLE) & WS_CHILD) &&
//    //            (hWndT = ::get_parent(hWndParent)) != nullptr)
//    //         {
//    //            hWndParent = hWndT;
//    //         }
//    //
//    //         return ::linux::interaction_impl::from_handle(hWndParent);
//
//    //return nullptr;
//    //}
//
//    */
//
// //   bool interaction_impl::IsTopParentActive()
// //   {
// //      ASSERT(get_handle() != nullptr);
// //      ASSERT_VALID(this);
// //
// //      ::pointer<::user::interaction>WndTopLevel=EnsureTopLevel();
// //
// //      return interaction_impl::GetForegroundWindow() == pWndTopLevel->GetLastActivePopup();
// //   }
//
// //   void interaction_impl::ActivateTopParent()
// //   {
// //      // special activate logic for floating toolbars and palettes
// //      ::pointer<::user::interaction>pActiveWnd = GetForegroundWindow();
// ////      if (pActiveWnd == nullptr || !(LNX_WINDOW(pActiveWnd)->get_handle() == get_handle() || ::IsChild(LNX_WINDOW(pActiveWnd)->get_handle(), get_handle())))
// //      {
// //         // clicking on floating frame when it does not have
// //         // focus itself -- activate the toplevel frame instead.
// //         EnsureTopLevel()->set_foreground_window();
// //      }
// //   }
//
//    /*
//       ::pointer<::user::frame_window>interaction_impl::top_level_frame()
//       {
//          if (get_handle() == nullptr) // no oswindow attached
//             return nullptr;
//
//          ASSERT_VALID(this);
//
//          ::pointer<::user::frame_window>pFrameWnd = nullptr;
//          if(m_puserinteraction != this)
//             pFrameWnd =  (m_puserinteraction);
//          else
//             pFrameWnd =  (this);
//          if (pFrameWnd == nullptr || !pFrameWnd->is_frame_window())
//             pFrameWnd = get_parent_frame();
//
//          if (pFrameWnd != nullptr)
//          {
//             ::pointer<::user::frame_window>pTemp;
//             while ((pTemp = pFrameWnd->get_parent_frame()) != nullptr)
//                pFrameWnd = pTemp;
//          }
//          return pFrameWnd;
//       }*/
//
//    /*   ::pointer<::interaction_impl>interaction_impl::GetSafeOwner(::interaction_impl * pParent, oswindow* pWndTop)
//       {
//          oswindow hWnd = GetSafeOwner_((oswindow) pParent->get_handle(), pWndTop);
//          return ::linux::interaction_impl::from_handle(hWnd);
//       }
//    */
// //   int interaction_impl::message_box(const char * pszText, const char * pszcaption, unsigned int nType)
// //   {
// //
// //      string strCaption;
// //
// //      if (pszcaption == nullptr)
// //      {
// //
// //         strCaption = get_app()->m_strAppName;
// //
// //      }
// //      else
// //      {
// //
// //         strCaption = pszcaption;
// //
// //      }
// //
// //      int nResult = ::os_message_box((oswindow)get_handle(), pszText, strCaption, nType);
// //
// //      return nResult;
// //
// //   }
//
//
//    /////////////////////////////////////////////////////////////////////////////
//    // Scroll bar helpers
//    //  hook for interaction_impl functions
//    //    only works for derived class (eg: ::view) that override 'GetScrollBarCtrl'
//    // if the interaction_impl doesn't have a _visible_ windows scrollbar - then
//    //   look for a sibling with the appropriate ID
//
//
// //   int interaction_impl::SetScrollPos(int nBar, int nPos, bool bRedraw)
// //   {
// ////      return ::SetScrollPos(get_handle(), nBar, nPos, bRedraw);
// //      return 0;
// //   }
// //
// //   int interaction_impl::GetScrollPos(int nBar) const
// //   {
// //      //return ::GetScrollPos(get_handle(), nBar);
// //      return 0;
// //   }
// //
// //   void interaction_impl::SetScrollRange(int nBar, int nMinPos, int nMaxPos, bool bRedraw)
// //   {
// //      //::SetScrollRange(get_handle(), nBar, nMinPos, nMaxPos, bRedraw);
// //   }
//
// //   void interaction_impl::GetScrollRange(int nBar, LPINT pMinPos, LPINT lpMaxPos) const
// //
// //   {
// //      //::GetScrollRange(get_handle(), nBar, pMinPos, lpMaxPos);
// //
// //   }
// //
// //   // Turn on/off non-control scrollbars
// //   //   for WS_?SCROLL scrollbars - show/hide them
// //   //   for control scrollbar - enable/disable them
// //   void interaction_impl::EnableScrollBarCtrl(int nBar, bool bEnable)
// //   {
// //      // WS_?SCROLL scrollbar - show or hide
// //      ShowScrollBar(nBar, bEnable);
// //   }
//
//    /*
//       bool interaction_impl::SetScrollInfo(int nBar, LPSCROLLINFO pScrollInfo, bool bRedraw)
//
//       {
//          ASSERT(pScrollInfo != nullptr);
//
//
//          oswindow hWnd = get_handle();
//          pScrollInfo->cbSize = sizeof(*lpScrollInfo);
//
//          ::SetScrollInfo(hWnd, nBar, pScrollInfo, bRedraw);
//
//          return true;
//       }
//
//       bool interaction_impl::GetScrollInfo(int nBar, LPSCROLLINFO pScrollInfo, unsigned int nMask)
//
//       {
//          __UNREFERENCED_PARAMETER(nMask);
//          ASSERT(pScrollInfo != nullptr);
//
//
//          oswindow hWnd = get_handle();
//          return ::GetScrollInfo(hWnd, nBar, pScrollInfo) != false;
//
//       }
//    */
// //   int interaction_impl::GetScrollLimit(int nBar)
// //   {
// //      int nMin, nMax;
// //      GetScrollRange(nBar, &nMin, &nMax);
// //      /*      SCROLLINFO info;
// //            if (GetScrollInfo(nBar, &info, SIF_PAGE))
// //            {
// //               nMax -= maximum(info.nPage-1,0);
// //            }*/
// //      return nMax;
// //   }
// //
// //   void interaction_impl::ScrollWindow(int xAmount, int yAmount,
// //                                       const ::int_rectangle & rectangle, const ::int_rectangle & lpClipRect)
// //
// //   {
// //      /*      ASSERT(::is_window((oswindow) get_handle()));
// //
// //            if (is_window_visible() || prectangle != nullptr || lpClipRect != nullptr)
// //
// //            {
// //               // When visible, let oswindows do the scrolling
// //               ::ScrollWindow(get_handle(), xAmount, yAmount, prectangle, lpClipRect);
// //
// //            }
// //            else
// //            {
// //               // oswindows does not perform any scrolling if the interaction_impl is
// //               // not visible.  This leaves child windows unscrolled.
// //               // To account for this oversight, the child windows are moved
// //               // directly instead.
// //               oswindow hWndChild = ::GetWindow(get_handle(), GW_CHILD);
// //               if (hWndChild != nullptr)
// //               {
// //                  for (; hWndChild != nullptr;
// //                     hWndChild = ::GetNextWindow(hWndChild, GW_HWNDNEXT))
// //                  {
// //                     ::int_rectangle rectangle;
// //                     ::window_rectangle(hWndChild, &rectangle);
// //                     screen_to_client(&rectangle);
// //                     ::set_window_position(hWndChild, nullptr,
// //                        rectangle.left()+xAmount, rectangle.top()+yAmount, 0, 0,
// //                        SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER);
// //                  }
// //               }
// //            }
// //      */
// //   }
// //
// //
// //   void interaction_impl::CalcWindowRect(::int_rectangle * pClientRect, unsigned int nAdjustType)
// //   {
// //
// //      /*unsigned int dwExStyle = GetExStyle();
// //      if (nAdjustType == 0)
// //         dwExStyle &= ~WS_EX_CLIENTEDGE;
// //      ::AdjustWindowRectEx(pClientRect, GetStyle(), false, dwExStyle);*/
// //
// //   }
// //
// //   /////////////////////////////////////////////////////////////////////////////
// //   // Special keyboard/system command processing
// //
// //   bool interaction_impl::HandleFloatingSysCommand(unsigned int nID, lparam lparam)
// //
// //   {
// //      /*      ::pointer<::user::interaction>pParent = GetTopLevelParent();
// //            switch (nID & 0xfff0)
// //            {
// //            case SC_PREVWINDOW:
// //            case SC_NEXTWINDOW:
// //               if (LOWORD(lparam) == VK_F6 && pParent != nullptr)
// //
// //               {
// //                  pParent->XXXSetFocus();
// //                  return true;
// //               }
// //               break;
// //
// //            case SC_CLOSE:
// //            case SC_KEYMENU:
// //               // Check lparam.  If it is 0L, then the ::account::user may have done
// //
// //               // an Alt+Tab, so just ignore it.  This breaks the ability to
// //               // just press the Alt-key and have the first menu selected,
// //               // but this is minor compared to what happens in the Alt+Tab
// //               // case.
// //               if ((nID & 0xfff0) == SC_CLOSE || lparam != 0L)
// //
// //               {
// //                  if (pParent != nullptr)
// //                  {
// //                     // Sending the above WM_SYSCOMMAND may destroy the cast,
// //                     // so we have to be careful about restoring activation
// //                     // and focus after sending it.
// //                     oswindow hWndSave = get_handle();
// //                     oswindow hWndFocus = ::GetFocus();
// //                     pParent->XXXSetActiveWindow();
// //                     pParent->send_message(WM_SYSCOMMAND, nID, lparam);
// //
// //
// //                     // be very careful here...
// //                     if (::is_window(hWndSave))
// //                        ::XXXSetActiveWindow(hWndSave);
// //                     if (::is_window(hWndFocus))
// //                        ::XXXSetFocus(hWndFocus);
// //                  }
// //               }
// //               return true;
// //            }
// //            return false;*/
// //
// //      return false;
// //   }
//
//    void interaction_impl::on_message_create(::message::message * pmessage)
//    {
//
//       __UNREFERENCED_PARAMETER(pmessage);
//
// //      Default();
//
// //      if(m_puserinteraction->is_message_only_window())
// //      {
// //
// //         informationf("good : opt out!");
// //
// //      }
// //      else
// //      {
// //
// //         m_pthreadDraw = fork([&]()
// //         {
// //
// //
// //         });
// //
// //      }
// //
//    }
//
//
//
// //   bool CALLBACK interaction_impl::GetAppsEnumWindowsProc(oswindow hwnd, lparam lparam)
// //
// //   {
// //      user::oswindow_array * phwnda = (user::oswindow_array *) lparam;
// //
// //      phwnda->add(hwnd);
// //      return true;
// //   }
// //
// //   void interaction_impl::get_app_wnda(user::oswindow_array & wnda)
// //   {
// //      __s_throw(not_implemented());
// ////      EnumWindows(GetAppsEnumWindowsProc, (LPARAM) &wnda);
// //   }
//
// //   void interaction_impl::_001OnDeferPaintLayeredWindowBackground(::image::image *pimage)
// //   {
// //
// //      _001DeferPaintLayeredWindowBackground(pgraphics);
// //
// //   }
//
//
//
// //   class print_window :
// //      virtual ::object
// //   {
// //   public:
// //
// //
// //
// //      manual_reset_happening m_happening;
// //      oswindow m_hwnd;
// //      HDC m_hdc;
// //
// //      print_window(::particle * pparticle, oswindow hwnd, HDC hdc, unsigned int tickTimeout) :
// //         ::object(pparticle)
// //      {
// //         m_happening.reset_happening();
// //         m_hwnd = hwnd;
// //         m_hdc = hdc;
// //
// //         fork();
// //#undef timeout
// //
// //         if(m_happening.wait(millis(tickTimeout)).timeout())
// //         {
// //            informationf("print_window::time_out");
// //         }
// //      }
// //
// //
// //      virtual ::e_status     run() override
// //      {
// //
// //         try
// //         {
// ////            HANDLE hevent = (HANDLE) pprintwindow->m_happening.get_os_data();
// //            //          throw ::not_implemented();
// //            /*            ::PrintWindow(pprintwindow->m_hwnd, pprintwindow->m_hdc, 0);
// //                        ::SetEvent(hevent);*/
// //         }
// //         catch(...)
// //         {
// //         }
// //         return ::success;
// //      }
// //   };
// //
// //   void interaction_impl::_001DeferPaintLayeredWindowBackground(HDC hdc)
// //   {
// //
// //      ::int_rectangle rectClient;
// //
// //      m_puserinteraction->rectangle(rectClient);
// //
// //
// //      //pgraphics->FillSolidRect(rectClient, 0x00000000);
// //
// //      //return;
// //      ::int_rectangle rectUpdate;
// //      m_puserinteraction->window_rectangle(rectUpdate);
// ////      SetContextOrgEx(hdc, 0, 0, nullptr);
// //      ::int_rectangle rectPaint;
// //      rectPaint = rectUpdate;
// //      m_puserinteraction->screen_to_client(rectPaint);
// //      user::oswindow_array wndaApp;
// //
// //
// //      HRGN rgnWindow;
// //      HRGN rgnIntersect;
// //      HRGN rgnUpdate = nullptr;
// //
// //      throw ::not_implemented();
// //      /*
// //            rgnWindow = CreateRectRgn(0, 0, 0, 0);
// //            rgnIntersect = CreateRectRgn(0, 0, 0, 0);
// //      */
// //      //      int iCount = wndaApp.get_count();
// //
// //      throw ::not_implemented();
// //   }
// //
// //   void interaction_impl::_001OnProdevianSynch(::message::message * pmessage)
// //   {
// //      __UNREFERENCED_PARAMETER(pmessage);
// //   }
//
//
//    void interaction_impl::_001OnPaint(::message::message * pmessage)
//    {
//
//       set_need_redraw();
//
//       //m_puserinteraction->defer_start_prodevian();
//
//    }
//
//
//    void interaction_impl::_001OnPrint(::message::message * pmessage)
//    {
//
//       set_need_redraw();
//
//    }
//
//
//    bool interaction_impl::_is_window()
//    {
//
//       if(::is_null(m_pwindow))
//       {
//
//          return false;
//
//       }
//
//       return m_pwindow->is_window();
//
//    }
//
//
// //   oswindow interaction_impl::get_handle() const
// //   {
// //
// //      return m_oswindow;
// //
// //   }
//
//
//    void interaction_impl::_001OnAfterExitIconic()
//    {
//
//       if(!m_pwindow)
//       {
//
//          return;
//
//       }
//
// //      
// //
// //      auto puser = user();
// //
// //      auto pwindowing = system()->windowing();
// //
// //      if(pwindowing)
// //      {
//
//          user_post([this]()
//                           {
//
//                              m_pwindow->exit_iconify();
//
//                           });
//
//       //}
//
//    }
//
//
//    void interaction_impl::_001OnAfterExitFullScreen()
//    {
//
//       if(!m_pwindow)
//       {
//
//          return;
//
//       }
//
// //      
// //
// //      auto puser = user();
// //
// //      auto pwindowing = system()->windowing();
// //
// //      if(pwindowing)
// //      {
//
//          user_post([this]()
//          {
//
//             m_pwindow->exit_full_screen();
//
//          });
//
//       //}
//
//    }
//
//
//    void interaction_impl::_001OnAfterExitZoomed()
//    {
//
// //      if(!m_pwindow)
// //      {
// //
// //         return;
// //
// //      }
// //
// //      
// //
// //      auto puser = user();
// //
// //      auto pwindowing = system()->windowing();
// //
// //      if(pwindowing)
// //      {
// //
// //         pwindowing->windowing_post([this]()
// //         {
// //
// //            m_pwindow->exit_zoomed();
// //
// //         });
// //
// //      }
//
//    }
//
//
//
// //   bool interaction_impl::node_is_iconic()
// //   {
// //
// //      if(!::is_window(m_oswindow))
// //      {
// //
// //         return false;
// //
// //      }
// //
// //#ifdef LINUX
// //
// //      return m_puserinteraction->layout().design().display() == ::e_display_iconic;
// //
// //#else
// //
// //      if(GetExStyle() & WS_EX_LAYERED)
// //      {
// //
// //         return m_puserinteraction->m_edisplay == ::e_display_iconic;
// //
// //      }
// //      else
// //      {
// //
// //         return ::is_iconic((oswindow) get_handle()) != false;
// //
// //      }
// //
// //#endif
// //
// //   }
// //
// ////
// ////   iptr interaction_impl::get_window_long_ptr(int nIndex) const
// ////   {
// ////
// ////      return get_window_long(nIndex);
// ////
// ////   }
// ////
// ////
// ////   iptr interaction_impl::set_window_long_ptr(int nIndex, iptr lValue)
// ////   {
// ////
// ////      return set_window_long(nIndex, lValue);
// ////
// ////   }
// ////
// //
// //
// //
// //
// //   // interaction_impl
// //   /* interaction_impl::operator oswindow() const
// //   { return this == nullptr ? nullptr : get_handle(); }*/
// //   bool interaction_impl::operator==(const ::windowing::window& wnd) const
// //   {
// //      return wnd.get_handle() ==((interaction_impl *)this)->get_handle();
// //   }
// //
// //   bool interaction_impl::operator!=(const ::windowing::window& wnd) const
// //   {
// //      return wnd.get_handle() != ((interaction_impl *)this)->get_handle();
// //   }
// //
// //   unsigned int interaction_impl::GetStyle() const
// //   {
// //
// //      return (unsigned int)get_window_long(GWL_STYLE);
// //
// //   }
// //
// //
// //   unsigned int interaction_impl::GetExStyle() const
// //   {
// //
// //      return (unsigned int)get_window_long(GWL_EXSTYLE);
// //
// //   }
//
//
// //   bool interaction_impl::ModifyStyle(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
// //   {
// //
// //      set_window_long(GWL_STYLE, (GetStyle() | dwAdd) & ~(dwRemove));
// //
// //      if(nFlags != 0)
// //      {
// //
// //         //set_window_position(0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOMOVE | nFlags);
// //         set_need_redraw();
// //
// //      }
// //
// //      return true;
// //
// //   }
// //
// //
// //   bool interaction_impl::ModifyStyleEx(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
// //   {
// //
// //      set_window_long(GWL_EXSTYLE, (GetExStyle() | dwAdd) & ~(dwRemove));
// //
// //      if(nFlags != 0)
// //      {
// //
// //         //set_window_position(0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOMOVE | nFlags);
// //         set_need_redraw();
// //
// //      }
// //
// //      return true;
// //
// //   }
// //
// //
// //   ::user::interaction_base * interaction_impl::set_owner(::user::interaction_base * pprimitiveOwner)
// //   {
// //
// //      auto puserinteraction = m_puserinteraction;
// //
// //      if(::is_null(puserinteraction))
// //      {
// //
// //         return nullptr;
// //
// //      }
// //
// //      auto puserinteractionOwner = puserinteraction->m_puserinteractionOwner;
// //
// //      if(::is_null(puserinteractionOwner))
// //      {
// //
// //         return nullptr;
// //
// //      }
// //
// //      return puserinteractionOwner;
// //
// //   }
//
//
// //   LRESULT interaction_impl::send_message(const ::id & id, wparam wparam, lparam lparam)
// //   {
// //
// //      return ::windowing::window::send_message(id, wparam, lparam);
// //
// //   }
//
//
// //   bool interaction_impl::aaa_post_message(const ::id & id, wparam wparam, lparam lparam)
// //   {
// //
// ////      if(::is_set(m_pwindowthread))
// ////      {
// ////
// ////         return ::windowing::window::aaa_post_message(message, wparam, lparam);
// ////
// ////      }
// ////
// //      return ::aaa_post_message((oswindow) get_handle(), id, wparam, lparam) != false;
// //
// //   }
//
//
// //   bool interaction_impl::DragDetect(const ::int_point & point) const
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //
// //      //return ::DragDetect(get_handle(), int_point) != false;
// //
// //   }
// //
//
//
// //   void interaction_impl::set_window_text(const ::string & strText)
// //   {
// //
// //      m_strWindowText = strText;
// //
// //      //windowing_output_debug_string("\nlinux::interaction_impl::set_window_text");
// //
// //      //fflush(stdout);
// //
// ////      x11_store_name(m_oswindow, m_strWindowText);
// //
// //      //windowing_output_debug_string("\nlinux::interaction_impl::set_window_text END");
// //
// //      //fflush(stdout);
// //
// //   }
//
//
// //   character_count interaction_impl::GetWindowText(char * pszString, character_count nMaxCount)
//
// //   {
// //
// //      ansi_count_copy(pszString, m_strWindowText, nMaxCount);
//
// //
// //      return minimum(nMaxCount, m_strWindowText.length());
// //
// //   }
//
// //
// //   character_count interaction_impl::GetWindowTextLength()
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //
// //      //return ::GetWindowTextLength(get_handle());
// //
// //   }
//
//
//    void interaction_impl::SetFont(::write_text::font* pfont, bool bRedraw)
//    {
//
//       __UNREFERENCED_PARAMETER(bRedraw);
//
//       //ASSERT(::is_window((oswindow) get_handle())); m_pfont = ___new ::write_text::font(*pfont);
//
//    }
//
//
//    ::write_text::font* interaction_impl::GetFont()
//    {
//
//       //ASSERT(::is_window((oswindow) get_handle()));
//
//       //return m_pfont;
//       return nullptr;
//
//    }
//
//
// //   void interaction_impl::DragAcceptFiles(bool bAccept)
// //   {
// //
// //      throw ::not_implemented();
// //
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::DragAcceptFiles(get_handle(), bAccept);
// //
// //   }
// //
// //   /*
// //      ::pointer<::user::frame_window>interaction_impl::EnsureParentFrame()
// //      {
// //
// //         ::pointer<::user::frame_window>pFrameWnd=get_parent_frame();
// //
// //         ENSURE_VALID(pFrameWnd);
// //
// //         return pFrameWnd;
// //
// //      }
// //
// //
// //      ::user::interaction * interaction_impl::EnsureTopLevelParent()
// //      {
// //
// //         ::pointer<::user::interaction>Wnd=GetTopLevelParent();
// //
// //         ENSURE_VALID(pWnd);
// //
// //         return pWnd;
// //
// //      }
// //
// //   */
// //
// //
// ////   void interaction_impl::MoveWindow(const ::int_rectangle & rectangle, bool bRepaint)
// ////   {
// ////
// ////      MoveWindow(rectangle.left(), rectangle.top(), rectangle.right() - rectangle.left(), rectangle.bottom() - rectangle.top(), bRepaint);
// ////
// ////   }
// //
// //
// //   unsigned int interaction_impl::ArrangeIconicWindows()
// //   {
// //
// //      throw ::not_implemented();
// //
// ////      ASSERT(::is_window((oswindow) get_handle())); return ::ArrangeIconicWindows(get_handle());
// //
// //   }
// //
// //
// //   int interaction_impl::SetWindowRgn(HRGN hRgn, bool bRedraw)
// //   {
// //
// //      __UNREFERENCED_PARAMETER(hRgn);
// //      __UNREFERENCED_PARAMETER(bRedraw);
// //
// //      //throw ::not_implemented();
// //
// ////      ASSERT(::is_window((oswindow) get_handle())); return ::SetWindowRgn(get_handle(), hRgn, bRedraw);
// //      return 0;
// //   }
// //
// //
// //   int interaction_impl::GetWindowRgn(HRGN hRgn)
// //   {
// //
// //      throw ::not_implemented();
// //
// ////      ASSERT(::is_window((oswindow) get_handle()) && hRgn != nullptr); return ::GetWindowRgn(get_handle(), hRgn);
// //
// //   }
// //
// //
// //   bool interaction_impl::BringWindowToTop()
// //   {
// //
// ////      throw ::not_implemented();
// ////      return ::BringWindowToTop(get_handle()) != false;
// //      return true;
// //   }
// //
// //
// //   void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, ::int_point * pPoint, unsigned int nCount)
// //
// //   {
// //
// //      throw ::not_implemented();
// //
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_handle(), pPoint, nCount);
// //
// //
// //   }
// //
// //
// //   void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, ::int_rectangle * prectangle)
// //
// //   {
// //
// //      throw ::not_implemented();
// //
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_handle(), (::int_point *)prectangle, 2);
// //
// //
// //   }
//
//
// //   ::draw2d::graphics * interaction_impl::GetDC()
// //   {
// //
// //      ::draw2d::graphics_pointer g(e_create);
// //
// //      windowing_output_debug_string("\nlinux::interaction_impl::GetDC");
// //
// //      fflush(stdout);
// //
// //      xdisplay d(m_oswindow->display());
// //
// //      oswindow oswindow;
// //
// //      if(get_handle() == nullptr)
// //      {
// //
// ////         oswindow = ::get_desktop_window();
// //
// //      }
// //      else
// //      {
// //
// //         oswindow = (::oswindow) get_handle();
// //
// //      }
// //
// //      ::int_rectangle rectClient;
// //
// //      //oswindow->rectangle(rectClient);
// //
// //      rectClient.left() = 0;
// //      rectClient.top() = 0;
// //      rectClient.right() = 500;
// //      rectClient.bottom() = 500;
// ////      (dynamic_cast < ::linux::graphics * >(g.m_p))->attach(cairo_create(cairo_xlib_surface_create(oswindow->display(), oswindow->interaction_impl(), oswindow->draw2d(),rectClient.width(), rectClient.height())));
// //
// //      windowing_output_debug_string("\nlinux::interaction_impl::GetDC END");
// //
// //      fflush(stdout);
// //
// //      return g.detach();
// //
// //   }
// //
// //
// //   ::draw2d::graphics * interaction_impl::GetWindowDC()
// //   {
// //      ASSERT(::is_window((oswindow) get_handle()));
// //      //::draw2d::graphics_pointer g(e_create);
// //      //g->attach(::GetWindowDC(get_handle()));
// //      //return g.detach();
// //      return nullptr;
// //   }
// //
// //   bool interaction_impl::ReleaseDC(::image::image *pimage)
// //   {
// //
// //      if(pimage->is_null())
// //         return false;
// //
// //      /*      cairo_t * pcairo = (cairo_t *) pgraphics->get_os_data();
// //
// //            cairo_surface_t * psurface = cairo_get_target(pcairo);
// //      	if(pcairo ==  g_cairo)
// //      	{
// //               printf("123");
// //
// //      	}
// //
// //            cairo_destroy(pcairo);
// //
// //      if(psurface == g_cairosurface)
// //      {
// //         printf("123");
// //      }      cairo_surface_destroy(psurface);*/
// //
// ////      if(((Gdiplus::Graphics *)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle()) == nullptr)
// //      //       return false;
// //
// //      //::ReleaseDC(get_handle(), (dynamic_cast < ::linux::graphics * > (pgraphics))->detach());
// //
// ////      (dynamic_cast<::linux::graphics * >(pgraphics))->m_hdc = nullptr;
// //
// ////      pgraphics->release();
// //
// //      return true;
// //
// //   }
// //
// //   void interaction_impl::UpdateWindow()
// //   {
// //      //throw ::not_implemented();
// //      //::UpdateWindow(get_handle());
// //   }
// //
// //   void interaction_impl::SetRedraw(bool bRedraw)
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::SendMessage(get_handle(), WM_SETREDRAW, bRedraw, 0);
// //   }
// //
// //   bool interaction_impl::GetUpdateRect(::int_rectangle * prectangle, bool bErase)
// //
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::GetUpdateRect(get_handle(), prectangle, bErase) != false;
// //
// //   }
// //
// //   int interaction_impl::GetUpdateRgn(draw2d::region * pRgn, bool bErase)
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::GetUpdateRgn(get_handle(), (HRGN)pRgn->get_handle(), bErase);
// //   }
// //
// //   void interaction_impl::Invalidate(bool bErase)
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::InvalidateRect(get_handle(), nullptr, bErase);
// //   }
// //
// //   void interaction_impl::InvalidateRect(const ::int_rectangle & rectangle, bool bErase)
// //
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::InvalidateRect(get_handle(), prectangle, bErase);
// //
// //   }
// //
// //   void interaction_impl::InvalidateRgn(::draw2d::region* pRgn, bool bErase)
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::InvalidateRgn(get_handle(), (HRGN)pRgn->get_handle(), bErase);
// //   }
// //
// //   void interaction_impl::ValidateRect(const ::int_rectangle & rectangle)
// //
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::ValidateRect(get_handle(), prectangle);
// //
// //   }
// //
// //   void interaction_impl::ValidateRgn(::draw2d::region* pRgn)
// //   {
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::ValidateRgn(get_handle(), (HRGN)pRgn->get_handle());
// //   }
//
//
// //   bool interaction_impl::_is_window_visible()
// //   {
// //
// //      if(!m_puserinteraction->is_this_visible())
// //      {
// //
// //         return false;
// //
// //      }
// //
// //      if(m_puserinteraction->m_puserinteractionParent != nullptr)
// //      {
// //
// //         if(!m_puserinteraction->m_puserinteractionParent->is_window_visible())
// //         {
// //
// //            return false;
// //
// //         }
// //
// //      }
// //
// //      return true;
// //
// //   }
//
//
// //   void interaction_impl::ShowOwnedPopups(bool bShow)
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::ShowOwnedPopups(get_handle(), bShow);
// //
// //   }
// //
// ////   void interaction_impl::send_message_to_descendants(const ::id & id, wparam wparam, lparam lparam, bool bDeep, bool bOnlyPerm)
// //
// ////   {
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      //interaction_impl::send_message_to_descendants(get_handle(), message, wparam, lparam, bDeep, bOnlyPerm);
// //
// ////
// ////      // walk through oswindows to avoid creating temporary interaction_impl objects
// ////      // unless we need to call this function recursively
// ////      user::interaction * pinteraction = m_puserinteraction->first_child();
// ////      while(pinteraction != nullptr)
// ////      {
// ////         try
// ////         {
// ////            pinteraction->send_message(message, wparam, lparam);
// //
// ////         }
// ////         catch(...)
// ////         {
// ////         }
// ////         if (bDeep)
// ////         {
// ////            // send to child windows after parent
// ////            try
// ////            {
// ////               pinteraction->send_message_to_descendants(message, wparam, lparam, bDeep, bOnlyPerm);
// //
// ////            }
// ////            catch(...)
// ////            {
// ////            }
// ////         }
// ////         try
// ////         {
// ////            pinteraction = pinteraction->next_sibling();
// ////         }
// ////         catch(...)
// ////         {
// ////            break;
// ////         }
// ////      }
// ////   }
// ////
// //
// //   ::draw2d::graphics * interaction_impl::GetDCEx(::draw2d::region * prgnClip, unsigned int flags)
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::draw2d::graphics_pointer g(this);
// //      //g->attach(::GetDCEx(get_handle(), (HRGN)prgnClip->get_handle(), flags));
// //      //return g.detach();
// //
// //   }
// //
// //   bool interaction_impl::LockWindowUpdate()
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::LockWindowUpdate(get_handle()) != false;
// //
// //   }
// //
// //   void interaction_impl::UnlockWindowUpdate()
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //::LockWindowUpdate(nullptr);
// //
// //   }
// //
//
// //   bool interaction_impl::RedrawWindow(const ::int_rectangle& rectUpdate, ::draw2d::region * prgnUpdate, unsigned int flags)
// //   {
// //
// ////      ASSERT(::is_window((oswindow) get_handle()));
// //
// //      if(flags & RDW_UPDATENOW)
// //      {
// //
// //         _001UpdateWindow();
// //
// //      }
// //      else
// //      {
// //
// //         m_puserinteraction->m_bRedraw = true;
// //
// //      }
// //
// //      return true;
// //
// //   }
//
//    /*
//       bool interaction_impl::EnableScrollBar(int nSBFlags, unsigned int nArrowFlags)
//       {
//
//          ASSERT(::is_window((oswindow) get_handle()));
//
//          return ::EnableScrollBar(get_handle(), nSBFlags, nArrowFlags) != false;
//
//       }
//    */
//
// //   bool interaction_impl::DrawAnimatedRects(int idAni, const LPRECTprcFrom, const LPRECTlprcTo)
// //
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::DrawAnimatedRects(get_handle(), idAni, prcFrom, lprcTo) != false;
// //
// //
// //   }
//
//
// //   bool interaction_impl::DrawCaption(::draw2d::graphics_pointer & pgraphics, const int_rectangle & prc, unsigned int uFlags)
// //
// //   {
// //
// //      throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::DrawCaption(get_handle(), (HDC)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle(), prc, uFlags) != false;
// //
// //
// //   }
// //
// //
// //   bool interaction_impl::set_timer(uptr uEvent, unsigned int nElapse, PFN_TIMER pfnTimer)
// //   {
// //
// //      return ::windowing::window::set_timer(uEvent, nElapse, pfnTimer);
// //
// //
// ////        __UNREFERENCED_PARAMETER(pfnTimer);
// //
// ////
// ////        m_puserinteraction->get_app()->set_timer(m_puserinteraction, uEvent, nElapse);
// ////
// ////        return uEvent;
// //
// //      //throw ::not_implemented();
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::set_timer(get_handle(), uEvent, nElapse, pfnTimer);
// //
// //
// //   }
// //
// //
// //   bool interaction_impl::kill_timer(uptr uEvent)
// //   {
// //
// //      return ::windowing::window::kill_timer(uEvent);
// //
// ////       m_puserinteraction->get_app()->unset_timer(m_puserinteraction, uEvent);
// //
// //      //     return true;
// //
// //      //return ::user::int
// //
// //      //ASSERT(::is_window((oswindow) get_handle()));
// //      //return ::kill_timer(get_handle(), uEvent)  != false;
// //
// //   }
//
//
//    bool interaction_impl::IsWindowEnabled()
//    {
//
//       return m_bEnabled;
//
//    }
//
//
//    bool interaction_impl::EnableWindow(bool bEnable)
//    {
//
//       return m_bEnabled = bEnable;
//
//    }
//
//
// //   ::user::interaction * interaction_impl::GetActiveWindow()
// //   {
// //
// //      oswindow oswindow = nullptr;
// //
// //      x11_sync([&]()
// //      {
// //
// //         oswindow = ::get_active_window();
// //
// //      });
// //
// //      if(oswindow == nullptr)
// //      {
// //
// //         return nullptr;
// //
// //      }
// //
// //      ::windowing::window * pimpl = ::linux::interaction_impl::from_handle(oswindow);
// //
// //      if(pimpl == nullptr)
// //      {
// //
// //         return nullptr;
// //
// //      }
// //
// //      return pimpl->m_puserinteraction;
// //
// //   }
//
//
// //   ::user::interaction * interaction_impl::XXXSetActiveWindow()
// //   {
// //
// //      return nullptr;
// //
// //
// ////      ::windowing::window * pimpl = ::linux::interaction_impl::from_handle(::set_active_window(get_handle()));
// //
// //  //    if(pimpl == nullptr)
// //    //  {
// //
// //      //   return nullptr;
// //
// //      //}
// //
// //      //return pimpl->m_puserinteraction;
// //
// //   }
//
//
// //   ::user::interaction * interaction_impl::get_keyboard_focus()
// //   {
// //
// //      return __user_interaction(m_pprimitiveFocus);
// //
// //   }
//
//
// //   ::e_status interaction_impl::set_keyboard_focus()
// //   {
// //
// //      auto estatus = ::windowing::window::set_keyboard_focus();
// //
// //      return estatus;
// ////
// ////
// ////      oswindow w = ::set_focus(get_handle());
// ////
// ////      if(w  == nullptr)
// ////      {
// ////
// ////         return false;
// ////
// ////      }
// ////
// ////      return true;
// //
// //   }
//
//
// //   ::user::interaction * interaction_impl::get_desktop_window()
// //   {
// //      /*
// //            return ::linux::interaction_impl::from_handle(::get_desktop_window());
// //      */
// //      return nullptr;
// //   }
//
//
// //   // Helper for radio buttons
// //   int interaction_impl::GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton)
// //   {
// //      for (int nID = nIDFirstButton; nID <= nIDLastButton; nID++)
// //      {
// //         if (IsDlgButtonChecked(nID))
// //            return nID; // id that matched
// //      }
// //      return 0; // invalid ID
// //   }
// //
// //   void interaction_impl::CheckDlgButton(int nIDButton, unsigned int nCheck)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::CheckDlgButton(get_handle(), nIDButton, nCheck);
// //
// //   }
// //
// //   void interaction_impl::CheckRadioButton(int nIDFirstButton, int nIDLastButton, int nIDCheckButton)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::CheckRadioButton(get_handle(), nIDFirstButton, nIDLastButton, nIDCheckButton);
// //
// //   }
// //
// //   int interaction_impl::DlgDirList(char * pPathSpec, int nIDListBox, int nIDStaticPath, unsigned int nFileType)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::DlgDirList(get_handle(), pPathSpec, nIDListBox, nIDStaticPath, nFileType);
// //
// //
// //   }
// //
// //   int interaction_impl::DlgDirListComboBox(char * pPathSpec, int nIDComboBox, int nIDStaticPath, unsigned int nFileType)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::DlgDirListComboBox(get_handle(), pPathSpec, nIDComboBox, nIDStaticPath, nFileType);
// //
// //
// //   }
// //
// //   bool interaction_impl::DlgDirSelect(char * pString, int nSize, int nIDListBox)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::DlgDirSelectEx(get_handle(), pString, nSize, nIDListBox) != false;
// //
// //
// //   }
// //
// //   bool interaction_impl::DlgDirSelectComboBox(char * pString, int nSize, int nIDComboBox)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::DlgDirSelectComboBoxEx(get_handle(), pString, nSize, nIDComboBox) != false;
// //
// //
// //   }
// //
// //   /*
// //      void interaction_impl::GetDlgItem(id id, oswindow* phWnd) const
// //      {
// //
// //         ASSERT(::is_window((oswindow) get_handle()));
// //         ASSERT(phWnd != nullptr);
// //         *phWnd = ::GetDlgItem(get_handle(), (int) id);
// //
// //      }
// //   */
// //
// //   /*
// //      unsigned int interaction_impl::GetDlgItemInt(int nID, int_bool * pTrans, bool bSigned) const
// //
// //      {
// //
// //         ASSERT(::is_window((oswindow) get_handle()));
// //
// //         return ::GetDlgItemInt(get_handle(), nID, pTrans, bSigned);
// //
// //
// //      }
// //   */
// //
// ////   int interaction_impl::GetDlgItemText(int nID, char * pStr, int nMaxCount) const
// //
// ////   {
// ////
// ////      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle())); return ::GetDlgItemText(get_handle(), nID, pStr, nMaxCount);}
// //
// //
// //   ::user::interaction * interaction_impl::GetNextDlgGroupItem(::user::interaction * pWndCtl, bool bPrevious) const
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::GetNextDlgGroupItem(get_handle(), (oswindow) pWndCtl->get_handle(), bPrevious));
// //
// //   }
// //
// //   ::user::interaction * interaction_impl::GetNextDlgTabItem(::user::interaction * pWndCtl, bool bPrevious) const
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::GetNextDlgTabItem(get_handle(), (oswindow) pWndCtl->get_handle(), bPrevious));
// //
// //   }
// //
// //   unsigned int interaction_impl::IsDlgButtonChecked(int nIDButton) const
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::IsDlgButtonChecked(get_handle(), nIDButton);
// //
// //   }
// //
// //   LPARAM interaction_impl::SendDlgItemMessage(int nID, const ::id & id, wparam wparam, lparam lparam)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::SendDlgItemMessage(get_handle(), nID, message, wparam, lparam);
// //
// //
// //   }
// //
// //   void interaction_impl::SetDlgItemInt(int nID, unsigned int nValue, bool bSigned)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::SetDlgItemInt(get_handle(), nID, nValue, bSigned);
// //
// //   }
// //
// //   void interaction_impl::SetDlgItemText(int nID, const char * pszString)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::SetDlgItemText(get_handle(), nID, pszString);
// //
// //
// //   }
// //
// //   int interaction_impl::ScrollWindowEx(int dx, int dy, const int_rectangle & pRectScroll, const int_rectangle & lpRectClip, ::draw2d::region * prgnUpdate, ::int_rectangle * lpRectUpdate, unsigned int flags)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::ScrollWindowEx(get_handle(), dx, dy, pRectScroll, lpRectClip, (HRGN)prgnUpdate->get_handle(), lpRectUpdate, flags);
// //
// //
// //   }
// //
// //   void interaction_impl::ShowScrollBar(unsigned int nBar, bool bShow)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::ShowScrollBar(get_handle(), nBar, bShow);
// //
// //   }
// //
// //   ::user::interaction * interaction_impl::ChildWindowFromPoint(const ::int_point & point)
// //   {
// //
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::ChildWindowFromPoint(get_handle(), int_point));
// //
// //   }
// //
// //   ::user::interaction * interaction_impl::ChildWindowFromPoint(const ::int_point & point, unsigned int nFlags)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::ChildWindowFromPointEx(get_handle(), point, nFlags));
// //
// //   }
// //
// //
// //
// //
// //
// //
// //   ::user::interaction * interaction_impl::GetTopWindow() const
// //   {
// //
// //      if(m_puserinteraction->m_uiptraChild.get_size() <= 0)
// //         return nullptr;
// //
// //      return m_puserinteraction->m_uiptraChild[0];
// //      //  throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::GetTopWindow(get_handle()));
// //
// //   }
// //
// //   ::user::interaction * interaction_impl::GetWindow(unsigned int nCmd)
// //   {
// //
// //      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::GetWindow(get_handle(), nCmd));
// //      return nullptr;
// //
// //   }
// //
// //   ::user::interaction * interaction_impl::GetLastActivePopup()
// //   {
// //
// //
// //      __throw(todo);
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::linux::interaction_impl::from_handle(::GetLastActivePopup(get_handle()));
// //
// //   }
// //
//
// //   ::user::interaction * interaction_impl::SetParent(::user::interaction * pWndNewParent)
// //   {
// //
// //      ASSERT(::is_window((oswindow) get_handle()));
// //
// //      return ::linux::interaction_impl::from_handle(::SetParent(get_handle(), (oswindow) pWndNewParent->get_handle()))->m_puserinteraction;
// //
// //   }
// //
// //
// //   ::user::interaction * PASCAL interaction_impl::oswindowFromPoint(const ::int_point & point)
// //   {
// //
// //      __s_throw(not_implemented());
// ////      return ::linux::interaction_impl::from_handle(::oswindowFromPoint(point));
// //
// //   }
// //
// //
// //   bool interaction_impl::FlashWindow(bool bInvert)
// //   {
// //
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::FlashWindow(get_handle(), bInvert) != false;
// //
// //   }
// //
// //   bool interaction_impl::ChangeClipboardChain(oswindow hWndNext)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::ChangeClipboardChain(get_handle(), hWndNext) != false;
// //
// //   }
// //
// //   oswindow interaction_impl::SetClipboardViewer()
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::SetClipboardViewer(get_handle());
// //
// //   }
// //
// //   bool interaction_impl::OpenClipboard()
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::OpenClipboard(get_handle()) != false;
// //
// //   }
// //
// //
// //   ::user::interaction * PASCAL interaction_impl::GetOpenClipboardWindow()
// //   {
// //
// //      __s_throw(not_implemented());
// ////      return ::linux::interaction_impl::from_handle(::GetOpenClipboardWindow());
// //
// //   }
// //
// //
// //   ::user::interaction * PASCAL interaction_impl::GetClipboardOwner()
// //   {
// //
// //      __s_throw(not_implemented());
// ////      return ::linux::interaction_impl::from_handle(::GetClipboardOwner());
// //
// //   }
// //
// //
// //   ::user::interaction * PASCAL interaction_impl::GetClipboardViewer()
// //   {
// //
// //      __s_throw(not_implemented());
// ////      return ::linux::interaction_impl::from_handle(::GetClipboardViewer());
// //
// //   }
// //
// //
// //
// //
// //
// //   int_point PASCAL interaction_impl::GetCaretPos()
// //   {
// //
// //      __s_throw(not_implemented());
// ////      const ::int_point & point;
// ////      ::GetcaretPos((::int_point *)&point); return point;
// //
// //   }
// //
// //
// //   void PASCAL interaction_impl::SetCaretPos(const ::int_point & point)
// //   {
// //
// //      __s_throw(not_implemented());
// ////      ::SetcaretPos(point.x, point.y);
// //
// //   }
// //
// //
// //   void interaction_impl::HideCaret()
// //   {
// //
// //      throw ::not_implemented();
// ////      ::Hidecaret(get_handle());
// //
// //   }
// //
// //   void interaction_impl::ShowCaret()
// //   {
// //
// //      throw ::not_implemented();
// ////    ::Showcaret(get_handle());
// //   }
// //
//
//
// //   bool interaction_impl::set_foreground_window()
// //   {
// //
// //      return ::set_foreground_window(get_handle()) != false;
// //
// //   }
//
// //
// //
// //   ::user::interaction * PASCAL interaction_impl::GetForegroundWindow()
// //   {
// //
// //      return nullptr;
// //
// //      __s_throw(not_implemented());
// ////      return ::linux::interaction_impl::from_handle(::GetForegroundWindow());
// //
// //   }
// //
// //
// //   bool interaction_impl::SendNotifyMessage(const ::id & id, wparam wparam, lparam lparam)
// //
// //   {
// //
// //      throw ::not_implemented();
// ////      return ::SendNotifyMessage(get_handle(), message, wparam, lparam) != false;
// //
// //
// //   }
// //
// //   void interaction_impl::Print(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      const_cast < interaction_impl * > (this)->send_message(WM_PRINT, (WPARAM)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle(), dwFlags);
// //
// //   }
// //
// //   void interaction_impl::PrintClient(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      const_cast < interaction_impl * > (this)->send_message(WM_PRINTCLIENT, (WPARAM)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle(), dwFlags);
// //
// //   }
// //
// //   bool interaction_impl::SetWindowContextHelpId(unsigned int dwContextHelpId)
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::SetWindowContextHelpId(get_handle(), dwContextHelpId) != false;
// //
// //   }
// //
// //   unsigned int interaction_impl::GetWindowContextHelpId() const
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::GetWindowContextHelpId(get_handle());
// //
// //   }
// //
// //
// //   // Default message ::collection::map implementations
// //   void interaction_impl::OnActivateApp(bool, unsigned int)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnActivate(unsigned int, ::user::interaction *, bool)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OncancelMode()
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnChildActivate()
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnClose()
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnContextMenu(::user::interaction *, int_point)
// //   {
// //   //Default();
// //   }
// //
// //   bool interaction_impl::OnCopyData(::user::interaction *, COPYDATASTRUCT*)
// //   {
// //   //Default();
// //   return false;
// //   }
// //
// //   void interaction_impl::OnEnable(bool)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnEndSession(bool)
// //   {
// //   //Default();
// //   }
// //
// //   bool interaction_impl::OnEraseBkgnd(::draw2d::graphics *)
// //   {
// //   //Default();
// //   }
// //
// //   void interaction_impl::OnGetMinMaxInfo(MINMAXINFO*)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnIconEraseBkgnd(::draw2d::graphics *)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnKillFocus(::user::interaction *)
// //   {
// //   //Default();
// //   }
// //   LRESULT interaction_impl::OnMenuChar(unsigned int, unsigned int, ::user::menu*)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnMenuSelect(unsigned int, unsigned int, HMENU)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnMove(int, int)
// //   {
// //   //Default();
// //   }
// //
// //   bool interaction_impl::OnQueryEndSession()
// //   {
// //   //return Default();
// //   return true;
// //   }
// //
// //   bool interaction_impl::OnQueryNewPalette()
// //   {
// //
// //      //return Default() != false;
// //      return true;
// //
// //   }
// //
// //   bool interaction_impl::OnQueryOpen()
// //   {
// //
// //      //return Default() != false;
// //      return true;
// //
// //   }
// //
//
//
//    void interaction_impl::_001OnSetCursor(::message::message * pmessage)
//    {
//
// //      ::pointer<::user::message>pmessage(pmessage);
// //
// //      
// //
// //      if(psession->get_cursor() != nullptr
// //            && psession->get_cursor()->m_ecursor != cursor_system)
// //      {
// //
// //         throw ::not_implemented();
// ////         ::SetCursor(nullptr);
// //      }
// //      pmessage->m_lresult  = 1;
// //      pmessage->m_bRet = true;
// //      //(bool)Default();
//    }
//
//
// //   void interaction_impl::OnShowWindow(bool, unsigned int)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnSize(unsigned int, int, int)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnTcard(unsigned int, unsigned int)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnWindowPosChanging(WINDOWPOS*)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnWindowPosChanged(WINDOWPOS*)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnDropFiles(HDROP)
// //   {
// //   //Default();
// //   }
// //   void interaction_impl::OnPaletteIsChanging(::user::interaction *)
// //   {
// //   //Default();
// //   }
// //
// //   bool interaction_impl::OnNcActivate(bool)
// //   {
// //
// //      //return Default() != false;
// //      return true;
// //
// //   }
// //
// //   void interaction_impl::OnNcCalcSize(bool, NCCALCSIZE_PARAMS*)
// //   {
// //   //Default();
// //   }
// //
// //   bool interaction_impl::OnNcCreate(::user::system *)
// //   {
// //
// ////      return Default() != false;
// //return true;
// //
// //   }
//
// //   LRESULT interaction_impl::OnNcHitTest(point)
// //   { return Default(); }
// //   void interaction_impl::OnNcLButtonDblClk(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcLButtonDown(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcLButtonUp(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcMButtonDblClk(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcMButtonDown(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcMButtonUp(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcMouseMove(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcPaint()
// //   { Default(); }
// //   void interaction_impl::OnNcRButtonDblClk(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcRButtonDown(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnNcRButtonUp(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnSysChar(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnSysCommand(unsigned int, LPARAM)
// //   { Default(); }
// //   void interaction_impl::OnSysDeadChar(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnSysKeyDown(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnSysKeyUp(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnCompacting(unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnFontChange()
// //   { Default(); }
// //   void interaction_impl::OnPaletteChanged(::user::interaction *)
// //   { Default(); }
// //   void interaction_impl::OnSpoolerStatus(unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnTimeChange()
// //   { Default(); }
// //   void interaction_impl::OnChar(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnDeadChar(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnKeyDown(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnKeyUp(unsigned int, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnLButtonDblClk(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnLButtonDown(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnLButtonUp(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnMButtonDblClk(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnMButtonDown(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnMButtonUp(unsigned int, int_point)
// //   { Default(); }
// //   int interaction_impl::OnMouseActivate(::user::interaction *, unsigned int, unsigned int)
// //   { return (int)Default(); }
// //   void interaction_impl::OnMouseMove(unsigned int, int_point)
// //   { Default(); }
//
// //   bool interaction_impl::OnMouseWheel(unsigned int, short, int_point)
// //   {
// //
// //      return Default() != false;
// //
// //   }
// //
// //   LRESULT interaction_impl::OnRegisteredMouseWheel(WPARAM, LPARAM)
// //   { return Default(); }
// //   void interaction_impl::OnRButtonDblClk(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnRButtonDown(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnRButtonUp(unsigned int, int_point)
// //   { Default(); }
// //   void interaction_impl::OnTimer(uptr)
// //   { Default(); }
// //   void interaction_impl::OnInitMenu(::user::menu*)
// //   { Default(); }
// //   void interaction_impl::OnInitMenuPopup(::user::menu*, unsigned int, bool)
// //   { Default(); }
// //   void interaction_impl::OnAskCbFormatName(unsigned int nMaxCount, char * lpszName)
// //   {
// //      (nMaxCount);
// //      if(nMaxCount>0)
// //      {
// //         /* defwindow proc should do this for us, but to be safe, we'hi do it here too */
// //         lpszName[0]='\0';
// //      }
// //      Default();
// //   }
// //   void interaction_impl::OnChangeCbChain(oswindow, oswindow)
// //   { Default(); }
// //   void interaction_impl::OnDestroyClipboard()
// //   { Default(); }
// //   void interaction_impl::OnDrawClipboard()
// //   { Default(); }
// //   void interaction_impl::OnHScrollClipboard(::user::interaction *, unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnPaintClipboard(::user::interaction *, HGLOBAL)
// //   { Default(); }
// //   void interaction_impl::OnRenderAllFormats()
// //   { Default(); }
// //   void interaction_impl::OnRenderFormat(unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnSizeClipboard(::user::interaction *, HGLOBAL)
// //   { Default(); }
// //   void interaction_impl::OnVScrollClipboard(::user::interaction *, unsigned int, unsigned int)
// //   { Default(); }
// //   unsigned int interaction_impl::OnGetDlgCode()
// //   { return (unsigned int)Default(); }
// //   void interaction_impl::OnMDIActivate(bool, ::user::interaction *, ::user::interaction *)
// //   { Default(); }
// //   void interaction_impl::OnEnterMenuLoop(bool)
// //   { Default(); }
// //   void interaction_impl::OnExitMenuLoop(bool)
// //   { Default(); }
// //   // Win4 support
// ////   void interaction_impl::OnStyleChanged(int, LPSTYLESTRUCT)
// ////   { Default(); }
// ////   void interaction_impl::OnStyleChanging(int, LPSTYLESTRUCT)
// ////   { Default(); }
// //   void interaction_impl::OnSizing(unsigned int, ::int_rectangle *)
// //   { Default(); }
// //   void interaction_impl::OnMoving(unsigned int, ::int_rectangle *)
// //   { Default(); }
// //   void interaction_impl::OncaptureChanged(::user::interaction *)
// //   { Default(); }
// //
// //   bool interaction_impl::OnDeviceChange(unsigned int, dword_ptr)
// //   {
// //
// //      return Default() != false;
// //
// //   }
// //
// //   void interaction_impl::OnWinIniChange(const char *)
// //   { Default(); }
// //   void interaction_impl::OnChangeUIState(unsigned int, unsigned int)
// //   { Default(); }
// //   void interaction_impl::OnUpdateUIState(unsigned int, unsigned int)
// //   { Default(); }
// //
// //   unsigned int interaction_impl::OnQueryUIState()
// //   {
// //
// //      return (unsigned int)Default();
// //
// //   }
//
//    // interaction_impl dialog data support
//    //    void interaction_impl::DoDataExchange(CDataExchange*)
//    //   { } // default does nothing
//
//    // interaction_impl modality support
//
// //   void interaction_impl::BeginModalState()
// //   {
// //
// //      __throw(todo);
// //
// //      //::EnableWindow(get_handle(), false);
// //
// //   }
// //
// //   void interaction_impl::EndModalState()
// //   {
// //
// //      __throw(todo);
// //
// //      //::EnableWindow(get_handle(), true);
// //
// //   }
// //
// //   // frame_window
// //   /*    void frame_window::DelayUpdateFrameTitle()
// //   { m_nIdleFlags |= idleTitle; }
// //   void frame_window::DelayRecalcLayout(bool bNotify)
// //   { m_nIdleFlags |= (idleLayout | (bNotify ? idleNotify : 0)); };
// //   bool frame_window::InModalState() const
// //   { return m_cModalStack != 0; }
// //   void frame_window::set_title(const char * pszTitle)
// //
// //   { m_strTitle = pszTitle; }
// //
// //   string frame_window::get_title() const
// //   { return m_strTitle; }
// //   */
// //
// //
// //
// //   void interaction_impl::CloseWindow()
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      ::CloseWindow(get_handle());
// //
// //   }
// //
// //   bool interaction_impl::OpenIcon()
// //   {
// //
// //      throw ::not_implemented();
// ////      ASSERT(::is_window((oswindow) get_handle()));
// ////      return ::OpenIcon(get_handle()) != false;
// //
// //   }
// //
// //   ////////////////////////////////////////////////////////////////////////////
// //   // UI related ::windowing::window functions
// //
// //   oswindow PASCAL interaction_impl::GetSafeOwner_(oswindow hParent, oswindow* pWndTop)
// //   {
// //      // get ::windowing::window to start with
// //      oswindow hWnd = hParent;
// //      if (hWnd == nullptr)
// //      {
// //         /* trans      ::pointer<frame_window>pFrame = channel::GetRoutingFrame_();
// //         if (pFrame != nullptr)
// //         hWnd = pFrame->get_handle();
// //         else
// //         hWnd = ::auraacmesystem()->GetMainWnd()->get_handle();*/
// //      }
// //
// //      // a popup ::windowing::window cannot be owned by a child ::windowing::window
// //      while (hWnd != nullptr && (::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD))
// //         hWnd = ::get_parent(hWnd);
// //
// //      // determine toplevel ::windowing::window to disable as well
// //      oswindow hWndTop = hWnd, hWndTemp = hWnd;
// //      for (;;)
// //      {
// //         if (hWndTemp == nullptr)
// //            break;
// //         else
// //            hWndTop = hWndTemp;
// //         hWndTemp = ::get_parent(hWndTop);
// //      }
// //
// //      __s_throw(todo());
// //      // get last active popup of first non-child that was found
// //      //    if (hParent == nullptr && hWnd != nullptr)
// //      //       hWnd = ::GetLastActivePopup(hWnd);
// //
// //      // disable and store top level parent ::windowing::window if specified
// //      if (pWndTop != nullptr)
// //      {
// //         /*         if (hWndTop != nullptr && ::IsWindowEnabled(hWndTop) && hWndTop != hWnd)
// //                  {
// //                     *pWndTop = hWndTop;
// //                     ::EnableWindow(hWndTop, false);
// //                  }
// //                  else
// //                     *pWndTop = nullptr;*/
// //      }
// //
// //      return hWnd;    // return the owner as oswindow
// //   }
// //
// //   void interaction_impl::on_delete(::object * pinteraction)
// //   {
// //      __UNREFERENCED_PARAMETER(pinteraction);
// //   }
// //
// //
// //
// //
// ////   void interaction_impl::_001OnEraseBkgnd(::message::message * pmessage)
// ////   {
// ////      ::pointer<::message::erase_bkgnd>perasebkgnd(pmessage);
// ////      perasebkgnd->m_bRet = true;
// ////      perasebkgnd->set_result(true);
// ////   }
// //
// //
// //   void interaction_impl::_001BaseWndInterfaceMap()
// //   {
// //
// //      ::windowing::window::_001BaseWndInterfaceMap();
// //
// //   }
// //
// //
// //   void interaction_impl::_001OnTriggerMouseInside()
// //   {
// //
//
// ////      m_bMouseHover = true;
// //
// //   }
//
//
//    void interaction_impl::set_origin(::draw2d::graphics_pointer & pgraphics)
//    {
//
//       pgraphics->set_origin(::int_point());
//
//    }
//
//
// //   void interaction_impl::_window_show_change_visibility_unlocked(::e_display edisplay, const ::user::activation & useractivation)
// //   {
// //
// //      __keep_flag_on(m_puserinteraction->layout().m_eflag, ::user::interaction_layout::flag_show_window);
// //
// ////      //auto edisplay = m_puserinteraction->layout().design().display();
// ////
// ////      //auto useractivation = m_puserinteraction->layout().design().activation();
// ////
// ////      //if(useractivation &)
// //////      {
// //////
// //////         wm_add_erase_state(m_oswindow, net_wm_state_hidden, false);
// //////
// //////      }
// //////
// ////
// ////      m_pwindow->show_window(edisplay, useractivation);
// ////
// //////      if (edisplay == e_display_full_screen)
// //////      {
// //////
// //////         if(m_puserinteraction->m_bWorkspaceFullScreen)
// //////         {
// //////
// //////            ::show_window(m_oswindow, e_display_zoomed);
// //////
// //////         }
// //////         else
// //////         {
// //////
// //////            m_oswindow->full_screen();
// //////
// //////         }
// //////
// //////      }
// //////      else
// //////      {
// //////
// ////
// //
// //        ::windowing::window::_window_show_change_visibility_unlocked(edisplay, useractivation);
// ////
// ////      }
// //
// //   }
//
//
// //   ::user::interaction * interaction_impl::GetNextWindow(unsigned int nFlag)
// //   {
// //
// //      if(nFlag == GW_HWNDNEXT)
// //      {
// //
// //         return get_next(true, nullptr);
// //
// //      }
// //      else
// //      {
// //
// //         __throw(error_interface_only);
// //
// //      }
// //
// //   }
// //
// //
// //   ::user::interaction * interaction_impl::get_next(bool bIgnoreChildren,int * piLevel)
// //   {
// //
// //      return  m_puserinteraction->get_next(bIgnoreChildren, piLevel);
// //
// //   }
// //
//
// //   void interaction_impl::show_task(bool bShow)
// //   {
// //
// //      wm_toolwindow(get_handle(), bShow ? 0: 1);
// //
// //   }
//
//
// //   bool interaction_impl::has_keyboard_focus() const
// //   {
// //
// //      if(!m_pwindow)
// //      {
// //
// //         return false;
// //
// //      }
// //
// //      return m_pwindow->has_keyboard_focus();
// //
// //   }
// //
// //
// //   bool interaction_impl::is_active_window() const
// //   {
// //
// //      if(!::is_window(m_oswindow))
// //      {
// //
// //         return false;
// //
// //      }
//
// //      x11_sync([this]()
// //      {
// //
// //         m_puserinteraction->m_ewindowflag.set(::window_flag_active, m_oswindow == ::get_active_window());
// //
// //      });
// //
// //      return m_puserinteraction->m_ewindowflag & ::e_window_flag_active;
// //
// //   }
//
//
// //   void interaction_impl::prodevian_update_screen()
// //   {
// //
// //      if(!m_puserinteraction)
// //      {
// //
// //         //return false;
// //
// //         throw ::exception(error_null_pointer);
// //
// //      }
// //
// //      if(m_puserinteraction->m_ewindowflag & e_window_flag_embedded_prodevian)
// //      {
// //
// //         _001UpdateScreen();
// //
// //      }
// //      else
// //      {
// //
// //         //x11_async_runnable(__routine([&]()
// //         //{
// //
// //            //synchronous_lock synchronouslock(x11_mutex());
// //
// //            _001UpdateScreen();
// //
// //         //}));
// //
// //      }
// //
// //      //return true;
// //
// //   }
//
//
//    void interaction_impl::non_top_most_upper_window_rects(::int_rectangle_array& recta)
//    {
//
// //      
// //
// //      auto puser = user();
// //
// //      auto pwindowing = system()->windowing();
// //
// //      pwindowing->upper_window_rects(get_oswindow(), recta);
//
//    }
//
//
// //   ::e_status interaction_impl::set_tool_window(bool bSet)
// //   {
// //
// //      wm_toolwindow(m_oswindow, bSet);
// //
// //      return ::success;
// //
// //   }
//
//
// } // namespace aura_linux
//
//
//
