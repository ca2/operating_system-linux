#Created by camilo on 2025-11-09 00:28 <3ThomasBorregaardSørensen!!


execute_process(COMMAND uname -m OUTPUT_VARIABLE __SYSTEM_ARCHITECTURE)
string(STRIP ${__SYSTEM_ARCHITECTURE} __SYSTEM_ARCHITECTURE)
message(STATUS "__SYSTEM_ARCHITECTURE is ${__SYSTEM_ARCHITECTURE}")


if(EXISTS "${CMAKE_SOURCE_DIR}/raspberrypios.txt")
   set(__TARGET_SYSTEM_ARCHITECTURE "aarch64")

   if(NOT "${__SYSTEM_ARCHITECTURE}" STREQUAL "aarch64")
      include("operating_system/aarch64-linux-toolchain.cmake")
   endif()
else()
   set(__SYSTEM_ARCHITECTURE "aarch64")
endif()



execute_process(COMMAND lsb_release -is OUTPUT_VARIABLE __OPERATING_SYSTEM)
string(STRIP ${__OPERATING_SYSTEM} __OPERATING_SYSTEM)
string(TOLOWER ${__OPERATING_SYSTEM} __OPERATING_SYSTEM)
message(STATUS "__OPERATING_SYSTEM is ${__OPERATING_SYSTEM}")

