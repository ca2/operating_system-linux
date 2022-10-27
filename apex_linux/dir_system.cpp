#include "framework.h"
#include "dir_system.h"

#undef USE_MISC


#include <dlfcn.h>
#include <link.h>


namespace apex_linux
{


   dir_system::dir_system()
   {

   }


   dir_system::~dir_system()
   {

   }


   void dir_system::initialize(::particle * pparticle)
   {

      //auto estatus =

         ::dir_system::initialize(pparticle);

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


} // namespace apex_linux



