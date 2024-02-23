.thumb
.section .vectors
.global __vectors
.word __main_stack_top // MSP
.word __reset // Reset
.word __hang // NMI
.word __hang // HardFault
