/******************************************************************************************************
 * File: LCD16x2.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 18 july 2021
 * LCD 4 Bit Mode
 * Description: This File include definitions of APIs List.
*******************************************************************************************************/
#include"../00-LIB/types.h"
#include"../00-LIB/BIT_MATH.h"
#include"../01-MCAL/01-DIO/DIO_interface.h"
#include"../02-HAL/02-LCD/LCD16x2.h"
#include "avr/delay.h"
void main()
{

    lcd_init();
    lcd_sendChar('K');
    lcd_sendChar('H');    
    lcd_sendChar('L');
    while(1);
}
