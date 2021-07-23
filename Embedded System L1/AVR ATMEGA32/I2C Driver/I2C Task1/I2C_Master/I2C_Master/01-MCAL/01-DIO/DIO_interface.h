/******************************************************************************************************
 * File: DIO_program.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 10 july 2021
 * Description: This File include Declarations of functions and Strucrures and some Macros.
*******************************************************************************************************/

#ifndef  DIO_interface_h_
#define  DIO_interface_h_

#define		PORTA	(uint8_t)0
#define		PORTB	(uint8_t)1
#define		PORTC	(uint8_t)2
#define		PORTD	(uint8_t)3



#define 	PIN0	(uint8_t)0
#define 	PIN1	(uint8_t)1
#define 	PIN2	(uint8_t)2
#define 	PIN3	(uint8_t)3
#define 	PIN4	(uint8_t)4
#define 	PIN5	(uint8_t)5
#define 	PIN6	(uint8_t)6
#define 	PIN7	(uint8_t)7


#define		INPUT	(uint8_t)0
#define		OUTPUT	(uint8_t)1

#define		HIGH	(uint8_t)1
#define		LOW		(uint8_t)0


typedef struct ST_DIO_config_t{
uint8_t port_no;   // Port name
uint8_t pin_no;	   // Pin name
uint8_t state; // input or output
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
 *      uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin, uint8_t copy_uint8_tvalue
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void DIO_voidSetPinValue	(uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin, uint8_t copy_uint8_tvalue);

/*****************************************************************
 * Function: DIO_uint8_tGetPinValue.
 * Description: 
 *      This Function Gives the state of the required pin 
 * Parameters: 
 *      uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin
 * Return: 
 *        Nothing
 *               
*************************************************************************/
uint8_t DIO_uint8_tGetPinValue		(uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin);

/*****************************************************************
 * Function: DIO_voidTogglePin.
 * Description: 
 *      This Function Change the state of the required pin 
 * Parameters: 
 *      uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void DIO_voidTogglePin		(uint8_t copy_uint8_tport, uint8_t copy_uint8_tpin);


#endif
