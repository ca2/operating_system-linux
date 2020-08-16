#include "framework.h"

extern "C"
void audio_alsa_factory_exchange()
{

   create_factory < ::multimedia::audio_alsa::wave_in  , ::wave::in                  > ();

   create_factory < ::multimedia::audio_alsa::wave_out ,::wave::out                 > ();

}



