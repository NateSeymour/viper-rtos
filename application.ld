MEMORY {
    ROM(rx) : ORIGIN = 0x00000000, LENGTH = 16K
    RAM(rwx) : ORIGIN = 0x21000000, LENGTH = 16M
}

__STACK_SIZE = 1M;
__HEAP_BLOCK_SIZE = 1K;

SECTIONS {
    . = ORIGIN(ROM);
    .text : {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
        . = ALIGN(LENGTH(ROM));
    } >ROM

    .data : {
        *(.data*)
    } >RAM

    . = ALIGN(0x4);
    .init_array : {
        __init_array_start = .;
        KEEP(*(.init_array*))
        __init_array_end = .;
    } >RAM

    .bss : {
        *(.bss*)
        _ebss = ALIGN(0x8);
    } >RAM

    . = ALIGN(__HEAP_BLOCK_SIZE);
    .heap : {
        __heap_base = .;
        __heap_top = ORIGIN(RAM) + LENGTH(RAM) - __STACK_SIZE;
    } >RAM

    .stack : {
        . = __heap_top;
        __stack_end = ALIGN(0x8);
        . = __stack_end + __STACK_SIZE;
        __stack_top = ALIGN(0x8);
    } >RAM
}