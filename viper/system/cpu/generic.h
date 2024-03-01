#ifndef VIPER_RTOS_GENERIC_H
#define VIPER_RTOS_GENERIC_H

#include <std/int.h>
#include <thread.h>

namespace system
{
    constexpr std::uint64_t kMaxThreadCount = 16;

    system::GenericArmCore *current_core();

    class GenericArmCore
    {
    protected:
        const std::uint8_t cpu_id;

        std::uint8_t thread_count = 0;
        std::uint8_t active_thread_index = 0;
        viper::Thread *threads[kMaxThreadCount];

    public:
        void RegisterThread(viper::Thread *thread);

        [[noreturn]] void BeginExecution();

        explicit GenericArmCore(std::uint8_t cpu_id);
    };
}

#endif //VIPER_RTOS_GENERIC_H
