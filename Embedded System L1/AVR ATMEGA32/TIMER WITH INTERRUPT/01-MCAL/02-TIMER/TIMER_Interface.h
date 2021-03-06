/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   16/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


typedef struct ST_TIMER_config_t{
u8 timer_no;   // Port name
u8 timer_mode;	   // Pin name
u8 timer_clk; // input or output
u8 pwm_mode;
u8 interrupt_mode;
}ST_TIMER_config_t;

#define NORMAL      0
#define CTC         1
#define PWM         2
#define FAST_PWM    3

#define TIMER0  0
#define TIMER1  1
#define TIMER2  2

#define NO_CLOCK                0
#define CLK                     1
#define CLK_8                   2
#define CLK_64                  3
#define CLK_256                 4
#define CLK_1024                5
#define EXTERNAL_CLK_FALLING    6
#define EXTERNAL_CLK_RISING     7
#define CLK_128                 8
#define CLK_32                  9

#define T1_NORMAL                           0
#define PWM_8BIT                            2
#define PWM_9BIT                            3
#define PWM_10BIT                           4
#define T1_CTC                              5
#define FAST_PWM_8BIT                       6
#define FAST_PWM_9BIT                       7
#define FAST_PWM_10BIT                      8
#define PWM_PHASE_FREQ_CORRECT_ICR1         9
#define PWM_PHASE_FREQ_CORRECT_OCR1A        10
#define PWM_PHASE__CORRECT_ICR1             11
#define PWM_PHASE__CORRECT_OCR1A            12
#define CTC_ICR1                            13
#define RESERVED                            14
#define FAST_PWM_ICR1                       15
#define FAST_PWM_OCR1A                      16


#define INVERTED                            0
#define NON_INVERTED                        1

#define INTERRUPT_ENABLE      0
#define INTERRUPT_DISABLE     1
void TM_voidTimerInit(ST_TIMER_config_t * configurations);
void TM_VoidPrealoadOverFlow(ST_TIMER_config_t *configurations ,u16 Copy_u16value);
void TM_VoidSetDuty (ST_TIMER_config_t *configurations ,u16 Copy_U8Duty);
void TM1_VoidInputCapture(void);
void TM0_OV_voidSetCallBack(void(*ptr)(void));
void TM2_OV_voidSetCallBack(void(*ptr)(void));

void T0delay();
#endif
