// From aura/hardware/device_group.cpp by camilo on 2023-11-11 12:00 <3ThomasBorregaardSorensen!!
#include "../framework.h"
#include "device_group.h"
#include "devices.h"
#include "acme/platform/application.h"


namespace aura_linux
{


   namespace hardware
   {


      device_group::device_group()
      {

         defer_create_synchronization();

      }


      device_group::~device_group()
      {


      }


      void device_group::initialize_device_group(::hardware::enum_device edevice, ::hardware::devices * pdevices)
      {

         ::hardware::device_group::initialize_device_group(edevice, pdevices);

         const char * pszDevType = nullptr;

         if(m_edevice == ::hardware::e_device_video_input)
         {

            pszDevType = "video4linux";
   
         }

         if(::is_null(pszDevType))
         {

            throw ::exception(error_wrong_state);
   
         }

         m_ptaskUdevListener = m_papplication->fork([this, pszDevType]()
         {

            __udev_listener_task(pszDevType);

         });

      }


      void device_group::finalize_device_group()
      {

         if(m_ptaskUdevListener)
         {

            m_ptaskUdevListener->set_finish();

         }

      }


      //void device_group::__start_udev_listener_task()


      // void device_group::on_device_list_updated()
      // {

      //    m_pdevices->update_device_list(m_edevice);

      //    for (auto & pdevicelistener: *this)
      //    {

      //       pdevicelistener->on_device_nodes_changed();

      //    }

      // }


   } // namespace hardware




} // namespace aura_linux



