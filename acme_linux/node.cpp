#include "framework.h"
#include "node.h"
#include "file_system.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/operating_system/summary.h"
#include "acme/platform/system.h"


void copy(::file::path & path, const ::string & str)
{

   path = str;

}


#include "acme/prototype/collection/_generic_array.h"


#include  "acme/operating_system/ansi/binreloc.h"
#include  "acme/operating_system/ansi/_pthread.h"


#include <unistd.h>
#include <sys/utsname.h>



//
//
//::user::enum_desktop _calculate_edesktop();
//::user::enum_desktop get_edesktop();


namespace acme_linux
{


   node::node()
   {

      //m_edesktop = ::user::e_operating_ambient_none;

      //m_pAcmePlatform = this;

      m_elinuxdistribution = e_linux_distribution_not_initialized;

   }


   node::~node()
   {


   }

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
//         ::file::path str = system()->m_pnodedir->system() / "CrashDumps" / strModuleNameWithTheExeExtension;
//         wstring wstr = str;
//         RegSetValueExW(k.m_hkey, L"DumpFolder", 0, REG_EXPAND_SZ, (unsigned char*)wstr.c_str(), unsigned int((wcslen(wstr) + 1) * sizeof(wchar_t)));
//         unsigned int dw = 10;
//         RegSetValueExW(k.m_hkey, L"DumpCount", 0, REG_DWORD, (unsigned char*)&dw, sizeof(dw));
//         dw = 2;
//         RegSetValueExW(k.m_hkey, L"DumpType", 0, REG_DWORD, (unsigned char*)&dw, sizeof(dw));
//
//      }
//
//      informationf("test01");

   }


   string node::audio_get_default_implementation_name()
   {

      return system()->implementation_name("audio", "alsa");

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

      auto lines = file_system()->lines("/etc/os-release");

      ::string strId;

      if(lines.case_insensitive_find_first_begins_eat(strId, "id="))
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

         informationf("warning: Unknown linux distribution with id \"" + strId + "\".");

         m_elinuxdistribution = e_linux_distribution_unknown;

      }

   }


//   ::user::enum_desktop node::get_edesktop()
//   {
//
//      return ::platform::node::get_edesktop();
//
//   }


//x

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

      strProcPidMaps.formatf("/proc/%d/maps", (int) processidentifier);

      auto stra = ::transfer(directory_system()->enumerate_content(strProcPidMaps));

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

      directory_system()->enumerate(listing);

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
//            strPath = module_path_from_pid(iCurrentPid.as_int());
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


   ::file::path node::process_identifier_module_path(::process_identifier pid)
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


   void node::shell_open(const ::file::path & path, const ::string & strParams, const ::file::path & pathFolder)
   {

      string str(path);

      fork([this, str]()
           {

               int iError = ::system("xdg-open \"" + str + "\" & ");

               if(iError != 0)
               {


                  warning() <<"node::shell_open xdg-open \"" << str << "\" returned error code " << iError;

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
////         auto psystem = system();
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
////                             auto psystem = system();
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
////                                information() << "Error launching file : \"" << strUri << "\" , " << strError;
////
////                             }
////
////                          });
//
//
//      }


   bool node::set_process_priority(::enum_priority epriority)
   {

      int iPolicy = SCHED_OTHER;

      sched_param schedparam;

      schedparam.sched_priority = 0;

      get_os_priority(&iPolicy, &schedparam, epriority);

      sched_setscheduler(0, iPolicy, &schedparam);

      return true;

   }


   ::pointer <::operating_system::summary > node::operating_system_summary()
   {

      auto psummary = __create_new < ::operating_system::summary >();

      ::string strOs;

      ::string strVer;

      // freedesktop.org and systemd
      if (file_system()->exists("/etc/os-release"))
      {

         auto set = file_system()->parse_standard_configuration("/etc/os-release");

         psummary->m_strDistroName = set["ID"];
         psummary->m_strDistroBranchName = set["VARIANT_ID"];
         psummary->m_strDesktopEnvironmentName = psummary->m_strDistroBranch;
         psummary->m_strDistroReleaseName = set["VERSION_ID"];
         psummary->m_strDistroFamilyName = set["ID_LIKE"];

         psummary->m_strDistro = psummary->m_strDistroName;
         psummary->m_strDistroBranch = psummary->m_strDistroBranchName;
         psummary->m_strDesktopEnvironment = psummary->m_strDesktopEnvironmentName;
         psummary->m_strDistroRelease = psummary->m_strDistroReleaseName;
         psummary->m_strDistroFamily = psummary->m_strDistroFamilyName;

         psummary->m_strName = set["PRETTY_NAME"];
         psummary->m_strDistroName = set["NAME"];
         psummary->m_strDistroReleaseName = set["VERSION"];

         if(psummary->m_strDistroName.is_empty())
         {

            psummary->m_strDistroName = psummary->m_strDistro;

         }

         if(psummary->m_strDistroReleaseName.is_empty())
         {

            psummary->m_strDistroReleaseName = psummary->m_strDistroRelease;

         }

         if(psummary->m_strName.is_empty())
         {

            psummary->m_strName = psummary->m_strDistroName;

            if(psummary->m_strDistroReleaseName.has_character())
            {

               psummary->m_strName += " " + psummary->m_strDistroReleaseName;

            }

         }

         psummary->m_strDistro.make_lower();
         psummary->m_strDistroBranch.make_lower();
         psummary->m_strDesktopEnvironment.make_lower();
         psummary->m_strDistroRelease.make_lower();
         psummary->m_strDistroFamily.make_lower();

         if (psummary->m_strDistroFamily.case_insensitive_equals("arch"))
         {

            auto setArch = file_system()->parse_standard_configuration("/etc/lsb-release");

            psummary->m_strDistroRelease = setArch["DISTRIB_RELEASE"];
            psummary->m_strDistroRelease.make_lower();

            if(psummary->m_strDistro.case_insensitive_equals("manjaro"))
            {

               auto dot = psummary->m_strDistroRelease.find('.');

               if(dot)
               {

                  psummary->m_strDistroRelease.truncate(dot);

               }

            }

         }
         else if(psummary->m_strDistro.case_insensitive_equals("opensuse-tumbleweed") && psummary->m_strDistroRelease.length() > 4)
         {

            //printf("This is a openSUSE Tumbleweed System...\n");
            //printf("Gonna tweak a bit the version :-)...\n");
            //pszVersion[4] = '\0';
            //printf("There it is ___new version : %s\n", pszVersion);
            psummary->m_strDistroRelease.truncate(4);

         }

      }
      else if (this->has_posix_shell_command("lsb_release"))
      {

         //         }
         //      elif
         //      type lsb_release >/dev / null
         //      2 > &1;
         //      then

         //# linuxbase.org

         strOs = this->get_posix_shell_command_output("lsb_release -si");
         strVer = this->get_posix_shell_command_output("lsb_release -sr");

         strOs.make_lower();
         strVer.make_lower();

      }
      else if (file_system()->exists("/etc/lsb-release"))
      {

         //# For some versions of Debian/Ubuntu without lsb_release command
         auto set = file_system()->parse_standard_configuration("/etc/lsb-release");
         //./ etc / lsb - release

         strOs = set["DISTRIB_ID"];
         strVer = set["DISTRIB_RELEASE"];
         strOs.make_lower();
         strVer.make_lower();


      }
      else if (file_system()->exists("/etc/debian_version"))
      {

         //      elif[-f / etc / debian_version];
         //      then
         //
         //# Older Debian/Ubuntu/etc.

         strOs = "Debian";
         strVer = file_system()->as_string("/etc/debian_version");
         strOs.make_lower();
         strVer.make_lower();


      }
      else if (file_system()->exists("/etc/SuSe-release"))
      {
         //      elif[-f / etc / SuSe - release];
         //      then
         //
         //# Older SuSE/etc.
         //
         //              ...
      }

      else if (file_system()->exists("/etc/redhat-release"))
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

         strOs = this->get_posix_shell_command_output("uname -s");
         strVer = this->get_posix_shell_command_output("uname -r");

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
//      else if (psummary->m_strDistro.case_insensitive_equals("manjaro"))
//      {
//
//         psummary->m_strDistroRelease.empty();
//
//      }

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

            auto strLowerCaseCurrentDesktop = this->get_environment_variable("XDG_CURRENT_DESKTOP").lowered();

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
            else if (strLowerCaseCurrentDesktop.equals("xfce"))
            {
               //      elif
               //      contains
               //      $__SYSTEM_LOWER_CASE_CURRENT_DESKTOP
               //      "kde";
               //      then
               //
               //# echo "lower case xdg_current_desktop contains gnome"

               psummary->m_strDesktopEnvironment = "xfce";

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
         else if (psummary->m_strDesktopEnvironment.case_insensitive_equals("xfce"))
         {

            psummary->m_strSlashedStore = "xubuntu/" + psummary->m_strDistroRelease;

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

      psummary->m_strSlashedStore.trim("/");

      psummary->m_strUnderscoreOperatingSystem = psummary->m_strSlashedStore;

      psummary->m_strSlashedIntegration = psummary->m_strSlashedStore;

      psummary->m_strUnderscoreOperatingSystem.find_replace("/", "_");

      this->set_environment_variable("__SYSTEM_DISTRO", psummary->m_strDistro);
      this->set_environment_variable("__SYSTEM_DISTRO_FAMILY", psummary->m_strDistroFamily);
      this->set_environment_variable("__SYSTEM_DISTRO_BRANCH", psummary->m_strDistroBranch);
      this->set_environment_variable("__SYSTEM_DISTRO_RELEASE", psummary->m_strDistroRelease);
      this->set_environment_variable("__SYSTEM_DESKTOP_ENVIRONMENT", psummary->m_strDesktopEnvironment);
      this->set_environment_variable("__SYSTEM_SLASHED_STORE", psummary->m_strSlashedStore);
      this->set_environment_variable("__SYSTEM_SLASHED_INTEGRATION", psummary->m_strSlashedIntegration);
      this->set_environment_variable("__SYSTEM_UNDERSCORE_OPERATING_SYSTEM", psummary->m_strUnderscoreOperatingSystem);
      this->set_environment_variable("__SYSTEM_SUDO_INSTALL", psummary->m_strSudoInstall);
      this->set_environment_variable("__SYSTEM_TERMINAL", psummary->m_strTerminal);

      return psummary;

   }



   ::enum_linux_distribution node::get_linux_distribution() const
   {

      if (m_elinuxdistribution == e_linux_distribution_not_initialized)
      {

         ((node *)this)->calculate_linux_distribution();

      }

      return m_elinuxdistribution;

   }


//   void node::calculate_linux_distribution()
//   {
//
//      //return ::success;
//
//   }


   ::file::path node::get_default_base_integration_folder()
   {

      return directory_system()->home() / "integration/_____";

   }






   ::string node::default_component_implementation(const ::scoped_string & scopedstrComponentName)
   {

#if defined(CUBE)

      return "command_line";

#else

      if(scopedstrComponentName == "nano_archive")
      {

         return "libarchive";

      }
      else if(scopedstrComponentName == "nano_graphics")
      {

         return "cairo";

      }
      else if(scopedstrComponentName == "nano_http")
      {

#ifdef LINUX

         return "libcurl";

#elif defined(WINDOWS_DESKTOP)

         return "wininet";

#endif

      }
//       else if(scopedstrComponentName == "nano_user")
//       {
//
//          ::string strToolkit = ::windowing::get_user_toolkit_id();
//
//          return strToolkit;
//
// // #ifdef LINUX
// //
// //          auto edesktop = this->get_edesktop();
// //
// //          if(edesktop & user::e_operating_ambient_kde)
// //          {
// //
// //             return "kde5";
// //
// //          }
// //          else
// //          {
// //
// // #if HAS_GTK4
// //
// //             return "gtk4";
// //
// // #else
// //
// //             return "gtk3";
// //
// // #endif
//
// //         }
//
//          // auto ewindowing = ::windowing::get_ewindowing();
//          //
//          // if(ewindowing == ::windowing::e_windowing_wayland)
//          // {
//          //    return "wayland";
//          // }
//          // else if(ewindowing == ::windowing::e_windowing_xcb)
//          // {
//          //    return "xcb";
//          // }
//          // else
//          // {
//          //
//          //    return "x11";
//          //
//          // }
//
// // #elif defined(WINDOWS_DESKTOP)
// //
// //          return "win32";
// //
// // #endif
//
//       }
      else if(scopedstrComponentName == "nano_idn")
      {

         return "libidn";

      }

      return {};

#endif

   }


} // namespace acme_linux



