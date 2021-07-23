#include"../00-LIB/types.h"
#include"../00-LIB/BIT_Math.h"
#include "../01-MCAL/05-TWI/I2C.h"
void main()
{
	ST_I2C_config_t Master = {32,DISABLE,ENABLE,ONE};
	TWI_MasterInit(&Master);
	TWI_VoidStartCondition();
	// 0 for write
	TWI_VoidMaster_Send_Slave_Address_With_Write('A',0);
	TWI_VoidMaster_Write_Byte_To_Slave('A');
	TWI_VoidStopCondition();
	while(1);
}