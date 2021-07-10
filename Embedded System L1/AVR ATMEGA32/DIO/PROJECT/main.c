
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "avr/delay.h"

void main(void)
{
    ST_DIO_config_t Led ={PORTA,PIN0,OUTPUT};
    ST_DIO_config_t Button ={PORTC,PIN0,INPUT};
    DIO_voidSetPinDirection(&Led);
    while (1)
    {
    	if(DIO_u8GetPinValue(PORTC,PIN0)==1)
    	{
			while(DIO_u8GetPinValue(PORTC,PIN0)==1);
			_delay_ms(10);
    		DIO_voidTogglePin(PORTA,PIN0);
    	}
    }
}
