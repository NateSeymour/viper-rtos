#ifndef VIPER_RTOS_SCHEDULER_H
#define VIPER_RTOS_SCHEDULER_H

#include <std/int.h>
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
    public:

    };

    void yield();
}

#endif //VIPER_RTOS_SCHEDULER_H
