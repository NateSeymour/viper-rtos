#ifndef VIPER_RTOS_MEMORY_H
#define VIPER_RTOS_MEMORY_H

#include <std/int.h>

namespace std
{
    void memset(std::byte *origin, std::byte value, std::size_t count);
}

#endif //VIPER_RTOS_MEMORY_H
