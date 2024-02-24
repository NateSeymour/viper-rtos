#include <sys/control.h>
#include <std/int.h>

struct X {
    std::uint32_t var;

    X() {
        this->var = 100;
    }
    ~X() = default;
};

X global_x;

/**
 * Goals:
 * 1. Initialize heap/allocator
 * 2. Initialize MCU
 * 3. Initialize PSP
 * 4. Leave privileged mode
 * @return
 */
int vInitialize() {
    //__set_psp(&__process_stack_top);
    sys::__set_active_stack(sys::StackType::kProcess);
    sys::__set_privilege_level(sys::PrivilegeLevel::kUnprivileged);
    return 0;
}