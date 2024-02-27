#ifndef VIPER_RTOS_EXCEPTION_H
#define VIPER_RTOS_EXCEPTION_H

#include <std/int.h>

namespace sys
{
    struct ExceptionContext
    {
        std::uint32_t r0;
        std::uint32_t r1;
        std::uint32_t r2;
        std::uint32_t r3;
        std::uint32_t r12;
        std::uint32_t lr;
        std::byte *return_address;
        std::uint32_t xpsr;
    };
}

#endif //VIPER_RTOS_EXCEPTION_H
