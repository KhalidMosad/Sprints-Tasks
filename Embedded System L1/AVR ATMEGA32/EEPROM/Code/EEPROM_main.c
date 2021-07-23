/*
 * main.c
 *
 *  Created on: Apr 21, 2021
 *      Author: Khaled
 */

#include"types.h"
#include"BIT_Math.h"
#include "I2C.h"
#include "EEPROM.h"
#include "DIO_interface.h"
#include "usart.h"
#include <util/delay.h>
#include <string.h>
//#define data 0b00001110
#define internal_reg 0b00001000
#define Slave_address 0b01010000

uint8_t ConvertFromAscitoInt(uint8_t * data)
{
	uint8_t address = 0;
	address = (data[2]-'0')*16 + (data[3]-'0');

	return address;
}


void main(void)
{
	uint8_t int_address ;
	uint8_t data[50] ;
	DIO_VoidSetPortDirection(PORTA,OUTPUT);
	DIO_VoidSetPortDirection(PORTD,OUTPUT);

	ST_UART_config_t master = {51,EIGHT_BITS,ONE_BIT,DISABLED,TRANSMITTER_RECEIVER};
	usart_Init(&master);
	EEPROM_VoidInit();
	while(1)
	{
		usart_SendString((uint8_t*)"Enter your Operation: \r");
		usart_ReceiveString(data,'\r');
		if(strcmp(data,"WRITE")== 0)
		{
			usart_SendString((uint8_t*)"Enter Address: \r");
			usart_ReceiveString(data,'\r');
			int_address= ConvertFromAscitoInt(data);
			usart_SendData(int_address);
			usart_SendString((uint8_t*)"\rOK \rEnter Data: \r");
			uint8_t data = usart_ReceiveData();
			usart_SendString((uint8_t*)"\rOK\r");
			EEPROM_VoidWriteDataByte(Slave_address,int_address,data);
		}
		if(strcmp(data,"READ")== 0)
		{
			usart_SendString((uint8_t*)"Enter Address To Read: \r");
			usart_ReceiveString(data,'\r');
			uint8_t add= ConvertFromAscitoInt(data);
			_delay_ms(50);
			uint8_t i= EEPROM_u8ReadDataByte(Slave_address,add);
			DIO_VidSetPortValue(PORTA,i);

		}





	}

}

