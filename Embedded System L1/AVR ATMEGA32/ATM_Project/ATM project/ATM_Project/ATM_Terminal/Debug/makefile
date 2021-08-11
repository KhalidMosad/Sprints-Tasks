################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ATM_Terminal/SERVICE/SER_UART/subdir.mk
-include ATM_Terminal/MCAL/UART/subdir.mk
-include ATM_Terminal/MCAL/SPI/subdir.mk
-include ATM_Terminal/MCAL/I2C/subdir.mk
-include ATM_Terminal/MCAL/EXTI/subdir.mk
-include ATM_Terminal/MCAL/DIO/subdir.mk
-include ATM_Terminal/MCAL/ADC/subdir.mk
-include ATM_Terminal/HAL/MOTOR/subdir.mk
-include ATM_Terminal/HAL/LM35/subdir.mk
-include ATM_Terminal/HAL/LCD/subdir.mk
-include ATM_Terminal/HAL/KeyPad/subdir.mk
-include ATM_Terminal/HAL/EEPROM/subdir.mk
-include ATM_Terminal/APP/subdir.mk
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
ATM_Terminal.lss \

FLASH_IMAGE += \
ATM_Terminal.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATM_Terminal.elf secondary-outputs

# Tool invocations
ATM_Terminal.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATM_Terminal.map -mmcu=atmega32 -o "ATM_Terminal.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATM_Terminal.lss: ATM_Terminal.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATM_Terminal.elf  >"ATM_Terminal.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATM_Terminal.hex: ATM_Terminal.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATM_Terminal.elf  "ATM_Terminal.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATM_Terminal.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATM_Terminal.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATM_Terminal.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
