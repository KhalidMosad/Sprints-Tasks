################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO_program.c \
../Keypad4x4.c \
../LCD16x2.c \
../adc_main.c 

OBJS += \
./ADC.o \
./DIO_program.o \
./Keypad4x4.o \
./LCD16x2.o \
./adc_main.o 

C_DEPS += \
./ADC.d \
./DIO_program.d \
./Keypad4x4.d \
./LCD16x2.d \
./adc_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


