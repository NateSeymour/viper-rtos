cmake_minimum_required(VERSION 3.27)

project(viper-boot ASM)

add_library(viper-boot
        vector.s
        init.s
)
target_link_libraries(viper-boot PUBLIC viper)
