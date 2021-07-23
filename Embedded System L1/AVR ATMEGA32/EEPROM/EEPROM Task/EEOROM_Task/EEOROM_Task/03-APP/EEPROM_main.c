/*
 * main.c
 *
 *  Created on: Apr 21, 2021
 *      Author: Khaled
 */

#include"../00-LIB/types.h"
#include"../00-LIB/BIT_Math.h"
#include "../01-MCAL/05-TWI/I2C.h"
#include "../01-MCAL/06-EEPROM/EEPROM.h"
#include "../01-MCAL/01-DIO/DIO_interface.h"
#define  F_CPU  8000000UL
#include <util/delay.h>

#define data 0b00001110
#define internal_reg 0b00001000
#define Slave_address 0b01010000

void main(void)
{
	DIO_VoidSetPortDirection(PORTA,OUTPUT);
	DIO_VoidSetPortDirection(PORTD,OUTPUT);
	
	EEPROM_VoidInit();
	EEPROM_VoidWriteDataByte(Slave_address,internal_reg,data);
	_delay_ms(50);
	uint8_t i= EEPROM_u8ReadDataByte(Slave_address,internal_reg);
	DIO_VidSetPortValue(PORTA,i);

	while(1);

}
