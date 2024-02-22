MEMORY {
    BOOT(rx) : ORIGIN = 0x00000000, LENGTH = 16K
}

SECTIONS {
    . = ORIGIN(BOOT);
    .text : {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
        . = ALIGN(LENGTH(BOOT));
    } >BOOT :NONE =0xadde
}