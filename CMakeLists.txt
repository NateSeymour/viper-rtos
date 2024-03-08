cmake_minimum_required(VERSION 3.27)

include(viper.cmake)
viper_init(mps3_an524)

project(viper-rtos)

add_library(viper-common-build-interface INTERFACE)
target_compile_options(viper-common-build-interface INTERFACE
        -g
        -std=c++20
        -ffreestanding
        -mthumb
        -fno-builtin
        -Wall
        -Wpedantic
        -ffunction-sections
        -fdata-sections
        -fomit-frame-pointer
        -mabi=aapcs
        -fno-exceptions
        -fno-non-call-exceptions
        -fno-rtti
        -fno-use-cxa-atexit
        -fno-common
)
target_link_options(viper-common-build-interface INTERFACE
        -Wl,--gc-sections
        -mthumb
        -mabi=aapcs
)

add_subdirectory(viper)
add_subdirectory(boot)
add_subdirectory(test)
