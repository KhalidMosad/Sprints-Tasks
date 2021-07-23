#include "types.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "usart.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include <string.h>



void main(void)
{

    ST_UART_config_t x={51,EIGHT_BITS,ONE_BIT,DISABLED,TRANSMITTER};
    if( usart_Init(&x) == TRANSMITION_ERROR){
    	DIO_voidSetPinValue(PORTA, PIN0,HIGH);
    }
    uint8_t local;
	usart_ReceiveString(&local, '\r');
	usart_SendString(&local);



    while(1)
    {


    }

}
