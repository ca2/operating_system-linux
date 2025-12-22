//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "aura_linux/node.h"
#include "node_x11/node.h"


namespace operating_ambient_x11
{


   class CLASS_DECL_OPERATING_AMBIENT_X11 node :
      virtual public ::aura_linux::node,
      virtual public ::node_x11::node
   {
   public:



      node();
      ~node() override;


      virtual void initialize(::particle * pparticle) override;


      virtual ::e_status node_post(const ::procedure & procedure);


   };


} // namespace operating_ambient_x11




