#include "framework.h"
#include "operating_system-posix/acme_posix/file_context.h"
#include "file_context.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "acme/operating_system/ansi/file_raw.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/platform/system.h"


struct PROCESS_INFO_t
{
   string csProcess;
   u32 dwImageListIndex;
};


namespace acme_linux
{


   file_context::file_context()
   {
   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::particle * pparticle)
   {

      //auto estatus =

         ::object::initialize(pparticle);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;


   }


   file_pointer file_context::get_file(const ::payload & varFile, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception)
   {

      return ::file_context::get_file(varFile, eopen, ppfileexception);

   }


   void file_context::init_system()
   {

   //auto estatus =

      ::file_context::init_system();

//   if(!estatus)
//   {
//
//   return estatus;
//
//   }
//
//      return estatus;

   }


   void file_context::init_context()
   {

      //auto estatus =

         ::file_context::init_context();

//   if(!estatus)
//   {
//
//   return estatus;
//
//   }
//
//      return estatus;

   }


//   bool file_context::is_link(string strPath)
//   {
//
//      return path_system()->is_link(strPath);
//
//   }


   ::file::path file_context::dropbox_info_network_payload()
   {

      ::file::path pathNetworkPayload;

      auto psystem = system();

      auto pacmedir = psystem->m_pacmedirectory;

      pathNetworkPayload = pacmedir->home() / ".dropbox/info.json";

      return pathNetworkPayload;

   }


   void file_context::erase(const ::file::path & path)
   {

      file_system()->erase(path);

   }


} // namespace acme_linux



