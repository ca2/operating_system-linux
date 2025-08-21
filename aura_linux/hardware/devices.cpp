// From aura/hardware/devices.cpp by camilo on 2023-11-11 12:00 <3ThomasBorregaardSorensen!!
// Created by camilo on 2022-02-20 12:22 <3ThomasBorregaardSoerensen!!
// From windowing_win32::devices by camilo on 2022-05-15 17:08 <3ThomasBorregaardSoerensen!! and Mummi!!
#include "../framework.h"
#include "device_group.h"
#include "devices.h"



namespace video_input_video_for_linux
{


//
//
//#if HAVE_UDEV
//   /**
// * Device added callback
// *
// * If everything went fine we can start capturing again when the device is
// * reconnected
// */
//static void device_added(void *vptr, calldata_t *calldata)
//{
//	V4L2_DATA(vptr);
//
//	obs_source_update_properties(m_pdevice->m_iSource);
//
//	const_char_pointer dev;
//	calldata_get_string(calldata, "device", &dev);
//
//	if (strcmp(data->device_id, dev))
//		return;
//
//	blog(LOG_INFO, "Device %s reconnected", dev);
//
//	v4l2_init(data);
//}
///**
// * Device removed callback
// *
// * We stop recording here so we don't block the device node
// */
//static void device_removed(void *vptr, calldata_t *calldata)
//{
//	V4L2_DATA(vptr);
//
//	obs_source_update_properties(m_pdevice->m_iSource);
//
//	const_char_pointer dev;
//	calldata_get_string(calldata, "device", &dev);
//
//	if (strcmp(data->device_id, dev))
//		return;
//
//	blog(LOG_INFO, "Device %s disconnected", dev);
//
//	v4l2_terminate(data);
//}
//
//#endif


//    void video_input::v4l2_init_udev(void)
//    {

//       system()->add_handler(this);

//       fork([]()
//            {


//               int fd;
//               fd_set fds;
//               struct timeval tv;
//               struct udev *udev;
//               struct udev_monitor *mon;
//               struct udev_device *dev;

//               /* set up udev monitoring */
//               udev = udev_new();
//               mon = udev_monitor_new_from_netlink(udev, "udev");
//               udev_monitor_filter_add_match_subsystem_devtype(mon, "video4linux",
//                                                               NULL);
//               if (udev_monitor_enable_receiving(mon) < 0)
//               {

//                  //return NULL;

//                  return;

//               }

//               /* set up fds */
//               fd = udev_monitor_get_fd(mon);

//               while (::task_get_run()) {
//                  FD_ZERO(&fds);
//                  FD_SET(fd, &fds);
//                  tv.tv_sec = 1;
//                  tv.tv_usec = 0;

//                  if (select(fd + 1, &fds, NULL, NULL, &tv) <= 0)
//                     continue;

//                  dev = udev_monitor_receive_device(mon);
//                  if (!dev)
//                     continue;

//                  udev_signal_event(dev);

//                  udev_device_unref(dev);
//               }

//               udev_monitor_unref(mon);
//               udev_unref(udev);


//            });





// //
// //      pthread_mutex_lock(&udev_mutex);
// //
// //      /* set up udev */
// //      if (udev_refs == 0)
// //      {
// //         if (os_event_init(&udev_event, OS_EVENT_TYPE_MANUAL) != 0)
// //            goto fail;
// //         if (pthread_create(&udev_thread, NULL, udev_event_thread,
// //                            NULL) != 0)
// //            goto fail;
// //
// //         udev_signalhandler = signal_handler_create();
// //         if (!udev_signalhandler)
// //            goto fail;
// //         signal_handler_add_array(udev_signalhandler, udev_signals);
// //      }
// //      udev_refs++;
// //
// //      signal_handler_t *sh = v4l2_get_udev_signalhandler();
// //
// //      signal_handler_connect(sh, "device_added", &s_device_added, data);
// //      signal_handler_connect(sh, "device_removed", &s_device_removed, data);
// //
// //
// //   fail:
// //      pthread_mutex_unlock(&udev_mutex);
//    }

//    void video_input::v4l2_unref_udev(void)
//    {
//       pthread_mutex_lock(&udev_mutex);

// //      /* unref udev monitor */
// //      if (udev_refs && --udev_refs == 0)
// //      {
// //         os_event_signal(udev_event);
// //         pthread_join(udev_thread, NULL);
// //         os_event_destroy(udev_event);
// //
// //         if (udev_signalhandler)
// //            signal_handler_destroy(udev_signalhandler);
// //         udev_signalhandler = NULL;
// //      }

//       pthread_mutex_unlock(&udev_mutex);
//    }


}

//signal_handler_t *v4l2_get_udev_signalhandler(void)
//{
//   return udev_signalhandler;
//}



namespace aura_linux
{

   namespace hardware
   {


      devices::devices()
      {

      }


      devices::~devices()
      {

      }


      // void devices::register_device_listener(device_listener * pdevicelistener, enum_device edevice)
      // {

      //    auto & pdevicegroup = m_mapdevicegroup[edevice];

      //    ødefer_construct(pdevicegroup);

      //    pdevicegroup->add(pdevicelistener);

      //    pdevicegroup->initialize_device_group(edevice, this);

      // }


      //void devices::on_register_device_listener(::hardware::enum_device edevice)
      //{


      //}


      // void devices::update_device_list(enum_device edevice)
      // {


      // }


   } // namespace hardware



} // namespace aura_linux

