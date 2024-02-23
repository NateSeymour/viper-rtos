#include "util.h"

/**
 * Goals:
 * 1. Initialize heap/allocator
 * 2. Initialize MCU
 * 3. Initialize PSP
 * 4. Leave privileged mode
 * @return
 */
int vInitialize() {
    __set_psp(&__process_stack_top);
    __set_active_stack(STACK_PROCESS);
    __set_privilege_level(EXECUTE_UNPRIVILEGED);
    return 0;
}