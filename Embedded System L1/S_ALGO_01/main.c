/******************************************************************************************************
 * File: main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 1 july 2021
 * Description: This File include Typedef for standard data types.
*******************************************************************************************************/
#include<stdio.h>
#include"Types.h"
#include"Binary.h"

void main()
{

    uint32_t  arr[10]= {5,8,7,9,15,16,18,25,19,29};
    sint16_t i =BinarySearch(arr,10,18);
    if(i>=0)   
        printf("Found at index %d\n",i);
    else
        printf("Not Found\n");


}