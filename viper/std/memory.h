#ifndef VIPER_RTOS_MEMORY_H
#define VIPER_RTOS_MEMORY_H

#include <interop.h>
#include <std/int.h>

#define __ALIGN(alignment) __attribute__((aligned(alignment)))

namespace std
{
    __STDCALL void memset(std::byte *origin, std::byte value, std::size_t count);
}

#endif //VIPER_RTOS_MEMORY_H
