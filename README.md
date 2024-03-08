# Viper RTOS 

A lightweight RTOS for Cortex-M Profile Microcontrollers. It supports statically allocated threads, debugging, and includes a small standard library with implementations for synchronization primitives. 

The `C++` API makes for a clean integration into your project.

It provides abstractions for common hardware-level functions. For example:
```c++
// Set VTOR and SysTick registers
*system::MReg.VTOR = (std::uint32_t)&viper::vectors;
system::__systick_set_reload();
system::__systick_enable();
```

It also makes defining statically-allocated threads/processes easy:
```c++
viper::StaticallyAllocatedStack<1024> main_stack;
viper::Thread main_thread(&system::Cpu0, main_stack, []() {
    /* My Code */
});
```

And has optional support for dynamic memory allocations:
```c++
struct MyStruct { /* Declarations */ };
MyStruct *my_struct = (MyStruct*)GlobalAllocator.AlloateRaw(sizeof(MyStruct));

/* Do Something */

GlobalAllocator.Free(my_struct);
```

But, of course, smart pointers are preferable:

```c++
struct MyStruct { /* Declarations */ };

void main()
{
    auto my_struct = std::Box::Make<MyStruct>();
    
    /* Do Something */
} // my_struct automatically freed
```

# Project Status

This project is currently under active development. It is not stable. Some features are only partially implemented and some may not be implemented at all. `viper` is not currently suited for real-world applications.

# Supported Devices

This project targets Cortex-M Profile Microcontrollers. Below is a table of currently-supported devices:

| Device Name  | Status  | Notes                                              |
|--------------|---------|----------------------------------------------------|
| `mps3_an524` | Partial | Used only for testing in `qemu`. Not real silicon. |
| `rp2040`     | Partial | Support for Raspberry Pi's Pico devices.           |

# Using Viper

`viper` uses CMake as its build system. It is recommended that you include it in your project with via the `FetchContent` API.

```cmake
cmake_minimum_required(VERSION 3.27)

### Include Viper ###
# NOTE: Viper MUST be included before your `project` directive
# It will take care of configuring the toolchain.
# You must set -DCMAKE_C_COMPILER to the gnu arm compiler toolchain.
include(FetchContent)

FetchContent_Declare(
        viper
        GIT_REPOSITORY https://github.com/NateSeymour/viper-rtos.git
)
FetchContent_MakeAvailable(viper)

viper_init()

### Project ###
project(my_project CXX ASM)

add_executable(my_project main.cpp)

# Simply link against your chosen device
target_link_libraries(my_project PUBLIC viper-rp2040)
```
