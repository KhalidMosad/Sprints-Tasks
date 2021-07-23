/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   8/2/2021          */
/*********Version: 1                     */
/****************Desc: *******************/


#include"../../00-LIB/types.h"
#include"../../00-LIB/BIT_Math.h"

#include "../05-TWI/I2C.h"
#include "EEPROM.h"

#define EEPROM_FIXED_ADDRESS    0x50
#define EEPROM_A2_VALUE             0
void EEPROM_VoidInit(void)
{
	ST_I2C_config_t Master = {32,DISABLE,ENABLE,ONE};
	TWI_MasterInit(&Master);
}

void EEPROM_VoidWriteDataByte(uint8_t SlaveAddress , uint8_t InternalReg, uint8_t Data)
{
	 TWI_VoidMaster1_Write_Byte_To_Slave(SlaveAddress,InternalReg,Data);
	
}


uint8_t EEPROM_u8ReadDataByte(uint8_t SlaveAddress , uint8_t InternalReg)
{
	uint8_t Result= TWI_VoidMaster1_Reading_Byte_From_Slave(SlaveAddress,InternalReg);
	return Result;
}







