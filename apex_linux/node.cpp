#include "framework.h"
//#include "node/platform/node.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/filesystem/filesystem/link.h"
#include "acme/platform/application.h"
#include "node.h"
#include "acme/exception/not_implemented.h"
#include "apex/filesystem/file/set.h"
//#include "acme/filesystem/filesystem/link.h"
#include "apex/operating_system/department.h"
#include "apex/platform/system.h"


i32 daemonize_process(const ::string & _cmd_line, i32 * pprocessId);

#undef USERNAME_LENGTH // mysql one


#include <sys/stat.h>
#include <unistd.h>


string empty_get_file_content_type(string)
{

   return "";

}

////#include "aura/operating_system/linux/_.h"


bool __node_node_pre_init();
bool __node_node_pos_init();


namespace apex_linux
{


   node::node()
   {

      m_pApexPlatform = this;

   }


   node::~node()
   {


   }


   string node::get_user_name()
   {

//      WCHAR wsz[1024];
//
//      DWORD dwSize = sizeof(wsz) / sizeof(WCHAR);
//
//      ::GetUserNameW(wsz, &dwSize);
//
//      return string(wsz);

      return "";

   }


   void node::initialize(::particle * pparticle)
   {

      //auto estatus =

      ::acme_linux::node::initialize(pparticle);

//         if (!estatus)
//         {
//
//            return estatus;
//
//         }

//         if (!__node_node_pre_init())
//         {
//
//            return error_failed;
//
//         }


//         if (!__node_node_pos_init())
//         {
//
//            return error_failed;
//
//         }

      //return estatus;

   }


   void node::_001InitializeShellOpen()
   {

      //ASSERT(m_atomApp == nullptr && m_atomSystemTopic == nullptr); // do once

      //m_atomApp            = ::GlobalAddAtomW(utf8_to_unicode(m_strAppName));

      //m_atomSystemTopic    = ::GlobalAddAtomW(L"system");

      //return ::success;

   }


//      void node::file_open(const ::file::path & path, const ::string& strParams, const ::file::path & pathFolder)
//      {
//
//         ::apex::node::file_open(path, strParams, pathFolder);
//
//      }


   ::e_status node::process_init()
   {

      //defer_initialize_winsock();
      return success;

   }


   void node::on_create_app_shortcut(::acme::application * papplication)
   {

      defer_create_app_shortcut(papplication);

//      string strAppName;
//
//      if (papplication->m_strAppName.has_char())
//      {
//
//         strAppName = m_strAppName;
//
//      }
//      else
//      {
//
//         string strAppIdUnderscore = papplication->m_strAppId;
//
//         strAppIdUnderscore.find_replace("/", "_");
//
//         strAppIdUnderscore.find_replace("-", "_");
//
//         strAppName = strAppIdUnderscore;
//
//      }
//
//      string strRoot = papplication->m_strAppId.left(papplication->m_strAppId.find('/'));
//
//      //auto pathCreatedShortcut = acmedirectory()->roaming() / m_strAppId / "created_shortcut.txt";
//
//      ::file::path pathShortcut;
//
//      pathShortcut = acmedirectory()->roaming() / "Microsoft/Windows/Start Menu/Programs" / strRoot / (strAppName + ".lnk");
//
//      auto path = acmefile()->module();
//
//      ::file::path pathTarget;
//      ::file::path pathIcon;
//      int iIcon = -1;
//
//      auto plink = node()->m_papexnode->resolve_link(pathShortcut);
//
//      // Enough condition to create shortcut
//      bool bEnoughCondition1 = !plink;
//      bool bEnoughCondition2 = !(plink->m_elink &::file::e_link_target);
//      bool bEnoughCondition3 = !acmepath()->final_is_same(plink->m_pathTarget, path);
//      bool bEnoughCondition4 = !(plink->m_elink & ::file::e_link_icon);
//      bool bEnoughCondition5 = plink->m_pathIcon.trimmed().is_empty() || !acmefile()->exists(plink->m_pathIcon);
//
//      //if (!acmefile()->exists(pathCreatedShortcut)
//      if (bEnoughCondition1
//         || bEnoughCondition2
//         || bEnoughCondition3
//         || bEnoughCondition4
//         || bEnoughCondition5
//         )
//      {
//
//         create_app_shortcut();
//
//      }

   }


   ::file::path node::app_shortcut_path(::acme::application* papplication)
   {

      ::file::path pathShortcut;

      ::string strDesktopFileName;

      strDesktopFileName = papplication->m_strAppId;

      strDesktopFileName.find_replace("/", ".");

      pathShortcut = acmedirectory()->home() / ".local/share/applications" / (strDesktopFileName + ".desktop");

      return pathShortcut;

   }


   string node::get_command_line()
   {

      return platform()->m_strCommandLine;

   }


   void node::shutdown(bool bIfPowerOff)
   {

      unix_shell_command("shutdown -h now");

   }


   void node::reboot()
   {

      //::sync();
      //::reboot(RB_AUTOBOOT);

      //system()->m_pnode->reboot();

      apex_posix::node::reboot();

      //return false;

   }


   void node::terminate_processes_by_title(const ::string & lpszName)
   {

      throw ::not_implemented();

      return;

      /*      ::u32 dwPid;
            while(get_pid_by_title(lpszName, dwPid))
            {
               HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                  PROCESS_VM_READ,
                  false, dwPid );
               TerminateProcess(hProcess, (::u32) -1);
               ClnodeeHandle(hProcess);
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
               ClnodeeHandle(hProcess);
               return bResult == true;*/

      //  }
   }


   ::process_identifier_array node::module_path_processes_identifiers(const ::scoped_string & scopedstrName)
   {

      ::process_identifier_array processidentifiera;

      auto dwa = processes_identifiers();

      for(i32 i = 0; i < dwa.get_count(); i++)
      {

         if(process_identifier_module_path(dwa[i]).case_insensitive_equals(scopedstrName))
         {

            processidentifiera.add(dwa[i]);

         }

      }

      return processidentifiera;

   }


   ::process_identifier_array node::title_processes_identifiers(const ::scoped_string & scopedstrName)
   {

      ::process_identifier_array processidentifiera;

      auto dwa = processes_identifiers();

      for(i32 i = 0; i < dwa.get_count(); i++)
      {

         if(process_identifier_module_path(dwa[i]).title().case_insensitive_equals(scopedstrName))
         {

            processidentifiera.add(dwa[i]);

         }

      }

      return processidentifiera;

   }


   ::file::path node::process_identifier_module_path(::process_identifier dwPid)
   {

      return ::acme_linux::node::process_identifier_module_path(dwPid);

   }


   ::process_identifier_array node::processes_identifiers()
   {

      return ::acme_linux::node::processes_identifiers();

//      throw ::not_implemented();
//
//      return {};

      /*
            dwa.set_size(0);
            ::u32 cbNeeded = 0;
            while(cbNeeded == natural(dwa.get_count()))
            {
               dwa.set_size(dwa.get_count() + 1024);
               if(!EnumProcesses(
                  dwa.get_data(),
                  (::u32) (dwa.get_count() * sizeof(::u32)),
                  &cbNeeded))
               {
                  return;
               }
               dwa.set_size(cbNeeded / sizeof(::u32));
            }*/
   }


//   string node::get_module_path(HMODULE hmodule)
//   {
//      throw ::not_implemented();
//      return "";
//      /*
//      string strPath;
//      ::u32 dwSize = 1;
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


   ::payload node::connection_settings_get_auto_detect()
   {
      //throw ::not_implemented();
      return false;

      /*
            registry::Key key1;

            key1.OpenKey(HKEY_CURRENT_USER, "Software\\Micrnodeoft\\Windows\\CurrentVersion\\Internet Settings\\Connections", false);

            memory mem;

            key1.QueryValue("DefaultConnectionSettings", mem);

            bool bAutoDetect = (((::u8 *) mem.get_data())[8] & 0x08) != 0;

            return bAutoDetect;
      */
   }



   ::payload node::connection_settings_get_auto_config_url()
   {

      //throw ::not_implemented();
      return "";
      /*
            registry::Key key;

            key.OpenKey(HKEY_CURRENT_USER, "Software\\Micrnodeoft\\Windows\\CurrentVersion\\Internet Settings", false);

            string strUrl;

            key.QueryValue("AutoConfigURL", strUrl);

            return strUrl;
      */
   }


   bool node::local_machine_set_run(const ::string & pszKey, const ::string & pszCommand)
   {

//      throw ::not_implemented();
      return false;

      /*
            registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Micrnodeoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(pszKey, pszCommand);


            return true;
      */
   }


   bool node::local_machine_set_run_once(const ::string & pszKey, const ::string & pszCommand)
   {


      throw ::not_implemented();
      return false;
      /*    registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Micrnodeoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(pszKey, pszCommand);
      */

      return false;

   }

   bool node::current_user_set_run(const ::string & pszKey, const ::string & pszCommand)
   {

      throw ::not_implemented();
      return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Micrnodeoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(pszKey, pszCommand);
      */

      return false;

   }

   bool node::current_user_set_run_once(const ::string & pszKey, const ::string & pszCommand)
   {

      throw ::not_implemented();
      return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Micrnodeoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(pszKey, pszCommand);

      */
      //return false;

   }


   void node::defer_register_ca2_plugin_for_mozilla()
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
                  keyPlugin.SetValue("Version", get_app()->file_as_string(dir()->ca2("appdata/x86/ca2_build.txt")));

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


   void node::file_extension_get_open_with_list_keys(string_array & straKey, const ::string & pszExtension)
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


   void node::file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & pszExtension)
   {

      string_array straKey;

      file_extension_get_open_with_list_keys(straKey, pszExtension);

//      if(!file_extension_get_open_with_list_keys(straKey, pszExtension))
//         return false;
//
//
//      return true;

   }


   void node::file_association_set_default_icon(const ::string & pszExtension, const ::string & pszExtensionNamingClass, const ::string & pszIconPath)
   {

      throw ::not_implemented();
      //return false;

      /*
            string strExtensionNamingClass(pszExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass, true);
            keyLink3.SetValue("DefaultIcon", pszIconPath);


            return false;
      */
   }


   void node::file_association_set_shell_open_command(const ::string & pszExtension, const ::string & pszExtensionNamingClass,  const ::string & pszCommand, const ::string & pszParam)
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

            string strExtensionNamingClass(pszExtensionNamingClass);

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


   void node::file_association_get_shell_open_command(const ::string & pszExtension, string & strExtensionNamingClass, string & strCommand, string & strParam)
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

               const ::string & psz = strFormat;

               try
               {

                  strCommand = ::unicode_consume_quoted_value(psz);
                  ::unicode_consume_spaces(psz);
                  ::unicode_consume(psz, "\"%L\"");
                  strParam = psz;

               }
               catch(...)
               {
               }


            }

            return true;
      */
   }


   bool node::open_in_ie(const ::string & pcsz)
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


   void node::link_open(const string & strUrl, const string & strProfile)
   {

      auto psystem = system();

      auto pnode = psystem->node();

      pnode->open_url_link_at_system_browser(strUrl);

   }


   bool node::create_service(::particle * pparticle)
   {

      //throw ::not_implemented();
      return true;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.case_insensitive_order("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_CREATE_SERVICE);

            string strcalling = papp->m_strModulePath + " : app=" + papp->m_XstrAppId + " service usehnodetlogin";

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
               ClnodeeServiceHandle(hdlSCM);
               //Ret = ::get_last_error();
               return false;
            }

            ClnodeeServiceHandle(hdlServ);
            ClnodeeServiceHandle(hdlSCM);

            return true;
      */

   }


   bool node::erase_service(::particle * pparticle)
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
               ClnodeeServiceHandle(hdlSCM);
               return false;
            }

            ::DeleteService(hdlServ);

            ClnodeeServiceHandle(hdlServ);

            ClnodeeServiceHandle(hdlSCM);

            return false;
      */
   }

   bool node::start_service(::particle * pparticle)
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
               ClnodeeServiceHandle(hdlSCM);
               //Ret = ::get_last_error();
               return false;
            }

            bool bOk = StartService(hdlServ, 0, nullptr) != false;

            ClnodeeServiceHandle(hdlServ);
            ClnodeeServiceHandle(hdlSCM);

            return bOk != false;
            */
   }

   bool node::stop_service(::particle * pparticle)
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
               ClnodeeServiceHandle(hdlSCM);
               return false;
            }

            SERVICE_STATUS ss;

            memory_set(&ss, 0, sizeof(ss));

            bool bOk = ::ControlService(hdlServ, SERVICE_CONTROL_STOP, &ss) != false;

            ::DeleteService(hdlServ);

            ClnodeeServiceHandle(hdlServ);

            ClnodeeServiceHandle(hdlSCM);

            return bOk != false;
      */
   }


   void node::raise_exception( ::u32 dwExceptionCode, ::u32 dwExceptionFlags)
   {

      throw ::not_implemented();
      return;
      /*
            RaiseException( dwExceptionCode, dwExceptionFlags, 0, nullptr );
            */
   }

   bool node::is_remote_session()
   {

//      throw ::not_implemented();
      return false;
      /*
            return GetSystemMetrics(SM_REMOTESESSION) != false;
      */
   }


   void node::post_to_all_threads(const ::atom & atom, wparam wparam, lparam lparam)

   {

      return;

   }


   ::process_identifier node::current_process_identifier()
   {

      return ::getpid();

   }


   void node::initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch)
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
   //#elif defined(MACnode)
   //   //string strDir;
   //   //strDir = dir()->path(getenv("HOME"), "Pictures");
   //   //imagefileset.add_search(strDir);
   //   string strDir;
   //   strDir = "/Library/Desktop Pictures";
   //   imagefileset.add_search(strDir, true);
   //            }
   //
   //#else

   void node::get_default_browser(string & strId, ::file::path & path, string & strParam)
   {

      string str = system()->m_papexsystem->operating_system().get_output("/bin/sh -c \"xdg-settings get default-web-browser\"");

      str.trim();

      if(str.case_insensitive_ends(".desktop"))
      {

         ::file::path pathDesktop = "/usr/share/applications";

         pathDesktop /= str;

         if(file_exists(pathDesktop))
         {

            auto plink = acmepath()->resolve_link(pathDesktop, ::file::e_link_target);

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


   void node::file_open(const ::file::path & pathTarget, const ::string & strParams, const ::file::path & pathFolder)
   {

      auto path = get_context()->m_papexcontext->defer_process_path(pathTarget);

      if(linux_can_exec(path))
      {

         //int iPid;

         //daemonize_process(strTarget, &iPid);

         //::system("cd /; setsid \"" + strTarget + "\" </dev/null &>/dev/null");

         //i32 daemonize_process(const ::string & _cmd_line, i32 * pprocessId)

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
//            int iExitCode = ::system(pszCommandLine);
//
//            free(pszCommandLine);
//
//            exit(iExitCode);
//
//         }
//         else if(pid < 0)
//         {
//
//            free(pszCommandLine);
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


   void node::list_process(::file::path_array & patha, ::process_identifier_array & uaPid)
   {

      ::acme::get()->platform()->informationf("linux::node::list_process");

      string_array stra;

      acmedirectory()->list(stra, "/proc/", ::file::e_flag_folder);

      auto psystem = system();

      auto pnode = psystem->node();

      for(auto & strPid : stra)
      {

         int iPid = atoi(strPid);

         if(iPid > 0)
         {

            ::file::path path = pnode->process_identifier_module_path(iPid);

            if(path.has_char())
            {

               patha.add(path);

               uaPid.add(iPid);

            }

         }

      }

   }


   bool node::has_alias_in_path(const ::scoped_string & str, bool bNoUI, bool bNoMount)
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


   bool node::linux_can_exec(const ::string &file)
   {

      struct stat st;

      string str(file);

      if(str.case_insensitive_begins_eat("\""))
      {

         strsize iFind = str.find_index("\"");

         if(iFind < 0)
         {

            return false;

         }

         str = str.left(iFind);

      }
      else if(str.case_insensitive_begins_eat("\'"))
      {

         strsize iFind = str.find_index("\'");

         if(iFind < 0)
         {

            return false;

         }

         str = str.left(iFind);

      }
      else
      {

         strsize iFind = str.find_index(" ");

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



