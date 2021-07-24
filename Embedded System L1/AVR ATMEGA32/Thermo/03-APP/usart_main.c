#include "types.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "usart.h"
#include "DIO_interface.h"
#include "DIO_register.h"




void main(void)
{
	DDRB =0xff;

	ST_DIO_config_t y = {PORTA, PIN0,OUTPUT};
	ST_DIO_config_t X = {PORTA, PIN1,OUTPUT};
    ST_UART_config_t x={51,EIGHT_BITS,ONE_BIT,DISABLED,TRANSMITTER};
    DIO_voidSetPinDirection(&y);
    DIO_voidSetPinDirection(&X);
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
