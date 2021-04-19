#pragma once


#include "aura_linux/_.h"
#include "platform-posix/node_gnome/_.h"


#include <gtk/gtk.h>
#include <gdk/gdkx.h>


#if defined(_DESKTOP_ENVIRONMENT_GNOME_LIBRARY)
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GNOME  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GNOME  CLASS_DECL_IMPORT
#endif


namespace desktop_environment_gnome
{


   class node;


} // namespace node_gnome


#include "node.h"


#include "factory_exchange.h"



