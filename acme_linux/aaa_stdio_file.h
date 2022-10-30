#pragma once


namespace acme_linux
{


   class stdio_file :
      virtual public ::file::text_file
   {
   public:


      //__creatable_from_library(stdio_file, ::file::text_file, "acme_linux");


      FILE *            m_pStream;


      stdio_file();
      ~stdio_file() override;


      // void dump(dump_context & dumpcontext) const override;


      void open(const ::file::path & pszFileName, const ::file::e_open & eopen) override;

      filesize get_position() const override;


      memsize read(void * pdata, memsize nCount) override;

      void write(const void * pdata, memsize nCount) override;


      void write_string(const char * psz) override;

      virtual char * read_string(char * psz, ::u32 nMax);

      bool read_string(string & rString) override;


      ::filesize translate(::filesize c, ::enum_seek eseek) override;

      void abort() override;
      void flush() override;
      void close() override;


      filesize get_size() const override;


   };


} // namespace acme_linux



