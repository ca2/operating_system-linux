#include "framework.h"


#undef USE_MISC


#include <dlfcn.h>
#include <link.h>


namespace linux
{


   dir_system::dir_system()
   {

   }


   dir_system::~dir_system()
   {

   }


   ::e_status dir_system::initialize(::object * pobject)
   {

      auto estatus = ::dir_system::initialize(pobject);

      if(!estatus)
      {

         return estatus;

      }

      m_pathCa2Module = m_psystem->m_pacmedir->module();

      m_pathHome = getenv("HOME");

      return estatus;

    }


} // namespace linux



