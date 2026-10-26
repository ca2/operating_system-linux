#include "platform.h"


__FACTORY_EXPORT void node_gtk4_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_gtk4_factory(::factory::factory * pfactory)
{

   // Register desktop services without replacing the operating-system node.
   node_gtk4_factory(pfactory);

}
