#ifndef VIPER_RTOS_THREAD_H
#define VIPER_RTOS_THREAD_H

#include <std/int.h>

namespace viper
{
    typedef void (*subroutine_t)(void);

    enum class ThreadState : std::uint32_t
    {
        kRunning,
        kPaused,
        kYielding,
        kCrashed,
    };

    enum class FailureBehavior : std::uint32_t
    {
        kRestart,
        kTerminate,
    };

    struct Thread
    {
        std::uint64_t thread_id = 0;
        std::uint8_t niceness = 1;
        std::byte *stack_base = nullptr;
        std::byte *sp = nullptr;
        subroutine_t subroutine = nullptr;
    };
}

#endif //VIPER_RTOS_THREAD_H
