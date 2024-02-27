#ifndef VIPER_RTOS_VIPER_H
#define VIPER_RTOS_VIPER_H

#include <std/int.h>
#include <thread.h>

#define __STDCALL extern "C"
#define __ALIGN(alignment) __attribute__((aligned(alignment)))

__STDCALL int vInitialize();

namespace viper
{

}

#endif //VIPER_RTOS_VIPER_H
