#include "platform.h"


__FACTORY_EXPORT void node_lxq1_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_lxq1_factory(::factory::factory * pfactory)
{

   // Register desktop services without replacing the operating-system node.
   node_lxq1_factory(pfactory);

}
