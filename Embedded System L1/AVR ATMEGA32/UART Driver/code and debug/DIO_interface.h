/******************************************************************************************************
 * File: DIO_program.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 10 july 2021
 * Description: This File include Declarations of functions and Strucrures and some Macros.
*******************************************************************************************************/

#ifndef  DIO_interface_h_
#define  DIO_interface_h_

#define		PORTA	(u8)0
#define		PORTB	(u8)1
#define		PORTC	(u8)2
#define		PORTD	(u8)3



#define 	PIN0	(u8)0
#define 	PIN1	(u8)1
#define 	PIN2	(u8)2
#define 	PIN3	(u8)3
#define 	PIN4	(u8)4
#define 	PIN5	(u8)5
#define 	PIN6	(u8)6
#define 	PIN7	(u8)7


#define		INPUT	(u8)0
#define		OUTPUT	(u8)1

#define		HIGH	(u8)1
#define		LOW		(u8)0


typedef struct ST_DIO_config_t{
u8 port_no;   // Port name
u8 pin_no;	   // Pin name
u8 state; // input or output
}ST_DIO_config_t;


/*****************************************************************
 * Function: DIO_VoidSetPinDirection.
 * Description: 
 *      This Function Set the Direction of DIO Pin whether OUTPUT or INPUT after selecting the PORT NUMBER AND PIN NUMBER 
 * Parameters: 
 *      ST_DIO_config_t * configurations.
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void DIO_voidSetPinDirection(ST_DIO_config_t * configurations);

/*****************************************************************
 * Function: DIO_VoidSetPinValue.
 * Description: 
 *      This Function Set the Value of DIO Pin whether HIGH or LOW after selecting the PORT NUMBER AND PIN NUMBER 
 * Parameters: 
 *      u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void DIO_voidSetPinValue	(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value);

/*****************************************************************
 * Function: DIO_u8GetPinValue.
 * Description: 
 *      This Function Gives the state of the required pin 
 * Parameters: 
 *      u8 copy_u8port, u8 copy_u8pin
 * Return: 
 *        Nothing
 *               
*************************************************************************/
u8 DIO_u8GetPinValue		(u8 copy_u8port, u8 copy_u8pin);

/*****************************************************************
 * Function: DIO_voidTogglePin.
 * Description: 
 *      This Function Change the state of the required pin 
 * Parameters: 
 *      u8 copy_u8port, u8 copy_u8pin
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void DIO_voidTogglePin		(u8 copy_u8port, u8 copy_U8pin);


#endif
