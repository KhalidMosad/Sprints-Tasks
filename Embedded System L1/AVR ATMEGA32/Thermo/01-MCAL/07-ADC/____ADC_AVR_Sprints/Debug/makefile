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
____ADC_AVR_Sprints.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ____ADC_AVR_Sprints.elf secondary-outputs

# Tool invocations
____ADC_AVR_Sprints.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,____ADC_AVR_Sprints.map -mmcu=atmega32 -o "____ADC_AVR_Sprints.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

____ADC_AVR_Sprints.lss: ____ADC_AVR_Sprints.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ____ADC_AVR_Sprints.elf  >"____ADC_AVR_Sprints.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ____ADC_AVR_Sprints.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ____ADC_AVR_Sprints.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ____ADC_AVR_Sprints.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
