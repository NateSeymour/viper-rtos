#include <viper.h>
#include <handler.h>
#include <system/cpu/generic.h>

void vNmiHandler() {}
void vHardFaultHandler() {}
void vMemManageFaultHandler() {}
void vBusFaultHandler() {}
void vUsageFaultHandler() {}

__ALIGN(128) std::uint32_t viper::vectors[] = {
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

[[noreturn]] void viper_main()
{
    system::current_core()->BeginExecution();
}