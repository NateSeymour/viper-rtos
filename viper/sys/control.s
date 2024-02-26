.thumb
.syntax unified
.section .text

.global __set_privilege_level
.type __set_privilege_level, %function
__set_privilege_level:
    mrs r1, CONTROL
    bfi r1, r0, #0, #1
    msr CONTROL, r1
    bx lr

.global __get_privilege_level
.type __get_privilege_level, %function
__get_privilege_level:
    mrs r0, CONTROL
    and r0, #1
    bx lr

.global __set_psp
.type __set_psp, %function
__set_psp:
    msr PSP, r0
    bx lr

.global __set_active_stack
.type __set_active_stack, %function
__set_active_stack:
    mrs r1, CONTROL
    bfi r1, r0, #1, #1
    msr CONTROL, r1
    bx lr

.global __systick_enable
.type __systick_enable, %function
// __STDCALL void __systick_enable();
__systick_enable:
    // Set CLKSOURCE[2], TICKINT[1], ENABLE[0] (7 == 0b111)
    ldr r1, =#0xE000E010 // SYST_CSR
    ldr r0, [r1]
    orr r0, #7
    str r0, [r1]
    dmb

    bx lr

.global __systick_set_reload
.type __systick_set_reload, %function
// __STDCALL void __set_systick_reload(std::uint32_t reload = kSysTickMax);
__systick_set_reload:
    ldr r1, =#0xE000E014 // SYST_RVR
    str r0, [r1]
    dmb

    bx lr

.global __set_vectors
.type __set_vectors, %function
// __STDCALL void __set_vectors(std::uint32_t *vectors);
__set_vectors:
    ldr r1, =#0xE000ED08
    str r0, [r1]
    dmb

    bx lr