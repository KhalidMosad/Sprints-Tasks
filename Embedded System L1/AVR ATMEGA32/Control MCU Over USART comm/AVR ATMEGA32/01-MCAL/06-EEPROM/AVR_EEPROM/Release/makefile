################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
AVR_EEPROM.lss \

FLASH_IMAGE += \
AVR_EEPROM.hex \

EEPROM_IMAGE += \
AVR_EEPROM.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_EEPROM.elf secondary-outputs

# Tool invocations
AVR_EEPROM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_EEPROM.map -mmcu=atmega32 -o "AVR_EEPROM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_EEPROM.lss: AVR_EEPROM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_EEPROM.elf  >"AVR_EEPROM.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_EEPROM.hex: AVR_EEPROM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_EEPROM.elf  "AVR_EEPROM.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVR_EEPROM.eep: AVR_EEPROM.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVR_EEPROM.elf  "AVR_EEPROM.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_EEPROM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_EEPROM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_EEPROM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
