#pragma once


namespace multimedia
{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA thread :
         public ::thread,
         public ::database::client
      {
      public:


         enum e_message
         {
            MessageMixerThread = WM_USER + 113,
         };

         bool                                m_bPendingShowCommand;

         ::pointer<::multimedia::audio_mixer::department>m_psection;


         thread();
         ~thread() override;


//         static LRESULT CALLBACK MessageProc(
//            int32_t code,       // hook code
//            WPARAM wParam,  // undefined
//            LPARAM lParam   // address of structure with message data
//            );


         void install_message_routing(::channel * pchannel);

         virtual bool initialize_instance();
         virtual int32_t exit_instance();
         virtual bool on_idle(::i32 lCount);
         virtual void pre_translate_message(::message::message * pmessage);


         DECLARE_MESSAGE_HANDLER(OnMixerMessage);
         DECLARE_MESSAGE_HANDLER(OnVmsmException);
         DECLARE_MESSAGE_HANDLER(OnUserMessage);


      };


   } // namespace audio_mixer_alsa


} // namespace multimedia





