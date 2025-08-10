#include "framework.h"
#include "os_context.h"
#include "node.h"
#include "acme/exception/not_implemented.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/path_system.h"
#include "acme/filesystem/filesystem/link.h"
#include "apex/filesystem/file/set.h"
//#include "acme/filesystem/filesystem/link.h"
#include "apex/operating_system/department.h"
#include "apex/platform/system.h"


int daemonize_process(const ::string & _cmd_line, int * pprocessId);

#undef USERNAME_LENGTH // mysql one


#include <sys/stat.h>
#include <unistd.h>


string empty_get_file_content_type(string)
{

   return "";

}

//PFN_GET_FILE_CONTENT_TYPE g_pfnGetFileContentType = &empty_get_file_content_type;
//
//string linux_get_file_content_type(string strPath)
//{
//
//   return (*g_pfnGetFileContentType)(strPath);
//
//}
//
//void set_get_file_content_type_function(PFN_GET_FILE_CONTENT_TYPE pfnGetFileContentType)
//{
//
//   g_pfnGetFileContentType = pfnGetFileContentType;
//
//}


namespace apex_linux
{


   os_context::os_context()
   {
   }


   os_context::~os_context()
   {
   }


   string os_context::get_command_line()
   {

      return platform()->m_strCommandLine;

   }


   void os_context::shutdown(bool bIfPowerOff)
   {

      node()->unix_shell_command("shutdown -h now");

   }


   void os_context::reboot()
   {

      //::sync();
      //::reboot(RB_AUTOBOOT);

      system()->m_pnode->reboot();

      //return false;

   }


   void os_context::terminate_processes_by_title(const ::string & lpszName)
   {

      throw ::not_implemented();

      return;

      /*      unsigned int dwPid;
            while(get_pid_by_title(lpszName, dwPid))
            {
               HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                  PROCESS_VM_READ,
                  false, dwPid );
               TerminateProcess(hProcess, (unsigned int) -1);
               Clos_contexteHandle(hProcess);
               ::EnumWindows((WNDENUMPROC)
               CKillProcessHelper::TerminateAppEnum,
               (LPARAM) dwId);
               // Wait on the handle. If it signals, great.

               //If it times out, then you kill it.

               if(WaitForSingleObject(hProcess, 5000)
               !=WAIT_OBJECT_0)
               bResult = TerminateProcess(hProcess,0);
               else
               bResult = true;
               Clos_contexteHandle(hProcess);
               return bResult == true;*/

      //  }
   }


   ::process_identifier_array os_context::module_path_processes_identifiers(const ::scoped_string & scopedstrName)
   {

      ::process_identifier_array processidentifiera;

      auto dwa = processes_identifiers();

      for(int i = 0; i < dwa.get_count(); i++)
      {

         if(process_identifier_module_path(dwa[i]).case_insensitive_equals(scopedstrName))
         {

            processidentifiera.add(dwa[i]);

         }

      }

      return processidentifiera;

   }


   ::process_identifier_array os_context::title_processes_identifiers(const ::scoped_string & scopedstrName)
   {

      ::process_identifier_array processidentifiera;

      auto dwa = processes_identifiers();

      for(int i = 0; i < dwa.get_count(); i++)
      {

         if(process_identifier_module_path(dwa[i]).title().case_insensitive_equals(scopedstrName))
         {

            processidentifiera.add(dwa[i]);

         }

      }

      return processidentifiera;

   }


   ::file::path os_context::process_identifier_module_path(::process_identifier dwPid)
   {

      throw ::not_implemented();

      return {};

   }


   ::process_identifier_array os_context::processes_identifiers()
   {

      throw ::not_implemented();

      return {};

      /*
            dwa.set_size(0);
            unsigned int cbNeeded = 0;
            while(cbNeeded == natural(dwa.get_count()))
            {
               dwa.set_size(dwa.get_count() + 1024);
               if(!EnumProcesses(
                  dwa.get_data(),
                  (unsigned int) (dwa.get_count() * sizeof(unsigned int)),
                  &cbNeeded))
               {
                  return;
               }
               dwa.set_size(cbNeeded / sizeof(unsigned int));
            }*/
   }

//   string os_context::get_module_path(HMODULE hmodule)
//   {
//      throw ::not_implemented();
//      return "";
//      /*
//      string strPath;
//      unsigned int dwSize = 1;
//      while(natural(strPath.get_length() + 1) == dwSize)
//      {
//         dwSize = ::GetModuleFileName(
//            hmodule,
//            strPath.get_buffer(dwSize + 1024),
//            (dwSize + 1024));
//         strPath.ReleaseBuffer();
//      }
//      return strPath;*/
//   }


   ::payload os_context::connection_settings_get_auto_detect()
   {
      //throw ::not_implemented();
      return false;

      /*
            registry::Key key1;

            key1.OpenKey(HKEY_CURRENT_USER, "Software\\Micros_contextoft\\Windows\\CurrentVersion\\Internet Settings\\Connections", false);

            memory mem;

            key1.QueryValue("DefaultConnectionSettings", mem);

            bool bAutoDetect = (((unsigned char *) mem.get_data())[8] & 0x08) != 0;

            return bAutoDetect;
      */
   }



   ::payload os_context::connection_settings_get_auto_config_url()
   {

      //throw ::not_implemented();
      return "";
      /*
            registry::Key key;

            key.OpenKey(HKEY_CURRENT_USER, "Software\\Micros_contextoft\\Windows\\CurrentVersion\\Internet Settings", false);

            string strUrl;

            key.QueryValue("AutoConfigURL", strUrl);

            return strUrl;
      */
   }

   bool os_context::local_machine_set_run(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand)
   {

//      throw ::not_implemented();
      return false;

      /*
            registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(scopedstrKey, pszCommand);


            return true;
      */
   }


   bool os_context::local_machine_set_run_once(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand)
   {


      throw ::not_implemented();
      return false;
      /*    registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(scopedstrKey, pszCommand);
      */

      return false;

   }

   bool os_context::current_user_set_run(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand)
   {

      throw ::not_implemented();
      return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(scopedstrKey, pszCommand);
      */

      return false;

   }

   bool os_context::current_user_set_run_once(const ::scoped_string & scopedstrKey, const ::scoped_string & scopedstrCommand)
   {

      throw ::not_implemented();
      return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(scopedstrKey, pszCommand);

      */
      //return false;

   }


   void os_context::defer_register_ca2_plugin_for_mozilla()
   {
      //  throw ::not_implemented();
      //return false;

      /*
            registry::Key keyPlugins;

            if(keyPlugins.OpenKey(HKEY_LOcaL_MACHINE, "SOFTWARE\\MozillaPlugins", true))
            {

               registry::Key keyPlugin;

               if(keyPlugin.OpenKey(keyPlugins, "@ca2.cc/npca2", true))
               {

                  keyPlugin.SetValue("Description", "ca2 plugin for NPAPI");
                  keyPlugin.SetValue("Path", ::apexacmesystem()->m_strCa2Module("npca2.dll"));
                  keyPlugin.SetValue("ProductName", "ca2 plugin for NPAPI");
                  keyPlugin.SetValue("Vendor", "ca2 Desenvolvimento de Software Ltda.");
                  keyPlugin.SetValue("Version", get_app()->file_as_string(directory()->ca2("appdata/x86/ca2_build.txt")));

                  registry::Key keyApplicationca2;

                  if(keyApplicationca2.OpenKey(keyPlugin, "application/ca2", true))
                  {

                     keyApplicationca2.SetValue("Description", "ca2 Document");

                  }

               }

            }

            return true;
      */
   }


   void os_context::file_extension_get_open_with_list_keys(string_array_base & straKey, const ::scoped_string & scopedstrExtension)
   {


      throw ::not_implemented();

      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += pszExtension;

            string strOpenWithKey;
            strOpenWithKey = strExt + "\\OpenWithList";

            registry::Key key;

            key.OpenKey(HKEY_CLASSES_ROOT, strOpenWithKey, false);

            key.EnumKey(straKey);

            return true;
      */
   }


   void os_context::file_extension_get_open_with_list_commands(string_array_base & straCommand, const ::scoped_string & scopedstrExtension)
   {

      string_array_base straKey;

      file_extension_get_open_with_list_keys(straKey, pszExtension);

//      if(!file_extension_get_open_with_list_keys(straKey, pszExtension))
//         return false;
//
//
//      return true;

   }


   void os_context::file_association_set_default_icon(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass, const ::scoped_string & scopedstrIconPath)
   {

      throw ::not_implemented();
      //return false;

      /*
            string strExtensionNamingClass(scopedstrExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass, true);
            keyLink3.SetValue("DefaultIcon", pszIconPath);


            return false;
      */
   }


   void os_context::file_association_set_shell_open_command(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass,  const ::scoped_string & scopedstrCommand, const ::scoped_string & scopedstrParam)
   {

      throw ::not_implemented();

//      return false;
//
//      throw ::not_implemented();
//
//      return false;

      /*
            string strExt;

            strExt = ".";
            strExt += pszExtension;

            string strExtensionNamingClass(scopedstrExtensionNamingClass);

            registry::Key key(HKEY_CLASSES_ROOT, strExt, true);
            key.SetValue(nullptr, strExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass + "\\shell", true);
            keyLink3.SetValue(nullptr, "open");

            registry::Key keyLink2(keyLink3, "open", true);
            keyLink2.SetValue(nullptr, "&Abrir");

            registry::Key keyLink1(keyLink2, "command", true);

            string strFormat;
            strFormat.formatf("\"%s\" \"%%L\" %s", pszCommand, pszParam);
            keyLink1.SetValue(nullptr, strFormat);

            return true;
      */
   }


   void os_context::file_association_get_shell_open_command(const ::scoped_string & scopedstrExtension, string & strExtensionNamingClass, string & strCommand, string & strParam)
   {

      throw ::not_implemented();

      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += pszExtension;

            registry::Key key(HKEY_CLASSES_ROOT, strExt, false);
            if(!key.QueryValue(nullptr, strExtensionNamingClass))
               return false;

            registry::Key keyLink(HKEY_CLASSES_ROOT, strExtensionNamingClass + "\\shell\\open\\command", false);

            string strFormat;
            if(keyLink.QueryValue(nullptr, strFormat))
            {

               const ::scoped_string & scopedstr = strFormat;

               try
               {

                  strCommand = ::unicode_consume_quoted_value(scopedstr);
                  ::unicode_consume_spaces(scopedstr);
                  ::unicode_consume(scopedstr, "\"%L\"");
                  strParam = psz;

               }
               catch(...)
               {
               }


            }

            return true;
      */
   }


   bool os_context::open_in_ie(const ::string & pcsz)
   {

      throw ::not_implemented();

      return false;

      /*    registry reg;
            string str;
            string str2;
            string strCommand;
            registry::Key key;
            if(key.OpenKey(HKEY_CLASSES_ROOT, ".html", false))
            {
               if(reg.RegQueryValue(key.m_hkey, "", str))
               {
                  if(key.OpenKey(HKEY_CLASSES_ROOT, ".html\\shell\\opennew\\command", false))
                  {
                     string str;
                     if(reg.RegQueryValue(HKEY_CLASSES_ROOT, str, str2))
                     {
                        string strCommand(str2);
                        strCommand.replace("%1", pcsz);

                        WinExec(strCommand,e_display_normal);
                     }
                  }
                  else
                  {
                     if(key.OpenKey(HKEY_CLASSES_ROOT, str, false))
                     {
                        str += "\\shell\\opennew\\command";
                        if(key.OpenKey(HKEY_CLASSES_ROOT, str, false))
                        {
                           if(reg.RegQueryValue(key.m_hkey, "", str2))
                           {
                              string strCommand(str2);
                              strCommand.replace("%1", pcsz);

                              WinExec(strCommand,e_display_normal);
                           }
                        }
                     }
                  }
               }
            }

            return true;
      */

   }


   void os_context::link_open(const ::scoped_string & scopedstrUrl, const ::scoped_string & scopedstrProfile)
   {

      auto psystem = system();

      auto pnode = psystem->node();

      pnode->open_url(strUrl);

   }


   bool os_context::create_service(::particle * pparticle)
   {

      //throw ::not_implemented();
      return true;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.case_insensitive_order("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_CREATE_SERVICE);

            string strcalling = papp->m_strModulePath + " : app=" + papp->m_XstrAppId + " service usehos_contexttlogin";

            if(hdlSCM == 0)
            {
               //::get_last_error()
               return false;
            }

            SC_HANDLE hdlServ = ::CreateService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               "ccwarehouse ca2 account " + papp->m_strAppName,        // service name to display
               STANDARD_RIGHTS_REQUIRED,  // desired access
               SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS, // service type
               SERVICE_AUTO_START,      // start type
               SERVICE_ERROR_NORMAL,      // error control type
               strcalling,                   // service's binary Path name
               0,                      // no load ordering group
               0,                      // no tag identifier
               0,                      // no dependencies
               0,                      // LocalSystem account
               0);                     // no password

            if (!hdlServ)
            {
               Clos_contexteServiceHandle(hdlSCM);
               //Ret = ::get_last_error();
               return false;
            }

            Clos_contexteServiceHandle(hdlServ);
            Clos_contexteServiceHandle(hdlSCM);

            return true;
      */

   }


   bool os_context::erase_service(::particle * pparticle)
   {
//      throw ::not_implemented();
      return false;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.case_insensitive_order("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

            if(hdlSCM == 0)
            {
               //::get_last_error();
               return false;
            }

            SC_HANDLE hdlServ = ::OpenService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               DELETE);                     // no password

            if (!hdlServ)
            {
               // Ret = ::get_last_error();
               Clos_contexteServiceHandle(hdlSCM);
               return false;
            }

            ::DeleteService(hdlServ);

            Clos_contexteServiceHandle(hdlServ);

            Clos_contexteServiceHandle(hdlSCM);

            return false;
      */
   }

   bool os_context::start_service(::particle * pparticle)
   {
      //throw ::not_implemented();
      return false;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.case_insensitive_order("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

            if(hdlSCM == 0)
            {
               //::get_last_error();
               return false;
            }

            SC_HANDLE hdlServ = ::OpenService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               SERVICE_START);                     // no password


            if (!hdlServ)
            {
               Clos_contexteServiceHandle(hdlSCM);
               //Ret = ::get_last_error();
               return false;
            }

            bool bOk = StartService(hdlServ, 0, nullptr) != false;

            Clos_contexteServiceHandle(hdlServ);
            Clos_contexteServiceHandle(hdlSCM);

            return bOk != false;
            */
   }

   bool os_context::stop_service(::particle * pparticle)
   {
      throw ::not_implemented();
      return false;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.case_insensitive_order("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

            if(hdlSCM == 0)
            {
               //::get_last_error();
               return false;
            }

            SC_HANDLE hdlServ = ::OpenService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               SERVICE_STOP);                     // no password

            if (!hdlServ)
            {
               // Ret = ::get_last_error();
               Clos_contexteServiceHandle(hdlSCM);
               return false;
            }

            SERVICE_STATUS ss;

            memory_set(&ss, 0, sizeof(ss));

            bool bOk = ::ControlService(hdlServ, SERVICE_CONTROL_STOP, &ss) != false;

            ::DeleteService(hdlServ);

            Clos_contexteServiceHandle(hdlServ);

            Clos_contexteServiceHandle(hdlSCM);

            return bOk != false;
      */
   }


   void os_context::raise_exception( unsigned int dwExceptionCode, unsigned int dwExceptionFlags)
   {

      throw ::not_implemented();
      return;
      /*
            RaiseException( dwExceptionCode, dwExceptionFlags, 0, nullptr );
            */
   }

   bool os_context::is_remote_session()
   {

//      throw ::not_implemented();
      return false;
      /*
            return GetSystemMetrics(SM_REMOTESESSION) != false;
      */
   }


   void os_context::post_to_all_threads(::enum_message emessage, ::wparam wparam, ::lparam lparam)

   {

      return;

   }


   ::process_identifier os_context::current_process_identifier()
   {

      return ::getpid();

   }


   void os_context::initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch)
   {

      if (bAddSearch)
      {

         string strDir;

         strDir = "/usr/share/backgrounds";

         pfileset->add_search(strDir, true);

      }

      //return true;

   }


   //#elif defined(LINUX)
   //            }
   //
   //#elif defined(MACos_context)
   //   //string strDir;
   //   //strDir = directory()->path(getenv("HOME"), "Pictures");
   //   //imagefileset.add_search(strDir);
   //   string strDir;
   //   strDir = "/Library/Desktop Pictures";
   //   imagefileset.add_search(strDir, true);
   //            }
   //
   //#else

   void os_context::get_default_browser(string & strId, ::file::path & path, string & strParam)
   {

      string str = system()->operating_system().get_output("/bin/sh -c \"xdg-settings get default-web-browser\"");

      str.trim();

      if(str.case_insensitive_ends(".desktop"))
      {

         ::file::path pathDesktop = "/usr/share/applications";

         pathDesktop /= str;

         if(file_exists(pathDesktop))
         {

            auto plink = path_system()->resolve_link(pathDesktop, ::file::e_link_target);

            if(plink && plink->m_elink & ::file::e_link_target)
            {

               path = plink->m_pathTarget;

            }

         }

      }

      //string str = ::apexacmesystem()->process().get_output("xdg-settings get default-web-browser");

      if(str.case_insensitive_contains("chrome"))
      {

         strId = "chrome";

         if(path.is_empty())
         {

            path = "google-chrome";

         }

      }
      else
      {

         strId = "firefox";


         path = "firefox";

      }

      //return true;

   }


   void os_context::file_open(const ::file::path & pathTarget, const ::scoped_string & scopedstrParams, const ::file::path & pathFolder)
   {

      auto path = get_context()->defer_process_path(pathTarget);

      if(linux_can_exec(path))
      {

         //int iPid;

         //daemonize_process(strTarget, &iPid);

         //::system("cd /; setsid \"" + strTarget + "\" </dev/null &>/dev/null");

         //int daemonize_process(const ::string & _cmd_line, int * pprocessId)

         // 2018-01-29 call_async("/bin/bash", "-c \"" + strTarget + "\"", strFolder, SW_SHOWDEFAULT, false);

         auto psystem = system();

         auto pnode = psystem->node();

         pnode->call_async(path, strParams, pathFolder, e_display_default, false);


//         char * pszCommandLine = strdup(strTarget + " " + strParams);

//         pid_t pid = ::fork();
//
//         if(pid == 0)
//         {
//
//            int iExitCode = ::system(scopedstrCommandLine);
//
//            free(scopedstrCommandLine);
//
//            exit(iExitCode);
//
//         }
//         else if(pid < 0)
//         {
//
//            free(scopedstrCommandLine);
//
//            return false;
//
//         }

         //return true;

         return;

      }
      else
      {

         //call_async("/bin/bash", "-i -c 'xdg-open \"" + strTarget + "\"'", strFolder, SW_SHOWDEFAULT, false);

         //::system("nohup /bin/bash -l -c 'xdg-open \"" + strTarget + "\"' > /dev/null 2>&1&");

         //::system("nohup xdg-open \"" + strTarget + "\" > /dev/null 2>&1&");

         auto psystem = system();

         auto pnode = psystem->node()->m_papexnode->m_pApexPlatform;

         pnode->shell_open(path, strParams, pathFolder);

//         pnode->node_fork([this, strTarget]()
//         {
//
//            string strUri = strTarget;
//
//            if(!strUri.contains("://"))
//            {
//
//               strUri = "file://" + strUri;
//
//            }
//
//            string strError;
//
//            int iBufferSize = 4096;
//
//            char * pszError = strError.get_buffer(iBufferSize);
//
//            auto psystem = system();
//
//            auto pnode = psystem->node();
//
//            int iBool = pnode->os_launch_uri(strUri, pszError, iBufferSize);
//
//            strError.release_buffer();
//
//            if(!iBool)
//            {
//
//               information() << "Error launching file : \"" << strUri << "\" , " << strError;
//
//            }
//
//         });

      }

      //return true;

      //re

   }


   void os_context::list_process(::file::path_array & patha, ::process_identifier_array & uaPid)
   {

      informationf("linux::os_context::list_process");

      string_array_base stra;

      directory_system()->list(stra, "/proc/", ::file::e_flag_folder);

      auto psystem = system();

      auto pnode = psystem->node();

      for(auto & strPid : stra)
      {

         int iPid = atoi(strPid);

         if(iPid > 0)
         {

            ::file::path path = pnode->process_identifier_module_path(iPid);

            if(path.has_character())
            {

               patha.add(path);

               uaPid.add(iPid);

            }

         }

      }

   }


   bool os_context::has_alias_in_path(const ::scoped_string & str, bool bNoUI, bool bNoMount)
   {

      ::file::path path(str);

      ::file::path_array patha;

      ascendants_path(path, patha);

      for(auto & path : patha)
      {

         if(is_alias(path))
         {

            return true;

         }

      }

      return false;

   }


   bool os_context::linux_can_exec(const ::string &file)
   {

      struct stat st;

      string str(file);

      if(str.case_insensitive_begins_eat("\""))
      {

         character_count iFind = str.find_index("\"");

         if(iFind < 0)
         {

            return false;

         }

         str = str.left(iFind);

      }
      else if(str.case_insensitive_begins_eat("\'"))
      {

         character_count iFind = str.find_index("\'");

         if(iFind < 0)
         {

            return false;

         }

         str = str.left(iFind);

      }
      else
      {

         character_count iFind = str.find_index(" ");

         if(iFind > 0)
         {

            str = str.left(iFind);

         }

      }

      if(str == "sudo")
      {

         return true;

      }

      zero(st);

      if (stat(str, &st) < 0)
      {

         return false;

      }

      if ((st.st_mode & S_IEXEC) != 0)
      {

         auto psystem = system();

         auto pnode = psystem->node();

         string strContentType = pnode->get_file_content_type(str);

         if(strContentType == "application/x-shellscript")
         {

            return true;

         }
         else if(strContentType == "application/x-sharedlib")
         {

            return true;

         }


         return false;

      }

      return false;

   }



} // namespace apex_linux



