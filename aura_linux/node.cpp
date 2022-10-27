#include "framework.h"
#include "node.h"


namespace aura_linux
{


   node::node()
   {

      //m_pnodenode = this;

      m_pAuraPlatform = this;

   }


   node::~node()
   {


   }


   void node::initialize(::particle * pparticle)
   {

      //auto estatus =

         ::apex_linux::node::initialize(pparticle);

//         if(!estatus)
//         {
//
//            return estatus;
//
//         }

      //estatus =
      //
      ::aura_posix::node::initialize(pparticle);

//         if(!estatus)
//         {
//
//            return estatus;
//
//         }

      //estatus =
      //
      ::aura::node::initialize(pparticle);

//         if(!estatus)
//         {
//
//            return estatus;
//
//         }
//
//         return estatus;

   }


   string node::get_user_name()
   {

//         WCHAR wsz[1024];
//
//         DWORD dwSize = sizeof(wsz) / sizeof(WCHAR);
//
//         ::GetUserNameW(wsz, &dwSize);
//
//         return string(wsz);

      return "";

   }


   void node::browse_for_folder(::file::path & pathFolder)
   {

//         wstring wstrFolder(pathFolder);
//
//         int i = (int) (iptr) ::ShellExecuteW(nullptr, L"open", wstrFolder, nullptr, nullptr, SW_NORMAL);
//
//         if (i < 32)
//         {
//
//            switch (i)
//            {
//            case 0:
//               //The operating system is out of memory or resources.
//               return error_no_memory;
//            case ERROR_FILE_NOT_FOUND:
//               return error_file_not_found;
//               //The specified file was not found.
//            case ERROR_PATH_NOT_FOUND:
//               return error_path_not_found;
//               //            The specified path was not found.
//            case          ERROR_BAD_FORMAT:
//               return error_bad_format;
//               //The.exe file is invalid(non - Win32.exe or error in.exe image).
//               //case SE_ERR_ACCESSDENIED:
//               //         return error_access_denied;
//               ////The operating system denied access to the specified file.
//               //SE_ERR_ASSOCINCOMPLETE
//               //The file name association is incomplete or invalid.
//               //SE_ERR_DDEBUSY
//               //The DDE transaction could not be completed because other DDE transactions were being processed.
//               //SE_ERR_DDEFAIL
//               //The DDE transaction failed.
//               //SE_ERR_DDETIMEOUT
//               //The DDE transaction could not be completed because the request timed out.
//               //SE_ERR_DLLNOTFOUND
//               //The specified DLL was not found.
//               //SE_ERR_FNF
//               //The specified file was not found.
//               //SE_ERR_NOASSOC
//               //There is no application associated with the given file name extension.This error will also be returned if you attempt to print a file that is not printable.
//               //SE_ERR_OOM
//               //There was not enough memory to complete the operation.
//               //SE_ERR_PNF
//               //The specified path was not found.
//               //SE_ERR_SHARE
//               //A sharing violation occurred.*/
//            default:
//               return error_failed;
//            }
//
//         }

      //return ::success;

   }


} // namespace aura_linux



