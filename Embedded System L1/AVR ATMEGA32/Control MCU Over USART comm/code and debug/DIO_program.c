/******************************************************************************************************
 * File: DIO_program.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 10 july 2021
 * Description: This File include Definitions of functions and Strucrures.
*******************************************************************************************************/

#include"STD_TYPES.h"
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
void DIO_voidSetPinValue			(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value)
{
	if(HIGH==copy_u8value)
	{
		switch (copy_u8port)
		{
			case PORTA:SET_BIT(PORT_A, copy_u8pin); break;
			case PORTB:SET_BIT(PORT_B, copy_u8pin); break;
			case PORTC:SET_BIT(PORT_C, copy_u8pin); break;
			case PORTD:SET_BIT(PORT_D, copy_u8pin); break;
	
		}	
	}
	else if(LOW==copy_u8value)
	{
		switch(copy_u8port)
		{
			case PORTA:CLR_BIT(PORT_A, copy_u8pin); break;
			case PORTB:CLR_BIT(PORT_B, copy_u8pin); break;
		    case PORTC:CLR_BIT(PORT_C, copy_u8pin); break;
		    case PORTD:CLR_BIT(PORT_D, copy_u8pin); break;
		}	
	}
	else
	{
		
	}	
	
	
	
}


u8 DIO_u8GetPinValue			(u8 copy_u8port, u8 Copy_U8Pin)
{
	u8 Lcal_U8PinResult=0;
	switch(copy_u8port){

			case PORTA :		Lcal_U8PinResult=GET_BIT(PINA,Copy_U8Pin);	        break;
			case PORTB :		Lcal_U8PinResult=GET_BIT(PINB,Copy_U8Pin); 		    break;
			case PORTC :		Lcal_U8PinResult=GET_BIT(PINC,Copy_U8Pin);			break;
			case PORTD :		Lcal_U8PinResult=GET_BIT(PIND,Copy_U8Pin);			break;

			}


return(Lcal_U8PinResult);
	
	
}

void DIO_voidTogglePin			(u8 copy_u8port, u8 copy_U8pin)
{

		switch (copy_u8port)
		{
					case PORTA:TOG_BIT(PORT_A, copy_U8pin); break;
					case PORTB:TOG_BIT(PORT_B, copy_U8pin); break;
					case PORTC:TOG_BIT(PORT_C, copy_U8pin); break;
					case PORTD:TOG_BIT(PORT_D, copy_U8pin); break;
		}

}





