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

      void start_node() override;

      void initialize(::object * pobject) override;

      virtual bool windowing_message_loop_step();

      void handle(::topic * ptopic, ::context * pcontext) override;

      bool should_launch_on_node(::topic * ptopic) override;

      bool launch_on_node(::topic * ptopic) override;


   };


} // namespace desktop_environment_gnome




