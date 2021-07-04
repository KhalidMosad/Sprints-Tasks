/******************************************************************************************************
 * File: PaymentSystem.c 
 * Author: Khalid Mosaad Zakaria
 * Data: 4 july 2021
 * Description: This File include API And Global Server Data.
*******************************************************************************************************/


/************ Include user defined and Standard Library ********/
#include<stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "PaymentSystem_int.h"
#include <string.h>

int Acc=0;
ST_accountBalance_t ServerData[10] =
    { 
        10.12, "123123456" ,
        100.00, "123456789" ,
        6000.00, "234567891",
        500.00, "258649173" ,
        1500.12, "456789123",
        .55, "456789321"    ,
        3250.25, "567891234",
        2100.00, "654823719",
        1.00, "793148625"   ,
        0.00, "971362485"   ,
};

void ReadCardData(ST_transaction* card)
{
    uint8_t str[25];
    printf("Please Enter Card Data: \n");
    printf("Please Enter the Card Holder Name:\n");
    gets(str);
   int i=0;
   for(i=0; str[i] !='\0'; i++)
   {
    card->cardHolderData.cardHolderName[i]= str[i];       
   }
   /***************** Add Null terminator*****************/
   card->cardHolderData.cardHolderName[i]=str[i];

    printf("Please Enter the Primary Account Number:\n");
    gets(card->cardHolderData.primaryAccountNumber);
    printf("Please card Expiry Date:\n");
    gets(card->cardHolderData.cardExpirationDate);

}

void ReadTerminalData(ST_transaction* Terminal)
{
    char str[20];
    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the transaction Amount:");
    scanf("%f", &Terminal->transData.transAmount);
    printf("Please Enter transaction Date:");
    scanf("%s", Terminal->transData.transactionDate);
}

EN_transStat_t CheckAccountNumFromServer(ST_transaction * data)
{
    int flag =0;
    for(int i = 0; i<10;i++)
    {
        int j=0;
        while(j<9)
        {
            if( ServerData[i].primaryAccountNumber[j] == data->cardHolderData.primaryAccountNumber[j])
            { 
                flag =1;             
            }
            else
            {
                flag =0;
                break;
            }                
            j++; 
        }
        if(flag == 1)
        {
            Acc = i;
            return APPROVED;
        }      
    }
    if(flag ==0 )
    {
        return DECLINED;
    }    
    
}
EN_transStat_t CheckBlanceFromServer(ST_transaction * data)
{

    if( ServerData[Acc].balance >= data->transData.transAmount)
    {
        return APPROVED;
    }
    else
    {
        return DECLINED;
    }

}

EN_transStat_t CheckExpiration(ST_transaction * data)
{
    int x = (data->cardHolderData.cardExpirationDate[3]-'0')*10 +  (data->cardHolderData.cardExpirationDate[4]-'0');
    int y = (data->transData.transactionDate[8]-'0')*10 +  (data->transData.transactionDate[9]-'0');
    int m1 = (data->cardHolderData.cardExpirationDate[0]-'0')*10 +  (data->cardHolderData.cardExpirationDate[1]-'0');
    int m2=  (data->transData.transactionDate[3]-'0')*10 +  (data->transData.transactionDate[4]-'0');

    if(x>y)
    {
        return APPROVED;
    }
    else 
    {
        if(x<y )
        {
            return DECLINED;
        }
        else
        {
            if(m1>=m2)
            {
                return APPROVED;
            }
            else
            {
                return DECLINED; 
            }

        }


    }

}
