
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "TIMER_Interface.h"

void Toggle(void)
{
	DIO_voidTogglePin(PORTA,PIN0);
}
void Toggle1(void)
{
	DIO_voidTogglePin(PORTB,PIN0);
}

void main(void)
{
	ST_TIMER_config_t TM0 = {TIMER0, NORMAL,CLK_256, 0,INTERRUPT_DISABLE};
	ST_TIMER_config_t TM1 = {TIMER2, NORMAL,CLK_256, 0,INTERRUPT_DISABLE};


    ST_DIO_config_t Led ={PORTA,PIN0,OUTPUT};
    ST_DIO_config_t Led1 ={PORTB,PIN0,OUTPUT};

    DIO_voidSetPinDirection(&Led);
    DIO_voidSetPinDirection(&Led1);

    TM_voidTimerInit(&TM0);
    TM_voidTimerInit(&TM1);


    TM0_OV_voidSetCallBack(Toggle);
    TM2_OV_voidSetCallBack(Toggle1);


    while (1)
    {
    	TM0_OV_NOINTERRUPT();
    	TM2_OV_NOINTERRUPT();
    }

}
