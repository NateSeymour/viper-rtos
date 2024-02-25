#include <memory/allocator.h>
#include <sys/control.h>

viper::Allocator viper::GlobalAllocator;

viper::Allocator::Allocator()
{
    this->heap_base = (std::byte *)&sys::__heap_base;
    this->heap_top = (std::byte *)&sys::__heap_top;

    this->heap_size = this->heap_top - this->heap_base;
    this->block_size = (std::uint32_t)&sys::__HEAP_BLOCK_SIZE;

    this->block_count = this->heap_size / this->block_size;

    std::size_t descriptor_table_size = this->block_count * sizeof(BlockDescriptor);
    std::size_t reserved_blocks = (descriptor_table_size / this->block_size) + 1;
    this->block_count -= reserved_blocks;

    this->descriptors = (BlockDescriptor *)this->heap_base;
    this->allocatable_base = this->heap_base + (reserved_blocks * this->block_size);
}

std::byte *viper::Allocator::Allocate(std::size_t size)
{
    if(sys::__get_privilege_level() != sys::PrivilegeLevel::kPrivileged) {
        return nullptr;
    }

    // TODO: Get requesting thread id
    std::uint8_t thread_id = 1;

    std::size_t requested_block_count = (size / this->block_size) + 1;
    if(requested_block_count > 256) {
        return nullptr;
    }

    std::size_t contiguous_blocks = 0;
    for(std::size_t i = 0; i < this->block_count; i++) {
        if(this->descriptors[i].thread_id == 0) {
            contiguous_blocks++;
        } else {
            contiguous_blocks = 0;
            i += this->descriptors[i].blocks_in_allocation;
        }

        if(contiguous_blocks >= requested_block_count) {
            this->descriptors[i] = {
                    .thread_id = thread_id,
                    .blocks_in_allocation = (std::uint8_t)requested_block_count,
                    .secure = false,
            };

            // TODO: Protect memory via MPU

            return this->allocatable_base + (i * this->block_size);
        }
    }

    // TODO: Reclaim memory from lower-priority thread (if applicable) and force allocation

    return nullptr;
}
