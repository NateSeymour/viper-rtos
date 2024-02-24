#ifndef VIPER_RTOS_LINK_H
#define VIPER_RTOS_LINK_H

#include <std/int.h>

#define __EXTSYM(type) extern "C" type

namespace sys
{
    __EXTSYM(std::byte*) __stack_top;
    __EXTSYM(std::byte*) __stack_end;
    __EXTSYM(std::byte*) __heap_base;
    __EXTSYM(std::byte*) __heap_top;

    __EXTSYM(std::uint32_t*) __HEAP_BLOCK_SIZE;
}


#endif //VIPER_RTOS_LINK_H
