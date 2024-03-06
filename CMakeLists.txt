cmake_minimum_required(VERSION 3.27)

if(NOT DEFINED VIPER_DEVICE)
    message(WARNING "No Viper Device is set. Please set one with set(VIPER_DEVICE ...) before including Viper in your CMakeLists.txt file.")
    set(VIPER_DEVICE mps3_an524)
endif()

include(viper.cmake)
viper_init()

# Viper
project(viper_rtos ASM CXX)

add_library(viper_rtos STATIC
        viper/handler.cpp
        viper/handler.h
        viper/handler.s
        viper/viper.cpp
        viper/viper.h
        viper/memory/allocator.cpp
        viper/memory/allocator.h
        viper/std/int.h
        viper/std/mutex.cpp
        viper/std/mutex.h
        viper/std/mutex.s
        viper/std/vector.cpp
        viper/std/vector.h
        viper/std/box.h
        viper/std/memory.h
        viper/std/memory.s
        viper/interop.h
        viper/thread.h
        viper/thread.cpp
        viper/system/cpu/generic.h
        viper/system/cpu/generic.cpp
        viper/system/cpu/armv8-m/armv8-m.cpp
        viper/system/cpu/armv8-m/armv8-m.h
        viper/system/system.h
        viper/system/system.s
        viper/system/register.h
        viper/system/cpu.h
        viper/system/exception.h
        viper/system/register.cpp
        viper/build_config.in.h
)
target_include_directories(viper_rtos PUBLIC "${CMAKE_SOURCE_DIR}/viper")

# Generic Bootloader
add_library(viper_generic_bootloader
    boot/vector.s
    boot/init.s
)
viper_set_device(${VIPER_DEVICE})
