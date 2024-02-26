#ifndef VIPER_RTOS_BOX_H
#define VIPER_RTOS_BOX_H

#include <memory/allocator.h>

namespace std
{
    template<typename T>
    class Box
    {
        T *data;

        Box(T *data) : data(data) {};

    public:
        template<typename... Args>
        static Box<T> Make(Args&&... args)
        {
            std::byte *data = viper::GlobalAllocator.AllocateRaw(sizeof(T));
            *data = T(args...);
            return Box(data);
        }

        ~Box()
        {
            viper::GlobalAllocator.Free(this->data);
        }
    };
}

#endif //VIPER_RTOS_BOX_H
