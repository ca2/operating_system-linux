#pragma once


namespace linux
{


   class stdio_file :
      virtual public ::file::text_file
   {
   public:


      FILE *            m_pStream;


      stdio_file();
      ~stdio_file() override;


      void dump(dump_context & dumpcontext) const override;

      void write_string(const char * psz) override;

      virtual char * read_string(char * psz, ::u32 nMax);

      bool read_string(string & rString) override;


      filesize get_position() const override;
      ::extended::status open(const ::file::path & pszFileName, const ::file::e_open & eopen) override;

      memsize read(void * pdata, memsize nCount) override;

      void write(const void * pdata, memsize nCount) override;

      ::index translate(::count c, ::enum_seek eseek) override;

      void abort() override;
      void flush() override;
      void close() override;


      filesize get_size() const override;


   };



} // namespace linux


