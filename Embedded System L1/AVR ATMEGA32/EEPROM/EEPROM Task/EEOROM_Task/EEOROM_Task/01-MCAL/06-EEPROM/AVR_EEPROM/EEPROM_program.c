/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   8/2/2021          */
/*********Version: 1                     */
/****************Desc: *******************/
#include"STD_Types.h"
#include"BIT_Math.h"

#include "I2C_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

void EEPROM_VoidInit(void)
{
	TWI_VoidMasterInit();
}

u8 EEPROM_VoidWriteDataByte(u8 SlaveAddress , u8 InternalReg, u8 Data)
{
	u8 x= TWI_VoidMaster1_Write_Byte_To_Slave(SlaveAddress,InternalReg,Data);
	return x;
}


u8 EEPROM_u8ReadDataByte(u8 SlaveAddress , u8 InternalReg)
{
	u8 Result= TWI_VoidMaster1_Reading_Byte_From_Slave(SlaveAddress,InternalReg);

	return Result;

}







