/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   8/2/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


u8 EEPROM_VoidWriteDataByte(u8 SlaveAddress , u8 InternalReg, u8 Data);

u8 EEPROM_u8ReadDataByte(u8 SlaveAddress , u8 InternalReg);

#endif /* I2C_INTERFACE_H_ */

