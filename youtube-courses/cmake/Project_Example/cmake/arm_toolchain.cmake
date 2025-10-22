# Set cross-compilation for ARM Cortex-M
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Path to ARM GCC toolchain
set(ARM_TOOLCHAIN_PATH "C:/Alif-project/tools/armgcc-10.3.2/bin")

# Specify compilers
set(CMAKE_C_COMPILER "${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "${ARM_TOOLCHAIN_PATH}/arm-none-eabi-g++.exe")
set(CMAKE_ASM_COMPILER "${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc.exe")

# CPU and FPU options (adjust to your MCU)
set(CPU_FLAGS "-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=soft")

# Common compiler flags
set(CMAKE_C_FLAGS "${CPU_FLAGS} -O2 -g -Wall")
set(CMAKE_CXX_FLAGS "${CPU_FLAGS} -O2 -g -Wall -fno-exceptions -fno-rtti")
set(CMAKE_ASM_FLAGS "${CPU_FLAGS}")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m4 -mthumb -T${CMAKE_SOURCE_DIR}/linker/linker_script.ld -Wl,--gc-sections")
