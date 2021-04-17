#include "framework.h"
//#include "acme/node/windows/registry.h"
//#include "acme_linux/acme.h"
//#include "apex_windows/apex.h"
//#include "aura.h"

extern "C"
void apex_linux_factory_exchange(::factory_map * pfactorymap);


extern "C"
void aura_linux_factory_exchange(::factory_map * pfactorymap)
{

   apex_linux_factory_exchange( pfactorymap);

   pfactorymap->create_factory < ::linux::aura::node, ::acme::node >();

}



