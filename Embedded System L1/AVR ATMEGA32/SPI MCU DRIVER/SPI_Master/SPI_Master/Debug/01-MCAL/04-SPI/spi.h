/******************************************************************************************************
 * File: spi.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 14 july 2021
 * Description: This File include APIs List.
*******************************************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#define	F_4				0
#define	F_16			1
#define	F_64			2
#define	F_128			3
#define	F_2				4
#define	F_8				5
#define	F_32			6
#define	F_64D  			8

#define	LEADING_RISING	0
#define	LEADING_FALLING	1

#define	LEADING_SAMPLE	0
#define	LEADING_SETUP	1

#define	MASTER			0
#define	SLAVE			1

#define	LSB_FIRST		0
#define	MSB_FIRST		1

#define	INT_ENABLE		0
#define	INT_DISABLE		1

typedef enum
{
    NO_ERROR,
    MODE_ERROR,
    CPHA_ERROR,
    FIRST_BITERROR,
    CPOL_SELECTION_ERROR,
    BAUDRATE_ERROR,
    OP_MODE_ERROR


}spi_errorstatus;




typedef struct ST_SPI_config_t{

  uint8_t SPI_Mode;                /*!< Specifies the SPI operating mode Master or Slave */
  uint8_t SPI_OP_Mode;                /*!< Specifies the SPI operating mode Interrupt or without */                                       
  uint8_t SPI_CPOL;                /*!< Specifies the serial clock steady state whether LEADING_RISING or LEADING_FALLING*/                                 
  uint8_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture LEADING_SAMPLE or LEADING_SETUP*/
  uint8_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                       used to configure the transmit and receive SCK clock. */
  uint8_t SPI_FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.*/
}ST_SPI_config_t;

/*****************************************************************
 * Function: SPI_Init.
 * Description: 
 *      This Function Init the SPI According to The required configurations.
 * Parameters: 
 *      ST_SPI_config_t * SPI_InitStruct.
 * Return: 
 *        spi_errorstatus
 *               
*************************************************************************/
spi_errorstatus SPI_Init(ST_SPI_config_t * SPI_InitStruct);

/*****************************************************************
 * Function: SPI_SendData.
 * Description: 
 *      This Function send the required data Through SPI.
 * Parameters: 
 *      uint8_t data
 * Return: 
 *      uint8_t data
 *               
*************************************************************************/
uint8_t SPI_SendData(uint8_t data);

/*****************************************************************
 * Function: SPI_ReceiveData.
 * Description: 
 *      This Function Receive the required data Through SPI.
 * Parameters: 
 *      void
 * Return: 
 *      uint8_t data
 *               
*************************************************************************/
uint8_t SPI_ReceiveData(void);

/*****************************************************************
 * Function: SPI_SETCALLBACK.
 * Description: 
 *      This Function Set the ISR function in case of interrupt.
 * Parameters: 
 *      void(*ptr)(void)
 * Return: 
 *      void
 *               
*************************************************************************/
void SPI_SETCALLBACK(void(*ptr)(void));


#endif 
