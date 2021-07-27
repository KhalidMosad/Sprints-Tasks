/******************************************************************************************************
 * File: ADC.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 24 july 2021
 * Description: This File include Definitions of APIs List.
*******************************************************************************************************/

#include"types.h"
#include"BIT_Math.h"
#include"ADC.h"
#include"ADC_reg.h"
#include"ADC_config.h"

uint8_t SPCR_Help;

#define NULL '\0'
void (*SETCALLBACK)(void) = NULL;


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
		GIE_voidEnable();	
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
/* We can select any divisor and set frequency Fosc/2,
 *  Fosc/4, etc. for ADC, But in AVR, ADC requires an
 *   input clock frequency
 *  less than 200KHz for max. accuracy.
 *  So we have to always take care of not exceeding ADC frequency more than 200KHz.
 *  Suppose your clock frequency
 *  of AVR is 8MHz, then we must have to use devisor 64 or 128.
 *  Because it gives 8MHz/64 = 125KHz,
 *   which is lesser than 200KHz. */

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

void ADC_VoidSelect_channel(uint8_t Copy_Channel)
{
	CLR_BIT(ADMUX,MUX4);
	CLR_BIT(ADMUX,MUX3);


	switch(Copy_Channel)
	{	case ADC_C0 : ADMUX&=0B11100000; break;  // choose channel
		case ADC_C1 :SET_BIT(ADMUX,MUX0);CLR_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX2); break;
		case ADC_C2 :CLR_BIT(ADMUX,MUX0);SET_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX2); break;
		case ADC_C3 :CLR_BIT(ADMUX,MUX0);SET_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX2); break;
		case ADC_C4 :SET_BIT(ADMUX,MUX0);CLR_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX2); break;
		case ADC_C5 :SET_BIT(ADMUX,MUX0);CLR_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX2); break;
		case ADC_C6 :SET_BIT(ADMUX,MUX0);SET_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX2); break;
		case ADC_C7 :SET_BIT(ADMUX,MUX0);SET_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX2); break;
	}
}

void adc_Enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}


void ADC_SetCallback(void(*ptrf)(void))
{
	if(ptrf != NULL)
	{
		SETCALLBACK  = ptrf;	
	}	
}
void adc_StartConversion(void)
{
	SET_BIT(ADCSRA,ADSC);
}

uint16_t adc_Read(ST_ADC__config_t * config)
{	
	adc_StartConversion();
	while(GET_BIT(ADCSRA,ADIF) == 0);
	SET_BIT(ADCSRA,ADIF);
	if(config->ADC_DataAlign == ADJUST_RIGHT)
	{
		return ADC_DATA;
	}
	else
	{
		return ADC_DATA>>HIGH_BITS;
	}
}

void __vector_16(void )
{
	SETCALLBACK();

}
