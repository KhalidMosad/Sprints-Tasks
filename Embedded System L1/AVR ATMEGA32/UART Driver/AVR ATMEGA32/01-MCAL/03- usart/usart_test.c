/******************************************************************************************************
 * File: usart_test.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 23 july 2021
 * Description: This File include Registers of usart.
*******************************************************************************************************/
#include "../../00-LIB/types.h"
#include "../../00-LIB/BIT_MATH.h"
#include "usart.h"
#include <assert.h>
#include <stdio.h>

#define	RXC			7		//USART Receive Complete
#define	TXC			6		//USART Transmit Complete
#define	UDRE		5		//USART Data Register Empty
#define	FE			4		//Frame Error
#define	DOR			3		//Data OverRun
#define	PE			2		//Parity Error
#define	U2X			1		// Double the USART Transmission Speed
#define	MPCM		0		// Multi-processor Communication Mode


/* UCSRB REGISTER*/
#define	RXCIE			7			//RX Complete Interrupt Enable
#define	TXCIE			6			//TX Complete Interrupt Enable
#define	UDRIE			5			// Data Register Empty Interrupt Enable
#define	RXEN			4			// Receiver Enable
#define	TXEN			3			// Transmitter Enable
#define	UCSZ2			2			// Character Size
#define	RXB8			1			// Receive Data Bit 8
#define	TXB8			0			//  Transmit Data Bit 8


#define	URSEL			7			//Register Select
/*
This bit selects between accessing the UCSRC or the UBRRH Register.
 It is read as one when reading UCSRC.
 The URSEL must be one when writing the UCSRC


*/
#define	UMSEL			6			//USART Mode Select

//  Parity Mode Select
#define	UPM1			5			
#define	UPM0			4	
		
#define	USBS			3			// Stop Bit Select
#define	UCSZ1			2			// Character Size
#define	UCSZ0			1			
#define	UCPOL			0			//  Clock Polarity

uint8_t UDR;
uint8_t UCSRA;
uint8_t UCSRB;
uint8_t UBRRL;
uint8_t UBRRH;
uint8_t UCSRC ;

error_state usart_Init(ST_UART_config_t * USART_InitStruct)
{
	UBRRH = (USART_InitStruct->USART_BaudRate>>8) & 0x7F;
    UBRRL = (USART_InitStruct->USART_BaudRate );

    uint8_t UCSRC_h;
    SET_BIT(UCSRC_h,URSEL);
    /****** Set Word Length *******/
    if(USART_InitStruct->USART_WordLength == FIVE_BITS)
    {
        CLR_BIT(UCSRC_h,UCSZ0 );
        CLR_BIT(UCSRC_h,UCSZ1 );        
        CLR_BIT(UCSRB,UCSZ2 );
    }
    else if(USART_InitStruct->USART_WordLength == SIX_BITS)
    {
        SET_BIT(UCSRC_h,UCSZ0 );
        CLR_BIT(UCSRC_h,UCSZ1 );        
        CLR_BIT(UCSRB,UCSZ2 );
    }
    else if(USART_InitStruct->USART_WordLength == SEVEN_BITS)
    {
        CLR_BIT(UCSRC_h,UCSZ0 );
        SET_BIT(UCSRC_h,UCSZ1 );        
        CLR_BIT(UCSRB,UCSZ2 );
    }
    else if(USART_InitStruct->USART_WordLength == EIGHT_BITS)
    {
        SET_BIT(UCSRC_h,UCSZ0 );
        SET_BIT(UCSRC_h,UCSZ1 );        
        CLR_BIT(UCSRB,UCSZ2 );
    }
    else if(USART_InitStruct->USART_WordLength ==NINE_BITS)
    {
        SET_BIT(UCSRC_h,UCSZ0 );
        SET_BIT(UCSRC_h,UCSZ1 );        
        SET_BIT(UCSRB,UCSZ2 );
    }    
    else
    {
        return WORD_LENGTH_ERROR;
    }
    /****** Set Number of Stop bits *******/
    if(USART_InitStruct->USART_StopBits == ONE_BIT)
    {
        CLR_BIT(UCSRC_h, USBS);
    }
    else if(USART_InitStruct->USART_StopBits == TWO_BIT)
    {
        SET_BIT(UCSRC_h, USBS);        
    }
    else
    {
        return STOP_BIT_ERROR;
    }

    if(USART_InitStruct->USART_Parity == DISABLED)
    {
        CLR_BIT(UCSRC_h,UPM1);
        CLR_BIT(UCSRC_h,UPM0);
    }
    else if(USART_InitStruct->USART_Parity == ENABLED_EVEN)
    {
        SET_BIT(UCSRC_h,UPM1);
        CLR_BIT(UCSRC_h,UPM0);
    } 
    else if(USART_InitStruct->USART_Parity == ENABLED_ODD)
    {
        SET_BIT(UCSRC_h,UPM1);
        SET_BIT(UCSRC_h,UPM0);
    }
    else
    {
        return PARITY_ERROR;
    }
    if(USART_InitStruct->USART_Mode == TRANSMITTER)  
    {
        //Transmitter Enable
	    SET_BIT(UCSRB,TXEN);
    }
    else if(USART_InitStruct->USART_Mode == RECEIVER)  
    {
        //Receiver Enable
        SET_BIT(UCSRB,RXEN);
    }
    else if(USART_InitStruct->USART_Mode == TRANSMITTER_RECEIVER)  
    {
        //Transmitter Enable
	    SET_BIT(UCSRB,TXEN);
        //Receiver Enable
        SET_BIT(UCSRB,RXEN);
    }    
    else
    {
        return MODE_ERROR;
    }

    UCSRC = UCSRC_h;

    return NO_ERROR;

}

error_state usart_SendData(uint8_t data_transmitted)
{
	UDR=data_transmitted;
    return NO_TRANSMITION_ERROR;
}

uint8_t usart_ReceiveData(void)
{
	uint8_t data;
	data=UDR;
	return data;
}


error_state usart_SendString(uint8_t *str)
{
	uint8_t j=0;

	while (str[j]!=0)		
	{
		usart_SendData(str[j]);
		j++;
	}

	return STRING_NOERROR;
}

uint8_t * usart_ReceiveString(uint8_t * au8data ,uint8_t terminating_character)
{
	uint32_t i,temp=0;
	for(i=0;;i++)
	{
		*(au8data+i)=usart_ReceiveData();
		if(*(au8data+i)==terminating_character)
			break;
		else
			temp++;
	}
	*(au8data+temp)='\0';
	return au8data;
}

void usart_InitTest(void)
{
    ST_UART_config_t x={51,EIGHT_BITS,ONE_BIT,DISABLED,TRANSMITTER};
    assert(usart_Init(&x) == NO_ERROR);
    assert(UBRRL==51);
    assert(UCSRC == 0X86);
    assert(UCSRB== 0x08);   
}


void usart_SendDataTest(void)
{
    assert(usart_SendData('k')==NO_TRANSMITION_ERROR);
}

void usart_ReceiveTest(void)
{
    assert(usart_ReceiveData()=='k');
}

void main()
{
    usart_InitTest();
    usart_SendDataTest();
    usart_ReceiveTest();
    printf("No Error");

}



