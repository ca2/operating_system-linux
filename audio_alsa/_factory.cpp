#include "framework.h"

__FACTORY_EXPORT void audio_alsa_factory(::factory_map * pfactorymap)
{

   pfactorymap->create_factory < ::multimedia::audio_alsa::wave_in  , ::wave::in                  > ();

   pfactorymap->create_factory < ::multimedia::audio_alsa::wave_out ,::wave::out                 > ();

}



