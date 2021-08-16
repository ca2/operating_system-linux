#include "framework.h"
#include <sys/utsname.h>


extern "C"
void node_linux_factory_exchange(::factory_map * pfactorymap)
{

   auto edesktop = ::acme::linux::node::_get_edesktop();

   ::e_status estatus = ::success_none;

   if (edesktop & ::user::e_desktop_kde)
   {

      estatus = pfactorymap->m_psystem->do_factory_exchange("desktop_environment", "kde");

   }
   else if (edesktop & ::user::e_desktop_gnome)
   {

      estatus = pfactorymap->m_psystem->do_factory_exchange("desktop_environment", "gnome");

   }
   else if (edesktop & ::user::e_desktop_xfce)
   {

      estatus = pfactorymap->m_psystem->do_factory_exchange("desktop_environment", "xfce");

   }
   else
   {

      estatus = pfactorymap->m_psystem->do_factory_exchange("desktop_environment", "gnome");

      if (!estatus)
      {

         estatus = pfactorymap->m_psystem->do_factory_exchange("desktop_environment", "kde");

      }

   }
//
//#else
//
//      estatus = do_factory_exchange("aura", "windows");
//
//#endif


//      apex_linux_factory_exchange( pfactorymap);
//
//   aura_posix_factory_exchange( pfactorymap);
//
//   pfactorymap->create_factory < ::aura::linux::node, ::acme::node >();

}





