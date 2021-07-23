/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   22/4/2021           */
/*********Version: 1                     */
/****************Desc: *******************/
#include"STD_Types.h"
#include"BIT_Math.h"
#include "I2C_interface.h"
#include "I2C_Config.h"
#include "I2C_private.h"
#include "avr/delay.h"

void TWI_VoidMasterInit(void)
{

	//Set Prescalar Value 0
	#if PRESCALER == ONE 
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
	#elif PRESCALER == FOUR
		SET_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);	
	#elif PRESCALER == SIXTEEN
		CLR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
	#elif PRESCALER == FOURTY_SIX
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);	
	#endif	

	#if INTERRUPT_O== ENABLE
		SET_BIT(TWCR, TWIE);
	#elif INTERRUPT_O== DISABLE
		CLR_BIT(TWCR, TWIE);
	#endif

	#if ACK_OP== ENABLE
		SET_BIT(TWCR, TWEA);
	#elif ACK_OP== DISABLE
		CLR_BIT(TWCR, TWEA);
	#endif

	//CLK 400kHZ
	TWBR = Division_Factor;

	//Enable I2C Peripheral
	SET_BIT(TWCR,TWEN);

}


void TWI_VoidSlaveInit(u8 Copy_u8Address)
{
	SET_BIT(TWCR,TWEN);
	TWAR = Copy_u8Address;
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
}



void  TWI_VoidStartCondition()
{
	//start condition
	//TWCR = (1<<TWINT)|(1<<TWSTA)| (1<<TWEN)
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

void TWI_VoidMaster_Send_Slave_Address_With_Write(u8 Address, u8 Copy_Rw)
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

u8  TWI_VoidMaster_Reading_Byte_From_Slave(u8 No_ofBytes)
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

u8 TWI_U8ReadACK(void)
{
	TWCR &= 0X07;
	TWCR |=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);   //enable Ack
	//Wait for TWINT flag to be set
	while (!(TWCR & (1<<TWINT)));
	// Read Data
	return TWDR;
							
		
}

u8 TWI_U8ReadNACK(void)
{
	TWCR |=(1<<TWEN)|(1<<TWINT);

	//Wait for TWINT flag to be set
	 while(!(TWCR&(1<<TWINT)));
	// Read Data
	return TWDR;

}

void TWI_VoidMaster_Write_Byte_To_Slave(u8 data)
{

	TWCR &= 0X07;
	// Load SLA_W into TWDR Register
	TWDR = data;
	// Clear TWINT bit in TWCR to start transmission of address
	TWCR |=(1<<TWEN)|(1<<TWINT);
	//Wait for TWINT flag to be set
	while(!(TWCR&(1<<TWINT)));

}

u8 TWI_VoidMaster1_Write_Byte_To_Slave(u8 SlaveAddress , u8 InternalReg, u8 Data)
{
	TWI_VoidStartCondition();
	if(TWI_U8GetStatus() != I2C_START)
	{

		return 8;
	}

	TWI_VoidMaster_Write_Byte_To_Slave((SlaveAddress<<1)| WRITE_MODE );
	if(TWI_U8GetStatus() != I2C_MT_SLA_ACK)
	{
		return 15;

	}
	TWI_VoidMaster_Write_Byte_To_Slave(InternalReg);
	if(TWI_U8GetStatus() != I2C_MT_DATA_ACK)
	{
		return 10;

	}
	TWI_VoidMaster_Write_Byte_To_Slave(Data);
	if(TWI_U8GetStatus() != I2C_MT_DATA_ACK)
	{
		return 11;

	}
	TWCR |=(1<<TWEN)|(1<<TWINT);
	//Wait for TWINT flag to be set
	while(!(TWCR&(1<<TWINT)));

	TWI_VoidStopCondition();

	return 5;

}


u8 TWI_U8GetStatus(void)
{
	u8 status;
	status = (TWSR & I2C_STATUS_CODE_MASK);
	return status;
}


void  TWI_VoidStopCondition()
{
	//TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	TWCR |=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);  /* Enable TWI, generate stop */
    while(TWCR&(1<<TWSTO));	               /* Wait until stop condition execution */

}

u8  TWI_VoidMaster1_Reading_Byte_From_Slave(u8 SlaveAddress , u8 InternalReg)
{
	TWI_VoidStartCondition();
	if(TWI_U8GetStatus() != I2C_START)
	{
		return 6;
	}
	TWI_VoidMaster_Write_Byte_To_Slave(SlaveAddress<<1 | WRITE_MODE);
	if(TWI_U8GetStatus()  != I2C_MT_SLA_ACK)
	{
		return 3;
	}
	TWI_VoidMaster_Write_Byte_To_Slave(InternalReg);
	if(TWI_U8GetStatus()  != I2C_MT_DATA_ACK)
	{

		return 9;
	}
	TWI_VoidRepeatedStartCondition();
	if(TWI_U8GetStatus()  != I2C_REP_START)
	{
		return 10;
	}
	TWI_VoidI2cListen();
	TWI_VoidMaster_Write_Byte_To_Slave(SlaveAddress<<1 | READ_MODE);
	if(TWI_U8GetStatus()  != I2C_MR_SLA_ACK)
	{
		return 3 ;
	}
	u8 Result =  TWI_U8ReadNACK() ;
	if(TWI_U8GetStatus()  != I2C_MR_DATA_NOT_ACK)
	{
		return 12;
	}
	TWI_VoidStopCondition();


	return Result;
}

void  TWI_VoidI2cListen(void)
{
	while(!(TWCR&(1<<TWINT)));
}
