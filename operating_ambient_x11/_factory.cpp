#include "platform.h"


__FACTORY_EXPORT void node_x11_factory(::factory::factory * pfactory);
__FACTORY_EXPORT void nano_graphics_cairo_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_x11_factory(::factory::factory * pfactory)
{

   // Register desktop services without replacing the operating-system node.
   node_x11_factory(pfactory);

   // The Acme X11 window creates nano::graphics::context directly from the
   // global factory. Register the Cairo implementation here so that context
   // construction does not depend on a separate lazy component lookup.
   nano_graphics_cairo_factory(pfactory);

}
