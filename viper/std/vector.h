#ifndef VIPER_RTOS_VECTOR_H
#define VIPER_RTOS_VECTOR_H

#include <memory/allocator.h>
#include <std/int.h>

namespace std
{
    template<typename T>
    class Vector
    {
        std::size_t size = 0;
        std::size_t capacity = 0;
        std::size_t count = 0;
        std::byte *data = nullptr;

    public:
        T Get(std::int32_t i) const
        {
            return *(T*)(this->data + (sizeof(T) * i));
        }

        T operator[](std::int32_t i) const
        {
            return this->Get(i);
        }

        T& operator[](std::int32_t i)
        {
            return *(T*)(this->data + (sizeof(T) * i));
        }

        explicit Vector(std::size_t capacity = 0) : capacity(capacity)
        {
            this->size = capacity * sizeof(T);
            this->data = viper::GlobalAllocator.AllocateRaw(this->size);
        }

        Vector()
        {
            viper::GlobalAllocator.Free(this->data);
        }
    };
}

#endif //VIPER_RTOS_VECTOR_H
