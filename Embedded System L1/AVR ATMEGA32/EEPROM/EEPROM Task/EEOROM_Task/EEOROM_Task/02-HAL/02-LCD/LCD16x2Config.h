/******************************************************************************************************
 * File: LCD16x2Config.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 18 july 2021
 * LCD 4 Bit Mode
 * Description: This File include Configurations.
*******************************************************************************************************/


/* Select the Required port and pin For LCD LS, R/W, E pins 
Select in pairs */

#define LS_PIN   PORTA,PIN0
#define EN_PIN   PORTA,PIN1
#define R_W_PIN  PORTA,PIN2

#define LCD_DATA_PORT PORTA