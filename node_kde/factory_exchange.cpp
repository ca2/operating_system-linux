#include "framework.h"


extern "C"
void node_kde_factory_exchange()
{

   create_factory < ::node_kde::node, ::acme::node > ();
   create_factory < ::node_kde::copydesk, ::user::copydesk > ();

}



