// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


namespace linux
{


   class CLASS_DECL_ACME_LINUX acme_file :
      virtual public ::posix::acme_file
   {
   public:


      acme_file();
      ~acme_file() override;


      ::file::path executable() override;


   };


} // namespace linux



