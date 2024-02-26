#include <sys/control.h>
#include <scheduler.h>
#include <handler.h>

extern void main();

void vNmiHandler() {}
void vHardFaultHandler() {}
void vMemManageFaultHandler() {}
void vBusFaultHandler() {}
void vUsageFaultHandler() {}
void vPendSVHandler() {}
void vSysTickHandler() {}

__ALIGN(128) std::uint32_t vectors[] = {
    0x0,                            // MSP on RESET
    0x0,                            // RESET
    (std::uint32_t)vNmiHandler,
    (std::uint32_t)vHardFaultHandler,
    (std::uint32_t)vMemManageFaultHandler,
    (std::uint32_t)vBusFaultHandler,
    (std::uint32_t)vUsageFaultHandler,
    0x0,                            // SecureFault
    0x0,                            // Reserved
    0x0,                            // Reserved
    0x0,                            // Reserved
    (std::uint32_t)viper::svcall_handler,
    0x0,                            // DebugMonitor
    0x0,                            // Reserved
    (std::uint32_t)vPendSVHandler,
    (std::uint32_t)vSysTickHandler,
};

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
    sys::__set_vectors(vectors);
    sys::__set_systick_reload();
    sys::__systick_enable();

    sys::__set_privilege_level(sys::PrivilegeLevel::kUnprivileged);

    viper::run(main);

    while(1) {}
}