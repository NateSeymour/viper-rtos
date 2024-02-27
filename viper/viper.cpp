#include <viper.h>
#include <sys/control.h>
#include <handler.h>

extern void main();

void vNmiHandler() {}
void vHardFaultHandler() {}
void vMemManageFaultHandler() {}
void vBusFaultHandler() {}
void vUsageFaultHandler() {}

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
    (std::uint32_t)viper::svcall_entry,
    0x0,                            // DebugMonitor
    0x0,                            // Reserved
    (std::uint32_t)viper::pendsv_handler,
    (std::uint32_t)viper::systick_handler,
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
    sys::__systick_set_reload();
    sys::__systick_enable();

    sys::__set_privilege_level(sys::PrivilegeLevel::kUnprivileged);

    viper::start_thread(main);

    while(1) {}
}