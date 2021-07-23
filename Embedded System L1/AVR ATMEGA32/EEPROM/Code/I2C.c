/******************************************************************************************************
 * File: I2C.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 17 july 2021
 * Description: This File include Definitions of APIs List.
*******************************************************************************************************/
#include"types.h"
#include"BIT_Math.h"
#include "I2C.h"
#include "I2C_Config.h"
#include "I2C_reg.h"

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

}


void TWI_SlaveInit(uint8_t Copy_u8Address)
{
	SET_BIT(TWCR,TWEN);
	TWAR = Copy_u8Address;
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
}



void  TWI_VoidStartCondition()
{
	//start condition
	TWCR |= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);   // Clearing TWINT flag by logic one
	// Wait for TWINT Flag set
	while (!(TWCR & (1<<TWINT)));
}

void TWI_VoidRepeatedStartCondition(void)
{
	TWCR = 0X07;
	// Send Repeated Start Condition
	TWCR |= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	// Wait for TWINT Flag set
	while (!(TWCR & (1<<TWINT)));

}

void TWI_VoidMaster_Send_Slave_Address_With_Write(uint8_t Address, uint8_t Copy_Rw)
{

	//Load SLA_W into TWDR Register

	TWDR = (Address<<1);
	if(Copy_Rw == 1)
	{
		SET_BIT(TWDR,R_W);		//Set R\W Bit To Read From Slave
		// Clear TWINT bit in TWCR to start transmission of address
		TWCR |=(1<<TWEN)|(1<<TWINT);
		//Wait for TWINT Flag set
		while(!(TWCR&(1<<TWINT)));

	}
	else
	{
		CLR_BIT(TWDR,R_W);
		// Clear TWINT bit in TWCR to start transmission of address
		TWCR |=(1<<TWEN)|(1<<TWINT);

		//Wait for TWINT Flag set
		while(!(TWCR&(1<<TWINT)));		
	}
}

uint8_t  TWI_VoidMaster_Reading_Byte_From_Slave(uint8_t No_ofBytes)
{
	if(No_ofBytes>1)
	{
			TWCR |=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); 
	}
	else
	{
			TWCR |=(1<<TWEN)|(1<<TWINT); 
	}

	while((TWCR & (1<<TWINT))==0);

	return TWDR;


}

uint8_t TWI_uint8_tReadACK(void)
{
	TWCR &= 0X07;
	TWCR |=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);   //enable Ack
	//Wait for TWINT flag to be set
	while (!(TWCR & (1<<TWINT)));
	// Read Data
	return TWDR;
							
		
}

uint8_t TWI_uint8_tReadNACK(void)
{
	TWCR |=(1<<TWEN)|(1<<TWINT);

	//Wait for TWINT flag to be set
	 while(!(TWCR&(1<<TWINT)));
	// Read Data
	return TWDR;

}

void TWI_VoidMaster_Write_Byte_To_Slave(uint8_t data)
{

	TWCR &= 0X07;
	// Load SLA_W into TWDR Register
	TWDR = data;
	// Clear TWINT bit in TWCR to start transmission of address
	TWCR |=(1<<TWEN)|(1<<TWINT);
	//Wait for TWINT flag to be set
	while(!(TWCR&(1<<TWINT)));

}

I2C_error_states TWI_VoidMaster1_Write_Byte_To_Slave(uint8_t SlaveAddress , uint8_t InternalReg, uint8_t Data)
{
	TWI_VoidStartCondition();
	if(TWI_uint8_tGetStatus() != I2C_START)
	{
		
		return I2C_START_ERROR;
	}

	TWI_VoidMaster_Write_Byte_To_Slave( (SlaveAddress<<1)|WRITE_MODE );
	if(TWI_uint8_tGetStatus() != I2C_MT_SLA_ACK)
	{
		return I2C_MT_SLA_ACK_ERROR;

	}
	TWI_VoidMaster_Write_Byte_To_Slave(InternalReg);
	if(TWI_uint8_tGetStatus ()!= I2C_MT_DATA_ACK)
	{
		return I2C_MT_DATA_ACK_ERROR;

	}	
	TWI_VoidMaster_Write_Byte_To_Slave(Data);
	if(TWI_uint8_tGetStatus()!= I2C_MT_DATA_ACK)
	{
		return I2C_MT_DATA_ACK_ERROR;

	}	
	TWCR |=(1<<TWEN)|(1<<TWINT);
	//Wait for TWINT flag to be set
	while(!(TWCR&(1<<TWINT)));

	TWI_VoidStopCondition();

	return WRITE_NO_ERROR;

}
uint8_t TWI_uint8_tGetStatus(void)
{
	uint8_t status;
	status = (TWSR & I2C_STATUS_CODE_MASK);
	return status;
}
void  TWI_VoidStopCondition()
{

	TWCR |=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);  /* Enable TWI, generate stop */
    while(TWCR&(1<<TWSTO));	               /* Wait until stop condition execution */

}

uint8_t  TWI_VoidMaster1_Reading_Byte_From_Slave(uint8_t SlaveAddress , uint8_t InternalReg)
{
	TWI_VoidStartCondition();
	if(TWI_uint8_tGetStatus() != I2C_START)
	{
		return I2C_START_ERROR;
	}
	TWI_VoidMaster_Write_Byte_To_Slave( (SlaveAddress<<1) | WRITE_MODE );
	if( TWI_uint8_tGetStatus() != I2C_MT_SLA_ACK)
	{
		return I2C_MT_SLA_ACK_ERROR;

	}
	TWI_VoidMaster_Write_Byte_To_Slave(InternalReg);
	if(TWI_uint8_tGetStatus() != I2C_MT_DATA_ACK)
	{
		return I2C_MT_DATA_ACK_ERROR;
	}
	TWI_VoidRepeatedStartCondition();
	if(TWI_uint8_tGetStatus() != I2C_REP_START)
	{
		return I2C_REP_START_ERROR;
	}
	TWI_VoidI2cListen();	
	TWI_VoidMaster_Write_Byte_To_Slave(SlaveAddress<<1|READ_MODE);
	if(TWI_uint8_tGetStatus() != I2C_MR_SLA_ACK)
	{
		return I2C_MR_SLA_ACK_ERROR;
	}	
	uint8_t Result =  TWI_uint8_tReadNACK();
	if(TWI_uint8_tGetStatus() != I2C_MR_DATA_NOT_ACK)
	{
		return I2C_MR_DATA_NOT_ACK_ERROR;
	}	
	TWI_VoidStopCondition();

	return Result;
}

void  TWI_VoidI2cListen(void)
{
	while(!(TWCR&(1<<TWINT)));
}
