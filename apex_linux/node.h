//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "acme_linux/node.h"
#include "apex_posix/node.h"


namespace apex_linux
{


   class CLASS_DECL_APEX_LINUX node :
      virtual public ::acme_linux::node,
      virtual public ::apex_posix::node
   {
   public:


      node();

      ~node() override;


      void initialize(::particle * pparticle) override;


      string get_user_name() override;

      virtual ::e_status process_init();

      virtual int node_init_check(int *, char ***);


      void _001InitializeShellOpen() override;

      //void shell_open(const ::file::path & path, const ::string& strParams, const ::file::path & pathFolder) override;


   };


} // namespace apex_linux



