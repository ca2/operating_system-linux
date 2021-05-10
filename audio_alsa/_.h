#pragma once


#include "app-core/audio/audio/_.h"


// apt install libasound2-dev
// dnf install alsa-lib-devel
// zypper install alsa-devel
#include <alsa/asoundlib.h>


#if defined(_AUDIO_ALSA_LIBRARY)
   #define CLASS_DECL_AUDIO_ALSA  CLASS_DECL_EXPORT
#else
   #define  CLASS_DECL_AUDIO_ALSA  CLASS_DECL_IMPORT
#endif


#include "translation.h"


#include "snd_pcm.h"


#include "wave_out.h"
#include "wave_in.h"


#include "factory_exchange.h"
