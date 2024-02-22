.cpu cortex-m3
.thumb
.section .vectors

.global __vectors
.word 0xadde // MSP
.word 0xadde // Reset
.word 0xadde // NMI
.word 0xadde // HardFault