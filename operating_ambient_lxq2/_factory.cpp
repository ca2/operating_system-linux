#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void aura_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_kde6_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_kde6_factory(::factory::factory * pfactory)
{

   aura_linux_factory(pfactory);

   node_kde6_factory(pfactory);

   pfactory->add_factory_item < ::operating_ambient_kde6::node, ::platform::node > ();


}



