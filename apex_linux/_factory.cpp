#include "framework.h"
#include "apex/operating_system.h"
//#include "apex/node/linux/_linux.h"
//#include "file_os_watcher.h"
#include "apex/platform/launcher.h"
#include "launcher.h"
#include "dir_system.h"
#include "dir_context.h"
#include "file_system.h"
#include "platform-posix/apex_posix/file_context.h"
#include "file_context.h"
//#include "process.h"
#include "os_context.h"
#include "apex/parallelization/service_handler.h"
#include "service_handler.h"
#include "crypto.h"
#include "ip_enum.h"
#include "interprocess_communication.h"
//#include "apex/node/linux/buffer.h"
//#include "apex/os/console.h"
//#include "console.h"
#include "apex/platform/node.h"
#include "node.h"


extern "C"
void apex_posix_factory_exchange(::factory_map * pfactorymap);


extern "C"
void acme_linux_factory_exchange(::factory_map * pfactorymap);


extern "C"
void apex_linux_factory_exchange(::factory_map * pfactorymap)
{


   apex_posix_factory_exchange(pfactorymap);

   acme_linux_factory_exchange(pfactorymap);

   pfactorymap->create_factory < ::linux::dir_system, ::dir_system >();
   pfactorymap->create_factory < ::linux::file_system, ::file_system >();

   pfactorymap->create_factory < ::linux::dir_context, ::dir_context >();
   pfactorymap->create_factory < ::linux::file_context, ::file_context >();

   //create_factory < ::linux::stdio_file, ::file::text_file >();
   //create_factory < ::linux::file, ::file::file >();
   pfactorymap->create_factory < ::linux::os_context, ::os_context >();
   //pfactorymap->create_factory < ::linux::pipe, ::process::pipe >();
   //pfactorymap->create_factory < ::linux::process, ::process::process >();

   //create_factory < ::linux::console, ::console::console >();
   //pfactorymap->create_factory < ::linux::crypto, ::crypto::crypto >();
   pfactorymap->create_factory < ::linux::ip_enum, ::net::ip_enum >();


   pfactorymap->create_factory < ::linux::interprocess_communication_base, ::interprocess_communication::base >();
   pfactorymap->create_factory < ::linux::interprocess_communication_rx, ::interprocess_communication::rx >();
   pfactorymap->create_factory < ::linux::interprocess_communication_tx, ::interprocess_communication::tx >();
   //create_factory < ::linux::interprocess_communication, ::interprocess_communication::interprocess_communication >();


   //create_factory < ::linux::buffer, ::graphics::graphics >();
   //create_factory < ::linux::interaction_impl, ::user::interaction_impl >();

   //pfactorymap->create_factory < ::file::os_watcher, ::file::watcher >();
   //pfactorymap->create_factory < ::file::os_watch, ::file::watch >();

   pfactorymap->create_factory < ::linux::file_context, ::file_context >();
   pfactorymap->create_factory < ::linux::service_handler, ::service_handler >();

   pfactorymap->create_factory < ::apex::linux::node, ::acme::node >();

   //create_factory < ::linux::copydesk, ::user::cop
   // 
   // 
   // ydesk >();
   ////create_factory < ::linux::shell, ::user::shell >();


}




