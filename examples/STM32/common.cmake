enable_language(C CXX ASM)

set(GCC_PREFIX         /usr/bin)
set(GCC_TRIPLET        arm-none-eabi)
set(CMAKE_C_COMPILER   ${GCC_PREFIX}/${GCC_TRIPLET}-gcc)
set(CMAKE_CXX_COMPILER ${GCC_PREFIX}/${GCC_TRIPLET}-g++)
set(CMAKE_ASM_COMPILER ${GCC_PREFIX}/${GCC_TRIPLET}-gcc)
set(CMAKE_AR           ${GCC_PREFIX}/${GCC_TRIPLET}-ar)
set(CMAKE_RANLIB       ${GCC_PREFIX}/${GCC_TRIPLET}-ranlib)
set(CMAKE_OBJDUMP      ${GCC_PREFIX}/${GCC_TRIPLET}-objdump)
set(CMAKE_OBJCOPY      ${GCC_PREFIX}/${GCC_TRIPLET}-objcopy)
set(CMAKE_NM           ${GCC_PREFIX}/${GCC_TRIPLET}-nm)
set(CMAKE_SIZE         ${GCC_PREFIX}/${GCC_TRIPLET}-size)

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../lmcu ${CMAKE_CURRENT_BINARY_DIR}/lmcu)
add_definitions(${LMCU_DEFINITIONS})
include_directories(${LMCU_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES src/*.S src/*.c src/*.cc src/*.h)
include_directories(src)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${LMCU_LIBRARY})

add_custom_command(
  TARGET
    ${CMAKE_PROJECT_NAME}
  POST_BUILD
    COMMAND
      ${CMAKE_SIZE}
        --format=berkeley "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>"
    COMMAND
      ${CMAKE_OBJCOPY}
        -Obinary
        "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>"
        "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>.bin"
    COMMAND
      ${CMAKE_OBJCOPY}
        -Oihex
        "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>"
        "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>.hex"
    COMMAND
      ${CMAKE_OBJDUMP}
        -drwlCS "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>" > "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>.s"
)
