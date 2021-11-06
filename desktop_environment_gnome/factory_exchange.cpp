#include "framework.h"


extern "C"
void aura_linux_factory_exchange(::factory_map * pfactorymap);


extern "C"
void node_gnome_factory_exchange(::factory_map * pfactorymap);


extern "C"
void desktop_environment_gnome_factory_exchange(::factory_map * pfactorymap)
{

   aura_linux_factory_exchange(pfactorymap);

   node_gnome_factory_exchange(pfactorymap);

   pfactorymap->create_factory < ::desktop_environment_gnome::node, ::acme::node > ();


}



