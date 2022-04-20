//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace apex
{


   namespace linux
   {


      class CLASS_DECL_APEX_LINUX node :
         virtual public ::acme::linux::node,
         virtual public ::apex::posix::node
      {
      public:


         node();

         ~node() override;


         void initialize(::object * pobject) override;


         string get_user_name() override;

         virtual ::e_status process_init();

         virtual int node_init_check(int *, char ***);


         void _001InitializeShellOpen() override;

         //void shell_open(const ::file::path & path, const ::string& strParams, const ::file::path & pathFolder) override;


      };


   } // namespace linux


} // namespace apex



