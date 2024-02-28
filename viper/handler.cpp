#include <handler.h>
#include <scheduler.h>

std::uint32_t __stack_chk_guard = 0x1ee7c0de;
__STDCALL void __stack_chk_fail(void)
{

}

#define _forward_svcall(svc_number, param1, param2, param3, param4) \
    { \
        register std::uint32_t r0 asm("r0") = (std::uint32_t)param1; \
        register std::uint32_t r1 asm("r1") = (std::uint32_t)param2; \
        register std::uint32_t r2 asm("r2") = (std::uint32_t)param3; \
        register std::uint32_t r3 asm("r3") = (std::uint32_t)param4; \
        asm volatile("SVC %[svc]\n" \
                : /* No outputs. */ \
                : [svc] "i" (svc_number), "r" (r0), "r" (r1), "r" (r2), "r" (r3)); \
    }

void _start_thread(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior, std::uint32_t priority)
{
    if(sys::__get_privilege_level() != sys::PrivilegeLevel::kPrivileged)
    {
        return;
    }
}

void viper::start_thread(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior, std::uint32_t priority) _forward_svcall(viper::SVCall::StartThread, subroutine, failure_behavior, priority, std::null);

void _yield()
{
    // TODO: Yield
}

void viper::yield() _forward_svcall(viper::SVCall::Yield, std::null, std::null, std::null, std::null)

void viper::svcall_handler(viper::SVCall svc_number, sys::ExceptionContext *context)
{
    switch(svc_number)
    {
        case viper::SVCall::StartThread:
        {
            _start_thread((viper::subroutine_t) context->r0, (viper::FailureBehavior) context->r1, context->r2);
            break;
        }

        case viper::SVCall::Yield:
        {
            _yield();
            break;
        }
    }
}

void viper::systick_handler()
{

}

void viper::pendsv_handler()
{

}
