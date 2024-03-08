cmake_minimum_required(VERSION 3.27)

project(viper ASM CXX)

add_library(viper-intermediate-interface INTERFACE)
target_include_directories(viper-intermediate-interface INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

### Viper ###
add_library(viper STATIC
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
target_include_directories(viper PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

### Devices ###
function(viper_create_device DEVICE CPU)
    add_library(viper-${DEVICE}-build-interface INTERFACE)
    target_link_options(viper-${DEVICE}-build-interface INTERFACE
            -T${CMAKE_CURRENT_SOURCE_DIR}/system/device/${DEVICE}/${DEVICE}.ld
            -mcpu=${CPU}
    )
    target_compile_options(viper-${DEVICE}-build-interface INTERFACE
            -mcpu=${CPU}
    )

    add_library(viper-${DEVICE} STATIC)

    target_link_libraries(viper-${DEVICE} PUBLIC $<BUILD_INTERFACE:viper-common-build-interface> $<BUILD_INTERFACE:viper-${DEVICE}-build-interface>)
    target_include_directories(viper-${DEVICE} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
endfunction()

viper_create_device(mps3_an524 cortex-m33)
target_sources(viper-mps3_an524 PUBLIC
        system/device/mps3_an524/mps3_an524.cpp
        system/device/mps3_an524/mps3_an524.h
)

viper_create_device(rp2040 cortex-m0plus)
target_sources(viper-rp2040 PUBLIC
        system/device/rp2040/rp2040.cpp
        system/device/rp2040/rp2040.h
)

target_link_libraries(viper PUBLIC viper-${VIPER_DEVICE})
