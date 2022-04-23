#pragma once


#if defined(__LP64__) || defined(_LP64)    // X64


#ifdef __arm__
#define ARM
#else
#define AMD64
#endif

#define OS64BIT
#define OSBIT 64
#if !defined(__LP64__)
#define __LP64__
#endif
#if !defined(_LP64)
#define _LP64
#endif



#else


#ifdef __arm__
#define ARM
#else
#define X86
#define _X86_
#endif


#define OS32BIT
#define OSBIT 32


#endif




















