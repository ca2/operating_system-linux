#include "framework.h"

extern "C"
void audio_alsa_factory_exchange(::factory_map * pfactorymap)
{

   pfactorymap->create_factory < ::multimedia::audio_alsa::wave_in  , ::wave::in                  > ();

   pfactorymap->create_factory < ::multimedia::audio_alsa::wave_out ,::wave::out                 > ();

}



