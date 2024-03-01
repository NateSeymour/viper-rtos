#ifndef VIPER_RTOS_VIPER_H
#define VIPER_RTOS_VIPER_H

#include <interop.h>
#include <std/int.h>
#include <std/memory.h>

__STDCALL [[noreturn]] void viper_main();

namespace viper
{
    __ALIGN(128) extern std::uint32_t vectors[];
}

#endif //VIPER_RTOS_VIPER_H
