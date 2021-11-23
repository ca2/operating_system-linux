#include "framework.h"


__FACTORY_EXPORT void acme_posix_factory(::factory_map * pfactorymap);


__FACTORY_EXPORT void acme_linux_factory(::factory_map * pfactorymap)
{


   acme_posix_factory(pfactorymap);


   pfactorymap->create_factory < ::acme::linux::node, ::acme::node >();
   pfactorymap->create_factory < ::linux::acme_dir, ::acme_dir >();
   pfactorymap->create_factory < ::linux::acme_file, ::acme_file >();
   pfactorymap->create_factory < ::linux::acme_path, ::acme_path >();

   pfactorymap->create_factory < ::linux::console, ::console::console >();
   pfactorymap->create_factory < ::linux::file, ::file::file >();
   //pfactorymap->create_factory < ::linux::stdio_file, ::file::file >();
   pfactorymap->create_factory < ::linux::stdio_file, ::file::text_file >();


}



