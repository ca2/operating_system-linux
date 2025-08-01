// Create on 2021-03-21 20:00 <3ThomasBS_
#pragma once


#include "acme_posix/directory_system.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX directory_system :
      virtual public ::acme_posix::directory_system
   {
   public:


      ::file::path            m_pathTimeFolder;
      ::file::path            m_pathNetSeedFolder;

      //::file::path            m_pathCa2;
      ::file::path            m_pathCommonAppData;
      ::file::path            m_pathCommonPrograms;
      ::file::path            m_pathProfile;
      ::file::path            m_pathPrograms;

      //__creatable_from_library(directory_system, ::directory_system, "acme_linux");


      directory_system();
      ~directory_system() override;


      void initialize(::particle * pparticle) override;


      ::file::path install() override;
      ::file::path default_install() override;
      ::file::path beforeca2() override;
      ::file::path module() override;
      ::file::path relative(::file::path path) override;
      ::string appid() override;
      ::file::path appdata() override; // appdata
      ::file::path archive() override;
      ::file::path tool() override;
      //::file::path public_system() override;
      ::file::path userconfig() override;
      ::file::path config() override;
      ::file::path local() override;
      ::file::path sensitive() override;
      ::file::path localconfig() override; // #vcs C:\\Users\\user\\AppData\\Roaming\\ca2\\localconfig
      ::file::path ca2roaming() override; // writable root (non-bin, non-exe)
      ::file::path ca2appdata() override; // writable root (non-bin, non-exe)
      ::file::path roaming() override;
      ::file::path program_data() override;
      ::file::path public_root() override; // writable common root (non-bin, non-exe)
      ::file::path bookmark() override;
      ::file::path home() override;
      ::file::path pathfind(const ::scoped_string & scopedstrEnv, const ::scoped_string & scopedstrTopic, const ::scoped_string & scopedstrMode) override;
      ::file::path program_files_x86() override;
      ::file::path program_files() override;
      //::file::path program_data() override;
      ::file::path stage(string strAppId, string strPlatform, string strConfiguration) override;
      ::file::path sys_temp() override;
      ::string dir_root() override;
      //virtual ::file::path home() override;
      //virtual ::file::path program_data() override;
      //virtual ::file::path roaming() override;
      ::file::path get_memory_map_base_folder_path() override;
      //virtual ::file::path ca2appdata() override;
      //virtual ::file::path ca2roaming() override;
      //virtual ::file::path localconfig() override;
      string system_short_name() override;


      //::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      //virtual ::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      ::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      ::file::path inplace_matter_install(string strAppId, string strPlatform, string strConfiguration) override;


      void set_path_install_folder(const ::scoped_string & scopedstrPath) override;

      //virtual  bool        _shell_get_special_folder_path(HWND hwnd, ::file::path& str, int csidl, bool fCreate);
      //virtual ::file::path _shell_get_special_folder_path(int csidl, bool fCreate = true, ::windowing::window* pwindow = nullptr);
      //virtual ::file::path _get_known_folder(REFKNOWNFOLDERID kfid);

      //virtual ::file::path pathfind(const ::scoped_string & scopedstrEnv, const ::scoped_string & scopedstrTopic, const ::scoped_string & scopedstrMode) override;

      ::file::path user_appdata_local() override;





   };


} // namespace acme_linux



