#pragma once


/* #define FF_API_AVIO_WRITE_NONCONST 1 */
extern "C"
{


#include <libavformat/version.h>


}

#ifdef DEBIAN_LINUX
//#error "debian check"
#define AVIO_FILE_WRITE_TYPE uint8_t
#elif defined(UBUNTU_LINUX)
//#error "debian check"
#define AVIO_FILE_WRITE_TYPE uint8_t
#elif defined(MINT_LINUX)
//#error "debian check"
#define AVIO_FILE_WRITE_TYPE uint8_t
#else
//#error "non debian check"

#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(59,0,0)
#define AVIO_FILE_WRITE_TYPE const uint8_t
#else
#define AVIO_FILE_WRITE_TYPE uint8_t
#endif
#endif
