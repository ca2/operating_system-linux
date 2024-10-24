/*
Copyright (C) 2014 by Leonhard Oelke <leonhard@in-verted.de>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "../framework.h"
#include "device_group.h"
#include <pthread.h>
#include <libudev.h>
#include "acme/constant/id.h"
#include "acme/handler/topic.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/acme.h"
#include "apex/platform/system.h"



// //#include <util/threading.h>
// //#include <util/darray.h>
// //#include <obs.h>

// //#include "v4l2-udev.h"

// /** udev action enum */
// enum udev_action {
//    UDEV_ACTION_ADDED,
//    UDEV_ACTION_REMOVED,
//    UDEV_ACTION_UNKNOWN
// };

//static const char *udev_signals[] = {"void device_added(string device)",
//                                     "void device_removed(string device)",
//                                     NULL};


//static pthread_t udev_thread;
//static os_event_t *udev_event;

// //static signal_handler_t *udev_signalhandler = NULL;

// ///**
// // * udev gives us the device action as string, so we convert it here ...
// // *
// // * @param action the udev action as string
// // * @return the udev action as enum value
// // */
// static enum udev_action udev_action_to_enum(const char *action)
// {
//    if (!action)
//       return UDEV_ACTION_UNKNOWN;

//    if (!strncmp("add", action, 3))
//       return UDEV_ACTION_ADDED;
//    if (!strncmp("remove", action, 6))
//       return UDEV_ACTION_REMOVED;

//    return UDEV_ACTION_UNKNOWN;
// }

// CLASS_DECL_ACME ::platform::system * system();

///**
// * Event listener thread
// */
//static void *udev_event_thread(void *vptr)
//{
//   UNUSED_PARAMETER(vptr);
//
//
//   return NULL;
//}




namespace aura_linux
{


   namespace hardware
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
//	const char *dev;
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
//	const char *dev;
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


   void device_group::__udev_listener_task(const char * pszDevType)
   {

      /* set up udev monitoring */
      auto pudev = udev_new();

      auto pudevmonitor = udev_monitor_new_from_netlink(pudev, "udev");

      udev_monitor_filter_add_match_subsystem_devtype(pudevmonitor, pszDevType, NULL);

      if (udev_monitor_enable_receiving(pudevmonitor) < 0)
      {

         return;
   
      }

      /* set up fds */
      auto iFileDescriptor = udev_monitor_get_fd(pudevmonitor);

      while (::task_get_run()) 
      {
   
         fd_set fdset;
         
         FD_ZERO(&fdset);
         
         FD_SET(iFileDescriptor, &fdset);
         
         struct timeval timeval;
         
         timeval.tv_sec = 1;

         timeval.tv_usec = 0;

         if (select(iFileDescriptor + 1, &fdset, NULL, NULL, &timeval) <= 0)
         {

            continue;

         }

         auto pudevdevice = udev_monitor_receive_device(pudevmonitor);

         if (!pudevdevice)
         {

            continue;

         }

         try
         {

            __udev_signal_event(pudevdevice);

         }
         catch(...)
         {
            
            warning() << "exception while processing __udev_signal_event";

         }
         

         udev_device_unref(pudevdevice);

      }

      udev_monitor_unref(pudevmonitor);

      udev_unref(pudev);

      m_ptaskUdevListener.release();
//
//      pthread_mutex_lock(&udev_mutex);
//
//      /* set up udev */
//      if (udev_refs == 0)
//      {
//         if (os_event_init(&udev_event, OS_EVENT_TYPE_MANUAL) != 0)
//            goto fail;
//         if (pthread_create(&udev_thread, NULL, udev_event_thread,
//                            NULL) != 0)
//            goto fail;
//
//         udev_signalhandler = signal_handler_create();
//         if (!udev_signalhandler)
//            goto fail;
//         signal_handler_add_array(udev_signalhandler, udev_signals);
//      }
//      udev_refs++;
//
//      signal_handler_t *sh = v4l2_get_udev_signalhandler();
//
//      signal_handler_connect(sh, "device_added", &s_device_added, data);
//      signal_handler_connect(sh, "device_removed", &s_device_removed, data);
//
//
//   fail:
//      pthread_mutex_unlock(&udev_mutex);
      }



      /**
    * Call all registered callbacks with the event
    *
    * @param dev udev device that had an event occuring
    */
      void device_group::__udev_signal_event(::udev_device * pudevdevice)
      {
         //const char *node;
         //enum udev_action action;
         //struct calldata data;

         _synchronous_lock synchronouslock(this->synchronization());

         //auto node = udev_device_get_devnode(dev);
         auto pszAction = udev_device_get_action(pudevdevice);
         //action = udev_action_to_enum(pszAction);

         if (!strncmp("add", pszAction, 3))
         {

            try
            {
               
               on_device_plugged();

            }
            catch(...)
            {
               
               warning() << "exception while processing on_device_plugged";

            }

         }
         else if (!strncmp("remove", pszAction, 6))
         {
      
            try
            {

               on_device_unplugged();

            }
            catch(...)
            {

               warning() << "exception while processing on_device_unplugged";
               
            }

         }


         // //calldata_init(&data);

         // //calldata_set_string(&data, "device", node);

         // try
         // {

         //    switch (action)
         //    {
         //       case UDEV_ACTION_ADDED:
         //       {

         //          on_device_plugged();

         //          // ::topic topic(id_video_input_device_added);

         //          // auto psystem = this->platform()->system();

         //          // psystem->route(&topic, nullptr);

         //       }
         //          break;
         //       case UDEV_ACTION_REMOVED:
         //       {

         //          on_device_unplugged();

         //          // ::topic topic(id_video_input_device_removed);

         //          // auto psystem = this->platform()->system();

         //          // psystem->route(&topic, nullptr);

         //       }
         //          break;
         //       default:
         //          break;
         //    }

         // }
         // catch(...)
         // {


         // }



//   calldata_free(&data);

         //pthread_mutex_unlock(&udev_mutex);
      }

//       void video_input::v4l2_unref_udev(void)
//    {
//       ;;pthread_mutex_lock(&udev_mutex);

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


   } // namespace aura_linux


} // namespace hardware


//signal_handler_t *v4l2_get_udev_signalhandler(void)
//{
//   return udev_signalhandler;
//}

