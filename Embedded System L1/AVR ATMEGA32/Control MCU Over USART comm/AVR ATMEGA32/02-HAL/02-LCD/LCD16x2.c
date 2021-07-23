/******************************************************************************************************
 * File: LCD16x2.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 18 july 2021
 * LCD 4 Bit Mode
 * Description: This File include definitions of APIs List.
*******************************************************************************************************/
#include"../../00-LIB/types.h"
#include"../../00-LIB/BIT_MATH.h"
#include"../../01-MCAL/01-DIO/DIO_interface.h"
#include"LCD16x2Config.h"
#include"LCD16x2.h"
#include "avr/delay.h"




#define TWO_LINES_5X7_DOT_MATRIX    0b00101000
#define DISPLAY_ON_CURSOR_OFF       0x0c
#define DISPLAY_CLEAR               0x01
#define INCREMENT_CURSOR            0x06
void lcd_init(void)
{
    _delay_ms(40);    
    ST_DIO_config_t rs_pin  = {LS_PIN,OUTPUT};
    ST_DIO_config_t E_pin   = {EN_PIN,OUTPUT};    
    ST_DIO_config_t R_W_pin = {R_W_PIN,OUTPUT};

    DIO_voidSetPinDirection(&rs_pin);
    DIO_voidSetPinDirection(&E_pin);
    DIO_voidSetPinDirection(&R_W_pin);
    DIO_VoidSetPortDirection(LCD_DATA_PORT,OUTPUT);

    lcd_command(0x33);
    lcd_command(0x32);    
    lcd_command(TWO_LINES_5X7_DOT_MATRIX);
    _delay_ms(2);
    lcd_command(DISPLAY_ON_CURSOR_OFF);
    _delay_ms(1);
    lcd_command(DISPLAY_CLEAR);
    _delay_ms(2);
    lcd_command(INCREMENT_CURSOR);
    

}
void lcd_command(uint8_t cmd)
{
    DIO_voidSetPinValue(LS_PIN,LOW);
    DIO_voidSetPinValue(R_W_PIN,LOW);    
    DIO_VidSetPortValue(LCD_DATA_PORT,((LCD_DATA_PORT&0x0f) | (cmd&0xf0)));
    DIO_voidSetPinValue(EN_PIN,HIGH);    
    _delay_ms(2);    
    DIO_voidSetPinValue(EN_PIN,LOW);
    _delay_ms(2);     
    DIO_VidSetPortValue(LCD_DATA_PORT,((LCD_DATA_PORT&0x0f) | ((cmd<<4)&0xf0)));
    DIO_voidSetPinValue(EN_PIN,HIGH);  
    _delay_ms(2);   
    DIO_voidSetPinValue(EN_PIN,LOW);        
}
void lcd_sendChar(uint8_t data)
{
    DIO_voidSetPinValue(LS_PIN,HIGH);
    DIO_voidSetPinValue(R_W_PIN,LOW);    
    DIO_VidSetPortValue(LCD_DATA_PORT,((LCD_DATA_PORT&0x0f) | (data&0xf0)));
    DIO_voidSetPinValue(EN_PIN,HIGH);    
    _delay_ms(2);    
    DIO_voidSetPinValue(EN_PIN,LOW);
    _delay_ms(2);     
    DIO_VidSetPortValue(LCD_DATA_PORT,((LCD_DATA_PORT&0x0f) | ((data<<4)&0xf0)));
    DIO_voidSetPinValue(EN_PIN,HIGH);  
    _delay_ms(2);   
    DIO_voidSetPinValue(EN_PIN,LOW);  
}
void lcd_sendString(uint8_t * data)
{



}
