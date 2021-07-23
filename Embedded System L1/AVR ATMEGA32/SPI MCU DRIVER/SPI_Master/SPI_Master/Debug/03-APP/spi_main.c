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
#include"../01-MCAL/01-DIO/DIO_register.h"
void main()
{
	DDRC = 0XFF;
	ST_SPI_config_t sppi = {MASTER,INT_DISABLE,LEADING_RISING,LEADING_SETUP,F_16,LSB_FIRST};
	ST_DIO_config_t PA4 = {PORTA,PIN4,OUTPUT};	
	DIO_voidSetPinDirection(&PA4);		
	if(SPI_Init(&sppi)==NO_ERROR)
	{
		DIO_voidSetPinValue(PORTA,PIN4,HIGH);
	}
	
	uint8_t data  = SPI_SendData((uint8_t)'k');
    while(1);

}