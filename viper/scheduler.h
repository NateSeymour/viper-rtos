#ifndef VIPER_RTOS_SCHEDULER_H
#define VIPER_RTOS_SCHEDULER_H

#include <std/int.h>
#include <std/vector.h>
#include <sys/control.h>

namespace viper
{
    class Thread
    {
        std::uint8_t cpu_id;
        std::uint8_t thread_id;
        std::byte *sp;
        sys::PrivilegeLevel privilege_level;
    };

    class Scheduler
    {
        std::Vector<Thread> threads;

    public:

    };

    extern Scheduler GlobalScheduler;

    typedef void (*subroutine_t)(void);

    void yield();
    void schedule_thread(subroutine_t subroutine);
}

#endif //VIPER_RTOS_SCHEDULER_H
