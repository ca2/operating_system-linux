#include "framework.h"


__FACTORY_EXPORT void write_text_pango_factory(::factory_map * pfactorymap)
{

   pfactorymap->create_factory < ::write_text_pango::font_department, ::font_department >();
   pfactorymap->create_factory < ::write_text_pango::write_text, ::write_text::write_text >();

}
