#include "framework.h"
#include "node.h"
#include "acme_file.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/operating_system/summary.h"
#include "acme/platform/system.h"


void copy(::file::path & path, const ::string & str)
{

   path = str;

}


#include "acme/primitive/collection/_generic_array.h"


#include  "acme/operating_system/ansi/binreloc.h"
#include  "acme/operating_system/ansi/_pthread.h"


#include <unistd.h>
#include <sys/utsname.h>





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


   string node::audio_get_default_implementation_name()
   {

      return acmesystem()->implementation_name("audio", "alsa");

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

         output_debug_string("warning: Unknown linux distribution with id \"" + strId + "\".");

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

//   ::dl_iterate_phdr(__get_module_names, &patha);
//   int __get_module_names(struct dl_phdr_info * pinfo, size_t size, void *data)
//   {
//
//      auto ppatha = (::file::path_array *) data;
//
//      ppatha->add(pinfo->dlpi_name);
//
//      return 0;
//
//   }

   //::dl_iterate_phdr(__get_module_names, &patha);




   ::file::path_array node::process_identifier_modules_paths(::process_identifier processidentifier)
   {

      ::file::path_array patha;

      ::string strProcPidMaps;

      strProcPidMaps.format("/proc/%d/maps", (int) processidentifier);

      auto stra = ::transfer(acmedirectory()->enumerate_content(strProcPidMaps));

      ::generic::array::copy(patha, stra);

      return ::transfer(patha);

   }


   bool node::load_modules_diff(string_array& straOld, string_array& straNew, const ::string & strExceptDir)
   {

      return ::acme_posix::node::load_modules_diff(straOld, straNew, strExceptDir);

   }


   ::process_identifier_array node::processes_identifiers()
   {

      ::file::listing listing;

      listing.set_folder_listing("/proc");

      acmedirectory()->enumerate(listing);

      process_identifier_array processidentifiera;

      for(auto & path : listing)
      {

         ::process_identifier processidentifier;

         processidentifier = atol(path.title());

         processidentifiera.add(processidentifier);

      }

      return ::transfer(processidentifiera);

   }


   ::process_identifier_array node::module_path_processes_identifiers(const ::string &pszModulePath,
                                                      bool bModuleNameIsPropertyFormatted)
   {

      return ::acme_posix::node::module_path_processes_identifiers(pszModulePath, bModuleNameIsPropertyFormatted);

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


   string node::process_identifier_module_path(::process_identifier pid)
   {

      return ::acme_posix::node::process_identifier_module_path(pid);

   }


   string node::process_identifier_command_line(::process_identifier pid)
   {

      return ::acme_posix::node::process_identifier_command_line(pid);

   }


//   bool node::is_shared_library_busy(::process_identifier processid, const string_array& stra)
//   {
//
//      return ::acme_posix::node::is_shared_library_busy(processid, stra);
//
//   }
//
//
//   bool node::is_shared_library_busy(const string_array& stra)
//   {
//
//      return ::acme_posix::node::is_shared_library_busy(stra);
//
//   }


   bool node::process_contains_module(string& strImage, ::process_identifier processID, const ::string & strLibrary)
   {

      return ::acme_posix::node::process_contains_module(strImage, processID, strLibrary);

   }


   ::process_identifier_array node::shared_library_process(string_array& straProcesses, const ::string & strLibrary)
   {

      return ::acme_posix::node::shared_library_process(straProcesses, strLibrary);

   }


   bool node::is_process_running(::process_identifier pid)
   {

      return ::acme_posix::node::is_process_running(pid);

   }


   string node::get_environment_variable(const ::scoped_string & scopestrEnvironmentVariable)
   {

      return ::acme_posix::node::get_environment_variable(scopestrEnvironmentVariable);

   }


   string node::expand_environment_variables(const ::scoped_string & scopedstr)
   {

      return ::acme_posix::node::expand_environment_variables(scopedstr);

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


                  warning("node::shell_open xdg-open \"" << str << "\" returned error code " << iError);

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
////                             char * pszError = strError.get_buffer(iBufferSize);
////
////                             auto psystem = acmesystem();
////
////                             auto pnode = psystem->node();
////
////                             int iBool = pnode->os_launch_uri(strUri, pszError, iBufferSize);
////
////                             strError.release_buffer();
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


      //::particle::initialize(pparticle);

      ::string strOs;
      ::string strVer;
      //}

      // freedesktop.org and systemd
      if (acmefile()->exists("/etc/os-release"))
      {

         auto set = acmefile()->parse_standard_configuration("/etc/os-release");

         psummary->m_strDistro = set["ID"];
         psummary->m_strDistroBranch = set["VARIANT_ID"];
         psummary->m_strDesktopEnvironment = psummary->m_strDistroBranch;
         psummary->m_strDistroRelease = set["VERSION_ID"];
         psummary->m_strDistroFamily = set["ID_LIKE"];

         psummary->m_strDistro.make_lower();
         psummary->m_strDistroBranch.make_lower();
         psummary->m_strDesktopEnvironment.make_lower();
         psummary->m_strDistroRelease.make_lower();
         psummary->m_strDistroFamily.make_lower();

         if (psummary->m_strDistroFamily.case_insensitive_equals("arch"))
         {

            auto setArch = acmefile()->parse_standard_configuration("/etc/os-release");

            psummary->m_strDistroRelease = setArch["DISTRIB_RELEASE"];
            psummary->m_strDistroRelease.make_lower();

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

      if (psummary->m_strDistroFamily.is_empty())
      {

         psummary->m_strDistroFamily = psummary->m_strDistro;

      }

      if (psummary->m_strDistro.case_insensitive_equals("ubuntu"))
      {

         psummary->m_strDistroFamily = "debian";

      }
      else if (psummary->m_strDistro.case_insensitive_equals("debian"))
      {

         psummary->m_strDistroFamily = "debian";

      }
      else if (psummary->m_strDistro.case_insensitive_equals("opensuse-tumbleweed"))
      {

         psummary->m_strDistroFamily = "zypper";

      }
      else if (psummary->m_strDistro.case_insensitive_equals("opensuse-leap"))
      {

         psummary->m_strDistroFamily = "zypper";

      }

      if (psummary->m_strDistro.case_insensitive_equals("fedora"))
      {

         if (psummary->m_strDistroBranch.case_insensitive_equals("workstation"))
         {

            psummary->m_strDesktopEnvironment = "gnome";

         }

      }

      //::string strLowerCaseCurrentDesktop;

      if (psummary->m_strDesktopEnvironment.is_empty())
      {
         ///# echo "DESKTOP_ENVIRONMENT is empty here"

         if (psummary->m_strDistroFamily.case_insensitive_equals("debian")
             || psummary->m_strDistroFamily.case_insensitive_equals("zypper")
             || psummary->m_strDistroFamily.case_insensitive_equals("arch"))
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

               psummary->m_strDesktopEnvironment = "gnome";

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

               psummary->m_strDesktopEnvironment = "kde";

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

               psummary->m_strDesktopEnvironment = "lxde";

            }

         }

      }

      if (psummary->m_strDistroFamily.case_insensitive_equals("debian"))
      {

         psummary->m_strDistroBranch = psummary->m_strDesktopEnvironment;

      }
      else if (psummary->m_strDistroFamily.case_insensitive_equals("zypper"))
      {

         psummary->m_strDistroBranch = psummary->m_strDesktopEnvironment;

      }
      else if (psummary->m_strDistroFamily.case_insensitive_equals("arch"))
      {

         psummary->m_strDistroBranch = psummary->m_strDesktopEnvironment;

      }


      if (psummary->m_strDistro.case_insensitive_equals("ubuntu"))
      {

         if (psummary->m_strDesktopEnvironment.case_insensitive_equals("kde"))
         {

            psummary->m_strSlashedStore = "kubuntu/" + psummary->m_strDistroRelease;

         }
         else
         {

            psummary->m_strSlashedStore =psummary-> m_strDistro + "/" +psummary-> m_strDistroRelease;
         }

      }
      else
      {

         psummary->m_strSlashedStore=psummary->m_strDistro + "/" + psummary->m_strDistroBranch + "/" + psummary->m_strDistroRelease;

      }


      if (psummary->m_strDistroFamily == "debian")
      {

         psummary->m_strSudoInstall = "sudo apt -y install";
         psummary->m_strStandardPackageFileExtension = "deb";
         psummary->m_strPackagePlatform = "amd64";

      }
      else if (psummary->m_strDistroFamily == "fedora")
      {

         psummary->m_strSudoInstall = "sudo dnf -y install";
         psummary->m_strStandardPackageFileExtension = "rpm";
         psummary->m_strPackagePlatform = "x86_64";

      }
      else if (psummary->m_strDistroFamily == "zypper")
      {

         psummary->m_strSudoInstall = "sudo zypper --non-interactive install";
         psummary->m_strStandardPackageFileExtension = "rpm";
         psummary->m_strPackagePlatform = "x86_64";

      }

      if (psummary->m_strDesktopEnvironment == "kde")
      {

         psummary->m_strTerminal = "konsole";

      }
      else
      {

         psummary->m_strTerminal = "gnome-terminal";

      }

      psummary->m_strUnderscoreOperatingSystem = psummary->m_strSlashedStore;

      psummary->m_strSlashedIntegration = psummary->m_strSlashedStore;

      psummary->m_strUnderscoreOperatingSystem.find_replace("/", "_");

      acmenode()->set_environment_variable("__SYSTEM_DISTRO", psummary->m_strDistro);
      acmenode()->set_environment_variable("__SYSTEM_DISTRO_FAMILY", psummary->m_strDistroFamily);
      acmenode()->set_environment_variable("__SYSTEM_DISTRO_BRANCH", psummary->m_strDistroBranch);
      acmenode()->set_environment_variable("__SYSTEM_DISTRO_RELEASE", psummary->m_strDistroRelease);
      acmenode()->set_environment_variable("__SYSTEM_DESKTOP_ENVIRONMENT", psummary->m_strDesktopEnvironment);
      acmenode()->set_environment_variable("__SYSTEM_SLASHED_STORE", psummary->m_strSlashedStore);
      acmenode()->set_environment_variable("__SYSTEM_SLASHED_INTEGRATION", psummary->m_strSlashedIntegration);
      acmenode()->set_environment_variable("__SYSTEM_UNDERSCORE_OPERATING_SYSTEM", psummary->m_strUnderscoreOperatingSystem);
      acmenode()->set_environment_variable("__SYSTEM_SUDO_INSTALL", psummary->m_strSudoInstall);
      acmenode()->set_environment_variable("__SYSTEM_TERMINAL", psummary->m_strTerminal);

      return psummary;

   }


} // namespace acme_linux



