#include <sys/control.h>
#include <memory/allocator.h>

/**
 * Goals:
 * 1. Initialize heap/allocator
 * 2. Start scheduler
 * 3. Start main thread
 * 2. Initialize MCU
 * 3. Initialize PSP
 * 4. Leave privileged mode
 * @return
 */
int vInitialize() {
    viper::GlobalAllocator.Allocate(1);

    sys::__set_privilege_level(sys::PrivilegeLevel::kUnprivileged);
    return 0;
}