// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#pragma once


namespace windowing_x11
{


   class CLASS_DECL_AURA windowing :
      virtual public ::windowing::windowing
   {
   public:


      windowing();
      virtual ~windowing();


      virtual ::e_status initialize() override;


      virtual bool sn_start_context()  override;

      virtual HCURSOR load_default_cursor(e_cursor ecursor) override;

      virtual int_bool window_set_mouse_cursor(window * pwindow, HCURSOR hcursor) override;

      virtual bool set_window_icon(window * pwindow, const ::file::path & path) override;

      virtual window * new_message_window(::user::interaction_impl * pimpl) override;

      virtual window * new_window(::user::interaction_impl * pimpl) override;

      virtual ::e_status remove_window(::user::interaction_impl * pimpl) override;

   };


} // namespace windowing



