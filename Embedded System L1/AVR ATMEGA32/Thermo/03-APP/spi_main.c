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
void main()
{
	ST_SPI_config_t sppi = {MASTER,INT_DISABLE,LEADING_RISING,LEADING_SETUP,F_16,LSB_FIRST};
	SPI_Init(&sppi);
	SPI_SendData('A');	
	
    while(1);

}