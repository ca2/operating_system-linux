#include "framework.h"


namespace win2
{


   application::application(::ca::application * papp) :
      ca(papp)
   {

      m_bLicense = false;

   }

   application::~application()
   {

   }



   ::user::printer * application::get_printer(const_char_pointer pszDeviceName)
   {
      ::win2::printer * pprinter = øallocate< ::win2::printer(get_app >());
      if(!pprinter->open(scopedstrDeviceName))
      {
         delete pprinter;
         return NULL;
      }
      return pprinter;
   }


} // namespace win2
