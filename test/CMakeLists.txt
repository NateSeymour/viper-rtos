cmake_minimum_required(VERSION 3.27)

project(viper-test CXX ASM)

add_executable(viper-test-scheduler
        scheduler/scheduler.test.cpp
)
target_link_libraries(viper-test-scheduler PUBLIC viper-boot)
