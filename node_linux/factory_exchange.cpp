#include "framework.h"

//
//namespace node_gnome
//{
//
//
//   factory_exchange::factory_exchange()
//   {
//
//      create_factory < node, ::acme::node > ();
//
//   }
//
//
//   factory_exchange::~factory_exchange()
//   {
//
//   }
//
//
//} // namespace music
//
//
//
//





extern "C"
void node_gnome_factory_exchange()
{

   create_factory < ::node_gnome::node, ::acme::node > ();
   create_factory < ::node_gnome::copydesk, ::user::copydesk > ();

}



