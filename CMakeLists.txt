cmake_minimum_required(VERSION 3.27)

include(viper.cmake)
viper_init()

project(viper-rtos)

add_subdirectory(viper)
add_subdirectory(viper/system/device)
add_subdirectory(test)
add_subdirectory(boot)
