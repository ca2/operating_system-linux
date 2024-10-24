#include "framework.h"
#include "node.h"
#include "directory_system.h"
#include "file_system.h"
#include "path_system.h"
//#include "console.h"
#include "directory_system.h"
#include "directory_context.h"
#include "file_context.h"
#include "file_system.h"
#include "file.h"


__FACTORY_EXPORT void acme_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_linux_factory(::factory::factory * pfactory)
{


   acme_posix_factory(pfactory);


   pfactory->add_factory_item < ::acme_linux::node, ::platform::node >();
   pfactory->add_factory_item < ::acme_linux::directory_system, ::directory_system >();
   pfactory->add_factory_item < ::acme_linux::file_system, ::file_system >();
   pfactory->add_factory_item < ::acme_linux::path_system, ::path_system >();


   pfactory->add_factory_item < ::acme_linux::directory_system, ::directory_system >();
   pfactory->add_factory_item < ::acme_linux::file_system, ::file_system >();
   pfactory->add_factory_item < ::acme_linux::directory_context, ::directory_context >();
   pfactory->add_factory_item < ::acme_linux::file_context, ::file_context >();


   //pfactory->add_factory_item < ::acme_linux::console, ::console::console >();
   //pfactory->add_factory_item < ::acme_linux::file, ::file::file >();
   //pfactory->add_factory_item < ::linux::stdio_file, ::file::file >();
   //pfactory->add_factory_item < ::linux::stdio_file, ::file::text_file >();


}



