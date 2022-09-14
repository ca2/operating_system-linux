#pragma once


#include "app-core/multimedia/audio_mixer/source.h"


namespace multimedia
{


   namespace audio_mixer_alsa
   {


      class CLASS_DECL_AUDIO_MIXER_ALSA source :
         virtual public ::multimedia::audio_mixer::source
      {
      public:


         //MIXERLINE                     m_mixerline;
         //MIXERLINECONTROLS             m_mixerlinecontrols;


         source();
         source(source & source);
         ~source() override;


         void mixerGetLineInfo(::u32 dwSource, ::u32 dwDestination, ::u32 fdwInfo);
         void mixerGetLineInfo(::u32 dwSource, ::multimedia::audio_mixer::destination * pdestination);

         ::atom GetLineID();
         const char * GetSZName();
         void update_all_controls();
         //MIXERLINECONTROLS & get_mixer_line_controls();
         //MIXERLINE & get_mixer_line();
         ::multimedia::audio_mixer::control_array & get_control_array();

         ::multimedia::audio_mixer::device * get_device();

         void SetDestination(::multimedia::audio_mixer::destination * pdestination);
         ::multimedia::audio_mixer::destination * get_destination();

         void OnMixerLineChange();
         //void OnArrayReallocation(void *pNewPointer);
         //::multimedia::result GetControl(::u32 dwControlType, ::u32 dwControlFlags, ::multimedia::audio_mixer::control ** ppControl);
         void GetLineControls();

         bool HasV001Controls() override;

         source & operator = (const source & source);


      };


   } // namespace audio_mixer_alsa


} // namespace multimedia







