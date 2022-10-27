#pragma once



#include "apex_posix/os_context.h"


namespace apex_linux
{


   class CLASS_DECL_APEX os_context :
      public ::apex_posix::os_context
   {
   public:


      os_context();
      ~os_context() override;


      virtual string get_command_line() override;


      virtual void reboot() override;
      virtual void shutdown(bool bPowerOff) override;

      virtual void terminate_processes_by_title(const ::string & lpszName) override;


      bool has_alias_in_path(const char * psz, bool bNoUI, bool bNoMount) override;


      virtual bool linux_can_exec(const ::string &file);


      //virtual ::file::path get_module_path(HMODULE hmodule) override;


      bool path_pid(::u32 & dwPid, const ::string & lpszName) override;
      bool title_pid(::u32 & dwPid, const ::string & lpszName) override;
      void get_all_processes(u32_array & dwa) override;
      ::file::path get_process_path(::u32 dwPid) override;
      int get_pid() override;

      ::payload connection_settings_get_auto_detect() override;
      ::payload connection_settings_get_auto_config_url() override;


      virtual bool local_machine_set_run(const ::string & pszKey, const ::string & pszCommand);
      virtual bool local_machine_set_run_once(const ::string & pszKey, const ::string & pszCommand);
      virtual bool current_user_set_run(const ::string & pszKey, const ::string & pszCommand);
      virtual bool current_user_set_run_once(const ::string & pszKey, const ::string & pszCommand);
      void defer_register_ca2_plugin_for_mozilla() override;

      void file_extension_get_open_with_list_keys(string_array & straKey, const ::string & pszExtension) override;
      void file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & pszExtension) override;

      void file_association_set_default_icon(const ::string & pszExtension, const ::string & pszExtensionNamingClass, const ::string & pszIconPath) override;
      void file_association_set_shell_open_command(const ::string & pszExtension, const ::string & pszExtensionNamingClass,  const ::string & pszCommand, const ::string & pszParam) override;
      void file_association_get_shell_open_command(const ::string & pszExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;


      virtual bool open_in_ie(const ::string & pcsz);


      void link_open(const ::string & strUrl, const ::string & strProfile);


      virtual bool create_service(::particle * pparticle);
      virtual bool erase_service(::particle * pparticle);

      virtual bool start_service(::particle * pparticle);
      virtual bool stop_service(::particle * pparticle);

      void raise_exception( ::u32 dwExceptionCode, ::u32 dwExceptionFlags);

      bool is_remote_session() override;

      virtual void post_to_all_threads(const ::atom & atom, wparam wparam, lparam lparam);


      void initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;

      void get_default_browser(string & strId, ::file::path & path, string & strParam) override;

      void file_open(const ::file::path & pathTarget, const ::string & strParams = "", const ::file::path & pathFolder = "") override;

      void list_process(::file::path_array & patha, u32_array & iaPid) override;


      virtual ::file::path _get_auto_start_desktop_file_path(const ::string & strAppId);

      void register_user_auto_start(const string & strAppId, const string & strCommand, const string & strArguments,
                                    bool bRegister) override;

      bool is_user_auto_start(const string & strAppId) override;


   };


} // namespace apex_linux



//typedef string GET_FILE_CONTENT_TYPE(string strPath);

//typedef GET_FILE_CONTENT_TYPE * PFN_GET_FILE_CONTENT_TYPE;

//void set_get_file_content_type_function(PFN_GET_FILE_CONTENT_TYPE pfnGetFileContentType);

