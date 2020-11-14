#pragma once


#define _THREAD_SAFE

#define ENABLE_BINRELOC

#ifndef LINUX
#define LINUX
#endif

#ifndef _LINUX
#define _LINUX
#endif


#define c_cdecl


#define BROAD_PRECOMPILED_HEADER 0

#ifndef __linux__
#define __linux__
#endif

#define _OPENGL 1

#define BSD_STYLE_SOCKETS
#define HAVE_MYSQL 1
#define HAVE_OPENSSL 1

#define VARIADIC_TEMPLATE_FORMAT2

#define HAVE_PTHREAD_MUTEX_TIMEDLOCK 1

#define OPENSSL_API_COMPAT 0x10100000L


#define CLASS_DECL_EXPORT
#define CLASS_DECL_IMPORT
#define CLASS_DECL_THREAD __thread


#define __PLATFORM   		"linux"
#define PLATFORM_NAMESPACE	linux






#ifdef cplus
#define inline static
#endif

#define static_inline static inline



#ifdef __cplusplus

#define LOG_THIS_TAG (get_demangle(typeid(*this).name()))
#define LOG_MEMBER_PREFIX __FUNCTION__

#define ALOG_FUNCTION __FUNCTION__
#define ALOG_LINE __LINE__
#define ALOG_FILE __FILE__


#include <initializer_list>

#endif



#define AXIS_FREEIMAGE


#define FONT_SANS "FreeSans"
#define FONT_SERIF "FreeSerif"
#define FONT_MONO "Ubuntu Mono"
#define FONT_SANS_EX "Liberation Sans"
#define FONT_SERIF_EX "Liberation Serif"
#define FONT_SANS_FX "Ubuntu"
#define FONT_SERIF_FX "Bitstream Charter"




#define _strdup strdup


#define HNULL 0
#define STR_NEWLINE "\n"


//#include "bit.h"





