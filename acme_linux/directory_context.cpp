#include "framework.h"
#include "directory_context.h"
#include "directory_system.h"
#include "file_system.h"
#include "acme/constant/id.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/operating_system/shared_posix/c_error_number.h"
#include "acme/parallelization/task_flag.h"
#include "acme/prototype/string/international.h"
#include "acme/platform/system.h"
#undef USE_MISC

#if defined(RASPBERRYPIOS) || defined(LINUX)
#include <sys/types.h>
#include <unistd.h>
#endif


inline bool linux_dir_myspace(char ch)
{

   return ch == ' ' ||
          ch == '\t' ||
          ch == '\r' ||
          ch == '\n';

}


//::file::path xdg_get_dir(::matter * pmatter, const ::scoped_string & scopedstr)
//{
//
//   ::file::path pathHome;
//
//   pathHome = getenv("HOME");
//
//   ::file::path path;
//
//   path = pathHome / ".config/user-dirs.dirs";
//
//   auto straLines = pmatter->file_system()->lines(path);
//
//   string strPrefix = str + "=";
//
//   straLines.case_insensitive_filter_begins(strPrefix);
//
//   if(straLines.get_size() != 1)
//   {
//
//      return "";
//
//   }
//
//   path = straLines[0];
//
//   path.case_insensitive_begins_eat(strPrefix);
//
//   path.find_replace("$HOME", pathHome);
//
//   path.trim("\"");
//
//   return path;
//
//}


namespace acme_linux
{


   directory_context::directory_context()
   {


   }


   directory_context::~directory_context()
   {


   }


   void directory_context::initialize(::particle * pparticle)
   {

      //auto estatus =

         ::object::initialize(pparticle);

//      if (!estatus)
//      {
//
//         return estatus;
//
//      }

      auto psystem = system();

      m_pfilesystem = psystem->m_pfilesystem.get();

      m_pdirectorysystem = psystem->m_pdirectorysystem.get();

      //return ::success;

   }


   void directory_context::init_system()
   {

      ::acme_posix::directory_context::init_system();

//      if(!::directory_context::init_system())
//      {
//
//         return false;
//
//      }
//
//      auto pathCa2 = module();
//
//      pathCa2.go_up(3);
//
//      m_pdirectorysystem->m_pathCa2 = pathCa2;

//      auto pdocument = create_xml_document();
//
//      pdocument->load(file()->as_string(appdata() /"configuration\\directory.xml"));
//
//      if(pdocument->root() && pdocument->root()->get_name() == "directory_configuration")
//      {
//
//         m_pdirectorysystem->m_pathTimeFolder = pdocument->root()->get_child_value("time");
//
//         m_pdirectorysystem->m_pathNetSeedFolder = pdocument->root()->get_child_value("netseed");
//
//      }

#ifdef LINUX

      m_pdirectorysystem->m_pathTimeFolder = "/var/tmp/ca2/time";

#else

      if(m_pdirectorysystem->m_pathTimeFolder.is_empty())
      {

         m_pdirectorysystem->m_pathTimeFolder = appdata() / "time";

      }

#endif

      if(m_pdirectorysystem->m_pathNetSeedFolder.is_empty())
      {

         m_pdirectorysystem->m_pathNetSeedFolder = install() / "netd";

      }

      create(m_pdirectorysystem->m_pathTimeFolder);

      if(!is(m_pdirectorysystem->m_pathTimeFolder))
      {

         throw ::exception(error_failed);

      }

      create(m_pdirectorysystem->m_pathTimeFolder / "time");

      ::file::path pathHome = getenv("HOME");

      string pathInstall;

      pathInstall = install();

      auto iFind = pathInstall.find_index(':');

      if(iFind >= 0)
      {

         auto iFind1 = pathInstall.rear_find_index("\\");

         auto iFind2 = pathInstall.rear_find_index("/", iFind);

         auto iStart = maximum(iFind1 + 1, iFind2 + 1);

         pathInstall = pathInstall.left(iFind - 1) + "_" + pathInstall.substr(iStart, iFind - iStart) + pathInstall.substr(iFind + 1);

      }

      //return true;

   }


   void directory_context::init_context()
   {

      //auto estatus =

         ::acme_posix::directory_context::init_context();

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;

   }


   ::file::listing & directory_context::root_ones(::file::listing & listing)
   {

      ::file::path path;

      path = "/";

      path.set_existent_folder();

      listing.defer_add(path);

      listing.m_straTitle.add("Filesystem");

      return listing;

   }


   bool directory_context::enumerate(::file::listing & listing)
   {

      if(::directory_context::enumerate(listing))
      {

         return true;

      }

//      if(listing.m_bRecursive)
//      {
//
//         index iStart = listing.get_count();
//
//         {
//
//            scoped_restore(listing.m_pathUser);
//
//            scoped_restore(listing.m_pathFinal);
//
//            scoped_restore(listing.m_eextract);
//
//            ::file::listing straDir;
//
//            ls_dir(straDir, listing.m_pathFinal);
//
//            for(int i = 0; i < straDir.get_count(); i++)
//            {
//
//               string strDir = straDir[i];
//
//               if(strDir == listing.m_pathFinal)
//               {
//
//                  continue;
//
//               }
//
//               if(listing.m_bDir)
//               {
//
//                  ::file::path & path = listing.add_get(::file::path(strDir));
//
//                  path.m_iSize = 0;
//
//                  path.m_iDir = 1;
//
//               }
//
//               get_app()->directory()->ls(listing, strDir);
//
//            }
//
//         }
//
//         if(listing.m_bFile)
//         {
//
//            scoped_restore(listing.m_bRecursive);
//
//            listing.m_bRecursive = false;
//
//            get_app()->directory()->ls_file(listing, listing.m_pathFinal);
//
//         }
//
//         for(::collection::index i = iStart; i < listing.get_size(); i++)
//         {
//
//            listing[i].m_iRelative = listing.m_pathFinal.get_length() + 1;
//
//         }
//
//      }
//      else
//      {

         //::file::path_array stra;

         directory_system()->enumerate(listing);

//         for(int i = 0; i < stra.get_count(); i++)
//         {
//
//            auto & strPath = stra[i];
//
//            if(!string_begins(strPath, listing.m_pathFinal))
//               continue;
//
//            bool bIsDir;
//
//            if(strPath.m_iDir >= 0)
//            {
//
//               bIsDir = strPath.m_iDir != 0;
//
//            }
//            else
//            {
//
//               bIsDir = ::directory_context::is(strPath);
//
//            }
//
//            if((bIsDir && !listing.m_bDir) || (!bIsDir && !listing.m_bFile))
//               continue;
//
//            if(!bIsDir && !matches_wildcard_criteria(listing.m_straPattern, strPath.name()))
//               continue;
//
//            ::file::path & path = listing.add_get(strPath);
//
//            path.m_iDir = bIsDir ? 1 : 0;
//
//            if(bIsDir)
//            {
//
//               path.m_iSize = 0;
//
//            }
//            else
//            {
//
//               path.m_iSize = file_system()->get_size(strPath);
//
//            }
//
//         }
//
//      }
//
//      //return listing;

      return true;

   }


//   ::file::e_type directory_context::file_type(const ::file::path & path)
//   {
//
//      auto etype = directory_system()->file_type(path);
//
//      if(etype != ::file::e_type_unknown)
//      {
//
//         return etype;
//
//      }
//
//      bool bIsDir = false;
//
//      if(!directory_system()->_is(bIsDir, path))
//      {
//
//         return false;
//
//      }
//
//      return bIsDir;
//
//   }


   bool directory_context::name_is(const ::file::path & str)
   {
      //information(str);
      character_count iLast = str.length() - 1;
      while(iLast >= 0)
      {
         if(str[iLast] != '\\' && str[iLast] != '/' && str[iLast] != ':')
            break;
         iLast--;
      }
      while(iLast >= 0)
      {
         if(str[iLast] == '\\' || str[iLast] == '/' || str[iLast] == ':')
            break;
         iLast--;
      }
      if(iLast >= 0)
      {
         while(iLast >= 0)
         {
            if(str[iLast] != '\\' && str[iLast] != '/' && str[iLast] != ':')
            {
               iLast++;
               break;
            }
            iLast--;
         }
      }
      else
      {
         return true; // assume empty string is root_ones directory
      }

      if(task_flag().is_set(e_task_flag_compress_is_dir) && iLast >= 3  && !case_insensitive_ansi_count_compare(&((const_char_pointer )str)[iLast - 3], ".zip", 4))
      {

         return true;

      }

      ::string strDir(str.begin(), iLast + 1);

      bool bIsDir = ::directory_context::is(strDir);

      return bIsDir;

   }


   ::file::path directory_context::time()
   {

      return m_pdirectorysystem->m_pathTimeFolder;

   }


   ::file::path directory_context::element_commonappdata(const ::scoped_string & scopedstrElement)
   {

      return ::file::path(scopedstrElement) / "commonappdata";

   }


   ::file::path directory_context::stage()
   {

      return install() / "stage";

   }


   ::file::path directory_context::stageapp()
   {

      return stage() / "basis";

   }


   ::file::path directory_context::netseed()
   {

      return m_pdirectorysystem->m_pathNetSeedFolder;

   }


   ::file::path directory_context::time_square()
   {

      return time() / "time";

   }


   ::file::path directory_context::time_log(const ::scoped_string & scopedstrId)
   {

      ::file::path strLogBaseDir;

      strLogBaseDir = appdata() / "log";

      return strLogBaseDir / scopedstrId;

   }


   void directory_context::create(const ::file::path & path)
   {

      directory_system()->create(path);

   }


   void directory_context::erase(const ::file::path & path, bool bRecursive)
   {

      if(bRecursive)
      {

         ::file::listing listing;

         listing.set_listing(path, e_depth_recursively);

         enumerate(listing);

         for(auto & pathItem : listing)
         {

            if(is(pathItem))
            {

               erase(pathItem, true);

            }
            else
            {

               ::unlink(pathItem);

            }

         }

      }

      if(::rmdir(path) < 0)
      {

         auto cerrornumber = c_error_number();

         auto estatus = cerrornumber.failed_estatus();

         throw ::exception(estatus);

      }

   }


   ::file::path directory_context::trash_that_is_not_trash(const ::file::path & path)
   {

      if(path[1] == ':')
      {

         string strDir = path.name();
         string str;
         str = strDir.left(2);
         str += "\\trash_that_is_not_trash\\";
         string strFormat;
         ::earth::time time;
         time = ::earth::time::now();
         strFormat.formatf("%04d-%02d-%02d %02d-%02d-%02d\\", time.year(), time.month(), time.day(), time.hour(), time.minute(), time.second());
         str += strFormat;
         if(strDir[2] == '\\')
         {
            str += strDir.substr(3);
         }
         else
         {
            str += strDir.substr(2);
         }
         return str;
      }

      return "";

   }


//   ::file::path directory_context::appdata()
//   {
//
//      return ::directory_context::appdata();
//
//   }


   ::file::path directory_context::commonappdata()
   {

      ::file::path path;

      path = ::file::path(getenv("HOME")) / ".config/ca2/commonappdata";

      string strRelative;

      strRelative = install();

      return path / "ca2" / strRelative;

   }


   ::file::path directory_context::userquicklaunch(::particle * pparticle)
   {

      ::file::path path;

      path = ::file::path(getenv("HOME")) / "Microsoft\\Internet Explorer\\Quick Launch";

      return path;

   }


   ::file::path directory_context::userprograms(::particle * pparticle)
   {

      ::file::path path;

      path = "/usr/bin";

      return path;

   }


   ::file::path directory_context::commonprograms()
   {

      ::file::path path;

      path = "/usr/share/";

      return path;

   }


   bool directory_context::is_inside_time(const ::file::path & path)
   {

      return is_inside(time(), path);

   }


   bool directory_context::is_inside(const ::file::path & pathFolder, const ::file::path & path)
   {

      return path.case_insensitive_begins(pathFolder);

   }


   bool directory_context::has_subdir(const ::file::path & path)
   {

      ::file::listing listing;

      listing.set_folder_listing(path);

      enumerate(listing);

      return listing.get_size() > 0;

   }


//   ::file::path directory_context::music()
//   {
//
//      if(m_pathMusic.has_character())
//      {
//
//         return m_pathMusic;
//
//      }
//
//      ::file::path path = xdg_get_dir(this, "XDG_MUSIC_DIR");
//
//      if(path.has_character())
//      {
//
//         m_pathMusic = path;
//
//         return path;
//
//      }
//
//      path = getenv("HOME");
//
//      path /= "Music";
//
//      m_pathMusic = path;
//
//      return path;
//
//   }
//
//
//   ::file::path directory_context::video()
//   {
//
//      if(m_pathVideo.has_character())
//      {
//
//         return m_pathVideo;
//
//      }
//
//      ::file::path path = xdg_get_dir(this, "XDG_VIDEOS_DIR");
//
//      if(path.has_character())
//      {
//
//         m_pathVideo = path;
//
//         return path;
//
//      }
//
//      path = getenv("HOME");
//
//      path /= "Videos";
//
//      m_pathVideo = path;
//
//      return path;
//
//   }
//
//
//   ::file::path directory_context::image::image()
//   {
//
//      if(m_pathImage.has_character())
//      {
//
//         return m_pathImage;
//
//      }
//
//      ::file::path path = xdg_get_dir(this, "XDG_PICTURES_DIR");
//
//      if(path.has_character())
//      {
//
//         m_pathImage = path;
//
//         return path;
//
//      }
//
//      path = getenv("HOME");
//
//      path /= "Pictures";
//
//      m_pathImage = path;
//
//      return path;
//
//   }
//
//
//   ::file::path directory_context::document()
//   {
//
//      if(m_pathDocument)
//      {
//
//         return m_pathDocument;
//
//      }
//
//      ::file::path path = xdg_get_dir(this, "XDG_DOCUMENTS_DIR");
//
//      if(path.has_character())
//      {
//
//         m_pathDocument = path;
//
//         return path;
//
//      }
//
//      path = getenv("HOME");
//
//      path /= "Documents";
//
//      m_pathDocument = path;
//
//      return path;
//
//   }
//
//
//   ::file::path directory_context::download()
//   {
//
//      if(m_pathDownload.has_character())
//      {
//
//         return m_pathDownload;
//
//      }
//
//      ::file::path path = xdg_get_dir(this, "XDG_DOWNLOAD_DIR");
//
//      if(path.has_character())
//      {
//
//         m_pathDownload = path;
//
//         return path;
//
//      }
//
//      path = getenv("HOME");
//
//      path /= "Downloads";
//
//      m_pathDownload = path;
//
//      return path;
//
//   }


} // namespace acme_linux



