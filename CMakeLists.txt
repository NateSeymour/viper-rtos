cmake_minimum_required(VERSION 3.27)

### Cross-Compilation ###
set(CMAKE_SYSTEM_NAME none)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

### Compiler Options ###
set(DBG_OBJECT_GEN_FLAGS "-O0")
set(REL_OBJECT_GEN_FLAGS "-O0")

set(OBJECT_GEN_FLAGS "-ffreestanding -mthumb -fno-builtin -Wall -Wpedantic -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -mcpu=cortex-m55")

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(OBJECT_GEN_FLAGS "${DBG_OBJECT_GEN_FLAGS} ${OBJECT_GEN_FLAGS}")
else()
    set(OBJECT_GEN_FLAGS "${REL_OBJECT_GEN_FLAGS} ${OBJECT_GEN_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "${OBJECT_GEN_FLAGS} -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-use-cxa-atexit -fno-common")
set(CMAKE_ASM_FLAGS "${OBJECT_GEN_FLAGS}")

### Linker Options ###
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/viper.ld)

set(DBG_LINKER_FLAGS "--specs=nano.specs")
set(REL_LINKER_FLAGS "-nostdlib -nostartfiles --specs=nosys.specs")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections -mthumb -mabi=aapcs -T${LINKER_SCRIPT}")

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(CMAKE_EXE_LINKER_FLAGS "${DBG_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS}")
    message(${CMAKE_EXE_LINKER_FLAGS})
else()
    set(CMAKE_EXE_LINKER_FLAGS "${REL_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS}")
endif()

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
        viper/system/device/mps3_an524/mps3_an524.h
        viper/system/device/mps3_an524/mps3_an534.cpp
        viper/system/system.h
        viper/system/system.s
        viper/system/register.h
        viper/system/cpu.h
        viper/system/exception.h
        viper/system/register.cpp
        viper/build_config.in.h
)
target_include_directories(viper_rtos PUBLIC "${CMAKE_SOURCE_DIR}/viper")

# Tests
add_executable(viper_rtos-test-scheduler
        boot/vector.s
        boot/init.s
        test/scheduler/scheduler.test.cpp
)
target_link_libraries(viper_rtos-test-scheduler PUBLIC viper_rtos)

add_executable(viper_rtos-test-std-vector
        boot/vector.s
        boot/init.s
        test/std/vector.test.cpp)
target_link_libraries(viper_rtos-test-std-vector PUBLIC viper_rtos)