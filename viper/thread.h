#ifndef VIPER_RTOS_THREAD_H
#define VIPER_RTOS_THREAD_H

#include <std/memory.h>
#include <std/int.h>

namespace system
{
    class GenericArmCore;
}

namespace viper
{
    typedef void (*subroutine_t)(void);

    constexpr std::uint64_t kDefaultProcessStackSize = 1024;

    enum class ThreadState : std::uint32_t
    {
        kRunning,
        kPaused,
        kPending,
        kYielding,
        kCrashed,
    };

    enum class FailureBehavior : std::uint32_t
    {
        kRestart,
        kTerminate,
    };

    struct Stack
    {
        virtual std::size_t Size() const = 0;
        virtual std::byte *Base() const = 0;
        virtual bool IsResizable() const = 0;

        Stack() {}
    };

    template<std::size_t size = kDefaultProcessStackSize>
    struct StaticallyAllocatedStack : public Stack
    {
        __ALIGN(0x8) std::byte stack[size];

        std::size_t Size() const override
        {
            return size;
        }

        std::byte *Base() const override
        {
            return (std::byte*)this->stack;
        }

        bool IsResizable() const override
        {
            return false;
        }

        StaticallyAllocatedStack()
        {
            std::memset(this->stack, 0, size);
        }
    };

    struct DynamicallyAllocatedStack : public Stack {};

    class Thread
    {
        friend class system::GenericArmCore;

    protected:
        Stack &stack;
        std::byte *sp;
        subroutine_t subroutine;
        std::uint8_t niceness;
        ThreadState state = ThreadState::kPaused;
        FailureBehavior failure_behavior = FailureBehavior::kTerminate;

    public:
        Thread(system::GenericArmCore *core, Stack &stack, subroutine_t subroutine, std::uint8_t niceness = 1);
    };

}

#endif //VIPER_RTOS_THREAD_H
