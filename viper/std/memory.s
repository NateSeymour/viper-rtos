.thumb
.syntax unified

.global memset
.type memset,%function
// void std::memset(std::byte *origin, std::byte value, std::size_t count);
memset:
    mov r3, #0
    copy:
        cmp r3, r2
        it ge
        bxge lr

        strb r1, [r0, r3]
        add r3, #1
        b copy
