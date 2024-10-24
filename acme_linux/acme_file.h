// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


#include "acme_posix/file_system.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX file_system :
      virtual public ::acme_posix::file_system
   {
   public:


      //__creatable_from_library(file_system, ::file_system, "acme_linux");


      file_system();
      ~file_system() override;


      ::file::path module() override;


   };


} // namespace acme_linux



