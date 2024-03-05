#ifndef VIPER_RTOS_CPU_H
#define VIPER_RTOS_CPU_H

#include <std/int.h>

namespace system
{
    class GenericArmCore;

    extern const std::uint8_t CoreCount;
    extern system::GenericArmCore *const Cores[];
}

#endif //VIPER_RTOS_CPU_H
