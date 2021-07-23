/******************************************************************************************************
 * File: spi_main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 14 july 2021
 * Description: This File include APIs List.
*******************************************************************************************************/

#include"../00-LIB/BIT_Math.h"
#include"../00-LIB/types.h"
#include"../01-MCAL/04-SPI/spi.h"
#include"../01-MCAL/01-DIO/DIO_interface.h"
#include "../01-MCAL/03- usart/usart.h"
void main()
{
	ST_UART_config_t uart ={51,EIGHT_BITS,ONE_BIT,DISABLED,TRANSMITTER};
	ST_SPI_config_t sppi = {SLAVE,INT_DISABLE,LEADING_RISING,LEADING_SETUP,F_16,LSB_FIRST};
	ST_DIO_config_t PA0 = {PORTA,PIN0,OUTPUT};
	DIO_voidSetPinDirection(&PA0);
	usart_Init(&uart);
	SPI_Init(&sppi);
	uint8_t  data[255];	
    while(1)
	{
		
		SPI_ReceiveString(data,'\r');		
		usart_SendString(data);
		DIO_voidTogglePin(PORTA,PIN0);	
	}

}