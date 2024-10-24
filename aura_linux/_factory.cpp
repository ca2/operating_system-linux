#include "framework.h"
#include "node.h"
#include "interaction_impl.h"
#include "hardware/device_group.h"
#include "hardware/devices.h"
#include "acme/prototype/prototype/factory.h"


__FACTORY_EXPORT void apex_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_linux_factory(::factory::factory * pfactory)
{


   apex_linux_factory( pfactory);


   aura_posix_factory( pfactory);


   pfactory->add_factory_item < ::aura_linux::node, ::platform::node >();
   //pfactory->add_factory_item < ::aura_linux::interaction_impl, ::windowing::window >();


   pfactory->add_factory_item < ::aura_linux::hardware::device_group, ::hardware::device_group >();
   pfactory->add_factory_item < ::aura_linux::hardware::devices, ::hardware::devices >();


}



