set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

cmake_minimum_required(VERSION 2.8)

project(soft_timers-example)

set(LMCU_DEVICE "STM32F103CB")
set(LMCU_BOOT_FROM_RAM TRUE)

include(../../common.cmake)
