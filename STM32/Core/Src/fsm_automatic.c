/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "fsm_automatic.h"

int led_buffer[2] = {0,0};
//Each state will have 1s to perform task
void fsm_automatic_run(void){
	if (mode == MODE1){
		//For W-E direction
		switch (statusAUTO1){
			case INIT:
				statusAUTO1 = STATE_RED;
				setTimer1(100);
				break;
			case STATE_RED:
				if (timer1_flag == 1){
					enableRed1();
					led_buffer[0] = counterRed1;
					counterRed1--;
					if (counterRed1 == INIT){
						counterRed1 = AUTO_RED;
						statusAUTO1 = STATE_GREEN;
					}
					setTimer1(100);
				}
				break;
			case STATE_GREEN:
				if (timer1_flag == 1){
					enableGreen1();
					led_buffer[0] = counterGreen1;
					counterGreen1--;
					if (counterGreen1 == INIT){
						counterGreen1 = AUTO_GREEN;
						statusAUTO1 = STATE_YELLOW;
					}
					setTimer1(100);
				}
				break;
			case STATE_YELLOW:
				if (timer1_flag == 1){
					enableYellow1();
					led_buffer[0] = counterYellow1;
					counterYellow1--;
					if (counterYellow1 == INIT){
						counterYellow1 = AUTO_YELLOW;
						statusAUTO1 = STATE_RED;
					}
					setTimer1(100);
				}
				break;
			default:
				break;
		}

		//For N-S direction
		switch (statusAUTO2){
			case INIT:
				statusAUTO2 = STATE_GREEN;
				setTimer2(100);
				break;
			case STATE_RED:
				if (timer2_flag == 1){
					enableRed2();
					led_buffer[1] = counterRed2;
					counterRed2--;
					if (counterRed2 == INIT){
						counterRed2 = AUTO_RED;
						statusAUTO2 = STATE_GREEN;
					}
					setTimer2(100);
				}
				break;
			case STATE_GREEN:
				if (timer2_flag == 1){
					enableGreen2();
					led_buffer[1] = counterGreen2;
					counterGreen2--;
					if (counterGreen2 == INIT){
						counterGreen2 = AUTO_GREEN;
						statusAUTO2 = STATE_YELLOW;
					}
					setTimer2(100);
				}
				break;
			case STATE_YELLOW:
				if (timer2_flag == 1){
					enableYellow2();
					led_buffer[1] = counterYellow2;
					counterYellow2--;
					if (counterYellow2 == INIT){
						counterYellow2 = AUTO_YELLOW;
						statusAUTO2 = STATE_RED;
					}
					setTimer2(100);
				}
				break;
			default:
				break;
		}

		// Display waiting time
		switch (statusAUTO3){
			case INIT:
				statusAUTO3 = DOZEN;
				setTimer3(100);
				break;
			case DOZEN:
				if (timer3_flag == 1){
					blinkDigit1(led_buffer[0], led_buffer[1]);
					statusAUTO3 = UNIT;
					setTimer3(50);
				}
				break;
			case UNIT:
				if (timer3_flag == 1){
					blinkDigit2(led_buffer[0], led_buffer[1]);
					statusAUTO3 = DOZEN;
					setTimer3(50);
				}
				break;
			default:
				break;
		}

		// Move to Modify Mode
		switch(statusAUTO4){
			case INIT:
				if (isButtonPressed(BUTTON1)==1)
					mode = MODE2;
				break;
			case MODE2:
				if (isButtonPressed(BUTTON1)==1)
					mode = MODE3;
				break;
			case MODE3:
				if (isButtonPressed(BUTTON1)==1)
					mode = MODE4;
				break;
			case MODE4:
				if (isButtonPressed(BUTTON1)==1)
					mode = MODE1;
				initVar();
				break;
			default:
				break;
		}
	}

}
