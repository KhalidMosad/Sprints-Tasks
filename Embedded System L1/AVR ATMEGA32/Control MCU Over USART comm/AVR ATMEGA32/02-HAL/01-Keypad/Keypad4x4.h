/******************************************************************************************************
 * File: Keypad4x4.h
 * Author: Khalid Mosaad Zakaria
 * Data: 18 july 2021
 * Description: This File include declaration of APIs List.
*******************************************************************************************************/

#ifndef KETPAD_INTERFACE_H_
#define KETPAD_INTERFACE_H_



#define 	PIN0	0
#define 	PIN1	1
#define 	PIN2	2
#define 	PIN3	3

#define 	PIN4	4
#define 	PIN5	5
#define 	PIN6	6
#define 	PIN7	7




#define	 DEFAULT_KEY 'C'

void Keypad_init(void);

uint8_t Keypad_u8ReadPin(void);





#endif

