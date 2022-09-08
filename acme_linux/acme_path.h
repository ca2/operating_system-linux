// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


#include "acme_posix/acme_path.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX acme_path :
      virtual public ::acme_posix::acme_path
   {
   public:


      //__creatable_from_library(acme_path, ::acme_path, "acme_linux");


      acme_path();
      ~acme_path() override;


   };


} // namespace acme_linux



