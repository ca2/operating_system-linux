#pragma once


#include "acme/_.h"


#if defined(_ACME_LINUX_LIBRARY)
#define CLASS_DECL_ACME_LINUX  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_LINUX  CLASS_DECL_IMPORT
#endif



