#ifndef VIPER_RTOS_CONTROL_H
#define VIPER_RTOS_CONTROL_H

#include <viper.h>
#include <std/int.h>

namespace sys
{
    enum class PrivilegeLevel : std::uint32_t
    {
        kPrivileged = 0,
        kUnprivileged = 1,
    };

    enum class StackType : std::uint32_t
    {
        kMain = 0,
        kProcess = 1,
    };

    constexpr std::uint32_t kSysTickMax = 0xFFFFFF;

    __STDCALL void __set_privilege_level(PrivilegeLevel npriv);
    __STDCALL PrivilegeLevel __get_privilege_level();
    __STDCALL void __set_psp(void *psp);
    __STDCALL void __set_active_stack(StackType stack);
    __STDCALL void __set_vectors(std::uint32_t *vectors);

    __STDCALL void __systick_enable();
    __STDCALL void __systick_set_reload(std::uint32_t reload = kSysTickMax);
}

#endif //VIPER_RTOS_CONTROL_H
