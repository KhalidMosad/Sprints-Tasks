/******************************************************************************************************
 * File: adc_main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 24 july 2021
 * LCD 4 Bit Mode
 * Description: This File include definitions of APIs List.
*******************************************************************************************************/
#include"../00-LIB/types.h"
#include"../00-LIB/BIT_MATH.h"
#include"../01-MCAL/07-ADC/ADC.h"
#include"../01-MCAL/01-DIO/DIO_interface.h"
#include"../02-HAL/02-LCD/LCD16x2.h"
#include "avr/delay.h"

void main(void)
{
    uint8_t buffer[50];
    uint16_t digital_value = 0;
    ST_ADC__config_t ch0 = {DISABLE,ACCC_PIN_SAMEVCC,ADJUST_RIGHT,ADC_C0,F_128};
    lcd_init();
    adc_Init(&ch0);
    adc_Enable();

    while(1)
    {
        digital_value = adc_Read(&ch0);
        digital_value *= 4.88;
        digital_value/=10;

        sprintf(buffer,"%d",digital_value);
        lcd_sendString("Temp = ");
        lcd_sendString(buffer);
		_delay_ms(1000);
		lcd_clear();
    }

    
}