/******************************************************************************************************
 * File: stackrest.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 2 july 2021
 * Description: This File include Test cases.
*******************************************************************************************************/
#include<stdio.h>
#include "Stack.h"
#include"Types.h"
void Testcase1(void)
{
    E_State_t Estate = Error;
    uint8_t * Testarr1 = "{{}";

    uint8_t *Ptr = balancedParentheses(Testarr1);

    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'N')
    {
      // Estate = E_OK;
        printf("Test Case 1 Passed\n");
    }
    else
    {
        printf("Test Case 1 Failed\n");
    }
}

void Testcase2(void)
{
    E_State_t Estate = Error;
    uint8_t*Testarr2 = "{}}";
	uint8_t *Ptr1 = NULL;
    Ptr1 = balancedParentheses(Testarr2);

    /* check if firest element of string  NoTBalanced*/
    if (Ptr1[0] == 'N')
    {
        Estate = E_OK;
        printf("Test Case 2 Passed\n");
    }
    else
    {
        printf("Test Case 2 Failed\n");
    }
}

void Testcase3(void)
{
    E_State_t Estate = Error;
    uint8_t * Testarr3 = "(({2*3}+5){8/3})";

    uint8_t *Ptr2 = balancedParentheses(Testarr3);


    /* check if firest element of string  Balanced*/
    if (Ptr2[0] == 'B')
    {
        Estate = E_OK;
        printf("Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
}


void Testcase4(void)
{
    E_State_t Estate = Error;
    uint8_t * Testarr4 = "{({2+10}}*11}})}";

    uint8_t *Ptr = balancedParentheses(Testarr4);


    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'N')
    {
        Estate = E_OK;
        printf("Test Case 4 Passed\n");
    }
    else
    {
        printf("Test Case 4 Failed\n");
    }
}


int main()
{
    Testcase3();	
    Testcase2();		
    Testcase1();
    Testcase4();
	
}