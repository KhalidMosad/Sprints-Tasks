/******************************************************************************************************
 * File: ADC.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 24 july 2021
 * Description: This File include Declaration of APIs List.
*******************************************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#define	F_2				0
#define	F_4				1
#define	F_8				3
#define	F_16			4
#define	F_32			5
#define	F_64			6
#define	F_128			7

#define AREF_PIN_SETEXTERNALLY  0
#define ACCC_PIN_SAMEVCC        1
#define RESERVED                2
#define INTERNAL_2_56           3


#define ADC_C0         0
#define ADC_C1         1
#define ADC_C2         2
#define ADC_C3         3 
#define ADC_C4         4
#define ADC_C5         5
#define ADC_C6         6
#define ADC_C7         7 

#define ADC0_ADC0_10X       8
#define ADC1_ADC0_10X       9
#define ADC0_ADC0_200X      10
#define ADC1_ADC0_200X      11
#define ADC2_ADC2_10X       12
#define ADC3_ADC2_10X       13
#define ADC2_ADC2_200X      14
#define ADC3_ADC2_200X      15
#define ADC0_ADC1_1x        16
#define ADC1_ADC1_1x        17
#define ADC2_ADC1_1x        18
#define ADC3_ADC1_1x        19
#define ADC4_ADC1_1x        20
#define ADC5_ADC1_1x        21
#define ADC6_ADC1_1x        22
#define ADC7_ADC1_1x        23
#define ADC0_ADC2_1x        24
#define ADC1_ADC2_1x        25
#define ADC2_ADC2_1x        26
#define ADC3_ADC2_1x        27
#define ADC4_ADC2_1x        28
#define ADC5_ADC2_1x        29


#define	ADJUST_LEFT 	0
#define	ADJUST_RIGHT  	1

#define DISABLE 0
#define ENABLE 1



typedef struct
{
  uint8_t ADC_Mode;                      /*  Configures the ADC to operate in With or Without Interrupt*/
  uint8_t ADC_VrefS;                    /* Defines the Vref Source*/
  uint8_t ADC_DataAlign;                 /* Specifies whether the ADC data alignment is left or right.*/
  uint8_t ADC_NbrOfChannel;               /*!< Specifies the number of ADC channels that will be converted*/
  uint8_t ADC_Prescaller;
}ST_ADC__config_t;


typedef enum
{
    ADC_NO_ERROR,
    VREF_SEL_ERROR,
    DATA_ALIGN_EEROR,
    ADC_MODE_ERROR,
    ADC_CHANNEL_ERROR,
    PRESCALLER_SELE_ERROR

}errorstatus;




errorstatus adc_Init(ST_ADC__config_t * config );
void adc_Enable(void);
void ADC_VoidSelect_channel(uint8_t Copy_Channel);
void adc_StartConversion(void);
uint16_t adc_Read(ST_ADC__config_t * config);

#endif 
