/******************************************************************************************************
 * File: TIMER_program.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 10 july 2021
 * Description: This File include Definitions of functions and Strucrures.
*******************************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Timer_interface.h"
#include"Timer_private.h"
#include"Timer_config.h"
#include "DIO_interface.h"

#define NULL '\0'

static void(*ptrf)(void) = NULL;

static void(*ptrftm2)(void) = NULL;

void TM0_OV_NOINTERRUPT(void);
void TM2_OV_NOINTERRUPT(void);


static u8 TM0OV_INTRRUPT_FLAG  =  INTERRUPT_ENABLE;
static u8 TM0CTC_INTRRUPT_FLAG  = INTERRUPT_ENABLE;

static u8 TM1OV_INTRRUPT_FLAG  =  INTERRUPT_ENABLE;
static u8 TM1CTC_INTRRUPT_FLAG  = INTERRUPT_ENABLE;

static u8 TM2OV_INTRRUPT_FLAG  =  INTERRUPT_ENABLE;
static u8 TM2CTC_INTRRUPT_FLAG  = INTERRUPT_ENABLE;

void TM_voidTimerInit(ST_TIMER_config_t * configurations)
{
    if( configurations->timer_no== TIMER0)
    {
        if( configurations->timer_mode==NORMAL)
        {

            CLR_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            if(configurations->interrupt_mode == INTERRUPT_ENABLE)
                SET_BIT(TIMSK, TOIE0);
            else
            {
                TM0OV_INTRRUPT_FLAG=INTERRUPT_DISABLE;
                TM0_OV_NOINTERRUPT();
            }

            
        }
        else if( configurations->timer_mode==CTC)
        {

            CLR_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            OCR0= OCR_VALUE_CTCMode;
            if(configurations->interrupt_mode == INTERRUPT_ENABLE)
                SET_BIT(TIMSK, OCIE0);
            else
                TM0CTC_INTRRUPT_FLAG=INTERRUPT_DISABLE;
        // WAVE GENERATOR ON PINB.3
            CLR_BIT(TCCR0,COM01);
            SET_BIT(TCCR0,COM00);
        }
        else if( configurations->timer_mode==PWM)
        {
            SET_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            if( configurations->pwm_mode == NON_INVERTED)
            {
                SET_BIT(TCCR0, COM01);
                CLR_BIT(TCCR0, COM00);                
            }
            else if( configurations->pwm_mode==INVERTED)
            {
                SET_BIT(TCCR0, COM01);
                SET_BIT(TCCR0, COM00);
            }
        }
        else if( configurations->timer_mode==FAST_PWM)
        {
            SET_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            if( configurations->pwm_mode == NON_INVERTED)
            {
                SET_BIT(TCCR0, COM01);
                CLR_BIT(TCCR0, COM00);                
            }
            else if( configurations->pwm_mode==INVERTED)
            {
                SET_BIT(TCCR0, COM01);
                SET_BIT(TCCR0, COM00);
            }
        }
        else
        {

        }

        if( configurations->timer_clk == NO_CLOCK)
        {
            CLR_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        }
        else if( configurations->timer_clk == CLK)
        {
            SET_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        }
        else if( configurations->timer_clk == CLK_8)
        {
            CLR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        }
        else if( configurations->timer_clk == CLK_64)
        {
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);            
        }

        else if( configurations->timer_clk  == CLK_256)
        {

            CLR_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        }
        else if( configurations->timer_clk == CLK_1024)
        {
            SET_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        }

        else if( configurations->timer_clk  == EXTERNAL_CLK_FALLING)
        {
            CLR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        }

        else if( configurations->timer_clk  == EXTERNAL_CLK_RISING)
        {
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);            
        }


    }
        



    else if( configurations->timer_no== TIMER1)
    {

        if( configurations->timer_mode==T1_NORMAL)
        {
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
            if(configurations->interrupt_mode == INTERRUPT_ENABLE)            
                SET_BIT(TIMSK, TOIE1);
            else
            {

                TM1OV_INTRRUPT_FLAG = INTERRUPT_DISABLE;

            }

        }    
        else if( configurations->timer_mode==PWM_8BIT)
        {
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);            
        }      

        else if( configurations->timer_mode==PWM_9BIT  )
        {
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);            
        }
        else if( configurations->timer_mode==PWM_10BIT )
        {
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);            
        }  
        else if( configurations->timer_mode==T1_CTC )
        {
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);           
            if(configurations->interrupt_mode == INTERRUPT_ENABLE)               
                SET_BIT(TIMSK, OCIE1A);
            else
              TM1CTC_INTRRUPT_FLAG= INTERRUPT_DISABLE;  
            /*WE CAN USE OCR1B In Here */                      
        }   
        else if( configurations->timer_mode==FAST_PWM_8BIT )
        {
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);            
        } 

        else if( configurations->timer_mode==FAST_PWM_9BIT )
        {
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);            
        }

        else if( configurations->timer_mode==FAST_PWM_10BIT)
        {
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);            
        }  
        else if( configurations->timer_mode==PWM_PHASE_FREQ_CORRECT_ICR1)
        {
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }  

        else if( configurations->timer_mode==PWM_PHASE_FREQ_CORRECT_OCR1A )
        {
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }

        else if( configurations->timer_mode==PWM_PHASE__CORRECT_ICR1)
        {
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }      
        else if( configurations->timer_mode==PWM_PHASE__CORRECT_OCR1A )
        {
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }    
        else if( configurations->timer_mode==CTC_ICR1)
        {
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }      

        else if( configurations->timer_mode==RESERVED )
        {
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }      

        else if( configurations->timer_mode==FAST_PWM_ICR1 )
        {
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }   

        else if( configurations->timer_mode==FAST_PWM_OCR1A )
        {
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);            
        }  
        if( configurations->timer_clk  == NO_CLOCK)
        {
            CLR_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);            
        }

        else if( configurations->timer_clk  == CLK)
        {
            SET_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);            
        }

        else if( configurations->timer_clk  == CLK_8)
        {
            CLR_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);            
        }

        else if( configurations->timer_clk  == CLK_64)
        {
            SET_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);
        }

        else if( configurations->timer_clk  == CLK_256)
        {
            CLR_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);            
        }

        else if( configurations->timer_clk  == CLK_1024)
        {
            SET_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);            
        }
        else if( configurations->timer_clk  == EXTERNAL_CLK_FALLING)
        {
            CLR_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);            
        }
       else if( configurations->timer_clk  == EXTERNAL_CLK_RISING)
        {
            SET_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);           
        }
    }
    else if( configurations->timer_no== TIMER2)
    {
        if( configurations->timer_mode==NORMAL)
        {

            CLR_BIT(TCCR2,WGM20);
            CLR_BIT(TCCR2,WGM21);
            if(configurations->interrupt_mode == INTERRUPT_ENABLE)               
                SET_BIT(TIMSK, TOIE2);  
            else
            {
                TM2OV_INTRRUPT_FLAG = INTERRUPT_DISABLE;  
                TM2_OV_NOINTERRUPT();               
            }
        
        }
        else if( configurations->timer_mode==CTC)
        {
            CLR_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);
            if(configurations->interrupt_mode == INTERRUPT_ENABLE)   
                 SET_BIT(TIMSK, OCIE2);
            else
               TM2CTC_INTRRUPT_FLAG = INTERRUPT_DISABLE;   
        // WAVE GENERATOR ON PINB.3
            CLR_BIT(TCCR2,COM21);
            SET_BIT(TCCR2,COM20);                   
        }
        else if( configurations->timer_mode==PWM)
        {
            SET_BIT(TCCR2,WGM20);
            CLR_BIT(TCCR2,WGM21);
            if( configurations->pwm_mode == NON_INVERTED)
            {
                SET_BIT(TCCR2, COM21);
                CLR_BIT(TCCR2, COM20);                
            }
            else if( configurations->pwm_mode==INVERTED)
            {
                SET_BIT(TCCR2, COM21);
                SET_BIT(TCCR2, COM20);
            }

        }
        else if( configurations->timer_mode==FAST_PWM)
        {
            SET_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);

            if( configurations->pwm_mode == NON_INVERTED)
            {
                SET_BIT(TCCR2, COM21);
                CLR_BIT(TCCR2, COM20);                
            }
            else if( configurations->pwm_mode==INVERTED)
            {
                SET_BIT(TCCR2, COM21);
                SET_BIT(TCCR2, COM20);
            }
           
        }
        if( configurations->timer_clk  == NO_CLOCK)
        {
            CLR_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);            
        }
        else if( configurations->timer_clk  == CLK)
        {
            SET_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);            
        }
        else if( configurations->timer_clk  == CLK_8)
        {
            CLR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);            
        }
        else if( configurations->timer_clk  == CLK_32)
        {
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);            
        }
        else if( configurations->timer_clk  == CLK_64)
        {
            CLR_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);            
        }

        else if( configurations->timer_clk  == CLK_128)
        {
            SET_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);            
        }

        else if( configurations->timer_clk  == CLK_256)
        {
            CLR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);            
        }

        else if( configurations->timer_clk  == CLK_1024)
        {
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);              
        }
   
    }
    if(configurations->interrupt_mode == INTERRUPT_ENABLE) 
         SET_BIT(SREG, BIT7);

}

void TM0_OV_voidSetCallBack(void(*ptr)(void))
{
	if(ptr !=NULL)
	{
	 ptrf=ptr;
	}
	
}

void TM2_OV_voidSetCallBack(void(*ptr)(void))
{
	if(ptr !=NULL)
	{
	 ptrftm2=ptr;
	}

}

void TM_VoidPrealoadOverFlow(ST_TIMER_config_t *configurations ,u16 Copy_u16value)
{ 
    if( configurations->timer_no== TIMER0)
        TCNT0= (u8)Copy_u16value;
    else if( configurations->timer_no== TIMER1)
        TCNT1= Copy_u16value;      
    else if( configurations->timer_no== TIMER2)
        TCNT2= (u8)Copy_u16value;  
   
}


void TM_VoidSetDuty (ST_TIMER_config_t *configurations ,u16 Copy_U8Duty)
{
    if( configurations->timer_no== TIMER0)
        OCR0= Copy_U8Duty;
    else if( configurations->timer_no== TIMER1)
        OCR1A= Copy_U8Duty;
    else if( configurations->timer_no== TIMER2)
        OCR2 =Copy_U8Duty;
}


void TM0_OV_NOINTERRUPT(void)
{
	TCNT0 = 0;
    if(TM0OV_INTRRUPT_FLAG == INTERRUPT_DISABLE)
    {
        static u16 counter=0;
        if(counter == 245)
        {
            TCNT0=0;

            counter=0;
        }
        while (GET_BIT(TIFR, TOV0) == 0);
        counter++;
        SET_BIT(TIFR, TOV0);
    }

}


void TM2_OV_NOINTERRUPT(void)
{
	TCNT2 = 0;
    if(TM2OV_INTRRUPT_FLAG == INTERRUPT_DISABLE)
    {
        static u16 counter=0;
        if(counter==245)
        {
            TCNT2=0;
            ptrftm2();
            counter=0;
        }
        while (GET_BIT(TIFR, TOV2) == 0);
        counter++;
        SET_BIT(TIFR, TOV2);
    	DIO_voidSetPinValue(PORTC,PIN1,HIGH);
    }
}

void __vector_11(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT0=0;
		ptrf();
		counter=0;
	}

}

void __vector_5(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT0=0;
		ptrftm2();
		counter=0;
	}

}
