/******************************************************************************************************
 * File: x_oGames.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 1 july 2021
 * Description: This File include Declarations of APIS and some Variables or Macros if needed.
*******************************************************************************************************/
#ifndef X_OGAME_H_
#define X_OGAME_H_


/*******************************************************
 *                    Erorr Status                     *
********************************************************/
typedef char E_Status_t;
#define E_OK                        1
#define E_INVALID_POSITION          2
#define E_POSSITION_ALREADY_TAKEN   3
#define E_ERROR                     4      



/* Size of the array*/
#define ARR_SIZE    25

/*****************************************************************
 * Function: Printboard.
 * Description: 
 *      This function takes a pointer to an array. 
 * Parameters: 
 *      uint8_t * arr. 
 * Return: 
 *        void ----- it returns nothing. 
 *               
*************************************************************************/
void Printboard(const uint8_t * arr);


/*****************************************************************
 * Function: checkwin.
 * Description: 
 *      FUNCTION TO RETURN GAME STATUS. 
 *      1 FOR GAME IS OVER WITH RESULT
 *     -1 FOR GAME IS IN PROGRESS
 *      O GAME IS OVER AND NO RESULT
 * Parameters: 
 *      No thing. 
 * Return: 
 *        void ----- it returns nothing. 
 *               
*************************************************************************/

int checkwin(void);

/*****************************************************************
 * Function: CheckChoicedublicate.
 * Description: 
 *      This function Check if the choosen number is not selected before
 * Parameters: 
 *      uint8_t choice.
 * Return: 
 *        0 if the choosen number is selected before, 1 if else
 *               
*************************************************************************/

uint8_t CheckChoicedublicate(uint8_t choice);


#endif