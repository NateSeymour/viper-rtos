#ifndef VIPER_RTOS_MUTEX_H
#define VIPER_RTOS_MUTEX_H

#include <std/int.h>

namespace std
{
    class Mutex
    {
        std::uint32_t value = 0;

    public:
        bool Lock(uint32_t max_attempt = 0);
        bool TryLock();
        void Release();
        ~Mutex();
    };

    class LockGuard
    {
        std::Mutex &m;
    public:
        LockGuard() = delete;

        explicit LockGuard(std::Mutex &m) : m(m)
        {
            m.Lock();
        }

        ~LockGuard()
        {
            m.Release();
        }
    };
}

#endif //VIPER_RTOS_MUTEX_H
