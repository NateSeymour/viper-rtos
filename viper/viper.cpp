#include <sys/control.h>
#include <memory/allocator.h>

extern int main();

/**
 * Goals:
 * 1. Initialize heap/allocator
 * 2. Start scheduler
 * 3. Initialize coprocessor
 * 4. Start coprocessor scheduler
 * 3. Initialize main thread
 * 4. Start main thread execution
 * @return
 */
int vInitialize() {
    sys::__set_privilege_level(sys::PrivilegeLevel::kUnprivileged);
    return 0;
}