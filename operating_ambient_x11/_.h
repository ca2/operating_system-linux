#pragma once


#include "aura_linux/_.h"
#include "node_x11/_.h"


#if defined(_operating_ambient_x11_project)
   #define CLASS_DECL_OPERATING_AMBIENT_X11  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_OPERATING_AMBIENT_X11  CLASS_DECL_IMPORT
#endif


namespace operating_ambient_x11
{


   class node;


} // namespace operating_ambient_x11



