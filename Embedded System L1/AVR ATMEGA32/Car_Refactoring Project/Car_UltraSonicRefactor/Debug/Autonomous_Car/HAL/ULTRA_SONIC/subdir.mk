################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autonomous_Car/HAL/ULTRA_SONIC/Ultrasonic.c 

OBJS += \
./Autonomous_Car/HAL/ULTRA_SONIC/Ultrasonic.o 

C_DEPS += \
./Autonomous_Car/HAL/ULTRA_SONIC/Ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
Autonomous_Car/HAL/ULTRA_SONIC/%.o: ../Autonomous_Car/HAL/ULTRA_SONIC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\APP" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\APP\Monitoring" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\APP\MotorlControl" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\HAL" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\HAL\LCD" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\HAL\MOTOR" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\HAL\ULTRA_SONIC" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\MCAL" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\MCAL\DIO" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\MCAL\EXTI" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\MCAL\PWM" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\MCAL\TIMER" -I"E:\Sprints\Project\Projects\Car_UltraSonicRefactor\Autonomous_Car\UTIL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


