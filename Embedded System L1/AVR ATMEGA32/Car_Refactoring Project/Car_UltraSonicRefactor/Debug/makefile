################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Autonomous_Car/MCAL/TIMER/subdir.mk
-include Autonomous_Car/MCAL/PWM/subdir.mk
-include Autonomous_Car/MCAL/EXTI/subdir.mk
-include Autonomous_Car/MCAL/DIO/subdir.mk
-include Autonomous_Car/HAL/ULTRA_SONIC/subdir.mk
-include Autonomous_Car/HAL/MOTOR/subdir.mk
-include Autonomous_Car/HAL/LCD/subdir.mk
-include Autonomous_Car/APP/MotorlControl/subdir.mk
-include Autonomous_Car/APP/Monitoring/subdir.mk
-include Autonomous_Car/APP/subdir.mk
-include Autonomous_Car/subdir.mk
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
Car_UltraSonicRefactor.lss \

FLASH_IMAGE += \
Car_UltraSonicRefactor.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Car_UltraSonicRefactor.elf secondary-outputs

# Tool invocations
Car_UltraSonicRefactor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Car_UltraSonicRefactor.map -mmcu=atmega32 -o "Car_UltraSonicRefactor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Car_UltraSonicRefactor.lss: Car_UltraSonicRefactor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Car_UltraSonicRefactor.elf  >"Car_UltraSonicRefactor.lss"
	@echo 'Finished building: $@'
	@echo ' '

Car_UltraSonicRefactor.hex: Car_UltraSonicRefactor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Car_UltraSonicRefactor.elf  "Car_UltraSonicRefactor.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Car_UltraSonicRefactor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Car_UltraSonicRefactor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Car_UltraSonicRefactor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
