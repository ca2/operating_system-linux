#include "acme/_start.h"
#include "acme/_.h"
__FACTORY_EXPORT void nano_graphics_cairo_factory(::factory::factory * factory);
IMPLEMENT_FACTORY(operating_ambient_wayland)
{
   // Keep the existing OS node; native Wayland supplies its own event transport.
   nano_graphics_cairo_factory(pfactory);
}
