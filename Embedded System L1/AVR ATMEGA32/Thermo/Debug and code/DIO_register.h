/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef _DIO_REGISTER_
#define _DIO_REGISTER_

#define DDRA *((uint8_t*)0x3A)
#define DDRC *((uint8_t*)0x34)
#define DDRB *((uint8_t*)0x37)
#define DDRD *((uint8_t*)0x31)

#define PORT_A *((uint8_t*)0x3B)
#define PORT_B *((uint8_t*)0x38)
#define PORT_C *((uint8_t*)0x35)
#define PORT_D *((uint8_t*)0x32)

#define PINA *((volatile uint8_t*)0x39)
#define PINB *((volatile uint8_t*)0x36)
#define PINC *((volatile uint8_t*)0x33)
#define PIND *((volatile uint8_t*)0x30)

#endif


	
	
	
	
	
	
	
  	

