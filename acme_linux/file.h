#pragma once

//
//class FileException;
//struct FileStatus;
//
//#include "acme/filesystem/file/file.h"
//
////void CLASS_DECL_ACME vfxGetRoot(const ::wide_character * pszPath, string& wstrRoot);
//
////void CLASS_DECL_ACME vfxGetRoot(wstring & wstrRoot, const wstring & wstrPath);
//
//
///////////////////////////////////////////////////////////////////////////////
//// File - raw unbuffered disk file I/O
//
//#define INVALID_FILE -1
//
//
//namespace acme_linux
//{
//
//
//   class CLASS_DECL_ACME file :
//      virtual public ::file::file
//   {
//   public:
//
//
//      //__creatable_from_library(file, ::file::file, "acme_linux");
//
//
////      enum Attribute
////      {
////         normal =    0x00,
////         readOnly =  0x01,
////         hidden =    0x02,
////         system =    0x04,
////         volume =    0x08,
////         directory = 0x10,
////         archive =   0x20
////      };
////
////      enum BufferCommand
////      {
////
////         bufferRead,
////         bufferWrite,
////         bufferCommit,
////         bufferCheck
////
////      };
//
//      int                  m_iFile;
//      //int                  m_iPutCharacter;
//
//
//      file();
//      ~file() override;
//
//
//      //// virtual void assert_ok() const override;
//      //virtual // void dump(dump_context & dumpcontext) const override;
//
//      virtual filesize get_position() const override;
//
//
//      bool GetStatus(::file::file_status & rStatus) const;
//      virtual string GetFileName() const;
//      virtual string GetFileTitle() const;
//      virtual string GetFilePath() const;
//      virtual void SetFilePath(const_char_pointer pszNewName);
//
//
//      void open(const ::file::path & pathFileName, ::file::e_open eopen, ::pointer < ::file::exception > * ppfilexception) override;
//
//
//      //virtual bool PASCAL GetStatus(const_char_pointer pszFileName, ::file::file_status& rStatus);
//
//      unsigned long long ReadHuge(void * pBuffer, unsigned long long dwCount);
//
//      void WriteHuge(const void * pBuffer, unsigned long long dwCount);
//
//
////      virtual ::pointer<::file::file>Duplicate() const;
//
//      virtual void translate(::filesize c, ::enum_seek eseek) override;
//      virtual void set_size(filesize dwNewLen) override;
//      virtual filesize size() const override;
//
//      virtual memsize read(void * pdata, memsize nCount) override;
//
//      virtual void write(const void * pdata, memsize nCount) override;
//
//
//      virtual void LockRange(filesize dwPos, filesize dwCount);
//      virtual void UnlockRange(filesize dwPos, filesize dwCount);
//
//      virtual void Abort();
//      void flush() override;
//      void close() override;
//
//      virtual bool IsOpened();
//
//      virtual unsigned long long GetBufferPtr(unsigned int nCommand, unsigned long long nCount = 0, void ** ppBufStart = nullptr, void ** ppBufMax = nullptr);
//
//      //void put_byte_back(unsigned char unsigned char) override;
//
//
//   };
//
//
////   namespace file_exception
////   {
////
////
////      ::e_status os_error_to_exception(int lOsError);
//////      ::e_status PASCAL ErrnoToException(int nErrno);
////      void throw_os_error(int lOsError, const_char_pointer pszFileName = nullptr);
//
////      //void PASCAL ThrowErrno(::pointer<::platform::application>papp, int nErrno, const_char_pointer pszFileName = nullptr);
//
////
////
////   }  // namespace file_exception
//
//
//} // namepsace acme_linux
//
//
//
//
////bool CLASS_DECL_ACME vfxFullPath(wstring & wstrFullPath, const wstring & wstrPath);
//
//
//
