cmake_minimum_required(VERSION 3.11)
project(soft_timers-example NONE)

include_directories(src)
file(GLOB_RECURSE SOURCES src/*.S src/*.c src/*.cc src/*.h)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

set(LMCU_DEVICE "STM32F103CB")
set(LMCU_BOOT_FROM_RAM TRUE)
include(../../../../lmcu/lmcu.cmake)
add_definitions(${LMCU_DEFINITIONS})
include_directories(${LMCU_INCLUDE_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME} ${LMCU_LIBRARY})
