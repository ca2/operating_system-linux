#include "framework.h"
#include "operating-system-posix/apex_posix/file_context.h"
#include "file_context.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "acme/operating_system/ansi/file_raw.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/platform/system.h"


struct PROCESS_INFO_t
{
   string csProcess;
   u32 dwImageListIndex;
};


namespace apex_linux
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


   file_pointer file_context::get_file(const ::payload & varFile, const ::file::e_open & eopen)
   {

      return ::file_context::get_file(varFile, eopen);

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
//      return acmepath()->is_link(strPath);
//
//   }


   ::file::path file_context::dropbox_info_network_payload()
   {

      ::file::path pathNetworkPayload;

      auto psystem = acmesystem();

      auto pacmedir = psystem->m_pacmedirectory;

      pathNetworkPayload = pacmedir->home() / ".dropbox/info.json";

      return pathNetworkPayload;

   }


   void file_context::erase(const ::file::path & path)
   {

      acmefile()->erase(path);

   }


} // namespace apex_linux



