set(LMCU_C_FLAGS
"\
-Os \
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
    set(LD_DIR "${LMCU_DIR}/mcu/device/ld/cortex-m3")
  elseif("${DEVICE_SERIES}" STREQUAL "STM32F4")
    set(CORTEX "M4")
    set(LMCU_C_FLAGS "${CORTEX_M4_C_FLAGS}")
    set(LD_DIR "${LMCU_DIR}/mcu/device/ld/cortex-m4")
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

if(NOT EXISTS "${LMCU_LD_SCRIPT}")
  message(FATAL_ERROR "Linker script for '${LMCU_DEVICE}' not found!")
endif()

if(NOT ${SUPPORTED_DEVICE})
  message(FATAL_ERROR "Unsupported device!")
endif()

set(LMCU_INCLUDE_DIR "${LMCU_DIR}" "${CMAKE_CURRENT_LIST_DIR}/include" CACHE INTERNAL "")
set(LMCU_LIBRARY lmcu CACHE INTERNAL "")

include_directories(${LMCU_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${LMCU_DIR}/*.cc" "${LMCU_DIR}/*.h")

set(CMAKE_MODULE_LINKER_FLAGS "" PARENT_SCOPE)
set(CMAKE_SHARED_LINKER_FLAGS "" PARENT_SCOPE)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "" PARENT_SCOPE)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "" PARENT_SCOPE)

set(CMAKE_MODULE_LINKER_FLAGS)
set(CMAKE_SHARED_LINKER_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

set(CMAKE_C_FLAGS "-std=c11 ${LMCU_C_FLAGS}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS "-std=c++2a -fno-rtti ${LMCU_C_FLAGS}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS "${LMCU_LD_FLAGS} -L ${LD_DIR} -T ${LMCU_LD_SCRIPT}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELEASE "" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_DEBUG "" CACHE INTERNAL "")

add_definitions(${LMCU_DEFINITIONS})
add_library(${LMCU_LIBRARY} ${SOURCES})
