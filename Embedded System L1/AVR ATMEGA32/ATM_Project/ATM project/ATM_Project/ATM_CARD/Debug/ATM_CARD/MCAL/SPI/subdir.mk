################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATM_CARD/MCAL/SPI/SPI.c 

OBJS += \
./ATM_CARD/MCAL/SPI/SPI.o 

C_DEPS += \
./ATM_CARD/MCAL/SPI/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
ATM_CARD/MCAL/SPI/%.o: ../ATM_CARD/MCAL/SPI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\APP" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\HAL\EEPROM" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\HAL\KeyPad" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\HAL\LCD" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\HAL\MOTOR" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\lib" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\MCAL\DIO" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\MCAL\EXTI" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\MCAL\I2C" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\MCAL\SPI" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\MCAL\UART" -I"E:\Sprints\ATM_Project\ATM_Project\ATM_CARD\ATM_CARD\SERVICE\SER_UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


