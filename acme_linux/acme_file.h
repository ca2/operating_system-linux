// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


#include "acme_posix/acme_file.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX acme_file :
      virtual public ::acme_posix::acme_file
   {
   public:


      //__creatable_from_library(acme_file, ::acme_file, "acme_linux");


      acme_file();
      ~acme_file() override;


      ::file::path module() override;


   };


} // namespace acme_linux



