#include "platform.h"
#include "node.h"


__FACTORY_IMPORT void aura_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_linux_factory(::factory::factory * pfactory)
{

   aura_linux_factory(pfactory);

   pfactory->add_factory_item<::node_linux::node, ::platform::node>();

}
