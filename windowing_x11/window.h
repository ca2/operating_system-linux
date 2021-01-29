// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:20 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#pragma once

namespace windowing_x11
{


   class CLASS_DECL_AURA window :
      virtual public ::windowing::window

      {
         public:


   XWindowAttributes             m_attr;
   XVisualInfo                   m_visualinfo;
   // GdkWindow *                   m_pgdkwindow;
   void *                        m_pgdkwindow;

   HCURSOR                                m_hcursorLast;

         //iptr_to_iptr *                   m_plongmap;
         int m_iXic;
         XIC                                    m_xic;
         osdisplay                              m_osdisplay;
         Window                                 m_window;
         Visual                                 m_visual;
         int m_iDepth;
         int m_iScreen;
         bool m_bMessageOnlyWindow;
         __pointer(::user::interaction_impl)    m_pimpl;
         __pointer(mq)                          m_pmq;
         hthread_t                                m_hthread;
         Colormap                               m_colormap;
         millis                                   m_millisLastMouseMove;
         Window                                 m_parent;
         ::rect                                 m_rect;
         string                                 m_strWMClass;
         int m_iaNetWmState[net_wm_state_count];


         static oswindow_dataptra * s_pdataptra;
         static::mutex * s_pmutex;

         static Atom s_atomLongType;
         static Atom s_atomLongStyle;
         static Atom s_atomLongStyleEx;

         static Atom get_window_long_atom(i32 nIndex);




         oswindow_data();
         //oswindow_data(::user::interaction * puibaseMessageOnlyWindow);
         //oswindow_data(const void * p);
         //oswindow_data(const LPARAM & lparam);

         //oswindow_data(const WPARAM & wparam);


         ~oswindow_data();



         operator void * ()
         {
            return this;
         }

         operator void * () const
         {
            return (void *) this;
         }

         oswindow_data & operator= (const oswindow_data & window);

         bool operator== (const void * p) const
         {
            return this == p;
         }

         bool operator!= (const void * p) const
         {
            return this != p;
         }

         Display * display()
         {
            return ::is_null(this) ? nullptr : m_osdisplay->display();
         }

         Display * display() const
         {
            return ::is_null(this) ? nullptr : m_osdisplay->display();
         }

         Window window()
         {
            return ::is_null(this) ? None : m_window;
         }

         Window window() const
         {
            return ::is_null(this) ? None : m_window;
         }

         Visual * visual()
         {
            return ::is_null(this) ? nullptr : &m_visual;
         }

         Visual * visual() const
         {
            return ::is_null(this) ? nullptr : (Visual * ) & m_visual;
         }

         Window root_window_raw() const
         {
            return ::is_null(this) || ::is_null(m_osdisplay) ? None : RootWindow(display(), m_iScreen);
         }

         void send_client_event(Atom atom, unsigned int numArgs, ...);
         i32 store_name(const char * psz);
         i32 select_input(i32 iInput);
         i32 select_all_input();
         i32 map_window();
         i32 unmap_window(bool bWithdraw);
         void set_wm_class(const char * psz);

         void exit_iconify();

         void full_screen(const::rect & rect = nullptr);

         void exit_full_screen();

         void exit_zoomed();

         void set_user_interaction(::user::interaction_impl * pinteraction);


         void post_nc_destroy();


         bool is_child(oswindow oswindowcandidateChildOrDescendant); // or descendant
         oswindow get_parent();
         Window get_parent_handle();

         oswindow set_parent(oswindow oswindowNewParent);
         long get_state();
         bool is_iconic();
         bool is_window_visible();
         bool show_window(const::e_display & edisplay, const::e_activation & eactivation);
         iptr get_window_long_ptr(i32 nIndex);
         iptr set_window_long_ptr(i32 nIndex, iptr l);
         bool _001ClientToScreen(POINT32 * ppoint);

         bool _001ScreenToClient(POINT32 * ppoint);


         Atom intern_atom(const char * pszAtomName, bool bCreate);
         Atom intern_atom(e_net_wm_state state, bool bCreate);

         bool is_null() const
         {
            return ::is_null(this);
         }

         bool set_window_pos(class::zorder zorder, i32 x, i32 y, i32 cx, i32 cy,::u32 nFlags);
         bool _set_window_pos(class::zorder zorder, i32 x, i32 y, i32 cx, i32 cy,::u32 nFlags);

         bool is_destroying();

         bool bamf_set_icon();

         bool set_icon(::image * pimage);

         int x_change_property(Atom property, Atom type, int format, int mode, const unsigned char * data, int nelements);

      };

   class oswindow_dataptra :
      public address_array<oswindow_data *>
   {
   public:

      virtual ~oswindow_dataptra()
      {

         remove_all();

      }

      void remove_all()
      {

         for (auto point : *this)
         {

            delete point;

         }

         address_array<oswindow_data *>::remove_all();
      }

   };

} // namespace windowing_x11


