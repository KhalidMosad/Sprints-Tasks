/******************************************************************************************************
 * File: I2C.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 17 july 2021
 * Description: This File include APIs List.
*******************************************************************************************************/

#ifndef I2C_H_
#define I2C_H_

typedef enum 
{
    PRESCALLER_SEL_ERROR,
    I2C_MODE_ERROR,
    ACK_ERROR,
    I2C_START_ERROR,
    I2C_MT_SLA_ACK_ERROR,
    I2C_MT_DATA_ACK_ERROR,
    I2C_REP_START_ERROR,
    I2C_MR_SLA_ACK_ERROR,
    I2C_MR_DATA_NOT_ACK_ERROR,
	WRITE_NO_ERROR,
	I2C_NO_ERROR

}I2C_error_states;






typedef struct
{  
  uint32_t I2C_DivisionFactor;          /*!< Specifies the clock frequency.This parameter must be set to a value lower than 400kHz */                     
  uint8_t I2C_Mode;                /*!< Specifies the I2C mode With or without Interrupt. */
  uint8_t I2C_Ack;                 /*!< Enables or disables the acknowledgement.  */
  uint8_t Prescaller;               /*  This Specifies the Prescaller */                                    
}ST_I2C_config_t;



#define ONE             0
#define FOUR            1
#define SIXTEEN         2
#define FOURTY_SIX      3

#define ENABLE      0
#define DISABLE     1

I2C_error_states  TWI_MasterInit(ST_I2C_config_t * configuration);
void TWI_SlaveInit(uint8_t Copy_u8Address);

void  TWI_VidInit(void);
void  TWI_VoidStartCondition(void);
void  TWI_VoidRepeatedStartCondition(void);
void TWI_VoidMaster_Send_Slave_Address_With_Write(uint8_t Address, uint8_t Copy_Rw);
uint8_t    TWI_U8ReadACK(void);
uint8_t    TWI_U8ReadNACK(void);
uint8_t    TWI_uint8_tGetStatus(void);
void  TWI_VoidMaster_Write_Byte_To_Slave(uint8_t data);
uint8_t    TWI_VoidMaster_Reading_Byte_From_Slave(uint8_t No_ofBytes);
void  TWI_VoidStopCondition(void);
I2C_error_states  TWI_VoidMaster1_Write_Byte_To_Slave(uint8_t SlaveAddress , uint8_t InternalReg, uint8_t Data);
uint8_t  TWI_VoidMaster1_Reading_Byte_From_Slave(uint8_t SlaveAddress , uint8_t InternalReg);
void  TWI_VoidI2cListen(void);
I2C_error_states TWI_VoidMaster1_WriteMultiple_Byte_To_Slave(uint8_t SlaveAddress , uint8_t InternalReg, uint8_t * Data);
uint8_t  TWI_VoidMaster1_Reading_MultipleByte_From_Slave(uint8_t SlaveAddress , uint8_t InternalReg,uint8_t * data);
#endif /* I2C_INTERFACE_H_ */

