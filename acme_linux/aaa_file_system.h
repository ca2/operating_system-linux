#pragma once


#include "acme/filesystem/filesystem/file_system.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX file_system:
      virtual public ::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void initialize(::particle * pparticle) override;

      void init_system() override;

      //virtual ::e_status update_module_path() override;


   };


} // namespace acme_linux



