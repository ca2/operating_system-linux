//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once



#include "aura_posix/node.h"
#include "apex_linux/node.h"


namespace aura_linux
{


   class CLASS_DECL_AURA_LINUX node :
      virtual public ::apex_linux::node,
      virtual public ::aura_posix::node
   {
   public:


      node();
      ~node() override;


      void initialize(::particle * pparticle) override;


      string get_user_name();


      void browse_for_folder(::file::path & pathFolder) override;


   };


} // namespace aura_linux



