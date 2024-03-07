function(viper_init)
    ### Toolchain Options ###
    set(CMAKE_SYSTEM_NAME Generic PARENT_SCOPE)
    set(CMAKE_SYSTEM_PROCESSOR arm PARENT_SCOPE)

    set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY PARENT_SCOPE)

    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER PARENT_SCOPE)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY PARENT_SCOPE)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY PARENT_SCOPE)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY PARENT_SCOPE)

    set(CMAKE_CXX_STANDARD 20 PARENT_SCOPE)
    set(CMAKE_C_STANDARD 11 PARENT_SCOPE)
endfunction()

function(viper_target_device TARGET DEVICE)
    ### Source Directory ###
    include(${viper-rtos_SOURCE_DIR}/viper/system/device/${DEVICE}/${DEVICE}.cmake)

    ### Compiler Options ###
    set(DBG_OBJECT_GEN_FLAGS "-O0")
    set(REL_OBJECT_GEN_FLAGS "-O0")

    set(OBJECT_GEN_FLAGS "-ffreestanding -mthumb -fno-builtin -Wall -Wpedantic -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs ${DEVICE_OBJECT_GEN_FLAGS}")

    if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(OBJECT_GEN_FLAGS "${DBG_OBJECT_GEN_FLAGS} ${OBJECT_GEN_FLAGS}" PARENT_SCOPE)
    else()
        set(OBJECT_GEN_FLAGS "${REL_OBJECT_GEN_FLAGS} ${OBJECT_GEN_FLAGS}" PARENT_SCOPE)
    endif()

    # TODO: Fix issue with -fstack-protector-strong
    # set(CMAKE_CXX_FLAGS "${OBJECT_GEN_FLAGS} -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-use-cxa-atexit -fno-common" PARENT_SCOPE)
    # set(CMAKE_ASM_FLAGS "${OBJECT_GEN_FLAGS}" PARENT_SCOPE)

    target_compile_options(${TARGET} PUBLIC "${OBJECT_GEN_FLAGS} -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-use-cxa-atexit -fno-common")

    ### Linker Options ###
    set(DBG_LINKER_FLAGS "--specs=nano.specs")
    set(REL_LINKER_FLAGS "-nostdlib -nostartfiles --specs=nosys.specs")

    set(LINKER_FLAGS "-Wl,--gc-sections -mthumb -mabi=aapcs -T${VIPER_SOURCE_DIR}/viper/system/device/${DEVICE}/${DEVICE}.ld")

    if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(CMAKE_EXE_LINKER_FLAGS "${DBG_LINKER_FLAGS} ${LINKER_FLAGS}" PARENT_SCOPE)
    else()
        set(CMAKE_EXE_LINKER_FLAGS "${REL_LINKER_FLAGS} ${LINKER_FLAGS}" PARENT_SCOPE)
    endif()
endfunction()

function(viper_add_generic_bootloader TARGET)
endfunction()
