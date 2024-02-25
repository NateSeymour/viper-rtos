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

set(OBJECT_GEN_FLAGS "-O0 -ffreestanding -mthumb -fno-builtin -Wall -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -mcpu=cortex-m33")

set(CMAKE_CXX_FLAGS "${OBJECT_GEN_FLAGS} -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-use-cxa-atexit -fstack-protector-strong -fno-common")
set(CMAKE_ASM_FLAGS "${OBJECT_GEN_FLAGS}")

set(CMAKE_CXX_STANDARD 14)

### Linker Options ###
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/application.ld)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections -nostdlib -nostartfiles --specs=nosys.specs -mthumb -mabi=aapcs -T${LINKER_SCRIPT}")

# Viper
project(viper_rtos ASM CXX)

add_library(viper_rtos STATIC
        viper/viper.cpp
        viper/viper.h
        viper/sys/control.h
        viper/sys/control.s
        viper/std/int.h
        viper/memory/allocator.cpp
        viper/memory/allocator.h
        viper/sys/link.h
)
target_include_directories(viper_rtos PUBLIC "${CMAKE_SOURCE_DIR}/viper")

# Bootloader
add_executable(bootloader
        boot/vector.s
        boot/init.s)
target_link_libraries(bootloader PUBLIC viper_rtos)
