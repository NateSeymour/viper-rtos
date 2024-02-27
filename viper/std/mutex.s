.thumb
.syntax unified

.global std_mutex_acquire
.type std_mutex_acquire, %function
std_mutex_acquire:
    ldrex r1, [r0, #0]
    cmp r1, #0
    itte eq
    moveq r1, #1
    strexeq r0, r1, [r0, #0]
    movne r0, #0
    dmb
    bx lr

.global std_mutex_release
.type std_mutex_release, %function
std_mutex_release:
    ldrex r1, [r0, #0]
    cmp r1, #0
    itte eq
    moveq r1, #1
    strexeq r0, r1, [r0, #0]
    movne r0, #0
    dmb
    bx lr
