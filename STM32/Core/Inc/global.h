#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include"software_timer.h"
#include "button.h"
#include "led_display.h"

/*-------------------------------- Define States -------------------------------*/
#define INIT 0

// For Mode1
#define STATE_RED 1
#define STATE_GREEN 2
#define STATE_YELLOW 3

// For Mode2-4
#define TOGGLE 1
#define INCREASE 2
#define DECREASE 3
#define SAVE 4

// Use to specify which 7-seg led is blinked
#define DOZEN 1
#define UNIT 2

// Threshold for waiting time
#define UPPER_BOUND 99
#define LOWER_BOUND 1

/*-----------------------------4 modes available--------------------------------*/
#define MODE1  1
#define MODE2  2
#define MODE3  3
#define MODE4  4

/*-----------------------------4 buttons available------------------------------*/
#define NUM_OF_BUTTON 4
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2
#define BUTTON4 3

/*-------------------------------Global Variables------------------------------*/
//Keep track of current mode
extern int mode;

// Waiting time at each state
extern int AUTO_RED;
extern int AUTO_GREEN ;
extern int AUTO_YELLOW;

// Counter for each side
extern int counterRed1 ;
extern int counterGreen1 ;
extern int counterYellow1 ;

extern int counterRed2 ;
extern int counterGreen2 ;
extern int counterYellow2 ;

// Status for MODE1
extern int statusAUTO1; // For displaying traffic light
extern int statusAUTO2;
extern int statusAUTO3; // For displaying countdown number
extern int statusAUTO4; // For changing MODEs

// Status for MODE2
extern int statusMODE2_1; // For blink led
extern int statusMODE2_2; // For display mode and value
extern int statusMODE2_3; // For making changes in waiting time

// Status for MODE3
extern int statusMODE3_1; // For blink led
extern int statusMODE3_2; // For display mode and value
extern int statusMODE3_3; // For making changes in waiting time

// Status for MODE4
extern int statusMODE4_1; // For blink led
extern int statusMODE4_2; // For display mode and value
extern int statusMODE4_3; // For making changes in waiting time

void initWaitingTime(void);
void initVar(void);

#endif /* INC_GLOBAL_H_ */
