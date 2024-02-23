MEMORY {
    ROM(rx) : ORIGIN = 0x00000000, LENGTH = 16K
    PSRAM(rwx) : ORIGIN = 0x21000000, LENGTH = 16M
}

SECTIONS {
    . = ORIGIN(ROM);
    .text.boot : {
        KEEP(*(.vectors))
        . = ALIGN(LENGTH(ROM));
    } >ROM :NONE

    .text : {
        *(.text*)
        *(.rodata*)
    } >PSRAM

    .data : {
        *(.data*)
    } >PSRAM

    .bss : {
        *(.bss*)
        _ebss = ALIGN(0x8);
    } >PSRAM

    __heap_base = _ebss;
    __main_stack_top = ORIGIN(PSRAM) + LENGTH(PSRAM);
    __process_stack_top = __main_stack_top - 1M;
}