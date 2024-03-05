#include <viper.h>
#include <handler.h>
#include <system/cpu/generic.h>
#include <system/cpu.h>

void vNmiHandler() {}
void vMemManageFaultHandler() {}
void vBusFaultHandler() {}
void vUsageFaultHandler() {}

__ALIGN(128) std::uint32_t viper::vectors[] = {
    0x0,                            // MSP on RESET
    0x0,                            // RESET
    (std::uint32_t)vNmiHandler,
    (std::uint32_t)viper::hardfault_handler,
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
    for(std::uint8_t i = 0; i < system::CoreCount; i++)
    {
        system::Cores[i]->InitializeCore();
    }

    system::current_core()->BeginExecution();
}