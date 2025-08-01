#pragma once


namespace win2
{


   class CLASS_DECL_lnx2 application :
      virtual public ::cubebase::application
   {
   public:


      application(::ca::application * papp);
      virtual ~application();

      virtual ::user::printer * get_printer(const_char_pointer pszDeviceName);

   };


} // namespace win2


