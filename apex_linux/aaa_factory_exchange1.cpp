#include "framework.h"


extern "C"
void node_linux_factory(::factory::factory * pfactory)
{

   create_factory < node_linux::node, ::acme::node >();

}



