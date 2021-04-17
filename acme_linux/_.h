#pragma once


#include "acme/_.h"
#include "acme/operating_system.h"
#include "platform-posix/acme_posix/_.h"


#if defined(_ACME_LINUX_LIBRARY)
#define CLASS_DECL_ACME_LINUX  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_LINUX  CLASS_DECL_IMPORT
#endif


#include "acme/filesystem/filesystem/acme_dir.h"
#include "acme/filesystem/filesystem/acme_path.h"


#include "acme_dir.h"
#include "acme_path.h"


#include "node.h"



