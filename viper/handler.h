#ifndef VIPER_RTOS_HANDLER_H
#define VIPER_RTOS_HANDLER_H

#include <viper.h>
#include <thread.h>
#include <std/int.h>
#include <system/exception.h>

namespace viper
{
    enum class SVCall : std::uint8_t
    {
        StartThread,
        Yield,
    };

    void start_thread(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior = viper::FailureBehavior::kRestart, std::uint32_t priority = 1);
    void yield();

    // Exception Handlers
    __STDCALL void svcall_entry();
    __STDCALL void svcall_handler(viper::SVCall svc_number, system::ExceptionContext *context);

    void systick_handler();
    void pendsv_handler();
    void hardfault_handler();
}

#endif //VIPER_RTOS_HANDLER_H
