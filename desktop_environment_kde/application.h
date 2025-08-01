#pragma once


//#include <gtk/gtk.h>


typedef struct
{

  //GtkApplication parent_instance;

  //gunsigned int quit_inhibit;
  //GMenu *time;
  //gunsigned int timeout;

} ApexApplication; // you can search for ApexApplication in 2017 and so Internet

//typedef GtkApplicationClass ApexApplicationClass;



extern ApexApplication * g_papexapplication;


void apex_application_run(const_char_pointer  pszAppName, const_char_pointer  pszProgName);






void apex_application_set_application_menu(::application_menu * pappmenu, ::apex::application * papp);


