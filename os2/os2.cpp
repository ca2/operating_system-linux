#include "framework.h"



extern "C" int32_t APIENTRY
DllMain(HINSTANCE hInstance, unsigned int dwReason, LPVOID lpReserved)
{


   __UNREFERENCED_PARAMETER(hInstance);
   __UNREFERENCED_PARAMETER(lpReserved);


   if (dwReason == DLL_PROCESS_ATTACH)
   {


      ::OutputDebugString("::ca2:: win2.dll :: initializing!\n");


   }
   else if (dwReason == DLL_PROCESS_DETACH)
   {


      ::OutputDebugString("::ca2:: win2.dll :: terminating!\n");


   }


   return 1;   // ok


}

