#include "framework.h"
#include "node.h"
#include "interaction_impl.h"
#include "acme/primitive/primitive/factory.h"


__FACTORY_EXPORT void apex_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_linux_factory(::factory::factory * pfactory)
{


   apex_linux_factory( pfactory);


   aura_posix_factory( pfactory);


   pfactory->add_factory_item < ::aura_linux::node, ::acme::node >();
   pfactory->add_factory_item < ::aura_linux::interaction_impl, ::user::interaction_impl >();


}



