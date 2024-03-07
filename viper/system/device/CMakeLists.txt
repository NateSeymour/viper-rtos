cmake_minimum_required(VERSION 3.27)

project(viper-device ASM CXX)

function(viper_create_device DEVICE CPU)
    message(${CMAKE_CURRENT_SOURCE_DIR})
    get_target_property(VIPER_SOURCES viper SOURCES)
    list(TRANSFORM VIPER_SOURCES PREPEND "${viper_SOURCE_DIR}/")

    add_library(viper-${DEVICE} STATIC ${VIPER_SOURCES})
    target_include_directories(viper-mps3_an524 PUBLIC "${viper_SOURCE_DIR}")
    target_link_options(viper-${DEVICE} PUBLIC
            -T${viper-device_SOURCE_DIR}/${DEVICE}/${DEVICE}.ld
            -Wl,--gc-sections
            -mthumb
            -mabi=aapcs
            -mcpu=${CPU}
    )
    target_compile_options(viper-${DEVICE} PUBLIC
            -mcpu=${CPU}
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
endfunction()

viper_create_device(mps3_an524 cortex-m55)
target_sources(viper-mps3_an524 PUBLIC
        mps3_an524/mps3_an524.cpp
        mps3_an524/mps3_an524.h
)

viper_create_device(rp2040 cortex-m0plus)
target_sources(viper-rp2040 PUBLIC
        rp2040/rp2040.cpp
        rp2040/rp2040.h
)
