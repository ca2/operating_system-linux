#pragma once


namespace music
{


   namespace midi
   {


      namespace alsa
      {


      class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_ALSA out :
         virtual public ::music::midi::out
      {
      public:


         snd_seq_t *       m_poseq;
         string            m_strClientName;
         //int               m_numPorts;


         out();
         virtual ~out();


         virtual ::e_status open();
         virtual ::e_status close();

         ::e_status send_short_message(::music::midi::e_message etype, int iChannel, int iData1, int iData2) override;

      };


      } // namespace alsa


   } // namespace midi


} // namespace music




