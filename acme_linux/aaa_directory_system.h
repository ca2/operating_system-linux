#pragma once


#include "acme/filesystem/filesystem/directory_system.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX directory_system :
      virtual public ::directory_system
   {
   public:


      ::file::path            m_pathTimeFolder;
      ::file::path            m_pathNetSeedFolder;

      //::file::path            m_pathCa2;
      ::file::path            m_pathCommonAppData;
      ::file::path            m_pathCommonPrograms;
      ::file::path            m_pathProfile;
      ::file::path            m_pathPrograms;


      directory_system();
      ~directory_system() override;


      void initialize(::particle * pparticle) override;


   };


} // namespace apex_linux



