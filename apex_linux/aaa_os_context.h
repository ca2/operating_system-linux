#pragma once



#include "apex_posix/os_context.h"

//
//namespace apex_linux
//{
//
//
//   class CLASS_DECL_APEX os_context :
//      public ::apex_posix::os_context
//   {
//   public:
//
//
//      os_context();
//      ~os_context() override;
//
//
////      virtual string get_command_line() override;
////
////
////      virtual void reboot() override;
////      virtual void shutdown(bool bPowerOff) override;
////
////      virtual void terminate_processes_by_title(const ::string & lpszName) override;
////
////
////      bool has_alias_in_path(const ::scoped_string & scopedstr, bool bNoUI, bool bNoMount) override;
////
////
////      virtual bool linux_can_exec(const ::string &file);
////
////
////      ::process_identifier_array module_path_processes_identifiers(const ::scoped_string & scopedstrName) override;
////      ::process_identifier_array title_processes_identifiers(const ::scoped_string & scopedstrName) override;
////      ::process_identifier_array processes_identifiers() override;
////      ::file::path process_identifier_module_path(::process_identifier dwPid) override;
////      ::process_identifier current_process_identifier() override;
////
////      ::payload connection_settings_get_auto_detect() override;
////      ::payload connection_settings_get_auto_config_url() override;
////
////
////      virtual bool local_machine_set_run(const ::string & pszKey, const ::string & pszCommand);
////      virtual bool local_machine_set_run_once(const ::string & pszKey, const ::string & pszCommand);
////      virtual bool current_user_set_run(const ::string & pszKey, const ::string & pszCommand);
////      virtual bool current_user_set_run_once(const ::string & pszKey, const ::string & pszCommand);
////      void defer_register_ca2_plugin_for_mozilla() override;
////
////      void file_extension_get_open_with_list_keys(string_array & straKey, const ::string & pszExtension) override;
////      void file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & pszExtension) override;
////
////      void file_association_set_default_icon(const ::string & pszExtension, const ::string & pszExtensionNamingClass, const ::string & pszIconPath) override;
////      void file_association_set_shell_open_command(const ::string & pszExtension, const ::string & pszExtensionNamingClass,  const ::string & pszCommand, const ::string & pszParam) override;
////      void file_association_get_shell_open_command(const ::string & pszExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;
////
////
////      virtual bool open_in_ie(const ::string & pcsz);
////
////
////      void link_open(const ::string & strUrl, const ::string & strProfile);
////
////
////      virtual bool create_service(::particle * pparticle);
////      virtual bool erase_service(::particle * pparticle);
////
////      virtual bool start_service(::particle * pparticle);
////      virtual bool stop_service(::particle * pparticle);
////
////      void raise_exception( unsigned int dwExceptionCode, unsigned int dwExceptionFlags);
////
////      bool is_remote_session() override;
////
////      virtual void post_to_all_threads(::enum_message emessage, ::wparam wparam, ::lparam lparam);
////
////
////      void initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;
////
////      void get_default_browser(string & strId, ::file::path & path, string & strParam) override;
////
////      void file_open(const ::file::path & pathTarget, const ::string & strParams = "", const ::file::path & pathFolder = "") override;
////
////      void list_process(::file::path_array & patha, ::process_identifier_array & processidentifierarray) override;
//
//
//
//
//   };
//
//
//} // namespace apex_linux
//


//typedef string GET_FILE_CONTENT_TYPE(string strPath);

//typedef GET_FILE_CONTENT_TYPE * PFN_GET_FILE_CONTENT_TYPE;

//void set_get_file_content_type_function(PFN_GET_FILE_CONTENT_TYPE pfnGetFileContentType);

