#ifndef VIPER_RTOS_VIPER_H
#define VIPER_RTOS_VIPER_H

#define __STDCALL extern "C"
#define __ALIGN(alignment) __attribute__((aligned(alignment)))

__STDCALL int vInitialize();

#endif //VIPER_RTOS_VIPER_H
