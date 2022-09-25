#pragma once


#include "aura_linux/_.h"
#include "operating-system-posix/node_kde/_.h"


#if defined(_DESKTOP_ENVIRONMENT_KDE_LIBRARY)
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_KDE  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_KDE  CLASS_DECL_IMPORT
#endif


#include <qmetatype.h>
#include <QApplication>
#include <QPalette>
#include <QAbstractNativeEventFilter>
//#define memory_new ACME_NEW

namespace desktop_environment_kde
{


   class node;


} // namespace node_kde


namespace user
{


   char * gsettings_get_malloc(const char * pszSchema, const char * pszKey);


} // namespace user


//#include "node.h"


//#include "copydesk.h"


//#include "appindicator.h"


//#include "factory_exchange.h"


//#include "node.h"



