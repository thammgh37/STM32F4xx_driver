################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/002led_button.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/002led_button.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/002led_button.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/ADMIN/Documents/STM32CubeIDE-Workspace/stm32f4xx_driver/drivers/Inc" -I"C:/Users/ADMIN/Documents/STM32CubeIDE-Workspace/stm32f4xx_driver/BSP" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

