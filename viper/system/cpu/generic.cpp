#include <system/cpu/generic.h>
#include <system/register.h>
#include <system/cpu.h>
#include <system/system.h>
#include <viper.h>

system::GenericArmCore *system::current_core()
{
    std::uint32_t cpu_id = *system::IDMReg.CPUID;
    return system::Cores[cpu_id];
}

void system::GenericArmCore::RegisterThread(viper::Thread *thread)
{
    this->threads[thread_count++] = thread;
}

void system::GenericArmCore::BeginExecution()
{
    viper::Thread *active_thread = this->threads[active_thread_index];

    // TODO: Fix bug where we rely on GenericArmCore to be constructed
    // TODO: Fix bug where local vars are no longer on stack

    system::__set_psp(active_thread->sp);
    system::__set_active_stack(system::StackType::kProcess);

    // TODO: Perform stack limit checking

    system::__set_privilege_level(system::PrivilegeLevel::kUnprivileged);

    active_thread->subroutine();

    /*
     * If subroutine ends up returning, we want to go into this low-power state
     * and let the system wait for an interrupt/exception to continue
     */
    while(true) {
        system::__wfi();
    }
}

void system::GenericArmCore::InitializeCore()
{
    if(system::current_core() != this) return;

    *system::MReg.VTOR = (std::uint32_t)&viper::vectors;
    system::__systick_set_reload();
    system::__systick_enable();
}
