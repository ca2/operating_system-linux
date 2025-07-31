#pragma once


#include "acme/node/linux/_node_linux.h"


//#include "exception.h"

//string get_error_message(unsigned int dwError);


//CLASS_DECL_APEX_LINUX bool __initialize();


//#include "system_dir.h"
//#include "system_file.h"
//
//#include "folder_watch.h"
//#include "factory_exchange.h"
//#include "uac_tools.h"
//#include "thread.h"
//#include "file.h"
//#include "crypto.h"
//#include "ip_enum.h"


#define NODE_THREAD(pthread) (dynamic_cast < ::linux::thread * > (dynamic_cast < thread * >(pthread)))


//
//#include "command.h"



//void CLASS_DECL_APEX_LINUX __cdecl _ca2_purecall();
//void CLASS_DECL_APEX_LINUX __cdecl _null_se_translator(unsigned int uiCode, EXCEPTION_POINTERS * ppointers);
//bool CLASS_DECL_APEX_LINUX __linux_init();
int CLASS_DECL_APEX_LINUX __linux_main(::apex::system * psystem, ::create * pmaininitdata);






//#include "file_find.h"
//#include "file.h"
//#include "shell.h"
//#include "stdio_file.h"
//#include "registry.h"
//#include "os.h"

//
//// Sanity checks for ATOMs
//CLASS_DECL_APEX_LINUX bool __is_valid_atom(ATOM nAtom);
////CLASS_DECL_APEX_LINUX bool __is_valid_atom(const char * psz);
//CLASS_DECL_APEX_LINUX bool __is_valid_atom(const wchar_t * psz);
//

///////////////////////////////////////////////////////////////////////////////
//// locale-invariant comparison helpers till CRT gets that support
//inline int __invariant_stricmp(const char *pszLeft,const char *pszRight)
//{
//#ifdef LINUX_DESKTOP
//   return ::CompareStringA(MAKELCID(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US),SORT_DEFAULT),
//                           NORM_IGNORECASE,
//                           pszLeft,
//                           -1,
//                           pszRight,
//                           -1) - CSTR_EQUAL;
//#else
//   return case_insensitive_ansi_compare(scopedstrLeft,pszRight);
//#endif
//}
//
//inline int __invariant_stricmp(const unichar *pwszLeft,const unichar *pwszRight)
//{
//#ifdef LINUX_DESKTOP
//   return ::CompareStringW(MAKELCID(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US),SORT_DEFAULT),
//                           NORM_IGNORECASE,
//                           pwszLeft,
//                           -1,
//                           pwszRight,
//                           -1) - CSTR_EQUAL;
//#else
//   return wide_compare_case_insensitive(pwszLeft,pwszRight);
//#endif
//}

/////////////////////////////////////////////////////////////////////////////
// Portability abstractions

#define __set_dialog_control_id(oswindow, nID)     SetWindowLong(oswindow, GWL_ID, nID)
#define __set_dialog_control_id_(oswindow, nID)     oswindow->SetWindowLong(GWL_ID, nID)
#define __get_dialog_control_id(oswindow)         ((unsigned int)(unsigned short)::GetDlgCtrlID(oswindow))
#define __get_dialog_control_id_(oswindow)         ((unsigned int)(unsigned short)oswindow->GetDlgCtrlId())


//#include "pipe.h"
//#include "process.h"








//
//
//namespace linux
//{
//
//
//   class thread;
//
//   class linux
//   {
//      int function();
//   };
//
//   CLASS_DECL_APEX_LINUX HINSTANCE   load_library(const char * psz);
//
//   CLASS_DECL_APEX_LINUX bool        shell_get_special_folder_path(::windowing::window * pwindow,::file::path &str,int csidl,bool fCreate);
//   CLASS_DECL_APEX_LINUX ::file::path  shell_get_special_folder_path(int csidl, bool fCreate = true, ::windowing::window * pwindow = nullptr);
//   CLASS_DECL_APEX_LINUX unsigned int       get_file_attributes(const char * pFileName);
//
//   CLASS_DECL_APEX_LINUX unsigned int       get_current_directory(string & str);
//   CLASS_DECL_APEX_LINUX unsigned int       get_temp_path(string & str);
//   CLASS_DECL_APEX_LINUX int        reg_query_value(HKEY hkey,const char * pszSubKey,string & str);
//
//   CLASS_DECL_APEX_LINUX HICON       extract_icon(HINSTANCE hInst,const char * pszExeFileName,unsigned int nIconIndex);
//
//   CLASS_DECL_APEX_LINUX bool        delete_file(const char * pFileName);
//
//   CLASS_DECL_APEX_LINUX int     get_menu_string(HMENU hMenu,unsigned int uDItem,string & str,unsigned int flags);
//   CLASS_DECL_APEX_LINUX void        time_to_file_time(::particle * pparticle,const ::earth::time& time,LPFILETIME pFileTime);
//
//
//} // namespace linux
//
//
//
//
//
//CLASS_DECL_APEX_LINUX int delete_registry_tree_helper(HKEY hParentKey,const ::scoped_string & scopedstrKeyName);
//
//
//CLASS_DECL_APEX_LINUX HINSTANCE __get_resource_handle();
//CLASS_DECL_APEX_LINUX void __set_resource_handle(HINSTANCE hInstResource);
//
//CLASS_DECL_APEX_LINUX HINSTANCE __get_resource_handle();
//CLASS_DECL_APEX_LINUX HINSTANCE __find_string_resource_handle(unsigned int nID);
//

CLASS_DECL_APEX_LINUX ::pointer<::apex::application>__get_app();

CLASS_DECL_APEX_LINUX int app_main(::apex::system * psystem, HINSTANCE hInstance, HINSTANCE hPrevInstance, char * pCmdLine, ::e_display edisplay);




//#include "tts_speaker.h"




