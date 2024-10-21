#include "framework.h"
#include "node.h"
#include "acme/exception/resource.h"
#include "acme/platform/system.h"
#include <sys/utsname.h>

namespace nano
{
   namespace user
   {
      ::windowing::enum_desktop get_edesktop();
   } // namespace user
}// namespace nano


__FACTORY_EXPORT void node_linux_factory(::factory::factory * pfactory)
{

   auto edesktop = ::windowing::get_edesktop();

   if (edesktop == ::windowing::e_desktop_kde)
   {

      auto & pfactoryKde = pfactory->system()->factory("desktop_environment", "kde");

      if(!pfactoryKde)
      {

         printf("desktop_environment_kde library failed to load\n");

         throw resource_exception();

      }

      printf("desktop_environment_kde loaded\n");

      pfactoryKde->merge_to_global_factory();

      printf("desktop_environment_kde merge_to_global_factory\n");

   }
   else if ((edesktop == ::windowing::e_desktop_gnome) || (edesktop == ::windowing::e_desktop_lxde))
   {

      auto psystem = pfactory->system();

      printf("Going to open desktop_environment_gtk_based\n");

      auto & pfactoryGtkBased = psystem->factory("desktop_environment", "gtk_based");

      if(!pfactoryGtkBased)
      {

         printf("desktop_environment_gtk_based library failed to load\n");

         throw resource_exception();

      }

      printf("desktop_environment_gtk_based loaded\n");

      pfactoryGtkBased->merge_to_global_factory();

      printf("desktop_environment_gtk_based merge_to_global_factory\n");

   }
   else if (edesktop == ::windowing::e_desktop_xfce)
   {

      auto & pfactoryXfce = pfactory->system()->factory("desktop_environment", "xfce");

      if(!pfactoryXfce)
      {

         printf("desktop_environment_xfce library failed to load\n");

         throw resource_exception();

      }

      printf("desktop_environment_xfce loaded\n");

      pfactoryXfce->merge_to_global_factory();

      printf("desktop_environment_xfce merge_to_global_factory\n");

   }
   else
   {

      auto & pfactoryGtkBased = pfactory->system()->factory("desktop_environment", "gtk_based");

      if (!pfactoryGtkBased)
      {

         printf("desktop_environment_gtk_based library failed to load (2)\n");

         auto & pfactoryKde = pfactory->system()->factory("desktop_environment", "kde");

         if(!pfactoryKde)
         {

            printf("desktop_environment_kde library failed to load (2)\n");

            throw resource_exception();

         }

         printf("desktop_environment_kde loaded (2)\n");

         pfactoryKde->merge_to_global_factory();

         printf("desktop_environment_kde merge_to_global_factory (2)\n");

      }
      else
      {

         printf("desktop_environment_gtk_based loaded (2)\n");

         pfactoryGtkBased->merge_to_global_factory();

         printf("desktop_environment_gtk_based merge_to_global_factory (2)\n");

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





