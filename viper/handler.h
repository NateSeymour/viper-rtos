#ifndef VIPER_RTOS_HANDLER_H
#define VIPER_RTOS_HANDLER_H

#include <viper.h>
#include <thread.h>
#include <std/int.h>
#include <sys/exception.h>

namespace viper
{
    enum class SVCall : std::uint8_t
    {
        Run,
    };

    // SVCalls
    extern std::uint32_t SVCLookupTable[256];

    void _run(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior, std::uint32_t priority);
    void run(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior = viper::FailureBehavior::kRestart, std::uint32_t priority = 1);

    void yield();

    // Exception Handlers
    __STDCALL void svcall_entry();
    __STDCALL void svcall_handler(viper::SVCall svc_number, sys::ExceptionContext *context);
}

#endif //VIPER_RTOS_HANDLER_H
