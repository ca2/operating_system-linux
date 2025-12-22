#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void aura_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_x11_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_x11_factory(::factory::factory * pfactory)
{


   aura_linux_factory(pfactory);

   node_x11_factory(pfactory);

   pfactory->add_factory_item < ::operating_ambient_x11::node, ::platform::node > ();


}



