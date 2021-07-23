/******************************************************************************************************
 * File: DIO_program.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 10 july 2021
 * Description: This File include Definitions of functions and Strucrures.
*******************************************************************************************************/

#include"types.h"
#include"BIT_MATH.h"
#include"DIO_register.h"
#include"DIO_interface.h"

void DIO_voidSetPinDirection		(ST_DIO_config_t * configurations)
{
	if(OUTPUT==configurations->state)
	{
		switch (configurations->port_no)
		{
			case PORTA:SET_BIT(DDRA, configurations->pin_no); break;
			case PORTB:SET_BIT(DDRB,  configurations->pin_no); break;
			case PORTC:SET_BIT(DDRC,  configurations->pin_no); break;
			case PORTD:SET_BIT(DDRD,  configurations->pin_no); break;
	
		}	
	}
	else if(INPUT==configurations->state)
	{
		switch(configurations->port_no)
		{
			case PORTA:CLR_BIT(DDRA,  configurations->pin_no); break;
			case PORTB:CLR_BIT(DDRB,  configurations->pin_no); break;
		    case PORTC:CLR_BIT(DDRC,  configurations->pin_no); break;
		    case PORTD:CLR_BIT(DDRD,  configurations->pin_no); break;
		}	
	}
	else
	{
		
	}
	
}
void DIO_voidSetPinValue			(uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin, uint8_t copy_uint8_tvalue)
{
	if(HIGH==copy_uint8_tvalue)
	{
		switch (copy_uint8_tport)
		{
			case PORTA:SET_BIT(PORT_A, copy_uint8_tpin); break;
			case PORTB:SET_BIT(PORT_B, copy_uint8_tpin); break;
			case PORTC:SET_BIT(PORT_C, copy_uint8_tpin); break;
			case PORTD:SET_BIT(PORT_D, copy_uint8_tpin); break;
	
		}	
	}
	else if(LOW==copy_uint8_tvalue)
	{
		switch(copy_uint8_tport)
		{
			case PORTA:CLR_BIT(PORT_A, copy_uint8_tpin); break;
			case PORTB:CLR_BIT(PORT_B, copy_uint8_tpin); break;
		    case PORTC:CLR_BIT(PORT_C, copy_uint8_tpin); break;
		    case PORTD:CLR_BIT(PORT_D, copy_uint8_tpin); break;
		}	
	}
	else
	{
		
	}	
	
	
	
}


uint8_t DIO_uint8_tGetPinValue			(uint8_t copy_uint8_tport, uint8_t Copy_uint8_tPin)
{
	uint8_t Lcal_uint8_tPinResult=0;
	switch(copy_uint8_tport){

			case PORTA :		Lcal_uint8_tPinResult=GET_BIT(PINA,Copy_uint8_tPin);	        break;
			case PORTB :		Lcal_uint8_tPinResult=GET_BIT(PINB,Copy_uint8_tPin); 		    break;
			case PORTC :		Lcal_uint8_tPinResult=GET_BIT(PINC,Copy_uint8_tPin);			break;
			case PORTD :		Lcal_uint8_tPinResult=GET_BIT(PIND,Copy_uint8_tPin);			break;

			}


return(Lcal_uint8_tPinResult);
	
	
}

void DIO_voidTogglePin			(uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin)
{

		switch (copy_uint8_tport)
		{
					case PORTA:TOG_BIT(PORT_A, copy_uint8_tpin); break;
					case PORTB:TOG_BIT(PORT_B, copy_uint8_tpin); break;
					case PORTC:TOG_BIT(PORT_C, copy_uint8_tpin); break;
					case PORTD:TOG_BIT(PORT_D, copy_uint8_tpin); break;
		}

}

void DIO_VoidSetPortDirection	(uint8_t copy_u8port, uint8_t copy_U8state)
{
	
	if(OUTPUT==copy_U8state)
	{
		switch (copy_u8port)
		{
			case PORTA:DDRA= ALL_OUTPUT		; break;
			case PORTB:DDRB= ALL_OUTPUT		; break;
			case PORTC:DDRC= ALL_OUTPUT		; break;
			case PORTD:DDRD= ALL_OUTPUT		; break;
	
		}	
	}
	else if(INPUT==copy_U8state)
	{
		switch(copy_u8port)
		{
			case PORTA:DDRA= ALL_INPUT		; break;
			case PORTB:DDRB= ALL_INPUT		; break;
			case PORTC:DDRC= ALL_INPUT		; break;
			case PORTD:DDRD= ALL_INPUT		; break;
		}	
	}
	else
	{
		
	}
	
	
}
void DIO_VidSetPortValue		(uint8_t copy_u8port, uint8_t copy_U8value)
{
		
		switch (copy_u8port)
		{
			case PORTA:PORT_A=copy_U8value		; break;
			case PORTB:PORT_B=copy_U8value		; break;
			case PORTC:PORT_C=copy_U8value		; break;
			case PORTD:PORT_D=copy_U8value		; break;
	
		}	
	
}





