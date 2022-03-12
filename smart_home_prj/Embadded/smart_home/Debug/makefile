################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 03_MCAL/UART_Driver/subdir.mk
-include 03_MCAL/PORT_Driver/subdir.mk
-include 03_MCAL/GIE_Driver/subdir.mk
-include 03_MCAL/EXTI_Driver/subdir.mk
-include 03_MCAL/DIO_Driver/subdir.mk
-include 02_HAL/LCD/subdir.mk
-include 02_HAL/KeyPad/subdir.mk
-include 02_HAL/7Segment/subdir.mk
-include 01_APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
IMT_PRJ.lss \

FLASH_IMAGE += \
IMT_PRJ.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: IMT_PRJ.elf secondary-outputs

# Tool invocations
IMT_PRJ.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,IMT_PRJ.map -mmcu=atmega32 -o "IMT_PRJ.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

IMT_PRJ.lss: IMT_PRJ.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S IMT_PRJ.elf  >"IMT_PRJ.lss"
	@echo 'Finished building: $@'
	@echo ' '

IMT_PRJ.hex: IMT_PRJ.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex IMT_PRJ.elf  "IMT_PRJ.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: IMT_PRJ.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 IMT_PRJ.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) IMT_PRJ.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
