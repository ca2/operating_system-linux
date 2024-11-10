// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


#include "acme_posix/path_system.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX path_system :
      virtual public ::acme_posix::path_system
   {
   public:


      //__creatable_from_library(path_system, ::path_system, "acme_linux");


      path_system();
      ~path_system() override;


   };


} // namespace acme_linux



