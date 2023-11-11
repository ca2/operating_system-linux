#include "framework.h"
#include "node.h"
#include "acme/exception/resource.h"
#include "acme/platform/system.h"
#include <sys/utsname.h>


::user::enum_desktop get_edesktop();


__FACTORY_EXPORT void node_linux_factory(::factory::factory * pfactory)
{

   auto edesktop = ::get_edesktop();

   if (edesktop & ::user::e_desktop_kde)
   {

      auto & pfactoryKde = pfactory->system()->factory("desktop_environment", "kde");

      if(!pfactoryKde)
      {

         throw resource_exception();

      }

      pfactoryKde->merge_to_global_factory();

   }
   else if ((edesktop & ::user::e_desktop_gnome) || (edesktop & ::user::e_desktop_lxde))
   {

      auto & pfactoryGnome = pfactory->system()->factory("desktop_environment", "gnome");

      if(!pfactoryGnome)
      {

         throw resource_exception();

      }

      pfactoryGnome->merge_to_global_factory();

   }
   else if (edesktop & ::user::e_desktop_xfce)
   {

      auto & pfactoryXfce = pfactory->system()->factory("desktop_environment", "xfce");

      if(!pfactoryXfce)
      {

         throw resource_exception();

      }

      pfactoryXfce->merge_to_global_factory();

   }
   else
   {

      auto & pfactoryGnome = pfactory->system()->factory("desktop_environment", "gnome");

      if (!pfactoryGnome)
      {

         auto & pfactoryKde = pfactory->system()->factory("desktop_environment", "kde");

         if(!pfactoryKde)
         {

            throw resource_exception();

         }

         pfactoryKde->merge_to_global_factory();

      }
      else
      {

         pfactoryGnome->merge_to_global_factory();

      }

   }
//
//#else
//
//      estatus = factory("aura", "windows");
//
//#endif


//      apex_linux_factory( pfactory);
//
//   aura_posix_factory( pfactory);
//
//   pfactory->add_factory_item < ::aura::linux::node, ::acme::node >();

}





