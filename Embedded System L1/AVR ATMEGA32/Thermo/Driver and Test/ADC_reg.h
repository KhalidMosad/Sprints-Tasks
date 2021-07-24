/******************************************************************************************************
 * File: ADC_reg.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 24 july 2021
 * Description: This File include Registers of ADC peripheral.
*******************************************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* ADMUX REGISTER */


#define 	REFS1	7		
#define 	REFS0	6		
#define 	ADLAR	5		
#define 	MUX4	4		
#define 	MUX3	3		
#define 	MUX2	2		
#define 	MUX1	1
#define 	MUX0	0
#define ADMUX    	 *((volatile uint8_t*)0x27)

/* ADCSRA REGISTER */
#define 	ADEN	7		
#define 	ADSC	6		
#define 	ADATE	5		
#define 	ADIF	4		
#define 	ADIE	3		
#define 	ADPS2	2		
#define 	ADPS1	1
#define 	ADPS0 	0

#define ADCSRA    	 *((volatile uint8_t*)0x26)

/* SFIOR REGISTER */
#define 	ADTS2	7		
#define 	ADTS1	6		
#define 	ADTS0	5		
#define 	R		4		
#define 	ACME	3		
#define 	PUD		2		
#define 	PSR2	1
#define 	PSR10 	0

#define SFIOR    	 *((volatile uint8_t*)0x50)

#define ADC_DATA    	 *((volatile uint16_t*)0x24)
#define HIGH_BITS   6

#define 	GIE		7
#define     SREG        *((volatile uint8_t*)0x5F)


static void GIE_voidEnable(void)
{
	SET_BIT(SREG,GIE);
}

static void GIE_voidDisable(void)
{
	CLR_BIT(SREG,GIE);
}
void __vector_16(void) __attribute__((signal));

#endif 
