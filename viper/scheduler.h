#ifndef VIPER_RTOS_SCHEDULER_H
#define VIPER_RTOS_SCHEDULER_H

#include <thread.h>
#include <std/int.h>
#include <std/vector.h>
#include <sys/control.h>
#include <std/mutex.h>

namespace viper
{
    constexpr std::uint64_t kDefaultProcessStackSize = 1024;

    class Scheduler
    {
        std::Vector<viper::Thread> threads;
        std::uint64_t thread_count = 0;

    public:
        void RegisterThread(viper::subroutine_t subroutine);
    };

    extern Scheduler GlobalScheduler;
}

#endif //VIPER_RTOS_SCHEDULER_H
