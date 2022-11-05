#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include"software_timer.h"
#include "button.h"
#include "led_display.h"

/*-------------------------------- Define States -------------------------------*/
#define INIT 0

#define RESET 1
#define INCREASE 2
#define DECREASE 3
#define TOGGLE 4
#define STANDBY 10

// Threshold for counter
#define UPPER_BOUND 9
#define LOWER_BOUND 0

/*-----------------------------3 buttons available------------------------------*/
#define NUM_OF_BUTTON 3
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2

/*-------------------------------Global Variables------------------------------*/
extern int status1; //Use to blink Led
extern int status2; //Use to modify counter
extern int counter;
extern int countDown10s;

void initCounter(void);
void initVar(void);

#endif /* INC_GLOBAL_H_ */
