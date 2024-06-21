//
// Created by camilo on 21/01/2021. <33TBS!!
//
//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "acme_posix/node.h"


namespace acme_linux
{


   class CLASS_DECL_ACME_LINUX node :
      virtual public ::acme_posix::node
   {
   public:


      //__creatable_from_library(node, ::acme::node, "acme_linux");

      //::user::enum_desktop             m_edesktop;


      //static ::user::enum_desktop      s_edesktop;

      enum_linux_distribution          m_elinuxdistribution;

      ::file::path                     m_strTimeFolder;
      ::file::path                     m_strNetSeedFolder;

      ::file::path                     m_strCommonAppData;
      ::file::path                     m_strAppData;
      ::file::path                     m_strPrograms;
      ::file::path                     m_strCommonPrograms;



      node();
      ~node() override;


      //void initialize_matter(::matter * pmatter) override;


      ::file::path _module_path() override;


      //virtual ::string dir_root() override;

      //virtual ::file::path get_memory_map_base_folder_path() const override;

      //virtual ::file::path home() override;

      //virtual ::file::path program_data() override;

      //virtual ::file::path roaming() override;


      void install_crash_dump_reporting(const string & strModuleNameWithTheExeExtension) override;


      //virtual bool memcnts();

      //virtual ::file::path memcnts_base_path();

      //virtual ::e_status datetime_to_file_time(file_time_t * pFileTime, const ::earth::time& time) override;


      //virtual ::e_status ::windows::last_error_status(::u32 dwLastError);


      string audio_get_default_implementation_name() override;


      void calculate_linux_distribution() override;


//      ::user::enum_desktop get_edesktop() override;
//
//
//      ::user::enum_desktop calculate_edesktop() override;
//
//
//      static ::user::enum_desktop get_edesktop();
//      static ::user::enum_desktop _calculate_edesktop();


      ::file::path_array process_identifier_modules_paths(::process_identifier processidentifier) override;

      bool load_modules_diff(string_array& straOld, string_array& straNew, const ::string & strExceptDir) override;

      ::process_identifier_array processes_identifiers() override;

      ::process_identifier_array module_path_processes_identifiers(const ::string & strModulePath, bool bModuleNameIsPropertyFormatted) override;

      ::file::path process_identifier_module_path(::process_identifier pid) override;

      string process_identifier_command_line(::process_identifier pid) override;

      //bool is_shared_library_busy(::process_identifier pid, const string_array& stra) override;

      //bool is_shared_library_busy(const string_array& stra) override;

      bool process_contains_module(string& strImage, ::process_identifier processID, const ::string & strLibrary) override;

      ::process_identifier_array shared_library_process(string_array& straProcesses, const ::string & strLibrary) override;

      bool is_process_running(::process_identifier pid) override;

      string get_environment_variable(const ::scoped_string & scopedstrEnvironmentVariable) override;

      string expand_environment_variables(const ::scoped_string & scopedstr) override;


      array <::serial::port_info> list_serial_ports() override;


      void shell_open(const ::file::path & path, const ::string & strParams = "", const ::file::path & pathFolder = "") override;

      //void shell_execute_async(const char *psz, const char * pszParams) override;


      bool set_process_priority(::enum_priority epriority) override;


      ::pointer <::operating_system::summary > operating_system_summary() override;


      enum_linux_distribution get_linux_distribution() const override;


      ::file::path get_default_base_integration_folder() override;


      ::file::path ___fonts_folder() override;


      ::string default_component_implementation(const ::scoped_string & scopedstrComponentName) override;


   };


} // namespace acme_linux



