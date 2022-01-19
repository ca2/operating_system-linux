#pragma once


namespace linux
{


   class CLASS_DECL_APEX file_system:
      virtual public ::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void initialize(::object * pobject) override;

      void init_system() override;

      //virtual ::e_status update_module_path() override;


   };


} // namespace linux



