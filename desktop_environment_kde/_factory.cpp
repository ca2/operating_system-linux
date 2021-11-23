#include "framework.h"


__FACTORY_EXPORT void aura_linux_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void node_kde_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void desktop_environment_kde_factory(::factory_map * pfactorymap)
{

   aura_linux_factory(pfactorymap);

   node_kde_factory(pfactorymap);

   pfactorymap->create_factory < ::desktop_environment_kde::node, ::acme::node > ();
//create_factory < ::node_kde::copydesk, ::user::copydesk > ();
   //pfactorymap->create_factory < ::node_kde::appindicator, ::node_linux::appindicator >();

}



