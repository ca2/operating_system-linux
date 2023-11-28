#pragma once



#define MEMDLEAK 0
#define STORE_LAST_BLOCK 0



//#define MCHECK



#ifdef MCHECK
#include <mcheck.h>
#define memory_alloc malloc
#define memory_realloc realloc
#define ::heap::management::memory(::heap::e_memory_main)->free free
#endif






