#include "framework.h"


extern "C"
void aura_linux_factory_exchange(::factory_map * pfactorymap);


extern "C"
void node_xfce_factory_exchange(::factory_map * pfactorymap);


extern "C"
void desktop_environment_xfce_factory_exchange(::factory_map * pfactorymap)
{

   aura_linux_factory_exchange(pfactorymap);

   node_xfce_factory_exchange(pfactorymap);

   pfactorymap->create_factory < ::desktop_environment_xfce::node, ::acme::node > ();


}



