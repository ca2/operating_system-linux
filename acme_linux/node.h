//
// Created by camilo on 21/01/2021. <33TBS!!
//
//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace acme
{


   namespace linux
   {


      class CLASS_DECL_ACME_LINUX node :
         virtual public ::acme::posix::node
      {
      public:


         __creatable_from_library(node, ::acme::node, "acme_linux_node");

         ::user::enum_desktop             m_edesktop;


         static ::user::enum_desktop      s_edesktop;



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

         //virtual ::e_status datetime_to_filetime(filetime_t * pFileTime, const ::datetime::time& time) override;


         //virtual ::e_status last_error_to_status(::u32 dwLastError);


         string audio_get_default_library_name() override;


         void calculate_linux_distribution() override;


         ::user::enum_desktop get_edesktop() override;


         ::user::enum_desktop calculate_edesktop() override;


         static ::user::enum_desktop _get_edesktop();
         static ::user::enum_desktop _calculate_edesktop();


         virtual bool process_modules(string_array& stra, u32 processID);

         virtual bool load_modules_diff(string_array& straOld, string_array& straNew, const char* pszExceptDir);

         virtual id_array get_pids();

         virtual id_array module_path_get_pid(const char* pszModulePath, bool bModuleNameIsPropertyFormatted);

         virtual string module_path_from_pid(u32 pid);

         virtual string command_line_from_pid(u32 pid);

         virtual bool is_shared_library_busy(u32 processid, const string_array& stra);

         virtual bool is_shared_library_busy(const string_array& stra);

         virtual bool process_contains_module(string& strImage, ::u32 processID, const char* pszLibrary);

         virtual void shared_library_process(dword_array& dwa, string_array& straProcesses, const char* pszLibrary);

         virtual bool is_process_running(::u32 pid);

         virtual string get_environment_variable(const char* pszEnvironmentVariable);

         virtual string expand_environment_variables(const string & str);


         virtual array <::serial::port_info> list_serial_ports();


      };


   } // namespace linux


} // namespace acme



