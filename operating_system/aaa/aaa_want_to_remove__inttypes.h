#pragma once


#include <inttypes.h>




#if OSBIT == 64

    typedef int64_t int_ptr, *pint_ptr;
    typedef ::u3264_t uptr, *puptr;

    typedef int64_t long_ptr, *plong_ptr;
    //typedef ::u3264_t ulong_ptr, *pulong_ptr;

//    typedef ::u3264_t dword_ptr;


#else

    typedef int32_t int_ptr, *pint_ptr;
    typedef ::u32 uptr, *puptr;

    typedef int32_t long_ptr, *plong_ptr;
//    typedef ::u32 ulong_ptr, *pulong_ptr;

//	typedef ::u32 dword_ptr;


#define __int3264   int32_t


#endif


typedef unsigned char byte;
typedef ::u32 ::u32;

