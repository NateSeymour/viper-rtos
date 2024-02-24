.thumb
.section .text

.global __set_privilege_level
.type __set_privilege_level, %function
__set_privilege_level:
    MRS r1, CONTROL
    BFI r1, r0, #0, #1
    MSR CONTROL, r1
    bx lr

.global __set_psp
.type __set_psp, %function
__set_psp:
    MSR PSP, r0
    bx lr

.global __set_active_stack
.type __set_active_stack, %function
__set_active_stack:
    MRS r1, CONTROL
    BFI r1, r0, #1, #1
    MSR CONTROL, r1
    bx lr
