#pragma once


#include "audio-system/audio_mixer/control.h"

//
//namespace multimedia
//{


namespace audio_mixer_alsa
{


   class CLASS_DECL_AUDIO_MIXER_ALSA control :
           virtual public ::audio_mixer::control
   {
   public:


      enum Styles
      {
         StyleV001 = 1
      };


      //MIXERCONTROL                     m_mixercontrol;
      //MIXERCONTROLDETAILS              m_mixercontroldetails;


      control();

      control(control &control);

      ~control() override;

      //using ::audio_mixer_user::control_ptr_array::add;
      //virtual iptr add(::audio_mixer_user::control *pcontrol);

      bool control_type(::audio_mixer::e_control econtrol) const;

      //bool OnCommand(WPARAM wParam, LPARAM lParam);
      ::pointer<::audio_mixer::control_data> GetWindowDataByDlgCtrlID(::u32 nID);

      //::pointer<::audio_mixer_user::control> GetControlByDlgCtrlID(::u32 nID);

      //   bool OnNotify(::u32 nID, LPNMHDR lpnmhdr);
      void OnVHScroll(::u32 nSBCode, ::u32 nPos, ::user::interaction *pscrollbar);

      ::pointer<::audio_mixer::control_data> GetWindowData(int32_t iType);

      void OnMixerControlChange();

      //::pointer<::audio_mixer_user::control> GetControl(int32_t iType);

      //::pointer<::audio_mixer_user::control> GetControlByIndex(::index iIndex);

      void Prepare();

      bool CreateWindowsVolumeV001(::user::interaction *puserinteractionParent, ::u32 nStartID, ::u32 *nNextID);

      //  bool _001CreateMuteControl(sp(::user::interaction) pParent, CRuntimeClass * pruntimeclassMuteControl, ::u32 nStartID, ::u32 * nNextID);
      bool _001CreateMuteControl(::user::interaction *puserinteractionParent, ::u32 nStartID, ::u32 *nNextID);

      bool CreateWindows(::user::interaction *puserinteractionParent, int32_t iStyle);

      control &operator=(const control &control);


      //MIXERCONTROL & GetMixerControl();
      //MIXERCONTROLDETAILS & GetMixerControlDetails();


   };


} // namespace audio_mixer_alsa

//
//} // namespace multimedia
//
//
//
//
