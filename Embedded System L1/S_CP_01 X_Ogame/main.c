/******************************************************************************************************
 * File: main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 1 july 2021
 * Description: the App.
*******************************************************************************************************/
#include<stdio.h>
#include"Types.h"
#include"x_oGame.h"

extern char game[ARR_SIZE];
extern char AllowedIndexes[9];
void main(void)
{
   int player = 1, i=-1, choice;

    char mark;
    do
    {
        Printboard(game);
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';        
        if(CheckChoicedublicate(choice))
        {

            game[AllowedIndexes[choice-1]] = mark;
        }            
        else
        {
            printf("\n");
            printf("\n"); 
            printf("Invalid move ");

            player--;
        }
        
        i = checkwin();

        player++;
        printf("\n");
        printf("\n");
        printf("\n");        
    }while (i ==  - 1);
    

    Printboard(game);
    
    if (i == 1)
        printf("\n\nPlayer %d win ", --player);
    else
        printf("\n\nNo Winner");


}