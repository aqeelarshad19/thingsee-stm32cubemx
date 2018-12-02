cmake_minimum_required (VERSION 3.5)

# configure toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/arm-gcc-toolchain.cmake")
include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)

# define project name
project(thingsee)

# set build configuration to debug
set(CMAKE_BUILD_TYPE Debug)

# set C++ standard to C++11
set (CMAKE_CXX_STANDARD 11)

enable_language(ASM)

set(MCU_OPTS "-mcpu=cortex-m3 -mthumb")
set(LD_SCRIPT "${CMAKE_SOURCE_DIR}/STM32L162VEYx_FLASH.ld")

# configure target
add_definitions(
    -DUSE_HAL_DRIVER
    -DSTM32L162xE
)

set(COMPILER_FLAGS "${MCU_OPTS} -Wall -fdata-sections -ffunction-sections")

if(CMAKE_BUILD_TYPE EQUAL "Debug")
    set(COMPILER_FLAGS "${COMPILER_FLAGS} -g -gdwarf-2 -Og")
endif()

set(CMAKE_CXX_FLAGS ${COMPILER_FLAGS})
set(CMAKE_C_FLAGS ${COMPILER_FLAGS})
set(CMAKE_AS_FLAGS ${COMPILER_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MCU_OPTS} -u _printf_float -specs=nano.specs -T${LD_SCRIPT}")

# define include directories
include_directories(
    App
    Inc
    Drivers/STM32L1xx_HAL_Driver/Inc
    Drivers/STM32L1xx_HAL_Driver/Inc/Legacy
    Drivers/CMSIS/Device/ST/STM32L1xx/Include
    Drivers/CMSIS/Include
    Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    Middlewares/u8g2
)

# source directories
add_subdirectory(Src)
add_subdirectory(Drivers/STM32L1xx_HAL_Driver/Src)
add_subdirectory(Middlewares/ST/STM32_USB_Device_Library/Core/Src)
add_subdirectory(Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src)
add_subdirectory(Middlewares/u8g2)
add_subdirectory(App)

add_custom_target(
    flash 
    COMMAND sudo dfu-util -d 0483:df11 -a0 --dfuse-address 0x08000000:leave  -D ${CMAKE_BINARY_DIR}/Src/firmware.bin
    DEPENDS firmware
    COMMENT "Flashing ${CMAKE_BINARY_DIR}/Src/firmware.bin with dfu-util..."
    USES_TERMINAL
)