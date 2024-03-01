#include <device/mps3_an524/mps3_an524.h>

const system::ImplementationDefinedRegisters IDMReg = {
        .CPUID = (std::uint32_t*)0x4001F000,
};

system::ArmAn524Core system::Cpu0(0);
system::ArmAn524Core system::Cpu1(1);

viper::GenericArmCore *viper::SystemCores[] = {&system::Cpu0, &system::Cpu1};

