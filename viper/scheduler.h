#ifndef VIPER_RTOS_SCHEDULER_H
#define VIPER_RTOS_SCHEDULER_H

#include <thread.h>
#include <std/int.h>
#include <std/vector.h>
#include <sys/control.h>
#include <std/mutex.h>

namespace viper
{
    struct Stack
    {
        std::byte stack[1024];
    };

    class Scheduler
    {
        std::Mutex m_threads;
        std::Vector<viper::Thread> threads;
        std::uint64_t thread_count = 0;

    public:

    };

    extern Scheduler GlobalScheduler;
}

#endif //VIPER_RTOS_SCHEDULER_H
