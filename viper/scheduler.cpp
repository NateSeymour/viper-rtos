#include <scheduler.h>
#include <sys/control.h>
#include <memory/allocator.h>

viper::Scheduler viper::GlobalScheduler;

void viper::Scheduler::RegisterThread(viper::subroutine_t subroutine)
{
    if(sys::__get_privilege_level() != sys::PrivilegeLevel::kPrivileged)
    {
        return;
    }

    // Create Thread
    viper::Thread new_thread;

    new_thread.thread_id = this->thread_count;
    new_thread.subroutine = subroutine;

    // Allocate new stack for thread
    new_thread.stack_base = viper::GlobalAllocator.AllocateRaw(viper::kDefaultProcessStackSize);
    new_thread.sp = new_thread.stack_base + viper::kDefaultProcessStackSize;

    this->threads.Push(new_thread);

    this->thread_count++;
}
