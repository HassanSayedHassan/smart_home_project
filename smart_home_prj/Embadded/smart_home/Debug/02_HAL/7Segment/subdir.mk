################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02_HAL/7Segment/H7SEG_Program.c 

OBJS += \
./02_HAL/7Segment/H7SEG_Program.o 

C_DEPS += \
./02_HAL/7Segment/H7SEG_Program.d 


# Each subdirectory must supply rules for building sources it contributes
02_HAL/7Segment/%.o: ../02_HAL/7Segment/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


