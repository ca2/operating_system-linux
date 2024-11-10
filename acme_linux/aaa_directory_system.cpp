#include "framework.h"
#include "directory_system.h"

#undef USE_MISC


#include <dlfcn.h>
#include <link.h>


namespace acme_linux
{


   directory_system::directory_system()
   {

   }


   directory_system::~directory_system()
   {

   }


   void directory_system::initialize(::particle * pparticle)
   {

      //auto estatus =

         ::directory_system::initialize(pparticle);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }

      m_pathHome = getenv("HOME");

      m_pathCa2Config = m_pathHome / ".config/ca2";

      //return estatus;

    }


} // namespace acme_linux



