/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   22/4/2021           */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


#define ONE             0
#define FOUR            1
#define SIXTEEN         2
#define FOURTY_SIX      3

#define ENABLE      0
#define DISABLE     1

void  TWI_VoidMasterInit(void);
void  TWI_VoidSlaveInit(u8 Copy_u8Address);
void  TWI_VidInit(void);
void  TWI_VoidStartCondition(void);
void  TWI_VoidRepeatedStartCondition(void);
void  TWI_VoidMaster_Send_Slave_Address_With_Write(u8 Address, u8 Copy_Rw);
u8    TWI_U8ReadACK(void);
u8    TWI_U8ReadNACK(void);
u8    TWI_U8GetStatus(void);
void  TWI_VoidMaster_Write_Byte_To_Slave(u8 data);
u8    TWI_VoidMaster_Reading_Byte_From_Slave(u8 No_ofBytes);
void  TWI_VoidStopCondition(void);
u8  TWI_VoidMaster1_Write_Byte_To_Slave(u8 SlaveAddress , u8 InternalReg, u8 Data);
u8  TWI_VoidMaster1_Reading_Byte_From_Slave(u8 SlaveAddress , u8 InternalReg);
void  TWI_VoidI2cListen(void);
#endif /* I2C_INTERFACE_H_ */

