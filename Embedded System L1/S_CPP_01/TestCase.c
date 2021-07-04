/******************************************************************************************************
 * File: Testcases.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 4 july 2021
 * Description: This File Set of test cases.
*******************************************************************************************************/
#include<stdio.h>
#include "PaymentSystem_int.h"
#include "Types.h"
extern int Acc;
extern ST_accountBalance_t ServerData[10];
void Test_CardNumb(void)
{
    ST_transaction Test;
    sint8_t check;

    Test.cardHolderData.primaryAccountNumber[0] = '1';
    Test.cardHolderData.primaryAccountNumber[1] = '2';
    Test.cardHolderData.primaryAccountNumber[2] = '3';
    Test.cardHolderData.primaryAccountNumber[3] = '0';
    Test.cardHolderData.primaryAccountNumber[4] = '2';
    Test.cardHolderData.primaryAccountNumber[5] = '4';
    Test.cardHolderData.primaryAccountNumber[6] = '5';
    Test.cardHolderData.primaryAccountNumber[7] = '6';
    Test.cardHolderData.primaryAccountNumber[8] = '\0';
    

    if (CheckAccountNumFromServer(&Test) == NOTFOUND)
    {
        printf("Test Case 1 Passed\n");
    }
    else
    {
        printf("Test Case 1 Failed\n");
    }
}

void Test_MaxAmount(void)
{
    ST_transaction Test;
    EN_transStat_t state;
    sint8_t index;

    Test.transData.transAmount = 6000;
    state = CheckBlanceFromServer(&Test);

    if (state == DECLINED)
    {
        printf("Test Case 2 Passed\n");
    }
    else
    {
        printf("Test Case 2 Failed\n");
    }
}

void Test_ExpiredDat1(void)
{
    ST_transaction Test;
    EN_transStat_t state;

    Test.cardHolderData.cardExpirationDate[0] = '0';
    Test.cardHolderData.cardExpirationDate[1] = '2';
    Test.cardHolderData.cardExpirationDate[2] = '/';
    Test.cardHolderData.cardExpirationDate[3] = '2';
    Test.cardHolderData.cardExpirationDate[4] = '2';
    

    Test.transData.transactionDate[0] = '0';
    Test.transData.transactionDate[1] = '2';
    Test.transData.transactionDate[2] = '/';
    Test.transData.transactionDate[3] = '0';
    Test.transData.transactionDate[4] = '5';
    Test.transData.transactionDate[5] = '/';
    Test.transData.transactionDate[6] = '2';
    Test.transData.transactionDate[7] = '0';
    Test.transData.transactionDate[8] = '1';
    Test.transData.transactionDate[9] = '2';

    if(CheckExpiration(&Test) == APPROVED)
    {
        printf("Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
}

void Test_ExpiredDat2(void)
{
    ST_transaction Test;
    EN_transStat_t state;

    Test.cardHolderData.cardExpirationDate[0] = '1';
    Test.cardHolderData.cardExpirationDate[1] = '1';
    Test.cardHolderData.cardExpirationDate[2] = '/';
    Test.cardHolderData.cardExpirationDate[3] = '3';
    Test.cardHolderData.cardExpirationDate[4] = '0';
    

    Test.transData.transactionDate[0] = '0';
    Test.transData.transactionDate[1] = '9';
    Test.transData.transactionDate[2] = '/';
    Test.transData.transactionDate[3] = '0';
    Test.transData.transactionDate[4] = '5';
    Test.transData.transactionDate[5] = '/';
    Test.transData.transactionDate[6] = '2';
    Test.transData.transactionDate[7] = '0';
    Test.transData.transactionDate[8] = '2';
    Test.transData.transactionDate[9] = '9';

    if(CheckExpiration(&Test) == APPROVED)
    {
        printf("Test Case 4 Passed\n");
    }
    else
    {
        printf("Test Case 4 Failed\n");
    }
}


int main()
{
    Test_CardNumb();
    Test_MaxAmount();
    Test_ExpiredDat1();
    Test_ExpiredDat2();
}