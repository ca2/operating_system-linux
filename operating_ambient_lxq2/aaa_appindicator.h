//
// Created by camilo on 20/01/2021. ThomasBS!!
//
#pragma once


namespace operating_ambient_gtk_based
{


   class appindicator :
      virtual public ::node_gnome::appindicator
   {
   public:


      appindicator();
      virtual ~appindicator();


      virtual bool create(const char * pszId, const char * pszIcon, const char * pszFolder, user_notify_icon_bridge * pbridge);



   };


} // namespace operating_ambient_gtk_based



