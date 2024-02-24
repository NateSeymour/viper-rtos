#ifndef VIPER_RTOS_ALLOCATOR_H
#define VIPER_RTOS_ALLOCATOR_H

#include <sys/link.h>
#include <std/int.h>

namespace viper
{
    struct BlockDescriptor
    {
        std::uint8_t thread_id = 0;
        std::uint8_t blocks_in_allocation = 0;
        bool secure = false;
    };

    class Allocator
    {
        std::byte *heap_base = nullptr;
        std::byte *heap_top = nullptr;
        std::byte *allocatable_base = nullptr;
        std::size_t heap_size = 0;

        BlockDescriptor *descriptors;

        std::size_t block_size = 0;
        std::size_t block_count = 0;

    public:
        std::byte *Allocate(std::size_t size);

        Allocator();
    };

    Allocator GlobalAllocator;
}

#endif //VIPER_RTOS_ALLOCATOR_H
