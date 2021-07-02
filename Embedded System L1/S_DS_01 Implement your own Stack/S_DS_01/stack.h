/******************************************************************************************************
 * File: Types.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 2 july 2021
 * Description: This File include Typedef for standard data types.
*******************************************************************************************************/

#ifndef STACK_H_
#define STACK_H_

/* Size of my stack   */
#define MAXSTACK  100


/*********************  My Stack elements ***********************/
int top;
uint8_t entry[MAXSTACK];
  
/*****************************************************************
 * Function: push.
 * Description: 
 *      This Function push an element in The stack and increment the top
 * Parameters: 
 *      uint8_t e... element to be added .
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void push (uint8_t e);
/*****************************************************************
 * Function: pop.
 * Description: 
 *      This Function pop an element from The stack and decrement the top
 * Parameters: 
 *      No parameters.
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void pop ();
/*****************************************************************
 * Function: balancedParentheses.
 * Description: 
 *      This Function Check if a string that contain Parentheses is blanced or not or if it doesn't have Parentheses. 
 * Parameters: 
 *      string literal.
 * Return: 
 *      string literal
 *               
*************************************************************************/
uint8_t * balancedParentheses(uint8_t * expression);

/*****************************************************************
 * Function: TraverseStack.
 * Description: 
 *      This Function go through the stack element by element and do the required function. 
 * Parameters: 
 *      Pointer to the required function.
 * Return: 
 *      Nothing
 *               
*************************************************************************/
void TraverseStack( void (*ptf)(uint8_t));

#endif