MEMORY {
    ROM(rx) : ORIGIN = 0x00000000, LENGTH = 16K
    RAM(rwx) : ORIGIN = 0x21000000, LENGTH = 16M
}

__STACK_SIZE = 1M;

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

    . = ALIGN(0x4);
    .heap : {
        __heap_base = .;
    } >RAM

    .stack : {
        . = ORIGIN(RAM) + LENGTH(RAM) - __STACK_SIZE;
        __stack_end = ALIGN(0x8);
        . = __stack_end + __STACK_SIZE;
        __stack_top = ALIGN(0x8);
    } >RAM
}