/*
 * main.c
 *
 *  Created on: Apr 21, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "I2C_Interface.h"
#include "DIO_interface.h"
#include "EEPROM_Interface.h"
#include "avr/delay.h"

void main(void)
{
	DIO_VidSetPortDirection(PORTA,OUTPUT);
	DIO_VidSetPortDirection(PORTD,OUTPUT);
	EEPROM_VoidInit();


	u8 x= EEPROM_VoidWriteDataByte(0b01010000,0b00001000,'A');
	DIO_VidSetPortValue(PORTD,x);
	_delay_ms(50);
	u8 i= EEPROM_u8ReadDataByte(0b01010000,0b00001000);
	DIO_VidSetPortValue(PORTA,i);

	while(1);

}
