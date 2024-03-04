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
    struct ArmMemoryMappedRegisters {};

    extern const ImplementationDefinedRegisters IDMReg;
    extern const ArmMemoryMappedRegisters MReg;
}

#endif //VIPER_RTOS_REGISTER_H
