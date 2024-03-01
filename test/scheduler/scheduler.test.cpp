#include <system/device/mps3_an524/mps3_an524.h>
#include <thread.h>

viper::StaticallyAllocatedStack<1024> main_stack;
viper::Thread main_thread(&system::Cpu0, main_stack, []() {
    // Do something
});
