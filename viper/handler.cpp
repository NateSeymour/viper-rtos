#include <handler.h>

void viper::_run(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior, std::uint32_t priority)
{
}

void viper::run(viper::subroutine_t subroutine, viper::FailureBehavior failure_behavior, std::uint32_t priority)
{
    register viper::subroutine_t r0 asm("r0") = subroutine;
    register viper::FailureBehavior r1 asm("r1") = failure_behavior;
    register std::uint32_t r2 asm("r2") = priority;
    asm volatile("SVC %[svc_number]\n"
        : /* No outputs. */
        : [svc_number] "i" (viper::SVCall::Run), "r" (r0), "r" (r1), "r" (r2));
}

void viper::svcall_handler(viper::SVCall svc_number, sys::ExceptionContext *context)
{
    switch(svc_number)
    {
        case viper::SVCall::Run:
        {
            viper::_run((viper::subroutine_t)context->r0, (viper::FailureBehavior)context->r1, context->r2);
            break;
        }
    }
}