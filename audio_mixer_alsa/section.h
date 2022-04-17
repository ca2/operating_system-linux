#pragma once


namespace multimedia
{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA departament :
         virtual public ::multimedia::audio_mixer::department
      {
      public:



         enum EIds
         {

            IdsMuteAll,
            IdsMute

         };


         departament();
         ~departament() override;


         virtual bool initialize1();



         bool initialize();


         bool finalize();





      };


   } // namespace mixguserbase


} // namespace multimedia






