### Target-Specific Compilation Options ###
set(TARGET_OBJECT_GEN_FLAGS "-mcpu=cortex-m3")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TARGET_OBJECT_GEN_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_OBJECT_GEN_FLAGS}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${TARGET_OBJECT_GEN_FLAGS}")

### Linker Options ###
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/vendor/mps2_an385/mps2_an385.ld)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections -nostdlib -nostartfiles --specs=nosys.specs -mthumb -mabi=aapcs -T${LINKER_SCRIPT}")