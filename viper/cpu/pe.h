#ifndef VIPER_RTOS_PE_H
#define VIPER_RTOS_PE_H

#include <std/int.h>

namespace system
{
    struct ImplementationDefinedRegisters
    {
        std::uint32_t *CPUID = nullptr;
    };

    struct ArmMemoryMappedRegisters
    {
    };

    extern const ImplementationDefinedRegisters IDMreg;
    const ArmMemoryMappedRegisters MReg;
}

namespace viper
{
    class GenericArmCore
    {
    protected:
        const std::uint8_t cpu_id;
    public:
        explicit GenericArmCore(std::uint8_t cpu_id) : cpu_id(cpu_id) {}
    };

    extern GenericArmCore *SystemCores[];
}

#endif //VIPER_RTOS_PE_H
