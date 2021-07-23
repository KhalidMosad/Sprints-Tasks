/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   8/2/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef EEPROM_H_
#define EEPROM_H_


void EEPROM_VoidInit(void);
void EEPROM_VoidWriteDataByte(uint8_t SlaveAddress , uint8_t InternalReg, uint8_t Data);

uint8_t EEPROM_u8ReadDataByte(uint8_t SlaveAddress , uint8_t InternalReg);

#endif /* I2C_INTERFACE_H_ */

