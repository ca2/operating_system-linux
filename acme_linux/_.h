#pragma once


#include "acme/_.h"
#include "acme_posix/_.h"


#if defined(_acme_linux_project)
#define CLASS_DECL_ACME_LINUX  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_LINUX  CLASS_DECL_IMPORT
#endif


namespace acme_linux
{


   class file_context;
   class file_system;


   class dir_context;
   class dir_system;


} // namespace acme_linux



