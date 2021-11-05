#include "framework.h"


extern "C"
void node_linux_factory_exchange(::factory_map * pfactorymap)
{

   create_factory < node_linux::node, ::acme::node >();

}



