//
// Created by camilo on 05/03/2021. 18:57 BRT ThomasBS_!!
//
#include "framework.h"


#include <xcb/xcb_icccm.h>


namespace windowing_xcb
{


   ::e_status window::get_wm_hints(void * p_xcb_icccm_wm_hints_t)
   {

      auto phints = (xcb_icccm_wm_hints_t * )p_xcb_icccm_wm_hints_t;

      auto cookie = xcb_icccm_get_wm_hints(xcb_connection(), xcb_window());

      auto preply = __malloc(xcb_get_property_reply(xcb_connection(), cookie, nullptr));

      if (!preply)
      {

         return ::error_failed;

      }

      auto response = __malloc(xcb_icccm_get_wm_hints_from_reply(phints, preply));

      if(!response)
      {

         return ::error_failed;

      }

      return ::success;

   }


   bool window::is_iconic()
   {

      auto state = (xcb_icccm_wm_state_t) _get_wm_state();

      return state == XCB_ICCCM_WM_STATE_ICONIC;

   }


   string window::_get_wm_name()
   {

      auto cookie = xcb_icccm_get_wm_name(xcb_connection(), xcb_window());

      xcb_icccm_get_text_property_reply_t reply;

      if(!xcb_icccm_get_wm_name_reply(xcb_connection(), cookie, &reply, nullptr))
      {

         return "";

      }

      string strWmName(reply.name, reply.name_len);

      return strWmName;

   }


} // namespace windowing_xcb


