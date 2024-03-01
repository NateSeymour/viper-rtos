#ifndef VIPER_RTOS_MPS3_AN524_H
#define VIPER_RTOS_MPS3_AN524_H

#include <cpu/pe.h>

namespace system
{
    class ArmAn524Core : public viper::GenericArmCore
    {
    public:
        explicit ArmAn524Core(const std::uint8_t cpu_id) : viper::GenericArmCore(cpu_id) {}
    };

    extern ArmAn524Core Cpu0;
    extern ArmAn524Core Cpu1;
}

#endif //VIPER_RTOS_MPS3_AN524_H
