#include "framework.h"


namespace linux
{


   void window::DeleteTempMap()
   {

      //oswindow_map* pMap = __get_module_state()->m_pmapHWND;

      //if(::is_null(pMap))
      //   return;

      //single_lock synchronouslock(&pMap->m_pmutex, true);

      array < oswindow > oswindowaRemove;
      array < ::pointer<::linux::window >>wndptraRemove;

      //POSITION pos = pMap->m_temporaryMap.get_start_position();
      //while (pos != nullptr)
      //{
      //   HANDLE h; // just used for asserts
      //   ::linux::window * pTemp;
      //   pMap->m_temporaryMap.get_next_assoc(pos, h, pTemp);

      //   if(!::IsWindow((oswindow) h))
      //   {
      //      oswindowaRemove.add((oswindow) h);
      //      wndptraRemove.add(pTemp);
      //   }

      //}

      //for(i32 i = 0; i < wndptraRemove.get_count(); i++)
      //{
      //   wndptraRemove[i]->m_handlea[0] = nullptr;
      //   wndptraRemove[i]->m_handlea[1] = nullptr;

      //   (*pMap->m_pfnDestructObject)(wndptraRemove[i]);   // destruct the object
      //}

      //for(i32 i = 0; i < oswindowaRemove.get_count(); i++)
      //{
      //   pMap->m_temporaryMap.erase_key(oswindowaRemove[i]);
      //}

   }


} // namespace linux


