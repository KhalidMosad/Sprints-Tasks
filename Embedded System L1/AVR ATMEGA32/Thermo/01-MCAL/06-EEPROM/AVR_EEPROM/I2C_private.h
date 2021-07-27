/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   22/4/2021           */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*TWAR Register*/
#define TWA6	7
#define TWA5	6
#define TWA4	5
#define TWA3	4
#define TWA2	3
#define TWA1	2
#define TWA0	1
#define TWGCE	0

#define TWAR 		*((volatile u8*)0x22)

/*TWCR Register*/
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define R2 		1
#define TWIE	0

#define TWCR  		*((volatile u8*)0x56)

/*TWSR Register*/
#define TWS7	7
#define TWS6	6
#define TWS5	5
#define TWS4	4
#define TWS3	3
#define R 		2
#define TWPS1	1
#define TWPS0	0

#define TWSR 		*((volatile u8*)0x21)



#define TWBR 		*((volatile u8*)0x20)
#define TWDR 		*((volatile u8*)0x23)


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
#endif /* I2C_PRIVATE_H_ */
