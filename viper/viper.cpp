#include <viper.h>
#include <sys/control.h>
#include <handler.h>
#include <thread.h>
#include <cpu/pe.h>

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
 * - Perform system initialization (via CPU0)
 *      - Setting VTOR
 *      - Enabling SysTick
 *      - Setting SysTick reload
 *      - Privilege De-escalation
 * - Start execution of thread_main
 * @return
 */
[[noreturn]] void vInitialize()
{
    sys::__set_vectors(vectors);
    sys::__systick_set_reload();
    sys::__systick_enable();

    sys::__set_privilege_level(sys::PrivilegeLevel::kUnprivileged);

    while(true) {
        sys::__wfi();
    }
}