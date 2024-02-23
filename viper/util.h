#ifndef VIPER_RTOS_UTIL_H
#define VIPER_RTOS_UTIL_H

typedef char ldsym_t;

typedef enum {
    EXECUTE_PRIVILEGED = 0,
    EXECUTE_UNPRIVILEGED = 1,
} __privilege_level_t;

typedef enum {
    STACK_MAIN = 0,
    STACK_PROCESS = 1,
} __stack_t;

extern ldsym_t __process_stack_top;

extern void __set_privilege_level(__privilege_level_t npriv);
extern void __set_psp(void *psp);
extern void __set_active_stack(__stack_t stack);

#endif //VIPER_RTOS_UTIL_H
