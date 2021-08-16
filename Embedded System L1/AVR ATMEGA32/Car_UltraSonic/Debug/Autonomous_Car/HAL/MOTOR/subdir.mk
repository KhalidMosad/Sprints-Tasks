################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autonomous_Car/HAL/MOTOR/MOTOR.c 

OBJS += \
./Autonomous_Car/HAL/MOTOR/MOTOR.o 

C_DEPS += \
./Autonomous_Car/HAL/MOTOR/MOTOR.d 


# Each subdirectory must supply rules for building sources it contributes
Autonomous_Car/HAL/MOTOR/%.o: ../Autonomous_Car/HAL/MOTOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\MCAL\PWM" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\APP" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\UTIL" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\APP" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\HAL" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\HAL\LCD" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\HAL\MOTOR" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\HAL\ULTRA_SONIC" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\MCAL" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\MCAL\DIO" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\MCAL\EXTI" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\MCAL\PWM" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\MCAL\TIMER" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\Car_UltraSonic_final\Car_UltraSonic\Autonomous_Car\UTIL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


