#include "types.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "usart.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include <string.h>



void main(void)
{
	DDRB =0xff;

	ST_DIO_config_t y = {PORTA, PIN0,OUTPUT};
	ST_DIO_config_t RED = {PORTB, PIN0,OUTPUT};
	ST_DIO_config_t Yellow = {PORTB, PIN2,OUTPUT};
	ST_DIO_config_t Green = {PORTB, PIN3,OUTPUT};

    ST_UART_config_t x={51,EIGHT_BITS,ONE_BIT,DISABLED,TRANSMITTER};
    DIO_voidSetPinDirection(&y);
    DIO_voidSetPinDirection(&RED);
    DIO_voidSetPinDirection(&Yellow);
    DIO_voidSetPinDirection(&Green);
    if( usart_Init(&x) == TRANSMITION_ERROR){
    	DIO_voidSetPinValue(PORTA, PIN0,HIGH);
    }
    uint8_t local;
		//usart_ReceiveString(&local, '\r');
	   // usart_SendString(&local);



    while(1)
    {

    	   usart_ReceiveString(&local, '\r');


    	   // usart_SendString(&local);


    	   if(strcmp("START",&local) == 0)
    	   {
     		  DIO_voidSetPinValue(PORTB, PIN0,LOW);
     		  DIO_voidSetPinValue(PORTB, PIN2,LOW);
    		  DIO_voidSetPinValue(PORTB, PIN3,HIGH);
    		  usart_SendString((uint8_t*)"Green Led On\r");
    	   }
    	   else if(strcmp("WAIT",&local) == 0)
    	   {
      		  DIO_voidSetPinValue(PORTB, PIN0,LOW);
      		  DIO_voidSetPinValue(PORTB, PIN3,LOW);
    		  DIO_voidSetPinValue(PORTB, PIN2,HIGH);
    		  usart_SendString((uint8_t*)"Yellow Led On\r");
    	   }
    	   else if(strcmp("STOP",&local) == 0)
    	   {
      		  DIO_voidSetPinValue(PORTB, PIN3,LOW);
      		  DIO_voidSetPinValue(PORTB, PIN2,LOW);
    		  DIO_voidSetPinValue(PORTB, PIN0,HIGH);
    		  usart_SendString((uint8_t*)"Red Led On\r");
    	   }
    	   else if(strcmp("AT",&local) == 0)
    	   {
    		  usart_SendString((uint8_t*)"OK\r");
    	   }





    }

}
