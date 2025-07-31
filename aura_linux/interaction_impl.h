#pragma once
//
//
// //#include "aura/user/user/interaction_impl.h"
//
//
// namespace aura_linux
// {
//
//
// //   LRESULT CALLBACK __send_message_hook(int, WPARAM, LPARAM);
// //   // void _::ca2::StandardSubclass(oswindow);
// //   LRESULT CALLBACK __cbt_filter_hook(int, WPARAM, LPARAM);
// //   LRESULT __call_window_procedure(::user::interaction * pWnd, oswindow hWnd, unsigned int nMsg, WPARAM wParam, LPARAM lParam);
//
//
//    class x11data;
//
//
//    class interaction_impl :
//       virtual public ::windowing::window
//    {
//    public:
//
//
//       string                           m_strWindowText;
//       ::user::interaction_base *              m_pbasewnd;
//       bool                             m_bExposing;
//       //::pointer<x11data>            m_px11data;
//       int                              m_iDepth;
//       int                              m_iScreen;
//       bool                             m_bEnabled;
//
//       //::pointer<::thread>           m_pthreadDraw;
//       ::long_long_rectangle                  m_rectLastPos;
//       class ::time                       m_timeLastPos;
//
//       ::int_point                      m_pointLastMove;
//       bool                             m_bMoveEvent;
//       ::int_size                       m_sizeLastSize;
//       bool                             m_bSizeEvent;
//       class ::time                       m_timeLastPlacementEvent;
//
//
//       interaction_impl();
//       ~interaction_impl() override;
//
//
//       void linux_interaction_impl_common_construct();
//
//
//       //void assert_ok() const override;
//       //// void dump(dump_context & dumpcontext) const override;
//
//
//       static const MESSAGE * GetCurrentMessage();
//
//       virtual void install_message_routing(::channel * pchannel) override;
//
//       bool operator==(const ::windowing::window& wnd) const;
//       bool operator!=(const ::windowing::window& wnd) const;
//
// //      unsigned int GetStyle() const override;
//       //unsigned int GetExStyle() const override;
//       //bool ModifyStyle(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags = 0) override;
//       //bool ModifyStyleEx(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags = 0) override;
//
//       //virtual ::e_status set_tool_window(bool bSet = true) override;
//
//       //virtual ::user::interaction * get_owner();
//       //virtual ::user::interaction_base * set_owner(::user::interaction_base * pprimitiveOwner) override;
//
//       //virtual oswindow get_handle() const override;
//
//       virtual void route_command(::message::command * pcommand, bool bRouteKeyToDescendants = false) override;
//
//       //virtual void on_control_event(::user::control_event * pevent) override;
//
//       DECLARE_MESSAGE_HANDLER(_001OnEraseBkgnd);
//       DECLARE_MESSAGE_HANDLER(_001OnMove);
//       DECLARE_MESSAGE_HANDLER(_001OnSize);
//       DECLARE_MESSAGE_HANDLER(_001OnShowWindow);
//
//
//       //void _window_show_change_visibility_unlocked(::e_display edisplay, const ::user::activation & useractivation) override;
//
//
//       virtual ::windowing::window * from_os_data(void * pdata) override;
//       //virtual void * get_os_data() const override;
//
//       static user::interaction_impl * from_handle(::oswindow hWnd);
//       static user::interaction_impl * FromHandlePermanent(::oswindow hWnd);
//       //static void DeleteTempMap();
//       bool Attach(::oswindow hWndNew);
//       ::oswindow Detach();
//
//       // subclassing/unsubclassing functions
//       virtual void pre_subclass_window() override;
// //      bool SubclassWindow(oswindow hWnd);
// //      //bool SubclassDlgItem(unsigned int nID, ::pointer<::interaction_impl>pParent);
// //      oswindow UnsubclassWindow();
//
//       // handling of RT_DLGINIT resource (extension to RT_DIALOG)
// //      bool ExecuteDlgInit(const char * pszResourceName);
// //
// //      bool ExecuteDlgInit(LPVOID pResource);
//
//       //virtual bool create_message_queue(::user::interaction * pinteraction, const char * lpszName) override;
//
// //      using ::windowing::window::create_window;
//
//       // for child windows, views, panes etc
// //      virtual bool create_window(
// //      ::user::interaction * pinteraction,
// //      const char * pszClassName,
//
// //      const char * pszWindowName,
//
// //      unsigned int dwStyle,
// //      const ::int_rectangle & rectangle,
// //      ::user::interaction * pParentWnd,
// //      id id,
// //      ::create * pContext = nullptr) override;
// //
// //      // advanced creation (allows access to extended styles)
// //      virtual bool create_window_ex(
// //      ::user::interaction * pinteraction,
// //      ::pointer<::user::system>pusersystem,
// //      ::user::interaction * pParentWnd = nullptr,
// //      id id = ::id()) override;
//
//
//          //void native_create_host() override;
//
//
// //      virtual bool native_create_window_ex(
// //      ::user::interaction * pinteraction,
// //      ::pointer<::user::system>pusersystem,
// //      ::user::interaction * pParentWnd = nullptr,
// //      id id = ::id());
//
//       void start_destroying_window() override;
//
//       // special pre-creation and ::windowing::window int_rectangle adjustment hooks
//       virtual bool pre_create_window(::user::system * pusersystem) override;
//
//       // Advanced: virtual AdjustWindowRect
// //      enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
// //      virtual void CalcWindowRect(::int_rectangle * pClientRect, unsigned int nAdjustType = adjustBorder);
//
//
//
//
//       void _thread_delayed_placement();
//
//       void defer_delayed_placement();
//
//
//       virtual void on_start_layout_experience(enum_layout_experience elayoutexperience) override;
//       virtual void on_end_layout_experience(enum_layout_experience elayoutexperience) override;
//
//
//       virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;
//
//
//
//
//       bool _is_window() override;
//
// #if(WINVER >= 0x0500)
//
//       ::user::interaction * GetAncestor(unsigned int gaFlags) const;
//
// #endif   // WINVER >= 0x0500
//
//       //LRESULT send_message(::enum_message emessage, ::wparam wparam = {}, ::lparam lparam = {}) override;
//
//       //bool post_message(::enum_message emessage, ::wparam wparam = {}, ::lparam lparam = {}) override;
//
//
// //      bool SendNotifyMessage(const ::id & id, WPARAM wParam, lparam lParam);
// //
// //      bool SendChildNotifyLastMsg(LRESULT* pResult = nullptr);
// //
// //      bool DragDetect(const ::int_point & point) const;
//
//
//
//
//
//       // oswindow Text Functions
//       //void set_window_text(const ::scoped_string & scopedstrString) override;
//
//       //character_count GetWindowText(char * pszStringBuf, character_count nMaxCount);
//
//       //void get_window_text(string & str) override;
//       //character_count GetWindowTextLength();
//       void SetFont(::write_text::font* pFont, bool bRedraw = true);
//       ::write_text::font* GetFont();
//
//
//       // oswindow int_size and position Functions
//       //virtual bool node_is_iconic() override;
//       //virtual bool layout().is_zoomed();
//       //virtual bool layout().is_full_screen();
//       //void MoveWindow(int x, int y, int nWidth, int nHeight,
//         //              bool bRepaint = true);
//       //void MoveWindow(const ::int_rectangle & rectangle, bool bRepaint = true);
//
// //      int SetWindowRgn(HRGN hRgn, bool bRedraw);
// //      int GetWindowRgn(HRGN hRgn);
//
//
//       void _001OnAfterExitIconic() override;
//       void _001OnAfterExitFullScreen() override;
//       void _001OnAfterExitZoomed() override;
//
//
//       //virtual bool set_window_position(iptr z, int x, int y, int cx, int cy, unsigned int nFlags);
// //      virtual unsigned int ArrangeIconicWindows();
//       //virtual bool BringWindowToTop();
// //      virtual bool window_rectangle(::long_long_rectangle * prectangle);
//
//   //    virtual bool _001GetWindowRect(::long_long_rectangle * prectangle);
//
//       //using ::windowing::window::this->rectangle;
//       //virtual bool this->rectangle(::long_long_rectangle * prectangle);
//
//
//       //virtual bool has_keyboard_focus() override;
//       //virtual bool is_active() override;
//
//       //virtual ::int_point client_screen_top_left() override;
//
// //      virtual bool client_to_screen(::int_rectangle * prectangle);
//
// //      virtual bool client_to_screen(::int_point * ppoint);
//
// //      virtual bool client_to_screen(::long_long_rectangle * prectangle);
//
// //      virtual bool client_to_screen(::long_long_point * ppoint);
//
// //      virtual bool screen_to_client(::int_rectangle * prectangle);
//
// //      virtual bool screen_to_client(::int_point * ppoint);
//
// //      virtual bool screen_to_client(::long_long_rectangle * prectangle);
//
// //      virtual bool screen_to_client(::long_long_point * ppoint);
//
//
// //      virtual bool GetWindowPlacement(WINDOWPLACEMENT* puserinteractionpl);
// //
// //      virtual bool SetWindowPlacement(const WINDOWPLACEMENT* puserinteractionpl);
//
//
//       // Coordinate Mapping Fufnctions
// //      virtual void MapWindowPoints(::user::interaction * puserinteractionTo, ::int_point * pPoint, unsigned int nCount);
// //
// //      virtual void MapWindowPoints(::user::interaction * puserinteractionTo, ::int_rectangle * prectangle);
//
//
//       // Update/Painting Functions
// //      virtual ::draw2d::graphics * GetDC();
// //      virtual ::draw2d::graphics * GetWindowDC();
// //      virtual bool ReleaseDC(::image::image *pimage);
// //      virtual void Print(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const;
// //      virtual void PrintClient(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const;
//
// //      virtual void UpdateWindow();
// //      virtual void SetRedraw(bool bRedraw = true);
// //      virtual bool GetUpdateRect(::int_rectangle * prectangle, bool bErase = false);
// //
// //      virtual int GetUpdateRgn(::draw2d::region* pRgn, bool bErase = false);
// //      virtual void Invalidate(bool bErase = true);
// //      virtual void InvalidateRect(const ::int_rectangle & rectangle, bool bErase = true);
// //
// //      virtual void InvalidateRgn(::draw2d::region* pRgn, bool bErase = true);
// //      virtual void ValidateRect(const ::int_rectangle & rectangle);
// //
// //      virtual void ValidateRgn(::draw2d::region* pRgn);
//       //virtual bool display(::e_display edisplay) override;
//
// //      virtual bool WfiOnStartDock();
// //      virtual void WfiOnDock(::e_display edisplay);
// //      virtual void prodevian_prepare_down();
// //      virtual void prodevian_prepare_up();
// //      virtual void WfiOnRestore();
// //      virtual void WfiOnMinimize(bool bNoActivate);
// //      virtual void WfiOnMaximize();
// //      virtual void WfiOnFullScreen();
// //      virtual void WfiOnExitFullScreen();
// //      virtual void WfiOnClose();
// //      virtual void WfiOnNotifyIcon();
//
//
//       //virtual bool _is_window_visible() override;
//       //virtual void ShowOwnedPopups(bool bShow = true);
//
//       //virtual ::draw2d::graphics * GetDCEx(::draw2d::region* prgnClip, unsigned int flags);
//       //virtual bool LockWindowUpdate();
//       //virtual void UnlockWindowUpdate();
// //      virtual bool RedrawWindow(const ::int_rectangle& rectUpdate = nullptr,
// //                                ::draw2d::region* prgnUpdate = nullptr,
// //                                unsigned int flags = RDW_INVALIDATE | RDW_ERASE);
//       // xxx      virtual bool EnableScrollBar(int nSBFlags, unsigned int nArrowFlags = ESB_ENABLE_BOTH);
//
//       virtual void set_origin(::draw2d::graphics_pointer & pgraphics) override;
//
// //
// //      //virtual bool DrawAnimatedRects(int idAni, const LPRECTprcFrom, const LPRECTlprcTo);
// //
// //      virtual bool DrawCaption(::draw2d::graphics_pointer & pgraphics, const int_rectangle & prc, unsigned int uFlags);
// //
// //
// //#if(WINVER >= 0x0500)
// //
// //      virtual bool AnimateWindow(unsigned int millis, unsigned int dwFlags);
// //
// //#endif   // WINVER >= 0x0500
// //
// //#if(_WIN32_WINNT >= 0x0501)
// //
// //      virtual bool PrintWindow(::draw2d::graphics_pointer & pgraphics, unsigned int nFlags) const;
// //
// //#endif   // _WIN32_WINNT >= 0x0501
//
//
//
// //      // Timer Functions
// //      virtual bool set_timer(uptr uEvent, unsigned int nElapse, PFN_TIMER pfnTimer);
// //      virtual bool kill_timer(uptr uEvent);
//
//       // oswindow State Functions
//       virtual bool IsWindowEnabled();
//       virtual bool EnableWindow(bool bEnable = true);
//
//
//       //void prodevian_update_screen() override;
//
//
//       DECLARE_MESSAGE_HANDLER(on_message_create);
//       DECLARE_MESSAGE_HANDLER(_001OnDestroy);
//       DECLARE_MESSAGE_HANDLER(_001OnPaint);
//       DECLARE_MESSAGE_HANDLER(_001OnPrint);
//       DECLARE_MESSAGE_HANDLER(_001OnSetCursor);
//
//
//
//       virtual void pre_translate_message(::message::message * pmessage) override;
//
//       void show_software_keyboard(::user::element * pelement) override;
//
//       void hide_software_keyboard(::user::element * pelement) override;
//
//       //virtual void message_handler(::message::message * pusermessage) override;
//
//       virtual void default_window_procedure(::message::message * pusermessage) override;
//
//       virtual void post_non_client_destroy() override;
//
//       virtual void on_final_release() override;
//
//       //static void get_app_wnda(user::oswindow_array & wnda);
//
//       //virtual iptr get_window_long_ptr(int nIndex) const override;
//       //virtual iptr set_window_long_ptr(int nIndex, iptr lValue) override;
//
//       //void _001OnTriggerMouseInside();
//
//
//       //::user::interaction * get_next(bool bIgnoreChildren, int * piLevel);
//
//       //void show_task(bool bShow) override;
//
//       virtual void non_top_most_upper_window_rects(::int_rectangle_array& recta) override;
//
//    };
//
//
// } // namespace aura_linux
//
//
//
//
