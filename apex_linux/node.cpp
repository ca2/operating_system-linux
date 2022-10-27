#include "framework.h"
//#include "node/platform/node.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_path.h"
//#include "acme_linux/acme.h"
#include "node.h"
////#include "aura/operating_system/linux/_.h"


bool __node_node_pre_init();
bool __node_node_pos_init();


namespace apex_linux
{


   node::node()
   {

      m_pApexPlatform = this;

   }


   node::~node()
   {


   }


   string node::get_user_name()
   {

//      WCHAR wsz[1024];
//
//      DWORD dwSize = sizeof(wsz) / sizeof(WCHAR);
//
//      ::GetUserNameW(wsz, &dwSize);
//
//      return string(wsz);

      return "";

   }


   void node::initialize(::particle * pparticle)
   {

      //auto estatus =

      ::acme_linux::node::initialize(pparticle);

//         if (!estatus)
//         {
//
//            return estatus;
//
//         }

//         if (!__node_node_pre_init())
//         {
//
//            return error_failed;
//
//         }


//         if (!__node_node_pos_init())
//         {
//
//            return error_failed;
//
//         }

      //return estatus;

   }


   void node::_001InitializeShellOpen()
   {

      //ASSERT(m_atomApp == nullptr && m_atomSystemTopic == nullptr); // do once

      //m_atomApp            = ::GlobalAddAtomW(utf8_to_unicode(m_strAppName));

      //m_atomSystemTopic    = ::GlobalAddAtomW(L"system");

      //return ::success;

   }


//      void node::file_open(const ::file::path & path, const ::string& strParams, const ::file::path & pathFolder)
//      {
//
//         ::apex::node::file_open(path, strParams, pathFolder);
//
//      }


   ::e_status node::process_init()
   {

      //defer_initialize_winsock();
      return success;

   }


   int node::node_init_check(int*, char***)
   {

      return ::success;

   }


} // namespace apex_linux



