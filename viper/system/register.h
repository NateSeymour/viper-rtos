#ifndef VIPER_RTOS_REGISTER_H
#define VIPER_RTOS_REGISTER_H

#include <std/int.h>

namespace system
{
    /**
     * Commonly-defined registers in the Arm ecosystem that
     * can vary between different silicon vendors. These
     * should be defined in the implementation's device
     * header.
     */
    struct ImplementationDefinedRegisters
    {
        std::uint32_t *CPUID = nullptr;
    };

    /**
     * Memory-mapped registers that are constant and documented
     * in the Arm architecture. These are only registers that are
     * common from Armv6-M to Armv8-M. Registers specific to any
     * architecture version should be placed in cpu/<arch>.
     */
    struct ArmMemoryMappedRegisters
    {
        // SysTick
        std::uint32_t *SYST_CALIB = (std::uint32_t*)0xE000E01C;
        std::uint32_t *SYST_CSR   = (std::uint32_t*)0xE000E010;
        std::uint32_t *SYST_CVR   = (std::uint32_t*)0xE000E018;
        std::uint32_t *SYST_RVR   = (std::uint32_t*)0xE000E014;

        std::uint32_t *VTOR = (std::uint32_t*)0xE000ED08;
    };

    extern const ImplementationDefinedRegisters IDMReg;
    extern const ArmMemoryMappedRegisters MReg;
}

#endif //VIPER_RTOS_REGISTER_H
