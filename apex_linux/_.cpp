#include "framework.h"
#include "acme/_library.h"
////#include "acme/exception/exception.h"


void CLASS_DECL_APEX_LINUX __cdecl _ca2_purecall()
{

   throw ::exception(error_pure_call);

}


namespace linux
{




   //HINSTANCE load_library(const char* psz)

   //{

   //   return ::LoadLibraryW(utf8_to_unicode(scopedstr));


   //}


   //bool CLASS_DECL_APEX_LINUX shell_get_special_folder_path(HWND hwnd, ::file::path& str, int csidl, bool fCreate)
   //{

   //   return ::SHGetSpecialFolderPathW(hwnd, wstring_adaptor(str, MAX_PATH * 8), csidl, fCreate) != false;

   //}


   //::file::path CLASS_DECL_APEX_LINUX shell_get_special_folder_path(int csidl, bool fCreate, ::windowing::window* pwindow)
   //{

   //   ::file::path path;

   //   if (!shell_get_special_folder_path(nullptr, path, csidl, fCreate))
   //   {

   //      return "";

   //   }

   //   return path;

   //}




   //unsigned int get_current_directory(string& str)
   //{

   //   return ::GetCurrentDirectoryW(MAX_PATH * 8, wstring_adaptor(str, MAX_PATH * 8));

   //}


   //unsigned int get_temp_path(string& str)
   //{

   //   return ::GetTempPathW(MAX_PATH * 8, wstring_adaptor(str, MAX_PATH * 8));

   //}


   //int reg_query_value(HKEY hkey, const char* pszSubKey, string& str)
   //{

   //   DWORD dwType = 0;
   //   DWORD dwSize = 0;
   //   int lResult = RegQueryValueExW(hkey, wstring(scopedstrSubKey), nullptr, &dwType, nullptr, &dwSize);

   //   if (lResult != ERROR_SUCCESS)
   //      return lResult;
   //   ASSERT(dwType == REG_SZ || dwType == REG_MULTI_SZ || dwType == REG_EXPAND_SZ);
   //   if (dwType == REG_SZ || dwType == REG_MULTI_SZ || dwType == REG_EXPAND_SZ)
   //   {

   //      natural_wstring pwsz(byte_count, dwSize);

   //      lResult = RegQueryValueExW(hkey, wstring(scopedstrSubKey), nullptr, &dwType, (unsigned char*)(unichar*)pwsz, &dwSize);

   //      str = pwsz;

   //      //str.release_buffer(dwSize);

   //      return lResult;

   //   }
   //   else
   //   {

   //      return ERROR_NOT_SUPPORTED;

   //   }

   //}


   //HICON extract_icon(HINSTANCE hInst, const char* pszExeFileName, unsigned int nIconIndex)

   //{

   //   return ::ExtractIconW(hInst, utf8_to_unicode(scopedstrExeFileName), nIconIndex);


   //}


   //bool delete_file(const char* pFileName)

   //{

   //   return ::DeleteFileW(utf8_to_unicode(pFileName)) != false;


   //}

   //CLASS_DECL_ACME ::file::path user_appdata_local();

   //CLASS_DECL_APEX_LINUX void time_to_file_time(::particle * pparticle, const ::earth::time& time, LPFILETIME pFileTime)
   //{

   //   SYSTEMTIME sysTime;

   //   sysTime.wYear = (unsigned short)time.GetYear();
   //   sysTime.wMonth = (unsigned short)time.GetMonth();
   //   sysTime.wDay = (unsigned short)time.GetDay();
   //   sysTime.wHour = (unsigned short)time.GetHour();
   //   sysTime.wMinute = (unsigned short)time.GetMinute();
   //   sysTime.wSecond = (unsigned short)time.GetSecond();
   //   sysTime.wMilliseconds = 0;

   //   // convert system time to local file time
   //   FILETIME localTime;

   //   DWORD dwLastError = ::GetLastError();

   //   if (!SystemTimeToFileTime((LPSYSTEMTIME)&sysTime, &localTime))
   //      ::file::throw_os_error(dwLastError);

   //   // convert local file time to UTC file time
   //   if (!LocalFileTimeToFileTime(&localTime, pFileTime))
   //      ::file::throw_os_error(dwLastError);

   //}



   //::file::path user_appdata_local()
   //{

   //   return shell_get_special_folder_path(CSIDL_LOCAL_APPDATA);

   //}



   //CLASS_DECL_ACME::file::path get_known_folder(REFKNOWNFOLDERID kfid)
   //{

   //   ::file::path str;

   //   ::cotaskptr < PWSTR > pwszPath;

   //   HANDLE hToken = nullptr;

   //   ::OpenProcessToken(::GetCurrentProcess(), TOKEN_QUERY | TOKEN_IMPERSONATE | TOKEN_DUPLICATE, &hToken);

   //   HRESULT hr = SHGetKnownFolderPath(kfid, 0, hToken, &pwszPath);

   //   return pwszPath;

   //}


} // namespace linux



//LRESULT CALLBACK __window_procedure(HWND oswindow, const ::id & id, wparam wparam, lparam lparam);
//
//WNDPROC get_window_procedure()
//{
//
//   return &::__window_procedure;
//
//}





