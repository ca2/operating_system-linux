#include "framework.h"
#include "control.h"
#include "destination.h"
#include "device.h"
#include "line_info.h"
#include "audio_mixer.h"
#include "source.h"


__FACTORY_EXPORT void audio_mixer_alsa_factory(::factory::factory * pfactory)
{

   //System.factory().cloneable_large < callback                    >  (System.type_info < ::multimedia::audio_mixer::callback                 > ());
   pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::control, ::multimedia::audio_mixer::control >();
   //System.factory().creatable_small < control_data                >  (System.type_info < ::multimedia::audio_mixer::control_data             > ());
   pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::destination, ::multimedia::audio_mixer::destination >();
   pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::device, ::multimedia::audio_mixer::device >();
   pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::line_info, ::multimedia::audio_mixer::line_info >();
   pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::audio_mixer, ::multimedia::audio_mixer::audio_mixer >();
   //System.factory().cloneable_large < departament                   >  (System.type_info < ::multimedia::audio_mixer::font                     > ());
   pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::source, ::multimedia::audio_mixer::source >();
   //pfactory->add_factory_item < ::multimedia::audio_mixer_alsa::thread, ::multimedia::audio_mixer::thread >();
   /*System.factory().creatable_small < user::label                 >  (System.type_info < ::multimedia::audio_mixer::user::label              > ());
   System.factory().creatable_small < user::control               >  (System.type_info < ::multimedia::audio_mixer::user::control            > ());
   System.factory().creatable_small < user::level_control         >  (System.type_info < ::multimedia::audio_mixer::user::level_control      > ());
   System.factory().creatable_small < user::toggle_control        >  (System.type_info < ::multimedia::audio_mixer::user::toggle_control     > ());*/

}



