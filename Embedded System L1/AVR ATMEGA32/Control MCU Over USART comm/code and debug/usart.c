/******************************************************************************************************
 * File: usart.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 14 july 2021
 * Description: This File include functions definitions.
*******************************************************************************************************/


#include "types.h"
#include "BIT_MATH.h"

#include "usart_reg.h"
#include "usart.h"
#include "uartConfig.h"




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
        //Receiver Enable
        SET_BIT(UCSRB,RXEN);
    }
    else if(USART_InitStruct->USART_Mode == RECEIVER)  
    {
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


	while(!GET_BIT(UCSRA,UDRE));
	UDR=data_transmitted;
    if(GET_BIT(UCSRA,TXC)!=1)
        return TRANSMITION_ERROR;

    return NO_TRANSMITION_ERROR;

}

uint8_t usart_ReceiveData(void)
{
	uint8_t data;
	while(0==GET_BIT(UCSRA,RXC));
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


