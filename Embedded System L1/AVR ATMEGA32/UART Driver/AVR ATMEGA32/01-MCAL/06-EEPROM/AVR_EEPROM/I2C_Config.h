/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   22/4/2021           */
/*********Version: 1                     */
/****************Desc: *******************/
#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_


/*    

SCL Frequency = (CPU_CLOCK_FREQUENCY / (16 + (2*Division_Factor) * prescaller))
*/ 

/* Select any deviation Factor less than 255 */
#define Division_Factor     32 


/* PreScaller Options: 
1- ONE
2- FOUR
3- SIXTEEN
4- FOURTY_SIX
*/
#define PRESCALER        ONE 

/*Interrupt Options: 
1- ENABLE
2- DISABLE
*/
#define INTERRUPT_O DISABLE

/*Acknowledge Options: 
1- ENABLE
2- DISABLE
*/
#define ACK_OP ENABLE


#endif /* I2C_CONFIGURATION_H_ */
