#include <system/device/mps3_an524/mps3_an524.h>
#include <system/register.h>
#include <system/cpu.h>

const system::ImplementationDefinedRegisters system::IDMReg = {
        .CPUID = (std::uint32_t*)0x4001F000,
};

system::ArmAn524Core system::Cpu0(0);
system::ArmAn524Core system::Cpu1(1);

const std::uint8_t system::CoreCount = 2;
system::GenericArmCore *const system::Cores[] = {&system::Cpu0, &system::Cpu1};
