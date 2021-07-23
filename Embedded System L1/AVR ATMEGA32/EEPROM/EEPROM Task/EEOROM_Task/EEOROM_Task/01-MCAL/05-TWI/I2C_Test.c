/******************************************************************************************************
 * File: I2C_Test.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 23 july 2021
 * Description: This File include Registers of usart.
*******************************************************************************************************/
#include "../../00-LIB/types.h"
#include "../../00-LIB/BIT_MATH.h"
#include "I2C.h"
#include <assert.h>
#include <stdio.h>

/*TWAR Register*/
#define TWA6	7
#define TWA5	6
#define TWA4	5
#define TWA3	4
#define TWA2	3
#define TWA1	2
#define TWA0	1
#define TWGCE	0
/*TWCR Register*/
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define R2 		1
#define TWIE	0




/*TWSR Register*/
#define TWS7	7
#define TWS6	6
#define TWS5	5
#define TWS4	4
#define TWS3	3
#define R 		2
#define TWPS1	1
#define TWPS0	0

// Status Codes for Master Transmitter Mode Definition page 183&186 in Data Sheet
#define I2C_START       	  0x08
#define I2C_REP_START   	  0x10
#define I2C_MT_SLA_ACK  	  0x18
#define I2C_MT_SLA_NOT_ACK    0x20
#define I2C_MT_DATA_ACK  	  0x28
#define I2C_MT_DATA_NOT_ACK   0x30
#define I2C_MT_ARB_LOST  	  0x38
#define I2C_MR_ARB_LOST   	  0x38
#define I2C_MR_SLA_ACK  	  0x40
#define I2C_MR_SLA_NOT_ACK    0x48
#define I2C_MR_DATA_ACK       0x50
#define I2C_MR_DATA_NOT_ACK   0x58

#define I2C_STATUS_CODE_MASK   0xF8

#define WRITE_MODE     0x00

#define READ_MODE     0x01


#define R_W             0


uint8_t TWAR;
uint8_t TWCR;
uint8_t TWSR;
uint8_t TWBR ;
uint8_t TWDR ;
I2C_error_states  TWI_MasterInit(ST_I2C_config_t * configuration)
{

	//Set Prescalar Value 0
	if(configuration->Prescaller== ONE)
	{
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);		
	} 
	else if(configuration->Prescaller == FOUR)
	{
		SET_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);		
	}	
	else if(configuration->Prescaller == SIXTEEN)
	{
		CLR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);		
	}
	else if(configuration->Prescaller == FOURTY_SIX)
	{
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);	
	}
	else
	{
		return PRESCALLER_SEL_ERROR; 
	}
	if(configuration->I2C_Mode== ENABLE)
	{
		SET_BIT(TWCR, TWIE);		
	}
	else if(configuration->I2C_Mode== DISABLE)
	{
		CLR_BIT(TWCR, TWIE);		
	}
	else
	{
		return I2C_MODE_ERROR;
	}
	if(configuration->I2C_Ack== ENABLE)
	{
		SET_BIT(TWCR, TWEA);		
	}
	else if(configuration->I2C_Ack== DISABLE)
	{
		CLR_BIT(TWCR, TWEA);		
	}
	else
	{
		return ACK_ERROR;
	}

	//CLK 400kHZ
	TWBR = configuration->I2C_DivisionFactor;

	//Enable I2C Peripheral
	SET_BIT(TWCR,TWEN);
    return I2C_NO_ERROR;

}


void TWI_SlaveInit(uint8_t Copy_u8Address)
{
	SET_BIT(TWCR,TWEN);
	TWAR = Copy_u8Address;
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
}


void TWI_MasterInitTest(void)
{
	ST_I2C_config_t Master = {32,DISABLE,ENABLE,ONE};
    assert(TWI_MasterInit(&Master) == I2C_NO_ERROR);
    assert(TWCR== 0X44);
    assert(TWBR == 32);
    assert(TWSR==0);

}

void TWI_SlaveInitTest()
{
    TWI_SlaveInit('A');
    assert(TWAR== 'A');
    assert(TWCR == 0xC4);


}


void main()
{
    TWI_MasterInitTest();
    TWI_SlaveInitTest();
    printf("No Error");



}