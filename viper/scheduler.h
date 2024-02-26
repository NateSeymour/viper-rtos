#ifndef VIPER_RTOS_SCHEDULER_H
#define VIPER_RTOS_SCHEDULER_H

#include <std/int.h>
#include <std/vector.h>
#include <sys/control.h>
#include <std/mutex.h>

namespace viper
{
    typedef void (*subroutine_t)(void);

    enum class ThreadState
    {
        kRunning,
        kPaused,
        kYielding,
        kCrashed,
    };

    enum class FailureBehavior
    {
        kRestart,
        kTerminate,
    };

    struct Stack
    {
        std::byte stack[1024];
    };

    struct Thread
    {
        std::uint8_t thread_id;
        std::byte *stack_base;
        std::byte *sp;
        subroutine_t subroutine;
    };

    class Scheduler
    {
        std::Mutex m_threads;
        std::Vector<Thread> threads;
        std::uint64_t thread_count = 0;

    public:

    };

    extern Scheduler GlobalScheduler;

    void yield();
    void run(subroutine_t subroutine, FailureBehavior failure_behavior = FailureBehavior::kRestart, std::uint32_t priority = 1);
}

#endif //VIPER_RTOS_SCHEDULER_H
