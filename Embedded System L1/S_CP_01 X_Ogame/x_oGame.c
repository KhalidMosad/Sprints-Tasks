/******************************************************************************************************
 * File: x_oGames.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 1 july 2021
 * Description: This File include APIS Definitions.
*******************************************************************************************************/

/****Include Header files********/
#include<stdio.h>
#include"Types.h"
#include"x_oGame.h"


/*******My Arrays Which represent the Playing Board *********/ 
char game[ARR_SIZE] = {
	'|','-','-','-','|',
	'|','1','2','3','|',
	'|','4','5','6','|',
	'|','7','8','9','|',
	'|','_','_','_','|',
};

char AllowedIndexes[9]={6,7,8,11,12,13,16,17,18};

void Printboard(const uint8_t * arr)
{
    printf("         X-O Game            \n\n");
	printf("Player 1 __X__ - Player 2 __O__)            \n\n");
    for(char i= 0; i<ARR_SIZE; i++)
    {
        if(i!=0 && i%5 == 0)
        {
            printf("\n");
            printf("\n");  
            printf("\n"); 
        }
        printf("%c \t",arr[i]);
          
    }
}

int checkwin()
{
    if (game[AllowedIndexes[0]] == game[AllowedIndexes[1]] && game[AllowedIndexes[1]] == game[AllowedIndexes[2]])
        return 1;
    else if (    game[AllowedIndexes[3]] == game[AllowedIndexes[4]] && game[AllowedIndexes[4]] == game[AllowedIndexes[5]] )
        return 1;        
    else if (game[AllowedIndexes[6]] == game[AllowedIndexes[7]] && game[AllowedIndexes[7]] == game[AllowedIndexes[8]] )
        return 1;       
    else if (game[AllowedIndexes[0]] == game[AllowedIndexes[3]] && game[AllowedIndexes[3]] == game[AllowedIndexes[6]])
        return 1;        
    else if (game[AllowedIndexes[1]] == game[AllowedIndexes[4]] && game[AllowedIndexes[4]] == game[AllowedIndexes[7]] )
        return 1;       
    else if (game[AllowedIndexes[2]] == game[AllowedIndexes[5]] && game[AllowedIndexes[5]] == game[AllowedIndexes[8]])
        return 1;       
    else if ( game[AllowedIndexes[0]] == game[AllowedIndexes[4]] && game[AllowedIndexes[4]] == game[AllowedIndexes[8]])
        return 1;        
    else if (game[AllowedIndexes[2]] == game[AllowedIndexes[4]] && game[AllowedIndexes[4]] == game[AllowedIndexes[6]])
        return 1;        
    else if (game[AllowedIndexes[0]] != '1' && game[AllowedIndexes[1]] != '2' && game[AllowedIndexes[2]] != '3' &&
        game[AllowedIndexes[3]] != '4' && game[AllowedIndexes[4]] != '5' && game[AllowedIndexes[5]] != '6' && game[AllowedIndexes[6]] 
        != '7' && game[AllowedIndexes[7]] != '8' && game[AllowedIndexes[8]] != '9')
        return 0;
    else
        return  - 1;
}

uint8_t CheckChoicedublicate(uint8_t choice)
{
    if(game[AllowedIndexes[choice-1]]>= '0' && game[AllowedIndexes[choice-1]]<= '9')
        return 1;
    else 
        return 0;
}





