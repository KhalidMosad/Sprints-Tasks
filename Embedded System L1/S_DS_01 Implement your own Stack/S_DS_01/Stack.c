/******************************************************************************************************
 * File: Types.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 2 july 2021
 * Description: This File include Typedef for standard data types.
*******************************************************************************************************/
#include<stdio.h>
#include"stack.h"
#include "Types.h"

/*
int top=0;
uint8_t entry[MAXSTACK];*/


 

void push (uint8_t data)
{
    entry[top]= data;
    top++ ; 
}

void pop ()
{
    top-- ;
}

uint8_t * balancedParentheses(uint8_t * expression)
{
    int i = 0;
    uint8_t x = '0';
    while (expression[i] != '\0')
    {
        if(expression[i]=='{' || expression[i]=='(' || expression[i]=='[')
        {
            push(expression[i]); 
            x ='A';           
        }
        else if(expression[i]=='}' || expression[i]==')' || expression[i]==']')
        {
            switch(expression[i])
            {
                case '}':
                    if(entry[top-1] == '{')
                    {
                        pop();
                        x = 'A';
                    }
                    else
                    {
                        return "Not Balanced" ;
                    }                    
                break;
                case ')':
                    if(entry[top-1] == '(')
                    {
                        x = 'A';
                        pop();
                    }
                    else
                    {
                        return "Not Balanced" ;
                    }                    
                break;
                case ']':
                    if(entry[top-1] == '[')
                    {
                        x = 'A';
                        pop();
                    }
                    else
                    {
                        return "Not Balanced" ;
                    }
                break;
            }
        }
        i++;
    }
    if(top == 0 && x== 'A')
    {
        return "Balanced";
    }   
    else if(top !=0)
    {
        return "Not Balanced" ; 
    }
    else
    {
        return "Expression doesn't include Parentheses.... ";
    }
}


void TraverseStack(void (*ptf)(uint8_t))
{
    while(top != 0)
    {
        (*ptf)(entry[--top]);
    }

}


