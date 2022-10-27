#pragma once


namespace apex_linux
{


   class CLASS_DECL_APEX file_context :
      virtual public ::apex_posix::file_context
   {
   public:


      ::pointer<file_system>     m_pfilesystem;
      ::pointer<dir_system>      m_pdirsystem;


      file_context();
      ~file_context() override;


      void initialize(::particle * pparticle) override;


      void init_system() override;
      void init_context() override;


      file_pointer get_file(const ::payload & varFile, const ::file::e_open & eopen) override;


      //virtual bool is_link(string strPath) override;

      //virtual ::file::path _


      virtual ::file::path dropbox_info_network_payload() override;

      void erase(const ::file::path & path) override;


   };


} // namespace apex_linux



