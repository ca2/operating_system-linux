//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace desktop_environment_gnome
{


   class CLASS_DECL_DESKTOP_ENVIRONMENT_GNOME node :
      virtual public ::aura::linux::node,
      virtual public ::node_gnome::node
   {
   public:


      node();
      ~node() override;


      int node_init_check(int * pi, char *** ppz) override;

      void defer_notify_startup_complete() override;

      ::e_status start_node() override;

      ::e_status initialize(::object * pobject) override;

      virtual bool windowing_message_loop_step();

      void handle(::subject * psubject, ::context * pcontext) override;

      bool should_launch_on_node(::subject * psubject) override;

      bool launch_on_node(::subject * psubject) override;


   };


} // namespace desktop_environment_gnome




