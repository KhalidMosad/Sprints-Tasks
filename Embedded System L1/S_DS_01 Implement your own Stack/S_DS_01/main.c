#include<stdio.h>
#include"stack.h"
#include "Types.h"


extern int top;
extern uint8_t entry[MAXSTACK];

void Display(uint8_t data)
{
 printf("%d\n", data);   
}

void main()
{  
    printf("5 \n");
    Push(5);
    Push(8);
    Push(9);
    printf("%d \n",top);
    TraverseStack(&Display);
    printf("%d \n",top);
}


