#ifndef VIPER_RTOS_THREAD_H
#define VIPER_RTOS_THREAD_H

#include <std/memory.h>
#include <std/int.h>

namespace viper
{
    typedef void (*subroutine_t)(void);

    constexpr std::uint64_t kDefaultProcessStackSize = 1024;

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

    template<std::size_t size>
    struct ProcessStack
    {
        __ALIGN(0x8) std::byte stack[size];

        consteval std::size_t Size() const
        {
            return size;
        }

        consteval std::byte *Base() const
        {
            return (std::byte*)this->stack;
        }

        ProcessStack()
        {
            std::memset(this->stack, 0, size);
        }
    };

    class Thread
    {
        ProcessStack *stack;
        std::byte *stack_base;
        std::byte *sp;
        subroutine_t subroutine;
        std::uint8_t niceness;

    public:
        explicit Thread(subroutine_t subroutine, std::uint8_t niceness = 1) : subroutine(subroutine), niceness(niceness)
        {

        }
    };
}

#endif //VIPER_RTOS_THREAD_H
