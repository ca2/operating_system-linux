//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"
#include "acme/windowing/windowing.h"


namespace operating_ambient_x11
{


   CLASS_DECL_ACME void _os_process_user_theme(const ::scoped_string & scopedstrTheme);


   node::node()
   {


   }


   node::~node()
   {


   }


   void node::initialize(::particle * pparticle)
   {

      ::aura_linux::node::initialize(pparticle);

      ::node_x11::node::initialize(pparticle);

   }


   ::e_status node::node_post(const ::procedure & procedure)
   {

      system()->acme_windowing()->_user_post(procedure);

      return ::success;

   }




} // namespace operating_ambient_x11



