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
        std::uint8_t thread_id;
        std::byte *stack_base;
        std::byte *sp;
        subroutine_t subroutine;
    };
}

#endif //VIPER_RTOS_THREAD_H
