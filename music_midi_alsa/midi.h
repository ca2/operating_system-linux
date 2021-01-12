#pragma once


namespace music
{


   namespace midi
   {


      namespace alsa
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_ALSA midi :
            virtual public ::music::midi::midi
         {
         public:


            //base_library                 m_library;
            //midi_listener_set             m_listenerptra;
            //::u32                      m_uiMidiOutDevice;


            midi();
            virtual ~midi();


            virtual ::e_status enumerate_midi_devices();


            //void RemoveListener(midi_listener * plistener);
            //void AddListener(midi_listener * plistener);
            //::u32 GetMidiOutDevice();
            //void SetMidiOutDevice(::u32 uiDevice);
            //bool Initialize();


            //bool IsSoftKaraokeFile(const char * lpszPathName);
            //bool IsXFFile(const char * lpcszPathName);


            //virtual bool veriwell_multimedia_music_midi_factory_exchange();


   /*            void mmsystem_LogMidiInCaps(::u32 i, MIDIINCAPSW caps);
            void mmsystem_GetMidiInDeviceInterface(::u32 i);
            void mmsystem_LogMidiOutCaps(::u32 i, MIDIOUTCAPSW caps);
            void mmsystem_GetMidiOutDeviceInterface(::u32 i);*/


            virtual __pointer(::music::midi::message_out) get_message_out(const string& strDevice) override;
            virtual __pointer(::music::midi::sequencer) create_midi_sequencer(sequence * psequence, const string& strDevice) override;


            using ::music::midi::midi::translate_os_result;
            virtual ::e_status translate_os_result(string & strMessage, string & strOsMessage, ::music::midi::object * pobject, int64_t iOsResult, const string & strContext, const string & strText);


            virtual bool Initialize();

            virtual bool list_midi_out_card_devices(int card);

            virtual bool list_midi_out_devices(snd_ctl_t *ctl, int card, int device);


         };


      } // namespace alsa


   } // namespace midi


} // namespace music




