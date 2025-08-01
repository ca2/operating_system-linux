//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "acme_linux/node.h"
#include "apex_posix/node.h"


namespace apex_linux
{


   class CLASS_DECL_APEX_LINUX node :
      virtual public ::acme_linux::node,
      virtual public ::apex_posix::node
   {
   public:


      node();

      ~node() override;


      void initialize(::particle * pparticle) override;


      string get_user_name() override;

      virtual ::e_status process_init();

      void _001InitializeShellOpen() override;

      //void shell_open(const ::file::path & path, const ::scoped_string & scopedstrParams, const ::file::path & pathFolder) override;

      void on_create_app_shortcut(::platform::application * papplication) override;


      ::file::path app_shortcut_path(::platform::application* papplication) override;

      virtual string get_command_line() override;


      virtual void reboot() override;
      virtual void shutdown(bool bPowerOff) override;

      virtual void terminate_processes_by_title(const ::scoped_string & scopedstrName) override;


      bool has_alias_in_path(const ::scoped_string & scopedstr, bool bNoUI, bool bNoMount) override;


      virtual bool linux_can_exec(const ::string &file);


      ::process_identifier_array module_path_processes_identifiers(const ::scoped_string & scopedstrName) override;
      ::process_identifier_array title_processes_identifiers(const ::scoped_string & scopedstrName) override;
      ::process_identifier_array processes_identifiers() override;
      ::file::path process_identifier_module_path(::process_identifier dwPid) override;
      ::process_identifier current_process_identifier() override;

      ::payload connection_settings_get_auto_detect() override;
      ::payload connection_settings_get_auto_config_url() override;


      virtual bool local_machine_set_run(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand);
      virtual bool local_machine_set_run_once(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand);
      virtual bool current_user_set_run(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand);
      virtual bool current_user_set_run_once(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand);
      void defer_register_ca2_plugin_for_mozilla() override;

      void file_extension_get_open_with_list_keys(string_array & straKey, const ::scoped_string & scopedstrExtension) override;
      void file_extension_get_open_with_list_commands(string_array & straCommand, const ::scoped_string & scopedstrExtension) override;

      void file_association_set_default_icon(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass, const ::scoped_string & scopedstrIconPath) override;
      void file_association_set_shell_open_command(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass,  const ::scoped_string & scopedstrCommand, const ::scoped_string & scopedstrParam) override;
      void file_association_get_shell_open_command(const ::scoped_string & scopedstrExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;


      virtual bool open_in_ie(const ::string & pcsz);


      void link_open(const ::scoped_string & scopedstrUrl, const ::scoped_string & scopedstrProfile);


      virtual bool create_service(::particle * pparticle);
      virtual bool erase_service(::particle * pparticle);

      virtual bool start_service(::particle * pparticle);
      virtual bool stop_service(::particle * pparticle);

      void raise_exception( unsigned int dwExceptionCode, unsigned int dwExceptionFlags);

      bool is_remote_session() override;

      virtual void post_to_all_threads(::enum_message emessage, ::wparam wparam, ::lparam lparam);


      void initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;

      void get_default_browser(string & strId, ::file::path & path, string & strParam) override;

      void file_open(const ::file::path & pathTarget, const ::scoped_string & scopedstrParams = "", const ::file::path & pathFolder = "") override;

      void list_process(::file::path_array & patha, ::process_identifier_array & processidentifierarray) override;

   };


} // namespace apex_linux



