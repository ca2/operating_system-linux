// From aura/hardware/devices.h by camilo on 2023-11-11 12:01 <3ThomasBorregaardSorensen!!
// Created by camilo on 2022-05-15 12:21 <3ThomasBorregaardSorensen!! and Mummi!!
#pragma once


#include "aura/hardware/devices.h"


namespace aura_linux
{


   namespace hardware
   {


      class device_group;


      class CLASS_DECL_AURA_LINUX devices :
         virtual public ::hardware::devices
      {
         public:


         devices();
         ~devices()  override;

         //virtual void register_device_listener(device_listener * pdevicelistener, enum_device edevice);


         //virtual void on_register_device_listener(enum_device edevice);


         //virtual void update_device_list(enum_device edevice);


      };


   } // namespace hardware


} // namespace aura_linux


