#include <thread.h>

viper::Thread *viper::GlobalThreadPool[viper::kMaxThreadCount] = {nullptr};

viper::Thread::Thread(viper::Stack &stack, viper::subroutine_t subroutine, std::uint8_t niceness) : stack(stack), subroutine(subroutine), niceness(niceness)
{
    this->sp = this->stack.Base();
    viper::GlobalThreadPool[this->id] = this;
}
