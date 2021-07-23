/******************************************************************************************************
 * File: Keypad4x4.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 18 july 2021
 * Description: This File include definitions of APIs List.
*******************************************************************************************************/
#include"../../00-LIB/types.h"
#include"../../00-LIB/BIT_MATH.h"
#include"../../01-MCAL/01-DIO/DIO_interface.h"
#include"Keypad4x4_config.h"
#include"Keypad4x4.h"
#include<avr/delay.h>



#define		ROWSHIFT	4

static uint8_t array_keypad[4][4]={	{'7','8','9','/'},
									{'4','5','6','*'},
									{'1','2','3','-'},
									{'Q','0','=','+'}};

void Keypad_init(void)
{
	ST_DIO_config_t Col0 = {COLS_ROWSPORT,COLS0,OUTPUT};
	ST_DIO_config_t Col1 = {COLS_ROWSPORT,COLS1,OUTPUT};
	ST_DIO_config_t Col2 = {COLS_ROWSPORT,COLS2,OUTPUT};
	ST_DIO_config_t Col3 = {COLS_ROWSPORT,COLS3,OUTPUT};


	ST_DIO_config_t row0 = {COLS_ROWSPORT,ROW0,INPUT};
	ST_DIO_config_t row1 = {COLS_ROWSPORT,ROW1,INPUT};
	ST_DIO_config_t row2 = {COLS_ROWSPORT,ROW2,INPUT};
	ST_DIO_config_t row3 = {COLS_ROWSPORT,ROW3,INPUT};

	DIO_voidSetPinDirection(&Col0);
	DIO_voidSetPinDirection(&Col1);
	DIO_voidSetPinDirection(&Col2);
	DIO_voidSetPinDirection(&Col3);

	DIO_voidSetPinDirection(&row0);
	DIO_voidSetPinDirection(&row1);
	DIO_voidSetPinDirection(&row2);
	DIO_voidSetPinDirection(&row3);
	
	DIO_voidSetPinValue(COLS_ROWSPORT,ROW0 ,HIGH);
	DIO_voidSetPinValue(COLS_ROWSPORT,ROW1 ,HIGH);
	DIO_voidSetPinValue(COLS_ROWSPORT,ROW2 ,HIGH);
  	DIO_voidSetPinValue(COLS_ROWSPORT,ROW3 ,HIGH);

	DIO_voidSetPinValue(COLS_ROWSPORT,COLS0,HIGH);
	DIO_voidSetPinValue(COLS_ROWSPORT,COLS1,HIGH);
	DIO_voidSetPinValue(COLS_ROWSPORT,COLS2,HIGH);
  	DIO_voidSetPinValue(COLS_ROWSPORT,COLS3,HIGH);
}
uint8_t Keypad_u8ReadPin(void)
{
	int result = DEFAULT_KEY ;

	DIO_voidSetPinValue(COLS_ROWSPORT,ROW0 ,HIGH);
	DIO_voidSetPinValue(COLS_ROWSPORT,ROW1 ,HIGH);
	DIO_voidSetPinValue(COLS_ROWSPORT,ROW2 ,HIGH);
  	DIO_voidSetPinValue(COLS_ROWSPORT,ROW3 ,HIGH);
	for (uint8_t row = 0; row<ROWSHIFT; row++)
	{
		DIO_voidSetPinValue(COLS_ROWSPORT,row,LOW);
		for(uint8_t col = 0; col<ROWSHIFT; col++)
		{
			if(DIO_uint8_tGetPinValue(COLS_ROWSPORT,col+ROWSHIFT)== 0)
			{
				result = array_keypad[row][col];				
				while(DIO_uint8_tGetPinValue(COLS_ROWSPORT,col+ROWSHIFT)== 0);
				_delay_ms(10);	
			}
			
		}
		DIO_voidSetPinValue(COLS_ROWSPORT,row,HIGH);
	}
	return result;

}




