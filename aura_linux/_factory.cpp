#include "framework.h"


__FACTORY_EXPORT void apex_linux_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void aura_posix_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void aura_linux_factory(::factory_map * pfactorymap)
{


   apex_linux_factory( pfactorymap);


   aura_posix_factory( pfactorymap);


   pfactorymap->create_factory < ::aura::linux::node, ::acme::node >();
   pfactorymap->create_factory < ::linux::interaction_impl, ::user::interaction_impl >();


}



