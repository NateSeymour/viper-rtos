#include <thread.h>
#include <system/cpu/generic.h>

viper::Thread::Thread(system::GenericArmCore *core, viper::Stack &stack, viper::subroutine_t subroutine, std::uint8_t niceness) : stack(stack), subroutine(subroutine), niceness(niceness)
{
    this->sp = this->stack.Base();
    core->RegisterThread(this);
}
