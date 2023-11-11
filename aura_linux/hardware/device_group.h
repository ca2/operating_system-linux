// From aura/hardware/device_group.h by camilo on 2023-11-11 11:59 <3ThomasBorregaardSorensen!!
#pragma once


#include "aura/hardware/device_group.h"

struct udev_device;


namespace aura_linux
{


   namespace hardware
   {


      class CLASS_DECL_AURA_LINUX device_group :
         virtual public ::hardware::device_group
      {
         public:


         ::task_pointer m_ptaskUdevListener;


         device_group();
         ~device_group() override;


         void initialize_device_group(::hardware::enum_device edevice, ::hardware::devices * pdevices) override;

         void finalize_device_group() override;

         virtual void __udev_listener_task(const char * pszDevType);
         //void on_device_list_updated() override;

         virtual void __udev_signal_event(::udev_device * pdevice);


      };

   }  // namespace hardware


} // namespace aura_linux