// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


namespace linux
{


   class CLASS_DECL_ACME_LINUX acme_file :
      virtual public ::posix::acme_file
   {
   public:


      //__creatable_from_library(acme_file, ::acme_file, "acme_linux");


      acme_file();
      ~acme_file() override;


      ::file::path module() override;


   };


} // namespace linux


