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

    __STDCALL void __set_privilege_level(PrivilegeLevel npriv);
    __STDCALL PrivilegeLevel __get_privilege_level();
    __STDCALL void __set_psp(void *psp);
    __STDCALL void __set_active_stack(StackType stack);
}

#endif //VIPER_RTOS_CONTROL_H