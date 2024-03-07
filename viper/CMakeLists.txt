cmake_minimum_required(VERSION 3.27)

project(viper ASM CXX)

add_library(viper INTERFACE
        handler.cpp
        handler.h
        handler.s
        viper.cpp
        viper.h
        memory/allocator.cpp
        memory/allocator.h
        std/int.h
        std/mutex.cpp
        std/mutex.h
        std/mutex.s
        std/vector.cpp
        std/vector.h
        std/box.h
        std/memory.h
        std/memory.s
        interop.h
        thread.h
        thread.cpp
        system/cpu/generic.h
        system/cpu/generic.cpp
        system/cpu/armv8-m/armv8-m.cpp
        system/cpu/armv8-m/armv8-m.h
        system/system.h
        system/system.s
        system/register.h
        system/cpu.h
        system/exception.h
        system/register.cpp
        build_config.in.h
)
