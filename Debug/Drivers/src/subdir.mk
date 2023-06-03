################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/GPIO.c \
../Drivers/src/LCD.c \
../Drivers/src/PollDataClient.c \
../Drivers/src/PollerTimer.c \
../Drivers/src/SPI.c \
../Drivers/src/device.c \
../Drivers/src/poller.c 

OBJS += \
./Drivers/src/GPIO.o \
./Drivers/src/LCD.o \
./Drivers/src/PollDataClient.o \
./Drivers/src/PollerTimer.o \
./Drivers/src/SPI.o \
./Drivers/src/device.o \
./Drivers/src/poller.o 

C_DEPS += \
./Drivers/src/GPIO.d \
./Drivers/src/LCD.d \
./Drivers/src/PollDataClient.d \
./Drivers/src/PollerTimer.d \
./Drivers/src/SPI.d \
./Drivers/src/device.d \
./Drivers/src/poller.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/sigma/workspace/tc72_task/inc" -I"C:/Users/sigma/workspace/tc72_task/CMSIS/device" -I"C:/Users/sigma/workspace/tc72_task/CMSIS/core" -I"C:/Users/sigma/workspace/tc72_task/Drivers/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


