/******************************************************************************************************
 * File: PaymentSystem_int.h 
 * Author: Khalid Mosaad Zakaria
 * Data: 4 july 2021
 * Description: This File include Declarations of functions and Strucrures.
*******************************************************************************************************/

#ifndef PAYMENTSYSTEM_INT_
#define PAYMENTSYSTEM_INT_



/****************** Card Data Structure ************/ 
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
} ST_cardData_t;

/****************** Terminal Data Structure ************/ 
typedef struct ST_terminalData_t
{
     float transAmount;
     float maxTransAmount;   
    uint8_t transactionDate[11];     
} ST_terminalData_t;


/****************** Transation State enum ************/ 
typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
} EN_transStat_t;


/****************** Structure of all data ************/ 
typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;
} ST_transaction;



/****************** Server Content Structure ************/ 
typedef struct ST_accountBalance_t
{
    float balance;
    uint8_t primaryAccountNumber[20];
} ST_accountBalance_t;

/*****************************************************************
 * Function: ReadCardData.
 * Description: 
 *      This Function Read the Card data from the user Like Acc Number and Expiration data and name
 * Parameters: 
 *      ST_transaction* card.
 * Return: 
 *        Nothing
 *               
*************************************************************************/

void ReadCardData(ST_transaction* card);

/*****************************************************************
 * Function: ReadTerminalData.
 * Description: 
 *      This Function Read the Terminal data from the user Like The amount to withdraw and data
 * Parameters: 
 *      ST_transaction* card.
 * Return: 
 *        Nothing
 *               
*************************************************************************/
void ReadTerminalData(ST_transaction* Terminal);



/*****************************************************************
 * Function: CheckAccountNumFromServer.
 * Description: 
 *      This Function CheckAccountNumFromServer
 * Parameters: 
 *      ST_transaction * data.
 * Return: 
 *        EN_transStat_t .... APPROVED OR DECLINED 
 *               
*************************************************************************/
EN_transStat_t CheckAccountNumFromServer(ST_transaction * data);

/*****************************************************************
 * Function: CheckBlanceFromServer.
 * Description: 
 *      This Function Check Blance From Server
 * Parameters: 
 *      ST_transaction * data.
 * Return: 
 *        EN_transStat_t .... APPROVED OR DECLINED 
 *               
*************************************************************************/
EN_transStat_t CheckBlanceFromServer(ST_transaction * data);

/*****************************************************************
 * Function: CheckExpiration.
 * Description: 
 *      This Function compare the Expire date of the card with the data of Transaction.
 * Parameters: 
 *      ST_transaction * data.
 * Return: 
 *        EN_transStat_t .... APPROVED OR DECLINED 
 *               
*************************************************************************/
EN_transStat_t CheckExpiration(ST_transaction * data);

#define NOELEMTARR  10
#define NOTFOUND    0


#endif /* PAYMENTSYSTEM_INT_ */