// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// hi5 contribution...
#include "framework.h"
#include "gnome_gnome.h"


namespace node_gnome
{


   windowing::windowing()
   {


   }


   windowing::~windowing()
   {


   }


   ::e_status windowing::user_fork(const ::promise::routine & routine)
   {

      gdk_fork([routine]()
               {

                  routine();

               });

      return success;

   }


   void windowing::message_loop_step()
   {

      x11_message_loop_step();

   }


} // namespace node_gnome



