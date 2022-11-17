#pragma once


#define index linux_bsd_index


#define MAX_PATH 260
#define _MAX_PATH MAX_PATH





// platform text char
#define platform_char char


#ifdef __cplusplus

#ifdef __arm__

#define DEBUG_BREAK __asm__("BKPT")

#else

#define DEBUG_BREAK asm("int $3")

#endif

#endif


#include <features.h>


#include <ctype.h>


#include <strings.h>
#include <cstring>


#include <cerrno>


#include <cstdarg>
#include <cstdlib>
#include <cstdio>

#include <ctime>


#include <climits>

#define sync unistd_sync
#include <unistd.h>
#undef sync


#include <wchar.h>
#include <wctype.h>

#include "__standard_type.h"
/*
#ifndef _XSERVER64
#ifndef _XTYPEDEF_XID
#define _XTYPEDEF_XID
typedef unsigned long XID;
#endif
#endif
*/

//#pragma once



#define __cdecl
#define _stdcall

#define _NORMAL_BLOCK  1


// Ubuntu apt-get install libx11-dev
// CentOS yum install libX11-devel
// openSUSE zypper install libx11-devel
//#include <X11/Xlib.h>
//#include <X11/Xutil.h>

//#ifdef __cplusplus
//struct pthread
//{
//
//   pthread_t m_thread;
//
//   pthread(){}
//   pthread(const pthread & p){operator=(p);}
//   pthread(const pthread_t & p){operator=(p);}
//
//   inline operator pthread_t &() { return m_thread; }
//   inline operator void *() { return (void *) (int_ptr) m_thread; }
//
//   inline operator pthread_t() const { return m_thread; }
//   inline operator void *() const { return (void *) (int_ptr) m_thread; }
//
//   pthread & operator =(const pthread & p) {m_thread = p.m_thread; return *this;}
//   pthread & operator =(const pthread_t & p) {m_thread = p; return *this;}
//
//   bool operator ==(const pthread_t & p) const {return m_thread == p;}
//   bool operator ==(const pthread & p) const {return operator==(p.m_thread);}
//   bool operator !=(const pthread_t & p) const {return !operator == (p);}
//   bool operator !=(const pthread & p) const {return operator != (p.m_thread);}
//
//};
//typedef pthread_t HTHREAD;
//
//#else
//struct pthread
//{
//   pthread_t m_thread;
//};
//#endif
//typedef struct pthread HTHREAD;

//typedef XID                      Window;

struct device_context;
struct gdi_object;




typedef struct device_context * HDC;

typedef struct gdi_object * HGDIOBJ;

//union _XEvent;

//typedef union _XEvent XEvent;

#define DECL_SPEC_ANY


// STRICT is the only supported option (NOSTRICT is no longer supported)
#ifndef STRICT
#define STRICT 1
#endif


#ifndef EXPORT
#define EXPORT
#endif

#ifdef __cplusplus


void debug_break();


#endif


#ifndef SIZE_T_MAX
	#define SIZE_T_MAX  UINT_MAX
#endif

#ifndef CDECL
	#define CDECL
#endif

#ifndef EXPORT
	#define EXPORT
#endif

// UNALIGNED is used for unaligned data access (in carchive mostly)
#if !defined(UNALIGNED)
#if defined(_M_IA64) || defined(_M_AMD64)
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif



// for global data that should be in COMDATs (packaged data)
#ifndef __COMDAT
#define __COMDAT // __declspec(selectany)
#endif


#define NO_ANSIUNI_ONLY

#define MAX_DWORD_PTR ((dword_ptr)(-1))

#define TRUE 1

#define FALSE 0




typedef unsigned short  wd16char;
typedef wchar_t         wd32char;
typedef wd32char        widechar;

#define DECL_C


#define _PRE_WIDEN(x) L##x
#define _WIDEN(x) _PRE_WIDEN(x)

#define NOTHROW throw()
#define THROWS // gnucc null throw statement means that the function can throw any exception


#ifdef _DEBUG

#define RELEASENOTHROW

#else

#define RELEASENOTHROW throw()

#endif


//#define ::u32     ::u32
//
//#define byte      ::u328_t

//#define NULL 0

#define _strcmpi strcasecmp


#define __forceinline inline




//typedef ::u328_t byte;


typedef void * PVOID;


#define PURE = 0


#define __stdcall
#define _gmtime64 gmtime


#define stricmp strcasecmp
#define strnicmp strncasecmp


#define _stricmp  stricmp
#define _strnicmp  strnicmp





#define MOVE_SEMANTICS










#define wcsicmp wcscasecmp
#define wcsnicmp wcsncasecmp


#define _strlwr __ansilwr
#define _strupr __ansiupr



#undef index


#define WINBOOL int


#define INFINITE_TIMEOUT UINT_MAX


#ifndef offsetof
#define offsetof(type, member)  __builtin_offsetof (type, member)
#endif



