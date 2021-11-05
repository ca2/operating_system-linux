#include "framework.h"


extern "C"
void aura_linux_factory_exchange(::factory_map * pfactorymap);


extern "C"
void node_kde_factory_exchange(::factory_map * pfactorymap);


extern "C"
void desktop_environment_kde_factory_exchange(::factory_map * pfactorymap)
{

   aura_linux_factory_exchange(pfactorymap);

   node_kde_factory_exchange(pfactorymap);

   pfactorymap->create_factory < ::desktop_environment_kde::node, ::acme::node > ();
//create_factory < ::node_kde::copydesk, ::user::copydesk > ();
   //pfactorymap->create_factory < ::node_kde::appindicator, ::node_linux::appindicator >();

}



