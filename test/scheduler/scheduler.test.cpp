#include <thread.h>

viper::StaticallyAllocatedStack<1024> main_stack;
viper::Thread main_thread(main_stack, []() {
    // Do something
});
