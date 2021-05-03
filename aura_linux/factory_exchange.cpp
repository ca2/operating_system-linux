#include "framework.h"


extern "C"
void apex_linux_factory_exchange(::factory_map * pfactorymap);

extern "C"
void aura_posix_factory_exchange(::factory_map * pfactorymap);

extern "C"
void aura_linux_factory_exchange(::factory_map * pfactorymap)
{

   apex_linux_factory_exchange( pfactorymap);

   aura_posix_factory_exchange( pfactorymap);

   pfactorymap->create_factory < ::aura::linux::node, ::acme::node >();
   pfactorymap->create_factory < ::linux::interaction_impl, ::user::interaction_impl >();

}



