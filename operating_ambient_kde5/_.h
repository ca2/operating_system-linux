#pragma once


#include "aura_linux/_.h"
#include "node_kde5/_.h"


#if defined(_operating_ambient_gtk4_project)
   #define CLASS_DECL_OPERATING_AMBIENT_KDE5  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_OPERATING_AMBIENT_KDE5  CLASS_DECL_IMPORT
#endif


namespace operating_ambient_gtk_based
{


   class node;


} // namespace operating_ambient_gtk_based



