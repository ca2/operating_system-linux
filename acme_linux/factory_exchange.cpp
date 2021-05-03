#include "framework.h"


extern "C"
void acme_posix_factory_exchange(::factory_map * pfactorymap);


extern "C"
void acme_linux_factory_exchange(::factory_map * pfactorymap)
{


   acme_posix_factory_exchange(pfactorymap);


   pfactorymap->create_factory < ::acme::linux::node, ::acme::node >();
   pfactorymap->create_factory < ::linux::acme_dir, ::acme_dir >();
   pfactorymap->create_factory < ::linux::acme_path, ::acme_path >();

   pfactorymap->create_factory < ::linux::console, ::console::console >();
   pfactorymap->create_factory < ::linux::file, ::file::file >();
   pfactorymap->create_factory < ::linux::stdio_file, ::file::text_file >();


}



