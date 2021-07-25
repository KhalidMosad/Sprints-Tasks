/******************************************************************************************************
 * File: adc_main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 24 july 2021
 * LCD 4 Bit Mode
 * Description: This File include definitions of APIs List.
*******************************************************************************************************/
#include"types.h"
#include"BIT_MATH.h"
#include"ADC.h"
#include"DIO_interface.h"
#include"LCD16x2.h"
#include "Keypad4x4.h"
#include <avr/delay.h>

uint8_t ConvertFromAscitoInt(uint8_t * data)
{
	uint8_t address = 0;
	address = (data[0]-'0')*10 + (data[1]-'0');

	return address;
}



void main(void)
{
	uint8_t KeyRead[5];
    uint8_t buffer[50];
    uint16_t digital_value = 0;
    ST_DIO_config_t PB0 = {PORTB,PIN0,OUTPUT};
    DIO_voidSetPinDirection(&PB0);
    ST_ADC__config_t ch0 = {DISABLE,ACCC_PIN_SAMEVCC,ADJUST_RIGHT,ADC_C0,F_128};
    lcd_init();
    adc_Init(&ch0);
    adc_Enable();
    Keypad_init();
    uint8_t i = 0;
    lcd_sendString("Set Temp:");
    uint8_t data = 0;
    while(1)
    {
    	data = Keypad_u8ReadPin();
    	if(data != DEFAULT_KEY)
    	{
    		KeyRead[i]= data;
    		lcd_sendChar(data);

    		i++;
    	}
    	if(data == '=')
    	{
    		break;
    	}

    }

    lcd_clear();
    uint8_t Value_set = ConvertFromAscitoInt(KeyRead);
    while(1)
    {


        digital_value = adc_Read(&ch0);
        digital_value *= 4.88;
        digital_value/=10;

        sprintf(buffer,"%d",digital_value);
        lcd_sendString("Temp = ");
        lcd_sendString(buffer);
        if(digital_value > Value_set)
        {
        	DIO_voidSetPinValue(PORTB,PIN0,HIGH);
        }
        else
        {
        	DIO_voidSetPinValue(PORTB,PIN0,LOW);
        }
		_delay_ms(1000);
		lcd_clear();
    }

    
}
