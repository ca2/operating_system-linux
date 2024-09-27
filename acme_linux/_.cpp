#include "framework.h"
// #include "acme/prototype/string/string.h"
#include "acme/_library.h"
#include <unistd.h>


namespace linux
{


   ::u32 get_current_directory(string& str)
   {

      str = ::string_from_strdup(get_current_dir_name());

      return str.length();

   }


} // namespace linux



