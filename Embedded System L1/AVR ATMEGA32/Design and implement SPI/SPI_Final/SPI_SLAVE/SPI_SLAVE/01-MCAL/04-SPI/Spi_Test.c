/******************************************************************************************************
 * File: spi_Test.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 23 july 2021
 * Description: This File include Registers of usart.
*******************************************************************************************************/
#include "../../00-LIB/types.h"
#include "../../00-LIB/BIT_MATH.h"
#include "spi.h"
#include <assert.h>
#include <stdio.h>


#define 	SPIE	7			//SPI Interrupt Enable
#define 	SPE		6			//SPI Enable
#define 	DORD	5			//Data Order
/*
When the DORD bit is written to one,
		the LSB of the data word is transmitted first.
When the DORD bit is written to zero, 
		the MSB of the data word is transmitted first.
*/
#define 	MSTR	4			//Master/Slave Select
/*
 Slave SPI mode when written logic zero  
 Master SPI mode when written to one
*/
#define 	CPOL	3			// Clock Polarity
#define 	CPHA	2			//CPHA Functionality

//Clock Rate Select
#define 	SPR1	1
#define 	SPR0	0

uint8_t SPCR;

/* SPSR REGISTER */
#define 	SPIF	7			//SPI Interrupt  Flag
#define 	WCOL	6			//Write COLlision Flag
#define 	SPI2X	0			//Double SPI Speed Bit
uint8_t SPSR ;

/* SPDR REGISTER */

#define 	MSB		7			//SPI Interrupt  Flag
#define 	LSB		0

uint8_t SPDR;


uint8_t SPCR_Help;

spi_errorstatus SPI_Init(ST_SPI_config_t * SPI_InitStruct)
{

	if( SPI_InitStruct->SPI_BaudRatePrescaler == F_16)
	{
		CLR_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);
	}
	else if( SPI_InitStruct->SPI_BaudRatePrescaler == F_4)
	{
		CLR_BIT(SPSR,SPI2X);
		CLR_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);		
	}
	else if( SPI_InitStruct->SPI_BaudRatePrescaler == F_64)
	{
		CLR_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR1);
		CLR_BIT(SPCR_Help,SPR0);
	}

	else if( SPI_InitStruct->SPI_BaudRatePrescaler== F_128)
	{
		CLR_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		SET_BIT(SPCR_Help,SPR1);		
	}
	else if( SPI_InitStruct->SPI_BaudRatePrescaler==F_8)
	{
		SET_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);		
	}
	else if( SPI_InitStruct->SPI_BaudRatePrescaler== F_2)
	{
		SET_BIT(SPSR,SPI2X);
		CLR_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);		
	}
	else if( SPI_InitStruct->SPI_BaudRatePrescaler== F_32)
	{
		SET_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR1);
		CLR_BIT(SPCR_Help,SPR0);		
	}
	else if( SPI_InitStruct->SPI_BaudRatePrescaler== F_64D)
	{
		SET_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		SET_BIT(SPCR_Help,SPR1);		
	}
	else
	{
		return BAUDRATE_ERROR;
	}

	
	if( SPI_InitStruct->SPI_CPOL==LEADING_RISING)
	{
		CLR_BIT(SPCR_Help,CPOL);		
	}
	else if( SPI_InitStruct->SPI_CPOL==LEADING_FALLING)
	{
		SET_BIT(SPCR_Help,CPOL);		
	}
	else
	{
		return CPOL_SELECTION_ERROR;
	}

	if( SPI_InitStruct->SPI_CPHA==LEADING_SAMPLE)
	{
		CLR_BIT(SPCR_Help,CPHA);		
	}
	else if( SPI_InitStruct->SPI_CPHA==LEADING_SETUP)
	{
		SET_BIT(SPCR_Help,CPHA); 		
	}
	else
	{
		return CPHA_ERROR;
	}
	
	if( SPI_InitStruct->SPI_FirstBit== LSB_FIRST)
	{
		SET_BIT(SPCR_Help,DORD);		
	}

	else if( SPI_InitStruct->SPI_FirstBit==MSB_FIRST)
	{
		CLR_BIT(SPCR_Help,DORD);		
	}
	else
	{
		return FIRST_BITERROR;
	}
	
	if( SPI_InitStruct->SPI_OP_Mode == INT_ENABLE)
	{
		SET_BIT(SPCR_Help,SPIE);

	}
	else if( SPI_InitStruct->SPI_OP_Mode == INT_DISABLE)
	{
		CLR_BIT(SPCR_Help,SPIE);	
	}
	else
	{
		return OP_MODE_ERROR;
	}



	if( SPI_InitStruct->SPI_Mode ==MASTER)
	{
			
	}

	else if( SPI_InitStruct->SPI_Mode ==SLAVE)
	{

	}
	else
	{
		return MODE_ERROR;
	}


	//SPI operations enable
	SET_BIT(SPCR_Help,SPE);	
	SPCR=SPCR_Help;

	return NO_ERROR;

}

uint8_t SPI_SendData(uint8_t data)
{
	SPDR=data;
	//wait for transmission complete
	while(0==GET_BIT(SPSR,SPIF));
	return SPDR;
}

uint8_t SPI_ReceiveData(void)
{
	while(0==GET_BIT(SPSR,SPIF));
	uint8_t x;
	x= SPDR;
	return x;
}

void SPI_InitTest(void)
{
	ST_SPI_config_t sppi = {MASTER,INT_DISABLE,LEADING_RISING,LEADING_SETUP,F_16,LSB_FIRST};
	assert(SPI_Init(&sppi) == NO_ERROR);  
    assert(SPCR==0x65);  
}
void SPI_SendDataTest()
{
    SET_BIT(SPSR,SPIF);
    assert(SPI_SendData('A')=='A');
}

void SPI_ReceiveDataTest()
{
    assert(SPI_ReceiveData()== 'A');
}

void main()
{
    SPI_InitTest();
    SPI_SendDataTest();
    SPI_ReceiveDataTest();
    printf("No ERROR");
}



