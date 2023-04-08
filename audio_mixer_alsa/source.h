#pragma once


#include "audio-system/audio_mixer/source.h"
//
//
//namespace multimedia
//{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA source :
         virtual public ::audio_mixer::source
      {
      public:


         //MIXERLINE                     m_mixerline;
         //MIXERLINECONTROLS             m_mixerlinecontrols;


         source();
         source(source & source);
         ~source() override;


         void mixerGetLineInfo(::u32 dwSource, ::u32 dwDestination, ::u32 fdwInfo);
         void mixerGetLineInfo(::u32 dwSource, ::audio_mixer::destination * pdestination);

         ::atom GetLineID();
         const char * GetSZName();
         void update_all_controls();
         //MIXERLINECONTROLS & get_mixer_line_controls();
         //MIXERLINE & get_mixer_line();
         ::audio_mixer::control_array & get_control_array();

         ::audio_mixer::device * get_device();

         void SetDestination(::audio_mixer::destination * pdestination);
         ::audio_mixer::destination * get_destination();

         void OnMixerLineChange();
         //void OnArrayReallocation(void *pNewPointer);
         //::multimedia::result GetControl(::u32 dwControlType, ::u32 dwControlFlags, ::audio_mixer::control ** ppControl);
         void GetLineControls();

         bool HasV001Controls() override;

         source & operator = (const source & source);


      };


   } // namespace audio_mixer_alsa

//
//} // namespace multimedia
//
//
//
//
//
//
//
