#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void aura_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_kde_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void desktop_environment_kde_factory(::factory::factory * pfactory)
{

   aura_linux_factory(pfactory);

   node_kde_factory(pfactory);

   pfactory->add_factory_item < ::desktop_environment_kde::node, ::acme::node > ();
//create_factory < ::node_kde::copydesk, ::user::copydesk > ();
   //pfactory->add_factory_item < ::node_kde::appindicator, ::node_linux::appindicator >();

}



