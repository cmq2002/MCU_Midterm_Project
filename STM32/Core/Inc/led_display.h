#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include "global.h"

void enableRed1();
void enableYellow1();
void enableGreen1();

void enableRed2();
void enableYellow2();
void enableGreen2();

void toggleREDs();
void toggleGREENs();
void toggleYELLOWs();

void display7SEG1(int num);
void display7SEG2(int num);

void blinkDigit1(int num1, int num2);
void blinkDigit2(int num1, int num2);

#endif /* INC_LED_DISPLAY_H_ */
