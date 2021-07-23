/******************************************************************************************************
 * File: spi.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 14 july 2021
 * Description: This File include APIs List.
*******************************************************************************************************/
#include"../../00-LIB/BIT_Math.h"
#include"../../00-LIB/types.h"
#include"spi.h"
#include"spi_reg.h"
#include"spiConfig.h"
#include"../01-DIO/DIO_interface.h"


#define NULL '\0'
static void(*ptrf)(void) = NULL;

uint8_t SPCR_Help=0;

spi_errorstatus SPI_Init(ST_SPI_config_t * SPI_InitStruct)
{
	if( SPI_InitStruct->SPI_Mode ==MASTER)
	{	
		SET_BIT(SPCR_Help,MSTR);
		ST_DIO_config_t MISO = {PORTB,PIN6,INPUT};
		ST_DIO_config_t MOSI = {PORTB,PIN5,OUTPUT};
		ST_DIO_config_t SCK =  {PORTB,PIN7,OUTPUT};
		ST_DIO_config_t SS =   {PORTB,PIN4,OUTPUT};
		// MISO PB6 INPUT
		DIO_voidSetPinDirection(&MISO);
		// SCK PB7 OUT
		DIO_voidSetPinDirection(&SCK);
		// MOSI PB5 OUT
		DIO_voidSetPinDirection(&MOSI);
		// SS PB4 OUT
		DIO_voidSetPinDirection(&SS);
		DIO_voidSetPinValue(PORTB,PIN4,LOW);
	}

	else if( SPI_InitStruct->SPI_Mode ==SLAVE)
	{

		ST_DIO_config_t MISO = {PORTB,PIN6,OUTPUT};
		ST_DIO_config_t MOSI = {PORTB,PIN5,INPUT};
		ST_DIO_config_t SCK =  {PORTB,PIN7,INPUT};
		ST_DIO_config_t SS =   {PORTB,PIN4,INPUT};
		CLR_BIT(SPCR_Help,MSTR);
		// PIN CONFIG
		// MISO PB6 out
		DIO_voidSetPinDirection(&MISO);
		// SCK PB7 IN
		DIO_voidSetPinDirection(&SCK);
		// MOSI PB5 IN
		DIO_voidSetPinDirection(&MOSI);
		// SS PB4 IN
		DIO_voidSetPinDirection(&SS);
		DIO_voidSetPinValue(PORTB,PIN4,HIGH);
	}
	else
	{
		return MODE_ERROR;
	}	
	
	
	//SPI operations enable
	SET_BIT(SPCR_Help,SPE);

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
		GIE_voidEnable();
	}
	else if( SPI_InitStruct->SPI_OP_Mode == OP_MODE == INT_DISABLE)
	{
		CLR_BIT(SPCR_Help,SPIE);
		GIE_voidDisable();		
	}
	else
	{
		return OP_MODE_ERROR;
	}




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
	uint8_t data;
	data= SPDR;
	return data;
}




static void GIE_voidEnable(void)
{
	// GIE
	SET_BIT(SREG,GIE);

}

static void GIE_voidDisable(void)
{
	// GIE
	CLR_BIT(SREG,GIE);
}

void SPI_SETCALLBACK(void(*ptr)(void))
{
	if(ptr !=NULL)
	{
	 ptrf=ptr;
	}
}




void __vector_12(void )
{
	ptrf();
}
