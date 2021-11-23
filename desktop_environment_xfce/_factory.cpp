#include "framework.h"


__FACTORY_EXPORT void aura_linux_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void node_xfce_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void desktop_environment_xfce_factory(::factory_map * pfactorymap)
{

   aura_linux_factory(pfactorymap);

   node_xfce_factory(pfactorymap);

   pfactorymap->create_factory < ::desktop_environment_xfce::node, ::acme::node > ();


}



