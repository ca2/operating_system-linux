#pragma once


#include "aura_linux/_.h"
#include "node_gnome/_.h"


#if defined(_desktop_environment_gnome_project)
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GNOME  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GNOME  CLASS_DECL_IMPORT
#endif


namespace desktop_environment_gnome
{


   class node;


} // namespace node_gnome



