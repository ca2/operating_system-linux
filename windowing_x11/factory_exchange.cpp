#include "framework.h"





extern "C"
void windowing_x11_factory_exchange()
{

   create_factory < ::windowing_x11::display, ::windowing::display > ();
   create_factory < ::windowing_x11::window, ::windowing::window > ();

}



