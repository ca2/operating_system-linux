#pragma once


#include "app-core/multimedia/audio_mixer/line_info.h"


namespace multimedia
{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA line_info :
         virtual public ::multimedia::audio_mixer::line_info
      {
      public:


         //MIXERLINE       m_mixerLine;


         line_info();
         ~line_info() override;


      };


   } // namespace audio_mixer_alsa


} // namespace multimedia









