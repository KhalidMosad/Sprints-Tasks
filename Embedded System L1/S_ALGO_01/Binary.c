
/******************************************************************************************************
 * File: Binary.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 1 july 2021
 * Description: This File include Typedef for standard data types.
*******************************************************************************************************/
#include"Types.h"
#include"Binary.h"

/******* Bubble Sort Algorithm********/
static void Sorting(uint32_t * arr, uint8_t size)
{
	int temp=0;
	for(int i=1; i<size; i++)
    {
        for(int j=0; j<size-i; j++)
        {
            if(arr[j]>= arr[j+1])
            {
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] =temp;
            }
        }

    }

}



uint8_t BinarySearch(uint32_t * arr, uint8_t size,  uint32_t number)
{
    int middle, bottom =0, top = size-1;
	if(size<=255)
	{
		Sorting(arr, size);
		while(bottom<= top)
		{
			middle = (bottom + top)/2;
			if(arr[middle]==number)
				return middle ;
			if (number<arr[middle])
			   top= middle-1;
			else
				bottom= middle+1;
		}
		return -1;			
	}
	else
	{
		return -1;	
	}

}


