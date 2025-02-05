//
// Created by camilo on 2024-02-04 23:03 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "node.h"

#include  "acme/operating_system/ansi/binreloc.h"

#include <unistd.h>


namespace acme_linux
{


   ::file::path node::_module_path()
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




