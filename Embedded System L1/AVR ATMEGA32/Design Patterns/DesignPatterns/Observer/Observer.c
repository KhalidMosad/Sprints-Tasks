/**
 * @file Observer.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DataTypes.h"
#include "Observer.h"
extern volatile uint8_t *gPrece_str;



Observer_t x;
void (*s[3])(void);
uint8_t arr[100] = {0};

void Subscribe(Observer_t *a)
{
	if(a->PtrFuncObserver != NULLPTR)
	{
		        arr[0] = a->check;
		        s[0] = a->PtrFuncObserver;
	}


}

void ob(Observer_t *a)
{
    uint8_t isr_var, i=0;

    if (UART_u8ReceiveNoBlock(gPrece_str[i]))
    {
        isr_var = gPrece_str[i];
    }
    if (isr_var > a->check)
    {
       s[0]();
    }
}
//
//void UnSubscribe(Observer_t *observer)
//{
//    observer->PtrFuncObserver = NULLPTR;
//}
