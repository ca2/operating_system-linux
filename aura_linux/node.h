//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace aura
{


   namespace linux
   {


      class CLASS_DECL_AURA_LINUX node :
         virtual public ::apex::linux::node,
         virtual public ::aura::posix::node
      {
      public:


         node();
         ~node() override;


         void initialize(::object* pobject) override;


         string get_user_name();


         void browse_for_folder(::file::path & pathFolder) override;


      };


   } // namespace linux


} // namespace aura



