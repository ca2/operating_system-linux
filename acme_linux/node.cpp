#include "framework.h"
#include "node.h"
#include "acme_file.h"
//#include "acme/primitive/collection/string_array.h"
#include <sys/utsname.h>


#include  "acme/operating_system/ansi/binreloc.h"


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
//            if(strPath.compare_ci(pszModulePath) == 0 )
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



} // namespace acme_linux



