/******************************************************************************************************
 * File: Binary.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 1 july 2021
 * Description: This File include APIS Of Binary Search.
*******************************************************************************************************/

#ifndef BINARY_H_
#define BINARY_H_

/*****************************************************************
 * Function: BinarySearch.
 * Description: 
 *      This Search for an element in a sorted array
 * Parameters: 
 *      uint32_t * arr, uint8_t size,  uint32_t number.
 * Return: 
 *        0 if not found, 1 if else
 *               
*************************************************************************/
sint16_t BinarySearch(uint32_t * arr, uint16_t size,  uint32_t number);

#define NOTSORTED   0
#define SORTED      1
#define NOTFOUND    -1
#define FOUND       1

#endif