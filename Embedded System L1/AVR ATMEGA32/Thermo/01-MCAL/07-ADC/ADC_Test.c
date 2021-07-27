/******************************************************************************************************
 * File: ADC_Test.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 24 july 2021
 * Description: This File include Registers of usart.
*******************************************************************************************************/
#include "../../00-LIB/types.h"
#include "../../00-LIB/BIT_MATH.h"
#include "ADC.h"
#include <assert.h>
#include <stdio.h>

#define 	REFS1	7		
#define 	REFS0	6		
#define 	ADLAR	5		
#define 	MUX4	4		
#define 	MUX3	3		
#define 	MUX2	2		
#define 	MUX1	1
#define 	MUX0	0



/* ADCSRA REGISTER */
#define 	ADEN	7		
#define 	ADSC	6		
#define 	ADATE	5		
#define 	ADIF	4		
#define 	ADIE	3		
#define 	ADPS2	2		
#define 	ADPS1	1
#define 	ADPS0 	0


/* SFIOR REGISTER */
#define 	ADTS2	7		
#define 	ADTS1	6		
#define 	ADTS0	5		
#define 	R		4		
#define 	ACME	3		
#define 	PUD		2		
#define 	PSR2	1
#define 	PSR10 	0
#define HIGH_BITS   6

uint8_t ADMUX  ;
uint8_t ADCSRA ;
uint8_t SFIOR ;
uint16_t ADC_DATA ;

errorstatus adc_Init(ST_ADC__config_t * config )
{
	
	if(config->ADC_VrefS==AREF_PIN_SETEXTERNALLY)
	{
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);		
	}
	else if(config->ADC_VrefS==ACCC_PIN_SAMEVCC)
	{
		CLR_BIT(ADMUX,REFS1);		
		SET_BIT(ADMUX,REFS0);		
	}
	else if(config->ADC_VrefS== RESERVED)
	{
		SET_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);		
	}
	else if(config->ADC_VrefS==INTERNAL_2_56)
	{
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);		
	}
	else
	{
		return VREF_SEL_ERROR;
	}
	if(config->ADC_DataAlign==ADJUST_RIGHT)
	{
		CLR_BIT(ADMUX,ADLAR);
	}
	else if(config->ADC_DataAlign==ADJUST_LEFT)
	{
		SET_BIT(ADMUX,ADLAR);			
	}	
	else
	{
		return DATA_ALIGN_EEROR;
	}
	if(config->ADC_Mode == DISABLE)
	{
		CLR_BIT(ADCSRA,ADIE);		
	}
	else if(config->ADC_Mode == ENABLE)
	{	
		SET_BIT(ADCSRA,ADIE);		
	}
	else
	{
		return ADC_MODE_ERROR;
	}
	
	if(config->ADC_NbrOfChannel == ADC_C0)
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel == ADC_C1)
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);	
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel == ADC_C2)
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel == ADC_C3)
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel== ADC_C4)
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);	
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel == ADC_C5)
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel == ADC_C6)
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);	
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel == ADC_C7)
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC0_ADC0_10X )
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC1_ADC0_10X )
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC0_ADC0_200X)
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC1_ADC0_200X)
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC2_ADC2_10X )
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC3_ADC2_10X)
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	} 
	else if(config->ADC_NbrOfChannel==ADC2_ADC2_200X)
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC3_ADC2_200X)
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);	
	}
	else if(config->ADC_NbrOfChannel==ADC0_ADC1_1x )
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC1_ADC1_1x )
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC2_ADC1_1x )
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC3_ADC1_1x )
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC4_ADC1_1x )
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC5_ADC1_1x )
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC6_ADC1_1x )
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC7_ADC1_1x  )
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC0_ADC2_1x )
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	} 
	else if(config->ADC_NbrOfChannel==ADC1_ADC2_1x )
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC2_ADC2_1x  )
	{
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC3_ADC2_1x )
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC4_ADC2_1x )
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else if(config->ADC_NbrOfChannel==ADC5_ADC2_1x )
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		SET_BIT(ADMUX,MUX3);
		SET_BIT(ADMUX,MUX4);		
	}
	else
	{
		return ADC_CHANNEL_ERROR;
	}


	if(config->ADC_Prescaller== F_2)
	{
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);		
	}	
	else if(config->ADC_Prescaller== F_4)
	{
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);		
	}
	else if(config->ADC_Prescaller== F_8)
	{
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);		
	}
	else if(config->ADC_Prescaller== F_16)
	{
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);		
	}
	else if(config->ADC_Prescaller == F_32)
	{
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);		
	}
	else if(config->ADC_Prescaller== F_64)
	{
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);		
	}
	else if(config->ADC_Prescaller== F_128)
	{
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);		
	}
	else
	{
		return PRESCALLER_SELE_ERROR;
	}

	return ADC_NO_ERROR;


}
void adc_Enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}

void adc_StartConversion(void)
{
	SET_BIT(ADCSRA,ADSC);
}


void adc_InitTest(void)
{
	ST_ADC__config_t ch0 = {DISABLE,ACCC_PIN_SAMEVCC,ADJUST_RIGHT,ADC_C0,F_128};
	assert(adc_Init(&ch0)==ADC_NO_ERROR);
	assert(ADMUX == 0x40);
	assert(ADCSRA==0X07);

}

void adc_EnableTest(void)
{
	adc_Enable();
	assert(ADCSRA==0X87);
    
}

void main(void)
{

	adc_InitTest();
	adc_EnableTest();
	printf("NO Error");




}