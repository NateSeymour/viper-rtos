cmake_minimum_required(VERSION 3.27)

### Cross-Compilation ###
set(CMAKE_SYSTEM_NAME none)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(tools /opt/homebrew)
set(CMAKE_C_COMPILER ${tools}/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-none-eabi-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(OBJECT_GEN_FLAGS "-O0 -ffreestanding -mthumb -fno-builtin -Wall -Wpedantic -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -mcpu=cortex-m55")

set(CMAKE_CXX_FLAGS "${OBJECT_GEN_FLAGS} -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-use-cxa-atexit -fstack-protector-strong -fno-common")
set(CMAKE_ASM_FLAGS "${OBJECT_GEN_FLAGS}")

set(CMAKE_CXX_STANDARD 20)

### Linker Options ###
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/viper.ld)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections -nostdlib -nostartfiles --specs=nosys.specs -mthumb -mabi=aapcs -T${LINKER_SCRIPT}")

# Viper
project(viper_rtos ASM CXX)

add_library(viper_rtos STATIC
        viper/handler.cpp
        viper/handler.h
        viper/handler.s
        viper/viper.cpp
        viper/viper.h
        viper/sys/control.h
        viper/sys/control.s
        viper/sys/exception.h
        viper/std/int.h
        viper/memory/allocator.cpp
        viper/memory/allocator.h
        viper/sys/link.h
        viper/scheduler.cpp
        viper/scheduler.h
        viper/std/mutex.cpp
        viper/std/mutex.h
        viper/std/mutex.s
        viper/std/vector.cpp
        viper/std/vector.h
        viper/std/box.h
        viper/std/memory.h
        viper/std/memory.s
        viper/thread.h
        viper/interop.h
        viper/thread.cpp
        viper/device/mps3_an524/mps3_an524.h
        viper/cpu/pe.cpp
        viper/cpu/pe.h
        viper/cpu/armv8-m/armv8-m.cpp
        viper/cpu/armv8-m/armv8-m.h
        viper/device/mps3_an524/mps3_an534.cpp
)
target_include_directories(viper_rtos PUBLIC "${CMAKE_SOURCE_DIR}/viper")

# Tests
add_executable(viper_rtos-test-scheduler
        boot/vector.s
        boot/init.s
        test/scheduler/scheduler.test.cpp
        test/scheduler/scheduler.test.h)
target_link_libraries(viper_rtos-test-scheduler PUBLIC viper_rtos)

add_executable(viper_rtos-test-std-vector
        boot/vector.s
        boot/init.s
        test/std/vector.test.cpp)
target_link_libraries(viper_rtos-test-std-vector PUBLIC viper_rtos)