.thumb
.syntax unified

.global std_mutex_acquire
.type std_mutex_acquire, %function
std_mutex_acquire:
    ldrex r1, [r0, #0]
    cmp r1, #0
    bne acquire_failed

    mov r1, #1
    strex r2, r1, [r0, #0]

    cmp r2, #0
    beq acquire_succeeded

    acquire_failed:
        clrex
        mov r0, #0
        dmb
        bx lr

    acquire_succeeded:
        mov r0, #1
        dmb
        bx lr

.global std_mutex_release
.type std_mutex_release, %function
std_mutex_release:
    dmb
    mov r1, #1
    str r1, [r0, #0]
    bx lr
