#include"../00-LIB/types.h"
#include"../00-LIB/BIT_Math.h"
#include "../01-MCAL/05-TWI/I2C.h"
#include "../01-MCAL/01-DIO/DIO_register.h"
void main()
{
	DDRB = 0xff;
	TWI_SlaveInit('A');
	TWI_VoidI2cListen();
	uint8_t i = 0;
	i= TWI_VoidMaster_Reading_Byte_From_Slave(1);
	
	PORT_B = i;
	while(1);
}