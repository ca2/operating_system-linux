#pragma once


#include "node_linux/_.h"
#include "aura/os/linux/appindicator.h"


#include <gtk/gtk.h>
#include <gdk/gdkx.h>


#if defined(_NODE_GNOME_LIBRARY)
   #define CLASS_DECL_NODE_GNOME  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_NODE_GNOME  CLASS_DECL_IMPORT
#endif


namespace node_gnome
{

   class node;


} // namespace node_gnome

namespace user
{

   char * gsettings_get_malloc(const char * pszSchema, const char * pszKey);


}

#include "node.h"


#include "copydesk.h"


#include "factory_exchange.h"



