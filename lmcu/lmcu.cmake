set(CMAKE_SYSTEM_NAME Generic)

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

if(NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug" AND NOT ${CMAKE_BUILD_TYPE} STREQUAL "Release")
  message(FATAL_ERROR "Unsupported build type '${CMAKE_BUILD_TYPE}'! Must be 'Debug' or 'Release'.")
endif()

set(GCC_TRIPLET arm-none-eabi)

if(EXISTS "/usr/bin/${GCC_TRIPLET}-gcc")
  set(GCC_PREFIX /usr/bin)
else()
  set(GCC_PREFIX /usr/local/bin)
endif()

set(CMAKE_C_COMPILER   ${GCC_PREFIX}/${GCC_TRIPLET}-gcc)
set(CMAKE_CXX_COMPILER ${GCC_PREFIX}/${GCC_TRIPLET}-g++)
set(CMAKE_ASM_COMPILER ${GCC_PREFIX}/${GCC_TRIPLET}-gcc)
set(CMAKE_AR           ${GCC_PREFIX}/${GCC_TRIPLET}-ar)
set(CMAKE_RANLIB       ${GCC_PREFIX}/${GCC_TRIPLET}-ranlib)
set(CMAKE_OBJDUMP      ${GCC_PREFIX}/${GCC_TRIPLET}-objdump)
set(CMAKE_OBJCOPY      ${GCC_PREFIX}/${GCC_TRIPLET}-objcopy)
set(CMAKE_NM           ${GCC_PREFIX}/${GCC_TRIPLET}-nm)
set(CMAKE_SIZE         ${GCC_PREFIX}/${GCC_TRIPLET}-size)

set(LMCU_C_FLAGS
"\
-g \
-fno-builtin \
-fdata-sections \
-ffunction-sections \
-fomit-frame-pointer \
-fno-common \
-fno-dwarf2-cfi-asm \
-fno-exceptions \
-fno-unwind-tables \
-Wall \
-Wextra \
-pedantic \
-fstack-usage \
${LMCU_C_FLAGS} \
")

set(CORTEX_M0_C_FLAGS
"\
-mcpu=cortex-m0 \
-march=armv6-m \
-mthumb \
-mlittle-endian \
-mfpu=vfp \
-mfloat-abi=soft \
${LMCU_C_FLAGS} \
")

set(CORTEX_M3_C_FLAGS
"\
-mcpu=cortex-m3 \
-march=armv7-m \
-mthumb \
-mlittle-endian \
-mfloat-abi=soft -mfpu=vfp \
-mfix-cortex-m3-ldrd \
${LMCU_C_FLAGS} \
")

set(CORTEX_M4_C_FLAGS
"\
-mcpu=cortex-m4 \
-march=armv7e-m \
-mthumb \
-mlittle-endian \
-mfloat-abi=hard -mfpu=fpv4-sp-d16 \
${LMCU_C_FLAGS} \
")

set(LMCU_LD_FLAGS
"\
-Wl,-O1 \
-Wl,--gc-sections \
--specs=nosys.specs \
--specs=nano.specs \
${LMCU_LD_FLAGS} \
")

set(LMCU_DIR "${CMAKE_CURRENT_LIST_DIR}")

if(LMCU_BOOT_FROM_RAM)
  set(LD_POSTFIX "RAM")
else()
  set(LD_POSTFIX "FLASH")
endif()

set(SUPPORTED_DEVICE FALSE)

string(TOUPPER "${LMCU_DEVICE}" LMCU_DEVICE)

string(SUBSTRING "${LMCU_DEVICE}" 0 5 DEVICE_SIG)
if("${DEVICE_SIG}" STREQUAL "STM32")
  set(DEVICE_FAMILY STM32)
  string(SUBSTRING "${LMCU_DEVICE}" 0  7  DEVICE_SERIES)
  string(SUBSTRING "${LMCU_DEVICE}" 0  9  DEVICE_NAME_0)
  string(SUBSTRING "${LMCU_DEVICE}" 0  10 DEVICE_NAME_1)
  string(SUBSTRING "${LMCU_DEVICE}" 0  11 DEVICE_NAME_2)
  string(SUBSTRING "${LMCU_DEVICE}" 5  2  DEVICE_TYPE)
  string(SUBSTRING "${LMCU_DEVICE}" 10 1  DEVICE_FLASH)

  if("${DEVICE_SERIES}" STREQUAL "STM32F1")
    set(CORTEX "M3")
    set(LMCU_C_FLAGS "${CORTEX_M3_C_FLAGS}")
    set(LD_DIR "${LMCU_DIR}/lib/ld/cortex-m3")
  elseif("${DEVICE_SERIES}" STREQUAL "STM32F4")
    set(CORTEX "M4")
    set(LMCU_C_FLAGS "${CORTEX_M4_C_FLAGS}")
    set(LD_DIR "${LMCU_DIR}/lib/ld/cortex-m4")
  endif()

  set(LMCU_DEFINITIONS
    -DLMCU_CORTEX
    -DLMCU_CORTEX_${CORTEX}
    -DLMCU_${DEVICE_FAMILY}
    -DLMCU_${DEVICE_SERIES}
    -DLMCU_${DEVICE_NAME_0}
    -DLMCU_${DEVICE_NAME_1}
    -DLMCU_${DEVICE_NAME_2}
  CACHE INTERNAL "")

  if(NOT LMCU_LD_SCRIPT)
    set(LMCU_LD_SCRIPT "${LD_DIR}/${DEVICE_NAME_0}x${DEVICE_FLASH}_${LD_POSTFIX}.ld")
  endif()

  set(SUPPORTED_DEVICE TRUE)
endif()

string(SUBSTRING "${LMCU_DEVICE}" 0 3 DEVICE_SIG)
if("${DEVICE_SIG}" STREQUAL "M48")
  set(DEVICE_FAMILY M480)
  string(SUBSTRING "${LMCU_DEVICE}" 0  4  DEVICE_SERIES)
  string(SUBSTRING "${LMCU_DEVICE}" 0  7  DEVICE_NAME_0)
  string(SUBSTRING "${LMCU_DEVICE}" 4  1  DEVICE_PACKAGE)
  string(SUBSTRING "${LMCU_DEVICE}" 5  1  DEVICE_FLASH)
  string(SUBSTRING "${LMCU_DEVICE}" 6  1  DEVICE_SRAM)
  string(SUBSTRING "${LMCU_DEVICE}" 7  1  DEVICE_REVISION)
  string(SUBSTRING "${LMCU_DEVICE}" 8  1  DEVICE_PERIPH)

  set(CORTEX "M4")
  set(LMCU_C_FLAGS "${CORTEX_M4_C_FLAGS}")
  set(LD_DIR "${LMCU_DIR}/lib/ld/cortex-m4")

  set(LMCU_DEFINITIONS
    -DLMCU_CORTEX
    -DLMCU_CORTEX_${CORTEX}
    -DLMCU_${DEVICE_FAMILY}
    -DLMCU_${DEVICE_SERIES}
    -DLMCU_${DEVICE_NAME_0}
  CACHE INTERNAL "")

  if(NOT LMCU_LD_SCRIPT)
    set(LMCU_LD_SCRIPT "${LD_DIR}/${DEVICE_FAMILY}x${DEVICE_FLASH}${DEVICE_SRAM}xxxx_${LD_POSTFIX}.ld")
  endif()

  set(SUPPORTED_DEVICE TRUE)
endif()

string(SUBSTRING "${LMCU_DEVICE}" 0 6 DEVICE_SIG)
if("${DEVICE_SIG}" STREQUAL "NUC131")
  set(DEVICE_FAMILY NUC131)
  string(SUBSTRING "${LMCU_DEVICE}" 7 1  DEVICE_FLASH)
  string(SUBSTRING "${LMCU_DEVICE}" 0 11 DEVICE_NAME_0)

  set(CORTEX "M0")
  set(LMCU_C_FLAGS "${CORTEX_M0_C_FLAGS}")
  set(LD_DIR "${LMCU_DIR}/lib/ld/cortex-m0")

  set(LMCU_DEFINITIONS
    -DLMCU_CORTEX
    -DLMCU_CORTEX_${CORTEX}
    -DLMCU_${DEVICE_FAMILY}
    -DLMCU_${DEVICE_NAME_0}
  CACHE INTERNAL "")

  if(NOT LMCU_LD_SCRIPT)
    set(LMCU_LD_SCRIPT "${LD_DIR}/${DEVICE_FAMILY}x${DEVICE_FLASH}xxx_${LD_POSTFIX}.ld")
  endif()

  set(SUPPORTED_DEVICE TRUE)
endif()

string(SUBSTRING "${LMCU_DEVICE}" 0 4 DEVICE_SIG)
if("${DEVICE_SIG}" STREQUAL "MG32")
  set(DEVICE_FAMILY MG32)
  string(SUBSTRING "${LMCU_DEVICE}" 0  6  DEVICE_SERIES)

  if("${DEVICE_SERIES}" STREQUAL "MG32F0")
    string(SUBSTRING "${LMCU_DEVICE}" 5 2  DEVICE_FAMILY)
    string(SUBSTRING "${LMCU_DEVICE}" 0 15 DEVICE_NAME_0)
    string(SUBSTRING "${LMCU_DEVICE}" 0 11 DEVICE_NAME_1)
    string(SUBSTRING "${LMCU_DEVICE}" 8 3  DEVICE_FLASH)
    string(SUBSTRING "${LMCU_DEVICE}" 11 2 DEVICE_PACKAGE)
    string(SUBSTRING "${LMCU_DEVICE}" 13 2 DEVICE_PINS)

    set(CORTEX "M0")
    set(LMCU_C_FLAGS "${CORTEX_M0_C_FLAGS}")
    set(LD_DIR "${LMCU_DIR}/lib/ld/cortex-m0")
  endif()

  set(LMCU_DEFINITIONS
    -DLMCU_CORTEX
    -DLMCU_CORTEX_${CORTEX}
    -DLMCU_${DEVICE_SERIES}
    -DLMCU_${DEVICE_PACKAGE}
    -DLMCU_${DEVICE_NAME_0}
    -DLMCU_${DEVICE_NAME_1}
  CACHE INTERNAL "")

   if(NOT LMCU_LD_SCRIPT)
    set(LMCU_LD_SCRIPT "${LD_DIR}/${DEVICE_SIG}x${DEVICE_FAMILY}z${DEVICE_FLASH}_${LD_POSTFIX}.ld")
  endif()

  #message(STATUS ${DEVICE_NAME_0})
  set(SUPPORTED_DEVICE TRUE)
endif()

if(NOT EXISTS "${LMCU_LD_SCRIPT}")
  message(FATAL_ERROR "Linker script for '${LMCU_DEVICE}' not found!")
endif()

if(NOT ${SUPPORTED_DEVICE})
  message(FATAL_ERROR "Unsupported device!")
endif()

set(LMCU_INCLUDE_DIR
  "${CMAKE_CURRENT_LIST_DIR}/include"
  "${CMAKE_CURRENT_LIST_DIR}/lib/include"
CACHE INTERNAL "")

set(LMCU_LIBRARY lmcu CACHE INTERNAL "")

include_directories(${LMCU_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${LMCU_DIR}/*.cc" "${LMCU_DIR}/*.h")

set(CMAKE_MODULE_LINKER_FLAGS)
set(CMAKE_SHARED_LINKER_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

set(CMAKE_C_FLAGS "-std=c11 ${LMCU_C_FLAGS}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS "-std=c++2a -fno-rtti ${LMCU_C_FLAGS}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS "${LMCU_LD_FLAGS} -L ${LD_DIR} -T ${LMCU_LD_SCRIPT}" CACHE INTERNAL "")
set(CMAKE_C_FLAGS_RELEASE "-Os" CACHE INTERNAL "")
set(CMAKE_C_FLAGS_DEBUG "-O0" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}" CACHE INTERNAL "")

enable_language(C CXX ASM)

add_definitions(${LMCU_DEFINITIONS})
add_library(${LMCU_LIBRARY} ${SOURCES})

set(LMCU_OUTPUT_BIN "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>.bin" CACHE INTERNAL "")
set(LMCU_OUTPUT_HEX "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>.hex" CACHE INTERNAL "")

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
        "${LMCU_OUTPUT_BIN}"
    COMMAND
      ${CMAKE_OBJCOPY}
        -Oihex
        "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>"
        "${LMCU_OUTPUT_HEX}"
    COMMAND
      ${CMAKE_OBJDUMP}
        -drwlCS "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>" > "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>.s"
)
