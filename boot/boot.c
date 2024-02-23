extern int vInitialize();

void __reset()
{
    vInitialize();
}

void __hang()
{
    __asm__("BKPT");
}