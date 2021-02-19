//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace node_linux
{


   class CLASS_DECL_ACME node :
      virtual public ::node_ansios::node,
      virtual public ::aura::node
   {
   public:



      node();
      virtual ~node();


      result_pointer < appindicator > new_appindicator();
      //virtual int node_init_check(int * pi, char *** ppz) override;

      virtual void os_application_system_run() override;

      virtual ::e_status initialize(::layered * pobjectContext) override;

      virtual ::file::path get_desktop_file_path(::apex::application * papp) const;


   };


} // namespace node_linux




