//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace aura_linux
{


   class CLASS_DECL_AURA_LINUX node :
      virtual public ::apex_linux::node,
      virtual public ::aura_posix::node
   {
   public:


      node();
      ~node() override;


      void initialize(::object* pobject) override;


      string get_user_name();


      void browse_for_folder(::file::path & pathFolder) override;


   };


} // namespace aura_linux



