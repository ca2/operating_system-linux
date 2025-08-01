//
// Created by camilo on 20/01/2021. ThomasBS!!
//
#pragma once


namespace node_kde
{


   class appindicator :
      virtual public ::node_linux::appindicator
   {
   public:


      appindicator();
      ~appindicator() override;


      bool create(const_char_pointer pszId, const_char_pointer pszIcon, const_char_pointer pszFolder, application_menu * papplicationmenu) override;



   };


} // namespace node_kde



