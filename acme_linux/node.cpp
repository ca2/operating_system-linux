#include "framework.h"
#include "node.h"
#include "acme_file.h"
#include "acme/operating_system/summary.h"
#include <sys/utsname.h>


#include  "acme/operating_system/ansi/binreloc.h"
#include  "acme/operating_system/ansi/_pthread.h"


#include <unistd.h>


::user::enum_desktop _calculate_edesktop();
::user::enum_desktop _get_edesktop();


namespace acme_linux
{


   node::node()
   {

      m_edesktop = ::user::e_desktop_none;

      m_pAcmePlatform = this;

   }


   node::~node()
   = default;


//      void initialize_matter(::matter * pmatter)
//      {
//
//         ::matter::initialize_matter(pmatter);
//
//      }

   // Twitter Automator and Denis Lakic and UpWork contribution
// enzymes: Liveedu.tv, Twitch.tv and Mixer.com streamers and viewers
// Mummi and bilbo!!
// create call to :
   void node::install_crash_dump_reporting(const string & strModuleNameWithTheExeExtension)
   {

//      ::linux::registry::key k;
//
//      string strKey = "SOFTWARE\\Microsoft\\Windows\\Windows Error Reporting\\LocalDumps\\" + strModuleNameWithTheExeExtension;
//
//      if (k._open(HKEY_LOCAL_MACHINE, strKey, true))
//      {
//         ::file::path str = acmesystem()->m_pnodedir->system() / "CrashDumps" / strModuleNameWithTheExeExtension;
//         wstring wstr = str;
//         RegSetValueExW(k.m_hkey, L"DumpFolder", 0, REG_EXPAND_SZ, (byte*)wstr.c_str(), ::u32((wcslen(wstr) + 1) * sizeof(wchar_t)));
//         ::u32 dw = 10;
//         RegSetValueExW(k.m_hkey, L"DumpCount", 0, REG_DWORD, (byte*)&dw, sizeof(dw));
//         dw = 2;
//         RegSetValueExW(k.m_hkey, L"DumpType", 0, REG_DWORD, (byte*)&dw, sizeof(dw));
//
//      }
//
//      output_debug_string("test01");

   }


   string node::audio_get_default_library_name()
   {

      return "audio_alsa";

   }


   ::file::path node::_module_path()
   {

      ::file::path path;

      char * pszModule = nullptr;

      if((pszModule = br_find_exe(nullptr)) == nullptr)
      {

         if (!br_init_lib(nullptr))
         {

            char path[PATH_MAX * 4];

            char dest[PATH_MAX * 4];

            pid_t pid = getpid();

            sprintf(path, "/proc/%d/exe", pid);

            auto iSize = readlink(path, dest, PATH_MAX);

            if (iSize > 0)
            {

               dest[iSize] = '\0';

               pszModule = strdup(dest);

            }

         }

      }

      path = pszModule;

      ::free(pszModule);

      return path;

   }


   void node::calculate_linux_distribution()
   {

      auto lines = acmefile()->lines("/etc/os-release");

      ::string strId;

      if(lines.find_first_begins_eat_ci(strId, "id="))
      {

         strId.make_lower();

         if (strId == "ubuntu")
         {

            m_elinuxdistribution = e_linux_distribution_ubuntu;

         }
         else if (strId == "manjaro")
         {

            m_elinuxdistribution = e_linux_distribution_manjaro;

         }

      }

      if(m_elinuxdistribution <= 0)
      {

         output_debug_string("WARNING: Unknown linux distribution with id \"" + strId + "\".");

         m_elinuxdistribution = e_linux_distribution_unknown;

      }

   }


   ::user::enum_desktop node::get_edesktop()
   {

      return ::acme::node::get_edesktop();

   }


   ::user::enum_desktop node::calculate_edesktop()
   {

      return _get_edesktop();

   }


   ::user::enum_desktop node::_get_edesktop()
   {

      return ::_get_edesktop();

   }


//      ::user::enum_desktop node::_calculate_edesktop()
//      {
//
//         return ::_calculate_edesktop();
//
//      }


   bool node::process_modules(string_array& stra, u32 processID)
   {

      return ::acme_posix::node::process_modules(stra, processID);

   }


   bool node::load_modules_diff(string_array& straOld, string_array& straNew, const char* pszExceptDir)
   {

      return ::acme_posix::node::load_modules_diff(straOld, straNew, pszExceptDir);

   }


   atom_array node::get_pids()
   {

      return ::acme_posix::node::get_pids();

   }


   atom_array node::module_path_get_pid(const char* pszModulePath, bool bModuleNameIsPropertyFormatted)
   {

      return ::acme_posix::node::module_path_get_pid(pszModulePath, bModuleNameIsPropertyFormatted);

//         atom_array iaPid;
//
//         atom_array pids = get_pids();
//
//         string strPath;
//
//         for(auto & iCurrentPid : pids)
//         {
//
//            strPath = module_path_from_pid(iCurrentPid.i32());
//
//            if(strPath.case_insensitive_order(pszModulePath) == 0 )
//            {
//
//               iaPid.add(iCurrentPid);
//
//            }
//
//         }
//
//         return iaPid;


   }


   string node::module_path_from_pid(u32 pid)
   {

      return ::acme_posix::node::module_path_from_pid(pid);

   }


   string node::command_line_from_pid(u32 pid)
   {

      return ::acme_posix::node::command_line_from_pid(pid);

   }


   bool node::is_shared_library_busy(u32 processid, const string_array& stra)
   {

      return ::acme_posix::node::is_shared_library_busy(processid, stra);

   }


   bool node::is_shared_library_busy(const string_array& stra)
   {

      return ::acme_posix::node::is_shared_library_busy(stra);

   }


   bool node::process_contains_module(string& strImage, ::u32 processID, const char* pszLibrary)
   {

      return ::acme_posix::node::process_contains_module(strImage, processID, pszLibrary);

   }


   void node::shared_library_process(dword_array& dwa, string_array& straProcesses, const char* pszLibrary)
   {

      ::acme_posix::node::shared_library_process(dwa, straProcesses, pszLibrary);

   }


   bool node::is_process_running(::u32 pid)
   {

      return ::acme_posix::node::is_process_running(pid);

   }


   string node::get_environment_variable(const char* pszEnvironmentVariable)
   {

      return ::acme_posix::node::get_environment_variable(pszEnvironmentVariable);

   }


   string node::expand_environment_variables(const string & str)
   {

      return ::acme_posix::node::expand_environment_variables(str);

   }


   array <::serial::port_info> node::list_serial_ports()
   {

      return ::acme_posix::node::list_serial_ports();

   }


   ::user::enum_desktop node::_calculate_edesktop()
   {

      return ::_calculate_edesktop();

   }


   void node::shell_open(const ::file::path & path, const ::string & strParams, const ::file::path & pathFolder)
   {

      string str(path);

      fork([this, str]()
           {

               int iError = ::system("xdg-open \"" + str + "\" & ");

               if(iError != 0)
               {


                  WARNING("node::shell_open xdg-open \"" << str << "\" returned error code " << iError);

               }

           });

   }


//      void node::shell_execute_async(const char * psz, const char * pszParams)
//      {
//
//         string str(psz);
//
//         fork([this, str]()
//              {
//
//                 ::system("xdg-open \"" + str + "\" & ");
//
//              });
//
////         string strTarget(psz);
////
////         auto psystem = acmesystem();
////
////         auto pnode = psystem->node();
////
////         pnode->node_fork([this, strTarget]()
////                          {
////
////                             string strUri = strTarget;
////
////                             if(!strUri.contains("://"))
////                             {
////
////                                strUri = "file://" + strUri;
////
////                             }
////
////                             string strError;
////
////                             int iBufferSize = 4096;
////
////                             char * pszError = strError.get_string_buffer(iBufferSize);
////
////                             auto psystem = acmesystem();
////
////                             auto pnode = psystem->node();
////
////                             int iBool = pnode->os_launch_uri(strUri, pszError, iBufferSize);
////
////                             strError.release_string_buffer();
////
////                             if(!iBool)
////                             {
////
////                                INFORMATION("Error launching file : \"" << strUri << "\" , " << strError);
////
////                             }
////
////                          });
//
//
//      }


   bool node::set_process_priority(::enum_priority epriority)
   {

      i32 iPolicy = SCHED_OTHER;

      sched_param schedparam;

      schedparam.sched_priority = 0;

      get_os_priority(&iPolicy, &schedparam, epriority);

      sched_setscheduler(0, iPolicy, &schedparam);

      return true;

   }


   ::pointer <::operating_system::summary > node::operating_system_summary()
   {

      auto psummary = __create_new < ::operating_system::summary >();


      ::particle::initialize(pparticle);

      ::string strOs;
      ::string strVer;
      //}

      // freedesktop.org and systemd
      if (acmefile()->exists("/etc/os-release"))
      {

         auto set = acmefile()->parse_standard_configuration("/etc/os-release");

         m_strDistro = set["ID"];
         m_strDistroBranch = set["VARIANT_ID"];
         m_strDesktopEnvironment = m_strDistroBranch;
         m_strDistroRelease = set["VERSION_ID"];
         m_strDistroFamily = set["ID_LIKE"];

         m_strDistro.make_lower();
         m_strDistroBranch.make_lower();
         m_strDesktopEnvironment.make_lower();
         m_strDistroRelease.make_lower();
         m_strDistroFamily.make_lower();

         if (m_strDistroFamily.case_insensitive_equals("arch"))
         {

            auto setArch = acmefile()->parse_standard_configuration("/etc/os-release");

            m_strDistroRelease = setArch["DISTRIB_RELEASE"];
            m_strDistroRelease.make_lower();

         }

      }
      else if (acmenode()->has_unix_shell_command("lsb_release"))
      {

         //         }
         //      elif
         //      type lsb_release >/dev / null
         //      2 > &1;
         //      then

         //# linuxbase.org

         strOs = acmenode()->unix_shell_command_string("lsb_release -si");
         strVer = acmenode()->unix_shell_command_string("lsb_release -sr");

         strOs.make_lower();
         strVer.make_lower();

      }
      else if (acmefile()->exists("/etc/lsb-release"))
      {

         //# For some versions of Debian/Ubuntu without lsb_release command
         auto set = acmefile()->parse_standard_configuration("/etc/lsb-release");
         //./ etc / lsb - release

         strOs = set["DISTRIB_ID"];
         strVer = set["DISTRIB_RELEASE"];
         strOs.make_lower();
         strVer.make_lower();


      }
      else if (acmefile()->exists("/etc/debian_version"))
      {

         //      elif[-f / etc / debian_version];
         //      then
         //
         //# Older Debian/Ubuntu/etc.

         strOs = "Debian";
         strVer = acmefile()->as_string("/etc/debian_version");
         strOs.make_lower();
         strVer.make_lower();


      }
      else if (acmefile()->exists("/etc/SuSe-release"))
      {
         //      elif[-f / etc / SuSe - release];
         //      then
         //
         //# Older SuSE/etc.
         //
         //              ...
      }

      else if (acmefile()->exists("/etc/redhat-release"))
      {


         //      }              elif[-f / etc / redhat - release];
         //      then
         //
         //# Older Red Hat, CentOS, etc.
         //
         //              ...

      }
      else
      {

         // # Fall back to uname, e.g. "Linux <version>", also works for BSD, etc.

         strOs = acmenode()->unix_shell_command_string("uname -s");
         strVer = acmenode()->unix_shell_command_string("uname -r");

      }

      if (m_strDistroFamily.is_empty())
      {

         m_strDistroFamily = m_strDistro;

      }

      if (m_strDistro.case_insensitive_equals("ubuntu"))
      {

         m_strDistroFamily = "debian";

      }
      else if (m_strDistro.case_insensitive_equals("debian"))
      {

         m_strDistroFamily = "debian";

      }
      else if (m_strDistro.case_insensitive_equals("opensuse-tumbleweed"))
      {

         m_strDistroFamily = "zypper";

      }
      else if (m_strDistro.case_insensitive_equals("opensuse-leap"))
      {

         m_strDistroFamily = "zypper";

      }

      if (m_strDistro.case_insensitive_equals("fedora"))
      {

         if (m_strDistroBranch.case_insensitive_equals("workstation"))
         {

            m_strDesktopEnvironment = "gnome";

         }

      }

      //::string strLowerCaseCurrentDesktop;

      if (m_strDesktopEnvironment.is_empty())
      {
         ///# echo "DESKTOP_ENVIRONMENT is empty here"

         if (m_strDistroFamily.case_insensitive_equals("debian")
             || m_strDistroFamily.case_insensitive_equals("zypper")
             || m_strDistroFamily.case_insensitive_equals("arch"))
         {
            //      if [ "$__SYSTEM_DISTRO_FAMILY" = "debian" ] || [ "$__SYSTEM_DISTRO_FAMILY" = "zypper" ] || [ "$__SYSTEM_DISTRO_FAMILY" = "arch" ];
            //      then

            //# echo "DISTRO_FAMILY is debian, zypper or arch"

            auto strLowerCaseCurrentDesktop = acmenode()->get_environment_variable("XDG_CURRENT_DESKTOP").lowered();

            //# echo "lower case xdg_current_desktop is $__SYSTEM_LOWER_CASE_CURRENT_DESKTOP"
            if (strLowerCaseCurrentDesktop.equals("gnome"))
            {
               //      if contains
               //      $__SYSTEM_LOWER_CASE_CURRENT_DESKTOP
               //      "gnome";
               //      then
               //
               //# echo "lower case xdg_current_desktop contains gnome"

               m_strDesktopEnvironment = "gnome";

            }
            else if (strLowerCaseCurrentDesktop.equals("kde"))
            {
               //      elif
               //      contains
               //      $__SYSTEM_LOWER_CASE_CURRENT_DESKTOP
               //      "kde";
               //      then
               //
               //# echo "lower case xdg_current_desktop contains gnome"

               m_strDesktopEnvironment = "kde";

            }
            else if (strLowerCaseCurrentDesktop.equals("lxde"))
            {
               //      elif
               //      contains
               //      $__SYSTEM_LOWER_CASE_CURRENT_DESKTOP
               //      "lxde";
               //      then
               //
               //# echo "lower case xdg_current_desktop contains lxde"

               m_strDesktopEnvironment = "lxde";

            }

            if (m_strDistroFamily.case_insensitive_equals("debian"))
            {

               m_strDistroBranch = m_strDesktopEnvironment;

            }
            else if (m_strDistroFamily.case_insensitive_equals("zypper"))
            {

               m_strDistroBranch = m_strDesktopEnvironment;

            }
            else if (m_strDistroFamily.case_insensitive_equals("arch"))
            {

               m_strDistroBranch = m_strDesktopEnvironment;

            }

         }

         if (m_strDistro.case_insensitive_equals("ubuntu"))
         {

            if (m_strDesktopEnvironment.case_insensitive_equals("kde"))
            {

               m_strSlashedOperatingSystem = "kubuntu/" + m_strDistroRelease;

            }
            else
            {

               m_strSlashedOperatingSystem = m_strDistro + "/" + m_strDistroRelease;
            }

         }
         else
         {

            m_strSlashedOperatingSystem = m_strDistro + "/" + m_strDistroBranch + "/" + m_strDistroRelease;

         }


         if (m_strDistroFamily == "debian")
         {

            m_strSudoInstall = "sudo apt -y install";
            m_strStandardPackageFileExtension = "deb";
            m_strPackagePlatform = "amd64";

         }
         else if (m_strDistroFamily == "fedora")
         {

            m_strSudoInstall = "sudo dnf -y install";
            m_strStandardPackageFileExtension = "rpm";
            m_strPackagePlatform = "x86_64";

         }
         else if (m_strDistroFamily == "zypper")
         {

            m_strSudoInstall = "sudo zypper --non-interactive install";
            m_strStandardPackageFileExtension = "rpm";
            m_strPackagePlatform = "x86_64";

         }

         if (m_strDesktopEnvironment == "kde")
         {

            m_strTerminal = "konsole";

         }
         else
         {

            m_strTerminal = "gnome-terminal";

         }

         m_strUnderscoreOperatingSystem = m_strSlashedOperatingSystem;

         m_strUnderscoreOperatingSystem.find_replace("/", "_");

         acmenode()->set_environment_variable("__SYSTEM_DISTRO", m_strDistro);
         acmenode()->set_environment_variable("__SYSTEM_DISTRO_FAMILY", m_strDistroFamily);
         acmenode()->set_environment_variable("__SYSTEM_DISTRO_BRANCH", m_strDistroBranch);
         acmenode()->set_environment_variable("__SYSTEM_DISTRO_RELEASE", m_strDistroRelease);
         acmenode()->set_environment_variable("__SYSTEM_DESKTOP_ENVIRONMENT", m_strDesktopEnvironment);
         acmenode()->set_environment_variable("__SYSTEM_SLASHED_OPERATING_SYSTEM", m_strSlashedOperatingSystem);
         acmenode()->set_environment_variable("__SYSTEM_UNDERSCORE_OPERATING_SYSTEM", m_strUnderscoreOperatingSystem);
         acmenode()->set_environment_variable("__SYSTEM_SUDO_INSTALL", m_strSudoInstall);
         acmenode()->set_environment_variable("__SYSTEM_TERMINAL", m_strTerminal);

      }


   }


} // namespace acme_linux



