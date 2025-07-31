#include "framework.h"
#include "apex/operating_system.h"
////#include <shlobj.h>
////#include <Security.h>
////#include <shlobj.h>
//
//
////#include "linux_dir.h"
////#include "linux_factory.h"
////#include "linux_port_forward.h"
////#include "linux_dir.h"
////#include "linux_file_system.h"
////#include "linux_file_set.h"
//#include "crypto.h"
////#include "linux_ip_enum.h"
//
//int crypto_encrypt(memory & storageEncrypt, const memory & storageDecrypt, memory & key);
//int crypto_decrypt(memory & storageDecrypt, const memory & storageEncrypt, memory & key);
//
//namespace linux
//{
//
//
//   crypto::crypto()
//   {
//   }
//
//
//
//   crypto::~crypto()
//   {
//
//   }
//
//
//   ::file::path crypto::get_crypt_key_file_path()
//   {
//
//      return directory()->appdata() / ".ca2/databin.bin";
//
//   }
//
//
//   bool crypto::decrypt(memory & storageDecrypt, const memory & storageEncrypt, const char * pszSalt)
//   {
//
//      return ::crypto::crypto::decrypt(storageDecrypt, storageEncrypt, pszSalt);
//
//#if 0
//
//      DATA_BLOB DataIn;
//      DATA_BLOB DataOut;
//
//      if (scopedstrSalt == nullptr)
//         pszSalt = "";
//
//      DATA_BLOB DataSalt;
//      memory memorySalt;
//      memorySalt.from_string(scopedstrSalt);
//      DataSalt.pbData = memorySalt.get_data();
//      DataSalt.cbData = (unsigned int)memorySalt.get_size();
//
//      //--------------------------------------------------------------------
//      // Initialize the DataIn structure.
//
//      DataIn.pbData = storageEncrypt.get_data();
//      DataIn.cbData = (unsigned int)storageEncrypt.get_size();
//
//      unichar * pwsz = nullptr;
//
//
//      //--------------------------------------------------------------------
//      //  begin protect phase. Note that the encryption key is created
//      //  by the function and is not passed.
//
//      if (CryptUnprotectData(
//            &DataIn,
//            nullptr, // A description string
//            // to be included with the
//            // encrypted data.
//            &DataSalt,                               // Optional entropy not used.
//            nullptr,                               // Reserved.
//            nullptr,                               // Pass nullptr for the
//            // prompt structure.
//            0,
//            &DataOut))
//      {
//         informationf("crypto::decrypt The encryption phase worked. \n");
//         storageDecrypt.allocate(DataOut.cbData);
//         ::memory_copy(storageDecrypt.get_data(), DataOut.pbData, DataOut.cbData);
//         LocalFree(pwsz);
//
//         LocalFree(DataOut.pbData);
//         return true;
//      }
//      else
//      {
//         //         TRACELASTERROR();
//         informationf("crypto::decrypt Decryption error! (1)");
//         return false;
//      }
//
//#else
//
//      memory memOut;
//
//      memory memIn;
//
//      memIn.append(storageEncrypt.get_data(), storageEncrypt.get_size());
//
//      memory memSalt;
//
//      memSalt.append(scopedstrSalt, strlen(scopedstrSalt));
//
//      if (!::crypto_decrypt(memOut, memIn, memSalt))
//      {
//
//         return false;
//
//      }
//
//      storageDecrypt = memOut;
//
//      return true;
//
//#endif
//
//   }
//
//
//   bool crypto::encrypt(memory & storageEncrypt, const memory & storageDecrypt, const char * pszSalt)
//   {
//
//      return ::crypto::crypto::encrypt(storageEncrypt, storageDecrypt, pszSalt);
//#if 0
//      DATA_BLOB DataIn;
//      DATA_BLOB DataOut;
//
//      if (scopedstrSalt == nullptr)
//         pszSalt = "";
//
//      DATA_BLOB DataSalt;
//      memory memorySalt;
//      memorySalt.from_string(scopedstrSalt);
//      DataSalt.pbData = memorySalt.get_data();
//      DataSalt.cbData = (unsigned int)memorySalt.get_size();
//
//
//      //--------------------------------------------------------------------
//      // Initialize the DataIn structure.
//
//      DataIn.pbData = (unsigned char *)storageDecrypt.get_data();
//      DataIn.cbData = (unsigned int)storageDecrypt.get_size();
//
//      //      unichar * pwsz = nullptr;
//
//
//      //--------------------------------------------------------------------
//      //  begin protect phase. Note that the encryption key is created
//      //  by the function and is not passed.
//
//      if (CryptProtectData(
//            &DataIn,
//            nullptr, // A description string
//            // to be included with the
//            // encrypted data.
//            &DataSalt,                               // Optional entropy not used.
//            nullptr,                               // Reserved.
//            nullptr,                               // Pass nullptr for the
//            // prompt structure.
//            0,
//            &DataOut))
//      {
//         informationf("crypto::encrypt The encryption phase worked. \n");
//         storageEncrypt.allocate(DataOut.cbData);
//         ::memory_copy(storageEncrypt.get_data(), DataOut.pbData, DataOut.cbData);
//         LocalFree(DataOut.pbData);
//         return true;
//      }
//      else
//      {
//         informationf("crypto::encrypt Encryption error! (1)");
//         return false;
//      }
//#else
//
//      memory memOut;
//
//      memory memIn;
//
//      memIn.append(storageDecrypt.get_data(), storageDecrypt.get_size());
//
//      memory memSalt;
//
//      memSalt.append(scopedstrSalt, strlen(scopedstrSalt));
//
//      if (!::crypto_encrypt(memOut, memIn, memSalt))
//         return false;
//
//
//      storageEncrypt = memOut;
//
//      return true;
//#endif
//
//   }
//
//
//} // namespace linux
//
//
//
