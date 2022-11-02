#include "framework.h"
#include "acme/primitive/string/string.h"
#include "acme/_library.h"


namespace linux
{


   ::u32 get_current_directory(string& str)
   {

      str = ::string_from_strdup(get_current_dir_name());

      return str.get_length();

   }


} // namespace linux



