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
