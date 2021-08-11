################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ATM_CARD/SERVICE/SER_UART/subdir.mk
-include ATM_CARD/MCAL/UART/subdir.mk
-include ATM_CARD/MCAL/SPI/subdir.mk
-include ATM_CARD/MCAL/I2C/subdir.mk
-include ATM_CARD/MCAL/EXTI/subdir.mk
-include ATM_CARD/MCAL/DIO/subdir.mk
-include ATM_CARD/HAL/MOTOR/subdir.mk
-include ATM_CARD/HAL/LCD/subdir.mk
-include ATM_CARD/HAL/KeyPad/subdir.mk
-include ATM_CARD/HAL/EEPROM/subdir.mk
-include ATM_CARD/APP/subdir.mk
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
ATM_CARD.lss \

FLASH_IMAGE += \
ATM_CARD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATM_CARD.elf secondary-outputs

# Tool invocations
ATM_CARD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATM_CARD.map -mmcu=atmega32 -o "ATM_CARD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATM_CARD.lss: ATM_CARD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATM_CARD.elf  >"ATM_CARD.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATM_CARD.hex: ATM_CARD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATM_CARD.elf  "ATM_CARD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATM_CARD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATM_CARD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATM_CARD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
