.thumb
.syntax unified

.global svcall_entry
.type svcall_entry, %function
svcall_entry:
    // Determine whether we were using MSP or PSP by looking at EXC_RETURN token
    tst lr, #4
    ite eq
    mrseq r1, MSP
    mrsne r1, PSP

    // Get SVC number from opcode
    ldr r3, [r1, #24] // Return address
    sub r3, #2
    ldrh r0, [r3]

    // void svcall_handler(viper::SVCall svc_number, system::ExceptionContext *context);
    b svcall_handler
