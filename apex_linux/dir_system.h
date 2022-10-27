#pragma once


#include "apex/filesystem/filesystem/dir_system.h"


namespace apex_linux
{


   class CLASS_DECL_APEX dir_system :
      virtual public ::dir_system
   {
   public:


      ::file::path            m_pathTimeFolder;
      ::file::path            m_pathNetSeedFolder;

      //::file::path            m_pathCa2;
      ::file::path            m_pathCommonAppData;
      ::file::path            m_pathCommonPrograms;
      ::file::path            m_pathProfile;
      ::file::path            m_pathPrograms;


      dir_system();
      ~dir_system() override;


      void initialize(::particle * pparticle) override;


   };


} // namespace apex_linux



