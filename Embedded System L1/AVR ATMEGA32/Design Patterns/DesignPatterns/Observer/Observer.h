/**
 * @file Observer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

typedef struct
{
    void (*PtrFuncObserver)(void);
    uint8_t check;

} Observer_t;

void Subscribe(Observer_t *a);
void ob(Observer_t *a);

//void UnSubscribe(void (*LocalPtr)(void));


#endif  /* OBSERVER_H_ */
