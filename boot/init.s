.thumb
.syntax unified
.section .text

.global __reset
.type __reset, %function
__reset:
    bl __runtime_init
    bl viper_main

.global __hang
.type __hang, %function
__hang:
    bkpt

__runtime_init:
    push {r4-r6, lr}
    ldr r4, =__init_array_start
    ldr r5, =__init_array_end

    loop:
        cmp r4, r5
        ldr r6, [r4], #4
        ldr lr, =loop
        orr lr, #1
        it ne
        bxne r6

    pop {r4-r6, lr}
    bx lr
