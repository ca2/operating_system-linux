#pragma once



struct win_handle;


typedef struct win_handle * HANDLE;
typedef HANDLE *PHANDLE, *LPHANDLE;



#define WINE_NO_UNICODE_MACROS
#define WINE_UNICODE_NATIVE
#define _WCTYPE_T_DEFINED


#ifdef WINE_NO_UNICODE_MACROS
# define DECL_WINELIB_TYPE_AW(type)  /* nothing */
#else
# define DECL_WINELIB_TYPE_AW(type)  typedef WINELIB_NAME_AW(type) type;
#endif



#include "base_tsd.h"
#include "win_def.h"
#include "win_crt.h"


#define MAX_PATH          260

#define near
#define far
#define CONST const



struct tagHandle
{

   void * m_p;

};

//typedef struct tagHandle * HANDLE;


typedef ::u32       ::u32;
//typedef int32_t                 WINBOOL;
typedef unsigned char       byte;
//typedef unsigned short      ::u16;
//typedef float               FLOAT;
//typedef FLOAT               *PFLOAT;
//typedef WINBOOL near           *PBOOL;
//typedef WINBOOL far            *int_bool *;
//typedef byte near           *PBYTE;
//typedef byte far            *LPBYTE;
//typedef int32_t near            *PINT;
//typedef int32_t far             *LPINT;
//typedef ::u16 near           *PWORD;
//typedef ::u16 far            *LPWORD;
//typedef int32_t far            *LPLONG;
//typedef ::u32 near          *PDWORD;
//typedef ::u32 far           *LPDWORD;
//typedef void far            *LPVOID;
//typedef CONST void far      *const void *;

//typedef int32_t                 INT;
//typedef ::u32        ::u32;
//typedef ::u32        *P::u32;



#define HFILE_ERROR ((HFILE)-1)



//typedef void * LPVOID;
//typedef const void * const void *;

//typedef const char * const char *;
typedef const char * LPCTSTR;
//typedef char * char *;
typedef char * LPTSTR;



//
// Basics
//

#ifndef VOID
#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef int32_t ::i32;
typedef int32_t INT;
#endif

//
// UNICODE (Wide Character) types
//

#ifndef _MAC
//typedef wchar_t WCHAR;    // wc,   16-bit UNICODE character
#else
// some Macintosh compilers don't define wchar_t in a convenient location, or define it as a char
typedef unsigned short WCHAR;    // wc,   16-bit UNICODE character
#endif


#undef FAR
#undef  NEAR
#define FAR
#define NEAR
#ifndef CONST
#define CONST               const
#endif


//////typedef WCHAR *PWCHAR, *LPWCH, *PWCH;
//typedef CONST WCHAR *LPCWCH, *PCWCH;

// null terminated
//typedef  WCHAR *NWPSTR, *LPWSTR, *PWSTR;
typedef  PWSTR *PZPWSTR;
typedef  CONST PWSTR *PCZPWSTR;
typedef  WCHAR UNALIGNED *LPUWSTR, *PUWSTR;
//typedef  CONST WCHAR *LPCWSTR, *PCWSTR;
typedef  PCWSTR *PZPCWSTR;
typedef  CONST WCHAR UNALIGNED *LPCUWSTR, *PCUWSTR;

// null null terminated
typedef  WCHAR *PZZWSTR;
typedef  CONST WCHAR *PCZZWSTR;
typedef  WCHAR UNALIGNED *PUZZWSTR;
typedef  CONST WCHAR UNALIGNED *PCUZZWSTR;

// __possibly_notnullterminated
typedef  WCHAR *PNZWCH;
typedef  CONST WCHAR *PCNZWCH;
typedef  WCHAR UNALIGNED *PUNZWCH;
typedef  CONST WCHAR UNALIGNED *PCUNZWCH;
//
// ANSI (Multi-byte Character) types
//
//typedef CHAR *PCHAR, *LPCH, *PCH;
//typedef CONST CHAR *LPCCH, *PCCH;

//typedef  CHAR *NPSTR, *char *, *PSTR;
typedef  PSTR *PZPSTR;
typedef  CONST PSTR *PCZPSTR;
//typedef  CONST CHAR *const char *, *PCSTR;
typedef  PCSTR *PZPCSTR;

typedef  CHAR *PZZSTR;
typedef  CONST CHAR *PCZZSTR;

typedef  CHAR *PNZCH;
typedef  CONST CHAR *PCNZCH;



#ifndef _TCHAR_DEFINED
typedef char TCHAR, *PTCHAR;
typedef unsigned char TBYTE , *PTBYTE ;
#define _TCHAR_DEFINED
#endif /* !_TCHAR_DEFINED */

typedef LPCH LPTCH, PTCH;
typedef LPCCH LPCTCH, PCTCH;
//typedef char * PTSTR, LPTSTR, PUTSTR, LPUTSTR;
//typedef const char * PCTSTR, LPCTSTR, PCUTSTR, LPCUTSTR;
typedef PZZSTR PZZTSTR, PUZZTSTR;
typedef PCZZSTR PCZZTSTR, PCUZZTSTR;
typedef PNZCH PNZTCH, PUNZTCH;
typedef PCNZCH PCNZTCH, PCUNZTCH;

#define TEXT(quote) __TEXT(quote)   // r_winnt


//typedef SHORT *PSHORT;
//typedef ::i32 *PLONG;


//typedef void *HINSTANCE;

#ifndef GUID_DEFINED
#define GUID_DEFINED
#if defined(__midl)
typedef struct {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    byte           Data4[ 8 ];
} GUID;
#else
typedef struct _GUID {
    ::u32   Data1;
    ::u3216_t   Data2;
    ::u3216_t   Data3;
    ::u328_t    Data4[ 8 ];
} GUID;
#endif
#endif


//#define APIENTRY

#define WINAPI

#define NEAR

#define FAR

#define DECLSPEC_NO_RETURN
void RaiseException(::u32 dwExceptionCode, ::u32 dwExceptionFlags, ::u32 nNumberOfArguments, const ulong_ptr *lpArguments);
typedef int32_t errno_t;


#ifdef __cplusplus
  #define MY_EXTERN_C extern "C"
#else
  #define MY_EXTERN_C extern
#endif


MY_EXTERN_C ::u32 GetLastError();
MY_EXTERN_C ::u32 SetLastError(::u32 dw);


/*#define MAKEWORD(a, b)      ((::u16)(((byte)(((DWORD_PTR)(a)) & 0xff)) | ((::u16)((byte)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((::i32)(((::u16)(((DWORD_PTR)(a)) & 0xffff)) | ((::u32)((::u16)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((::u16)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((::u16)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((byte)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((byte)((((DWORD_PTR)(w)) >> 8) & 0xff))*/

#define MAKEWPARAM(l, h)      ((WPARAM)(::u32)MAKELONG(l, h))
#define MAKELPARAM(l, h)      ((LPARAM)(::u32)MAKELONG(l, h))
#define MAKELRESULT(l, h)     ((LRESULT)(::u32)MAKELONG(l, h))


#include "win_error.h"
#include "win_base.h"
#include "win_gdi.h"
#include "win_user.h"


#include "win_errno.h"
#include "win_crtdefs.h"

#include "win_nls.h"


#include "win_file.h"

#include "win_mmeapi.h"
#include "win_mmsystem.h"






#define _T(psz) psz


#define c_cdecl __cdecl

//#define c_decl __cdecl



#include "ntstatus.h"



#include "win_common_controls.h"
