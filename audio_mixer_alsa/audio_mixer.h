#pragma once


#include "app-core/multimedia/audio_mixer/audio_mixer.h"


namespace multimedia
{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA audio_mixer :
         virtual public ::multimedia::audio_mixer::audio_mixer
      {
      public:


         ::pointer<::multimedia::audio_mixer_alsa::window>           m_pwindow;


         audio_mixer();
         ~audio_mixer() override;



         ::multimedia::audio_mixer::callback * get_callback();
         void set_callback(::multimedia::audio_mixer::callback * pcallback);


         void set_new_device(::u32 uiMixerId);


         //bool OnCommand(WPARAM wparam, LPARAM lparam);
         //void OnMixerControlChange(HMIXER hMixer, ::u32 dwControlID);
         //void OnMixerLineChange(HMIXER hMixer, ::u32 dwLineID);


         //static bool get_component_name(LPMIXERLINE pmxl, string & strComponent);
         //static bool get_control_type_name(LPMIXERCONTROL pmxctrl, string & strTypeName);



      };


   } // namespace audio_mixer_alsa


} // namespace multimedia







