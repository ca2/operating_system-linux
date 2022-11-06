// Create on 2021-03-22 09:12 <3ThomasBS_
#include "framework.h"
#include "acme_file.h"


#include "acme/operating_system/ansi/binreloc.h"


namespace acme_linux
{

   
   acme_file::acme_file()
   {

      m_pplatformfile = this;

   }


   acme_file::~acme_file()
   {


   }


   ::file::path acme_file::module()
   {

      ::file::path path;

      char * pszModule = nullptr;

      if((pszModule = br_find_exe(nullptr)) == nullptr)
      {

         if (!br_init_lib(nullptr))
         {

            char path[PATH_MAX * 4];

            char dest[PATH_MAX * 4];

            pid_t pid = getpid();

            sprintf(path, "/proc/%d/exe", pid);

            auto iSize = readlink(path, dest, PATH_MAX);

            if (iSize > 0)
            {

               dest[iSize] = '\0';

               pszModule = strdup(dest);


            }

         }

      }

      path = pszModule;

      ::free(pszModule);

      return path;

   }


} // namespace acme_linux



