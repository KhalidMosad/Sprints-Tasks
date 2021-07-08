/******************************************************************************************************
 * File: main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 2 july 2021
 * Description: This File include Typedef for standard data types.
*******************************************************************************************************/

#include<stdio.h>
#include"stack.h"
#include "Types.h"

void main()
{
    uint8_t * y = "{(5+6+9}";
    uint8_t * x= NULL;
    x= balancedParentheses(y);
    printf("%s", x);

}


