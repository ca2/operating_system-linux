#pragma once


#include "app-core/multimedia/audio_mixer/user/_.h"


namespace multimedia
{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA callback
      {
      public:


         callback();
         virtual ~callback();


         virtual ::audio_mixer::user::level_control * allocate_level_control();
         virtual ::audio_mixer::user::toggle_control * allocate_toggle_control();
         virtual ::audio_mixer::user::label * allocate_label();


      };


   } // namespace audio_mixer_alsa


} // namespace multimedia



