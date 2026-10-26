#include "platform.h"


__FACTORY_EXPORT void node_lxq2_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_lxq2_factory(::factory::factory * pfactory)
{

   // Register desktop services without replacing the operating-system node.
   node_lxq2_factory(pfactory);

}
