#include<stdio.h>
#include"stack.h"
#include "Types.h"

int top=0;
uint8_t entry[MAXSTACK];
 

void Push (uint8_t data)
{
    entry[top]= data;
    top++ ; 
}

void Pop ()
{
    top-- ;
}

void TraverseStack(void (*ptf)(uint8_t))
{
    while(top != 0)
    {
        (*ptf)(entry[--top]);
    }

}