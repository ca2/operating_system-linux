#include "framework.h"
#include "file.h"
#include "directory_system.h"
#include "acme/exception/dump_context.h"
#include "acme/exception/io.h"
#include "acme/filesystem/file/exception.h"
#include "acme/filesystem/file/status.h"
#include "acme/platform/debug.h"

//
//#include <fcntl.h>
//#undef USE_MISC
//#include <unistd.h>
//
//
//#include <link.h>
//
//
//#include <ctype.h>
//#include <sys/stat.h>
//
////#elif defined(MACOS)
////#include <dlfcn.h>
////#endif
//
///*__STATIC inline bool IsDirSep(WCHAR ch)
//{
//
//   return (ch == '\\' || ch == '/');
//
//}*/
//
//
//namespace acme_linux
//{
//
//
//   file::file()
//   {
//
//      //m_iPutCharacter = -1;
//      m_iFile = INVALID_FILE;
//
//   }
//
//
////   file::file(::particle * pparticle, int iFile) :
////      ::matter(pparticle)
////   {
////
////      m_iFile = iFile;
////
////   }
////
////
////   file::file(::particle * pparticle, const ::file::path & pathFileName, const enumeration < ::file::e_open > & eopen) :
////      ::matter(pparticle)
////   {
////
////      m_iFile = INVALID_FILE;
////
////      if(!open(scopedstrFileName, eopen))
////      {
////
////         __throw(::file::exception(::error_file, -1, pszFileName));
////
////      }
////
////
////   }
//
//
//   file::~file()
//   {
//
//      if (m_iFile != INVALID_FILE)
//         close();
//
//   }
//
////   ::pointer<::file::file>file::Duplicate() const
////
////   {
////
////      int iNew = dup(m_iFile);
////
////      if(iNew == INVALID_FILE)
////         return nullptr;
////
////      auto pFile  = __allocate file(get_app(), iNew);
////      pFile->m_iFile = (unsigned int)iNew;
////      ASSERT(pFile->m_iFile != INVALID_FILE);
////      return pFile;
////
////   }
////
//
//   void file::open(const ::file::path & pathFileName, ::file::e_open eopen, ::pointer < ::file::exception> * ppfileexception)
//   {
//
//      if (m_iFile != INVALID_FILE)
//      {
//
//         close();
//
//      }
//
//      ASSERT(is_string_ok(scopedstrFileName));
//
//      // file objects are always binary and CreateFile does not need flag
//      eopen -= ::file::e_open_binary;
//
//      if ((eopen & ::file::e_open_defer_create_directory) && (eopen & ::file::e_open_write))
//      {
//
//         directory_system()->create(scopedstrFileName.folder());
//
//      }
//
//      m_iFile = INVALID_FILE;
//      m_path.empty();
//
//      m_path     = pszFileName;
//
//
//      //ASSERT(sizeof(HANDLE) == sizeof(uptr));
//      ASSERT(::file::e_open_share_compat == 0);
//
//      // ::collection::map read/write mode
//      ASSERT((::file::e_open_read|::file::e_open_write|::file::e_open_read_write) == 3);
//      unsigned int dwFlags =  0;
//      switch (eopen & ::file::e_open_read_write)
//      {
//      case ::file::e_open_read:
//         dwFlags |=  O_RDONLY;
//         break;
//      case ::file::e_open_write:
//         dwFlags |=  O_WRONLY ;
//         break;
//      case ::file::e_open_read_write:
//         dwFlags |=  O_RDWR;
//         break;
//      default:
//         dwFlags |=  O_RDONLY;
//         break;
//      }
//
//      // ::collection::map share mode
//      unsigned int dwShareMode = 0;
//      switch (eopen & ::file::e_open_share_mask)    // ::collection::map compatibility mode to exclusive
//      {
//      default:
//         ASSERT(false);  // invalid share mode?
//      case ::file::e_open_share_compat:
//      case ::file::e_open_share_exclusive:
//         //dwShareMode = 0;
//         break;
//      case ::file::e_open_share_deny_write:
//         //dwFlags |= O_SHLOCK;
//         break;
//      case ::file::e_open_share_deny_read:
////         dwFlags |= O_EXLOCK;
//         break;
//      case ::file::e_open_share_deny_none:
//         //dwFlags = FILE_SHARE_WRITE|FILE_SHARE_READ;
//         break;
//      }
//
//      if(eopen & ::file::e_open_create)
//      {
//         dwFlags |= O_CREAT;
//         if(!(eopen & ::file::e_open_no_truncate))
//            dwFlags |= O_TRUNC;
//      }
//      else if(eopen & ::file::e_open_truncate)
//      {
//         dwFlags |= O_TRUNC;
//      }
//
//      unsigned int dwPermission = 0;
//
//      dwPermission |= S_IRUSR | S_IWUSR | S_IXUSR;
//      dwPermission |= S_IRGRP | S_IWGRP | S_IXGRP;
//      dwPermission |= S_IROTH | S_IROTH;
//
//      //auto path = path_system()->final(m_path);
//
//      if(eopen & ::file::e_open_file)
//      {
//
//         if(directory_system()->is(m_path))
//         {
//
//            if(eopen & ::file::e_open_no_exception_on_open)
//            {
//
//               m_estatus = error_not_a_file;
//
//               return;
//
//            }
//            else
//            {
//
//               throw ::exception(error_not_a_file);
//
//            }
//
//         }
//
//      }
//
//      // attempt file creation
//      //HANDLE hFile = shell::CreateFile(utf8_to_unicode(m_path), dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);
//      int iFile = ::open(m_path, dwFlags, dwPermission); //::open(m_path, dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);
//
//      if(iFile == INVALID_FILE)
//      {
//
//         int iError = errno;
//
//         auto estatus = failed_errno_status(iError);
//
//         m_estatus = estatus;
//
//         set_nok();
//
//         if(eopen & ::file::e_open_no_exception_on_open)
//         {
//
//            m_estatus = estatus;
//
//            return;
//
//         }
//         else
//         {
//
//            throw ::exception(estatus);
//
//         }
//
//         //return //::fesp(get_app(), file_exception::os_error_to_exception(dwLastError), dwLastError, m_path);
//
//      }
//
//      //::lseek64(m_iFile, 0, SEEK_SET);
//
//      m_iFile = iFile;
//
//      m_eopen = eopen;
//
//      m_estatus = success;
//
//      set_ok_flag();
//
//   }
//
//
//   memsize file::read(void * pdata, memsize nCount)
//   {
//
//      if(m_iFile < 0)
//      {
//
//         throw io_exception(error_wrong_state);
//
//      }
//
//      if (nCount == 0)
//      {
//
//         return 0;   // avoid Win32 "null-read"
//
//      }
//
//      ASSERT(pdata != nullptr);
//
//      ASSERT(is_memory_segment_ok(pdata, nCount));
//
////      if(m_iPutCharacter >= 0)
////      {
////
////         auto p = (unsigned char *) pdata;
////
////         *p = (unsigned char) m_iPutCharacter;
////
////         m_iPutCharacter = -1;
////
////         nCount--;
////
////         if(nCount <= 0)
////         {
////
////            return 1;
////
////         }
////
////         p++;
////
////         pdata = p;
////
////      }
//
//      memsize pos = 0;
//      memsize sizeRead = 0;
//      memsize readNow;
//      while(nCount > 0)
//      {
//         readNow = (size_t) minimum(I32_MAXIMUM, nCount);
//         int iRead = ::read(m_iFile, &((unsigned char *)pdata)[pos], readNow);
//
//         if(iRead < 0)
//         {
//            int iErrNo = errno;
//            if(iErrNo == EAGAIN)
//            {
//
//            }
//            throw ::file::exception(error_io, errno_error_code(iErrNo), m_path, "read < 0");
//         }
//         else if(iRead == 0)
//         {
//            break;
//         }
//
//         nCount -= iRead;
//         pos += iRead;
//         sizeRead += iRead;
//      }
//
//      return sizeRead;
//   }
//
//
//   void file::write(const void * pdata, memsize nCount)
//   {
//
//      ASSERT(m_iFile != INVALID_FILE);
//
//      if (nCount == 0)
//      {
//
//         return;     // avoid Win32 "null-write" option
//
//      }
//
//      ASSERT(pdata != nullptr);
//
//      ASSERT(is_memory_segment_ok(pdata, nCount, false));
//
//      memsize pos = 0;
//
//      while(nCount > 0)
//      {
//
//         auto bytesToWrite = minimum(I32_MAXIMUM, nCount);
//
//         auto pdataToWrite = ((const unsigned char *)pdata) + pos;
//
//         int iWrite = ::write(m_iFile, pdataToWrite, bytesToWrite);
//
//         if(iWrite < 0)
//         {
//
//            auto cerrornumber = c_error_number();
//
//            auto estatus = errno_status(iErrNo);
//
//            auto errorcode = cerrornumber.error_code();
//
//            throw ::file::exception(estatus, errorcode, m_path, "write < 0", m_eopen);
//
//         }
//
//         nCount -= iWrite;
//
//         pos += iWrite;
//
//      }
//
//      // Win32s will not return an error all the time (usually DISK_FULL)
//      //if (iWrite != nCount)
//      //vfxThrowFileexception(::file::exception::diskFull, -1, m_path);
//   }
//
//
//   void file::translate(::filesize offset, ::enum_seek eseek)
//   {
//
//      if(m_iFile == INVALID_FILE)
//      {
//
//         auto cerrornumber = c_error_number();
//
//         auto estatus = errno_status(iErrNo);
//
//         auto errorcode = cerrornumber.error_code();
//
//         throw ::file::exception(estatus, errorcode, m_path, "m_iFile == INVALID_FILE", m_eopen);
//
//      }
//
//
//      ASSERT(m_iFile != INVALID_FILE);
//      ASSERT(eseek == ::e_seek_set || eseek == ::e_seek_from_end || eseek == ::e_seek_current);
//      ASSERT(::e_seek_set == SEEK_SET && ::e_seek_from_end == SEEK_END && ::e_seek_current == SEEK_CUR);
//
//      //int lLoOffset = offset & 0xffffffff;
//      //int lHiOffset = (lOff >> 32) & 0xffffffff;
//
//      //0	SEEK_SET
//      //1	SEEK_CUR
//      //2	SEEK_END
//
//      int iSeek = (int) eseek;
//
//
//      //auto posNew = ::lseek(m_iFile, offset, iSeek);
//      long int i = lseek(m_iFile, offset, iSeek);
////      posNew |= ((filesize) lHiOffset) << 32;
//      if(i < 0)
//      {
//
//         auto cerrornumber = c_error_number();
//
//         auto estatus = errno_status(iErrNo);
//
//         auto errorcode = cerrornumber.error_code();
//
//         throw ::file::exception(estatus, errorcode, m_path, "lseek64 < 0", m_eopen);
//
//      }
//
//      //return i;
//
//   }
//
//
//   filesize file::get_position() const
//   {
//
//      ASSERT(m_iFile != INVALID_FILE);
//
//      int lLoOffset = 0;
////      int lHiOffset = 0;
//
//      filesize pos = ::lseek64(m_iFile, lLoOffset, SEEK_CUR);
//      //    pos |= ((filesize)lHiOffset) << 32;
//      if(pos < 0)
//      {
//
//         auto cerrornumber = c_error_number();
//
//         auto estatus = errno_status(iErrNo);
//
//         auto errorcode = cerrornumber.error_code();
//
//         throw ::file::exception(estatus, errorcode, m_path, "lseek64 < 0", m_eopen);
//
//      }
//
//      return pos;
//   }
//
//
//   void file::flush()
//   {
//
//      if (m_iFile == INVALID_FILE)
//      {
//
//         return;
//
//      }
//
//      auto iRet = ::fsync(m_iFile);
//
//      if(iRet < 0)
//      {
//
//         int iErrNo = errno;
//
//         auto estatus = errno_status(iErrNo);
//
//         auto errorcode = cerrornumber.error_code();
//
//         throw ::file::exception(estatus, errorcode, m_path, "fsync < 0", m_eopen);
//
//      }
//
//      /*      ::open
//            ::read
//            ::write
//
//            access the system directly no buffering : direct I/O - efficient for large writes - innefficient for lots of single unsigned char writes
//
//            */
//
////      if (m_iFile == INVALID_FILE)
////         return;
////
////      if (!::FlushFileBuffers((HANDLE)m_iFile))
////         throw ::file::exception(errno_status(errno), -1, errno, m_path);
//   }
//
//   void file::close()
//   {
//
//      bool bError = false;
//
//      if (m_iFile != INVALID_FILE)
//         bError = ::close(m_iFile) != 0;
//
//      m_iFile = INVALID_FILE;
//
//      m_path.empty();
//
//      if (bError)
//      {
//
//         auto cerrornumber = c_error_number();
//
//         auto estatus = errno_status(iErrNo);
//
//         auto errorcode = cerrornumber.error_code();
//
//         throw ::file::exception(estatus, errorcode, m_path, "close != 0", m_eopen);
//
//      }
//
//   }
//
//
//   void file::Abort()
//   {
//
//      if (m_iFile != INVALID_FILE)
//      {
//
//         ::close(m_iFile);
//
//         m_iFile = INVALID_FILE;
//
//      }
//
//      m_path.empty();
//
//   }
//
//
//   void file::LockRange(filesize dwPos, filesize dwCount)
//   {
//
//      ASSERT(m_iFile != INVALID_FILE);
//
//   }
//
//
//   void file::UnlockRange(filesize dwPos, filesize dwCount)
//   {
//
//      ASSERT(m_iFile != INVALID_FILE);
//
//   }
//
//
//   void file::set_size(filesize dwNewLen)
//   {
//
//      ASSERT(m_iFile != INVALID_FILE);
//
//      set_position(dwNewLen);
//
//      if (::ftruncate64(m_iFile, dwNewLen) == -1)
//      {
//
//         auto cerrornumber = c_error_number();
//
//         auto estatus = errno_status(iErrNo);
//
//         auto errorcode = cerrornumber.error_code();
//
//         throw ::file::exception(estatus, errorcode, m_path, "ftruncate64 == -1", m_eopen);
//
//      }
//
//   }
//
//
//   filesize file::size() const
//   {
//
//      filesize length, current;
//
//      // seek is a non const operation
//      file* pFile = (file*)this;
//      current = pFile->get_position();
//      pFile->seek_to_end();
//      length = pFile->get_position();
//      pFile->set_position(current);
//      VERIFY(current == pFile->get_position());
//
//      return (filesize) length;
//
//   }
//
//
//   // file does not support direct buffering (CMemFile does)
//   unsigned long long file::GetBufferPtr(unsigned int /*nCommand*/, unsigned long long /*nCount*/, void ** /*ppBufStart*/, void ** /*ppBufMax*/)
//   {
//
//      //ASSERT(nCommand == bufferCheck);
//
//      //UNUSED(nCommand);    // not used in retail build
//
//      return 0;   // no support
//
//   }
//
//
////   void file::assert_ok() const
////   {
////
////      ::file::file::assert_ok();
////
////   }
////
////
////   void file::dump(dump_context & dumpcontext) const
////   {
////
////      ::file::file::dump(dumpcontext);
////
//////      dumpcontext << "with handle " << (unsigned int)m_iFile;
//////      dumpcontext << " and name \"" << m_path << "\"";
//////      dumpcontext << "\n";
////
////   }
//
//
//
//   string file::GetFileName() const
//   {
//
//      ::file::file_status status;
//
//      GetStatus(status);
//
//      return status.m_strFullName.name();
//
//   }
//
//
//   string file::GetFileTitle() const
//   {
//
//
//
//      ::file::file_status status;
//
//      GetStatus(status);
//
//      return status.m_strFullName.title();
//
//   }
//
//
//   string file::GetFilePath() const
//   {
//
//
//      ::file::file_status status;
//      GetStatus(status);
//      return status.m_strFullName;
//   }
//
//
//
//
//   /////////////////////////////////////////////////////////////////////////////
//   // FileException
//
//
//
//
////   void PASCAL file_exception::throw_os_error(int lOsError, const char * pszFileName /* = nullptr */)
//
////   {
////      if (lOsError != 0)
////         ::file::throw_os_error(file_exception::os_error_to_exception(lOsError), lOsError, pszFileName);
//
////   }
//
////   void PASCAL file_exception::ThrowErrno(int nErrno, const char * pszFileName /* = nullptr */)
//
////   {
////      if (nErrno != 0)
////         vfxThrowFileexception(file_exception::errno_status(nErrno), errno, pszFileName);
//
////   }
//
//
//
////   ::e_status PASCAL file_exception::os_error_to_exception(int lOsErr)
////   {
////      // NT Error codes
////      switch ((unsigned int)lOsErr)
////      {
////      case NO_ERROR:
////         return ::file::exception::undefined;
////      case ERROR_FILE_NOT_FOUND:
////         return ::file::exception::fileNotFound;
////      case ERROR_PATH_NOT_FOUND:
////         return ::file::exception::badPath;
////      case ERROR_TOO_MANY_OPEN_FILES:
////         return ::file::exception::tooManyOpenFiles;
////      case ERROR_ACCESS_DENIED:
////         return ::file::exception::accessDenied;
////      case ERROR_INVALID_HANDLE:
////         return ::file::exception::fileNotFound;
////      case ERROR_BAD_FORMAT:
////         return ::file::exception::invalidFile;
////      case ERROR_INVALID_ACCESS:
////         return ::file::exception::accessDenied;
////      case ERROR_INVALID_DRIVE:
////         return ::file::exception::badPath;
////      case ERROR_CURRENT_DIRECTORY:
////         return ::file::exception::eraseCurrentDir;
////      case ERROR_NOT_SAME_DEVICE:
////         return ::file::exception::badPath;
////      case ERROR_NO_MORE_FILES:
////         return ::file::exception::fileNotFound;
////      case ERROR_WRITE_PROTECT:
////         return ::file::exception::accessDenied;
////      case ERROR_BAD_UNIT:
////         return ::file::exception::hardIO;
////      case ERROR_NOT_READY:
////         return ::file::exception::hardIO;
////      case ERROR_BAD_COMMAND:
////         return ::file::exception::hardIO;
////      case ERROR_CRC:
////         return ::file::exception::hardIO;
////      case ERROR_BAD_LENGTH:
////         return ::file::exception::badSeek;
////      case ERROR_SEEK:
////         return ::file::exception::badSeek;
////      case ERROR_NOT_DOS_DISK:
////         return ::file::exception::invalidFile;
////      case ERROR_SECTOR_NOT_FOUND:
////         return ::file::exception::badSeek;
////      case ERROR_WRITE_FAULT:
////         return ::file::exception::accessDenied;
////      case ERROR_READ_FAULT:
////         return ::file::exception::badSeek;
////      case ERROR_SHARING_VIOLATION:
////         return ::file::exception::sharingViolation;
////      case ERROR_LOCK_VIOLATION:
////         return ::file::exception::lockViolation;
////      case ERROR_WRONG_DISK:
////         return ::file::exception::badPath;
////      case ERROR_SHARING_BUFFER_EXCEEDED:
////         return ::file::exception::tooManyOpenFiles;
////      case ERROR_HANDLE_EOF:
////         return ::file::exception::endOfFile;
////      case ERROR_HANDLE_DISK_FULL:
////         return ::file::exception::diskFull;
////      case ERROR_DUP_NAME:
////         return ::file::exception::badPath;
////      case ERROR_BAD_NETPATH:
////         return ::file::exception::badPath;
////      case ERROR_NETWORK_BUSY:
////         return ::file::exception::accessDenied;
////      case ERROR_DEV_NOT_EXIST:
////         return ::file::exception::badPath;
////      case ERROR_ADAP_HDW_ERR:
////         return ::file::exception::hardIO;
////      case ERROR_BAD_NET_RESP:
////         return ::file::exception::accessDenied;
////      case ERROR_UNEXP_NET_ERR:
////         return ::file::exception::hardIO;
////      case ERROR_BAD_REM_ADAP:
////         return ::file::exception::invalidFile;
////      case ERROR_NO_SPOOL_SPACE:
////         return ::file::exception::directoryFull;
////      case ERROR_NETNAME_DELETED:
////         return ::file::exception::accessDenied;
////      case ERROR_NETWORK_ACCESS_DENIED:
////         return ::file::exception::accessDenied;
////      case ERROR_BAD_DEV_TYPE:
////         return ::file::exception::invalidFile;
////      case ERROR_BAD_NET_NAME:
////         return ::file::exception::badPath;
////      case ERROR_TOO_MANY_NAMES:
////         return ::file::exception::tooManyOpenFiles;
////      case ERROR_SHARING_PAUSED:
////         return ::file::exception::badPath;
////      case ERROR_REQ_NOT_ACCEP:
////         return ::file::exception::accessDenied;
////      case ERROR_FILE_EXISTS:
////         return ::file::exception::accessDenied;
////      case ERROR_CANNOT_MAKE:
////         return ::file::exception::accessDenied;
////      case ERROR_ALREADY_ASSIGNED:
////         return ::file::exception::badPath;
////      case ERROR_INVALID_PASSWORD:
////         return ::file::exception::accessDenied;
////      case ERROR_NET_WRITE_FAULT:
////         return ::file::exception::hardIO;
////      case ERROR_DISK_CHANGE:
////         return ::file::exception::fileNotFound;
////      case ERROR_DRIVE_LOCKED:
////         return ::file::exception::lockViolation;
////      case ERROR_BUFFER_OVERFLOW:
////         return ::file::exception::badPath;
////      case ERROR_DISK_FULL:
////         return ::file::exception::diskFull;
////      case ERROR_NO_MORE_SEARCH_HANDLES:
////         return ::file::exception::tooManyOpenFiles;
////      case ERROR_INVALID_TARGET_HANDLE:
////         return ::file::exception::invalidFile;
////      case ERROR_INVALID_CATEGORY:
////         return ::file::exception::hardIO;
////      case ERROR_INVALID_NAME:
////         return ::file::exception::badPath;
////      case ERROR_INVALID_LEVEL:
////         return ::file::exception::badPath;
////      case ERROR_NO_VOLUME_LABEL:
////         return ::file::exception::badPath;
////      case ERROR_NEGATIVE_SEEK:
////         return ::file::exception::badSeek;
////      case ERROR_SEEK_ON_DEVICE:
////         return ::file::exception::badSeek;
////      case ERROR_DIR_NOT_ROOT:
////         return ::file::exception::badPath;
////      case ERROR_DIR_NOT_EMPTY:
////         return ::file::exception::eraseCurrentDir;
////      case ERROR_LABEL_TOO_LONG:
////         return ::file::exception::badPath;
////      case ERROR_BAD_PATHNAME:
////         return ::file::exception::badPath;
////      case ERROR_LOCK_FAILED:
////         return ::file::exception::lockViolation;
////      case ERROR_BUSY:
////         return ::file::exception::accessDenied;
////      case ERROR_INVALID_ORDINAL:
////         return ::file::exception::invalidFile;
////      case ERROR_ALREADY_EXISTS:
////         return ::file::exception::accessDenied;
////      case ERROR_INVALID_EXE_SIGNATURE:
////         return ::file::exception::invalidFile;
////      case ERROR_BAD_EXE_FORMAT:
////         return ::file::exception::invalidFile;
////      case ERROR_FILENAME_EXCED_RANGE:
////         return ::file::exception::badPath;
////      case ERROR_META_EXPANSION_TOO_LONG:
////         return ::file::exception::badPath;
////      case ERROR_DIRECTORY:
////         return ::file::exception::badPath;
////      case ERROR_OPERATION_ABORTED:
////         return ::file::exception::hardIO;
////      case ERROR_IO_INCOMPLETE:
////         return ::file::exception::hardIO;
////      case ERROR_IO_PENDING:
////         return ::file::exception::hardIO;
////      case ERROR_SWAPERROR:
////         return ::file::exception::accessDenied;
////      default:
////         return ::file::exception::type_generic;
////      }
////   }
////
//
//   // IMPLEMENT_DYNAMIC(WinFileException, ::exception::acme)
//
//   /////////////////////////////////////////////////////////////////////////////
//
//
//
//
//   /////////////////////////////////////////////////////////////////////////////
//   // file Status implementation
//
//   bool file::GetStatus(::file::file_status& rStatus) const
//   {
//
//
//      //memory_set(&rStatus, 0, sizeof(::file::file_status));
//
//      // copy file name from cached m_path
//      rStatus.m_strFullName = m_path;
//
//      if (m_iFile != INVALID_FILE)
//      {
//         struct stat st;
//         if(fstat(m_iFile, &st) == -1)
//            return false;
//
//         rStatus.m_filesize = st.st_size;
//
//         rStatus.m_attribute = 0;
//
//         rStatus.m_ctime = ::earth::time(st.st_mtime);
//         rStatus.m_atime = ::earth::time(st.st_atime);
//         rStatus.m_mtime = ::earth::time(st.st_ctime);
//
//         if (rStatus.m_ctime.get_time() == 0)
//            rStatus.m_ctime = rStatus.m_mtime;
//
//         if (rStatus.m_atime.get_time() == 0)
//            rStatus.m_atime = rStatus.m_mtime;
//      }
//      return true;
//   }
//
//
//
//   bool file::IsOpened()
//   {
//      return m_iFile != INVALID_FILE;
//   }
//
//
//   void file::SetFilePath(const char * pszNewName)
//
//   {
//
//
//      m_path = pszNewName;
//
//   }
//
//   unsigned long long file::ReadHuge(void * pBuffer, unsigned long long dwCount)
//
//   {
//
//      return  read(pBuffer, dwCount);
//
//
//   }
//
//   void file::WriteHuge(const void * pBuffer, unsigned long long dwCount)
//
//   {
//
//      write(pBuffer, dwCount);
//
//
//   }
//
//
////   int file::put_byte_back(int iCharacter)
////   {
////
////      m_iPutCharacter = (int)(unsigned char)iCharacter;
////
////      return 0;
////
////   }
//
//
//} // namespace acme_linux
//
//
//
//
//#define _wcsdec(_cpc1, _cpc2) ((_cpc1)>=(_cpc2) ? nullptr : (_cpc2)-1)
//
//#define _wcsinc(_pc)    ((_pc)+1)
//
//
//
//
//// turn a file, relative path or other into an absolute path
//bool CLASS_DECL_ACME vfxFullPath(wstring & wstrFullPath, const wstring & wstrPath)
//// pszPathOut = buffer of _MAX_PATH
//
//// pszFileIn = file, relative path or absolute path
//
//// (both in ANSI character set)
//{
//
//
//   wstrFullPath = wstrPath;
//
//
//   return true;
//}
//
//
//CLASS_DECL_ACME void vfxGetModuleShortFileName(void * hInst, string& strShortName)
//{
//
//   link_map * plm;
//
//   dlinfo(hInst, RTLD_DI_LINKMAP, &plm);
//
//   strShortName = plm->l_name;
//
//
//}
//
//
//CLASS_DECL_ACME bool posix_resolve_shortcut(string & strTarget, const char * pszSource, ::pointer<::user::interaction_base>puiMessageParentOptional)
//{
//
//   char realname[_POSIX_PATH_MAX * 4];
//
//   int rc = 0;
//
//   if(realpath(scopedstrSource, realname) == 0)
//   {
//
//      return false;
//
//   }
//
//   strTarget = realname;
//
//   return true;
//
//}
//
//
//
