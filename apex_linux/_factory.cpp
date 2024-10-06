#include "framework.h"
//#include "apex/operating_system.h"
//#include "apex/operating_system/linux/_linux.h"
//#include "file_os_watcher.h"
#include "apex/platform/launcher.h"
#include "app_launcher.h"
#include "launcher.h"
//#include "process.h"
//#include "os_context.h"
#include "apex/parallelization/service_handler.h"
#include "service_handler.h"
//#include "crypto.h"
#include "ip_enum.h"
//#include "inteprocess_channel.h"
//#include "apex/operating_system/linux/buffer.h"
//#include "apex/os/console.h"
//#include "console.h"
#include "apex/platform/node.h"
#include "node.h"


__FACTORY_EXPORT void apex_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void apex_linux_factory(::factory::factory * pfactory)
{


   apex_posix_factory(pfactory);

   acme_linux_factory(pfactory);


   //create_factory < ::linux::stdio_file, ::file::text_file >();
   //create_factory < ::linux::file, ::file::file >();
   //pfactory->add_factory_item < ::apex_linux::os_context, ::os_context >();
   //pfactory->add_factory_item < ::linux::pipe, ::process::pipe >();
   //pfactory->add_factory_item < ::linux::process, ::process::process >();

   //create_factory < ::linux::console, ::console::console >();
   //pfactory->add_factory_item < ::linux::crypto, ::crypto::crypto >();
   //pfactory->add_factory_item < ::apex_linux::ip_enum, ::networking::ip_enum >();


//   pfactory->add_factory_item < ::linux::interprocess_communication_base, ::inteprocess_channel::base >();
//   pfactory->add_factory_item < ::linux::interprocess_handler, ::inteprocess::handler >();
//   pfactory->add_factory_item < ::linux::interprocess_caller, ::inteprocess::caller >();
   //create_factory < ::linux::inteprocess_channel, ::inteprocess_channel::inteprocess_channel >();


   //create_factory < ::linux::buffer, ::graphics::graphics >();
   //create_factory < ::linux::interaction_impl, ::windowing::window >();

   //pfactory->add_factory_item < ::file::os_watcher, ::file::watcher >();
   //pfactory->add_factory_item < ::file::os_watch, ::file::watch >();

   //pfactory->add_factory_item < ::apex_linux::file_context, ::file_context >();
   pfactory->add_factory_item < ::apex_linux::service_handler, ::service_handler >();

   pfactory->add_factory_item < ::apex_linux::node, ::acme::node >();

   pfactory->add_factory_item < ::apex_linux::app_launcher, ::apex::app_launcher >();

   //create_factory < ::linux::copydesk, ::user::cop
   // 
   // 
   // ydesk >();
   ////create_factory < ::linux::shell, ::user::shell >();


}




