cmake_minimum_required(VERSION 3.27)

### STOLEN FROM THE PICO TEAM THX ###
function(viper_add_bin_output TARGET)
    add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${TARGET}> $<IF:$<BOOL:$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>>,$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>,$<TARGET_PROPERTY:${TARGET},NAME>>.bin
            VERBATIM)
endfunction()

### Cross-Compilation ###
set(CMAKE_SYSTEM_NAME none)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(tools /opt/homebrew)
set(CMAKE_C_COMPILER ${tools}/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER ${tools}/bin/arm-none-eabi-gcc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(OBJECT_GEN_FLAGS "-O0 -ffreestanding -mthumb -fno-builtin -Wall -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs")

set(CMAKE_C_FLAGS "${OBJECT_GEN_FLAGS}")
set(CMAKE_CXX_FLAGS "${OBJECT_GEN_FLAGS}")
set(CMAKE_ASM_FLAGS "${OBJECT_GEN_FLAGS}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 99)

### Target-Specific Compilation Options ###
set(TARGET_OBJECT_GEN_FLAGS "-mcpu=cortex-m3")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TARGET_OBJECT_GEN_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_OBJECT_GEN_FLAGS}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${TARGET_OBJECT_GEN_FLAGS}")

### Linker Options ###
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/vendor/mps2-an385/mps2-an385.ld)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections -nostdlib -nostartfiles --specs=nosys.specs -mthumb -mabi=aapcs -T${LINKER_SCRIPT}")

# Viper
project(viper_rtos ASM C CXX)

add_library(viper_rtos STATIC
        viper/viper.cpp)

# Vendor Specific
add_executable(target_mps2-an385
        vendor/mps2-an385/boot.s)

viper_add_bin_output(target_mps2-an385)
