/******************************************************************************************************
 * File: usart.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 14 july 2021
 * Description: This File include APIs List.
*******************************************************************************************************/
#ifndef USART_H_
#define USART_H_



#define	DISABLED		0
#define	ENABLED_EVEN	1
#define	ENABLED_ODD		2

#define	ONE_BIT			0
#define	TWO_BIT			1

#define FIVE_BITS		5
#define SIX_BITS		6
#define SEVEN_BITS		7
#define EIGHT_BITS		8
#define NINE_BITS		9

#define TRANSMITTER     0
#define RECEIVER        1
#define TRANSMITTER_RECEIVER      2



typedef struct ST_UART_config_t{

    uint16_t USART_BaudRate;    /*!< This member configures the USART communication baud rate.The baud rate is computed using the following formula:
                                           - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                            - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */

    uint8_t USART_WordLength;       /*!< Specifies the number of data bits transmitted or received in a frame.This parameter can be a value of */
    uint8_t USART_StopBits;            /*!< Specifies the number of stop bits transmitted.*/
    uint8_t USART_Parity;              /*!< Specifies the parity mode.
                                           This parameter can be a value of 
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */
 
     uint8_t USART_Mode;                /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.*/

}ST_UART_config_t;


typedef enum
{
    NO_ERROR,
    WORD_LENGTH_ERROR,
    STOP_BIT_ERROR,
    PARITY_ERROR,
    MODE_ERROR,
    TRANSMITION_ERROR,
	NO_TRANSMITION_ERROR,
	STRING_NOERROR
}error_state;

/*****************************************************************
 * Function: usart_Init.
 * Description: 
 *      This Function Init the USART According to The required configurations.
 * Parameters: 
 *      ST_UART_config_t * USART_InitStruct.
 * Return: 
 *        error_state
 *               
*************************************************************************/
error_state usart_Init(ST_UART_config_t * USART_InitStruct);
/*****************************************************************
 * Function: usart_SendData.
 * Description: 
 *      This Function send the required data Through USART.
 * Parameters: 
 *      uint8_t data_transmitted
 * Return: 
 *        error_state
 *               
*************************************************************************/
error_state usart_SendData(uint8_t data_transmitted);

/*****************************************************************
 * Function: usart_ReceiveData.
 * Description: 
 *      This Function Receive the required data Through USART.
 * Parameters: 
 *      uint8_t data_transmitted
 * Return: 
 *        it returns uint8_t data 
 *               
*************************************************************************/
uint8_t usart_ReceiveData(void);

/*****************************************************************
 * Function: usart_SendString.
 * Description: 
 *      This Function send the required string Through USART.
 * Parameters: 
 *      uint8_t *str
 * Return: 
 *        it returns error_state 
 *               
*************************************************************************/
error_state usart_SendString(uint8_t *str);

/*****************************************************************
 * Function: usart_ReceiveString.
 * Description: 
 *      This Function RECEIVER the required string Through USART.
 * Parameters: 
 *      uint8_t * au8data ,uint8_t terminating_character
 * Return: 
 *        it returns pointer to the Received data. 
 *               
*************************************************************************/
uint8_t * usart_ReceiveString(uint8_t * au8data ,uint8_t terminating_character);



#endif
