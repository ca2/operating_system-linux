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


      bool create(const char * pszId, const char * pszIcon, const char * pszFolder, application_menu * papplicationmenu) override;



   };


} // namespace node_kde



