#ifndef VIPER_RTOS_SYSTEM_H
#define VIPER_RTOS_SYSTEM_H

#include <std/int.h>
#include <interop.h>

namespace system
{
    constexpr std::uint32_t kSysTickMax = 0xFFFFFF;

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

    __EXTSYM(std::byte*) __stack_top;
    __EXTSYM(std::byte*) __stack_end;
    __EXTSYM(std::byte*) __heap_base;
    __EXTSYM(std::byte*) __heap_top;

    __EXTSYM(std::uint32_t*) __HEAP_BLOCK_SIZE;

    __STDCALL void __set_privilege_level(PrivilegeLevel npriv);
    __STDCALL PrivilegeLevel __get_privilege_level();
    __STDCALL void __set_psp(void *psp);
    __STDCALL void __set_active_stack(StackType stack);
    __STDCALL void __set_vectors(std::uint32_t *vectors);

    __STDCALL void __systick_enable();
    __STDCALL void __systick_set_reload(std::uint32_t reload = kSysTickMax);

    __STDCALL void __wfi();
}

#endif //VIPER_RTOS_SYSTEM_H
