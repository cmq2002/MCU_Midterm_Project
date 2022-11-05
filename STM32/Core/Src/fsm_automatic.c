/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "fsm_automatic.h"

void off_mode(){
	countDown10s-=1;
	if (countDown10s < 0){
		counter-=1;
		if (counter < 0){
			counter = 0;
			return;
		}
		display7SEG(counter);
	}
}

void fsm_simple_buttons_run(void){

	//Blink Led
	switch (status1){
		case INIT:
			status1 = TOGGLE;
			setTimer1(1);
			break;
		case TOGGLE:
			if (timer1_flag == 1){
				toggleRED();
				setTimer1(100);
			}
			break;
		default:
			break;
	}

	//Modify counter
	switch (status2){
		case INIT:
			if (isButtonPressed(BUTTON1)==1){
				status2 = RESET;
				countDown10s = STANDBY;
			}

			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					counter = LOWER_BOUND;
				countDown10s = STANDBY;
			}

			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					counter = UPPER_BOUND;
				countDown10s = STANDBY;
			}
			break;
		case RESET:
			counter = LOWER_BOUND;
			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					counter = LOWER_BOUND;
				countDown10s = STANDBY;
			}
			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					counter = UPPER_BOUND;
				countDown10s = STANDBY;
			}
			break;
		case INCREASE:
			if (isButtonPressed(BUTTON1)==1){
				status2 = RESET;
				countDown10s = STANDBY;
			}
			if (isButtonPressed(BUTTON2)==1){
				counter += 1;
				if (counter > UPPER_BOUND)
					counter = LOWER_BOUND;
				countDown10s = STANDBY;
			}
			if (isButtonPressedLong(BUTTON2)==1){
				counter += 1;
				if (counter > UPPER_BOUND)
					counter = LOWER_BOUND;
				countDown10s = STANDBY;
			}
			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					counter = UPPER_BOUND;
				countDown10s = STANDBY;
			}
			break;
		case DECREASE:
			if (isButtonPressed(BUTTON1)==1){
				status2 = RESET;
				countDown10s = STANDBY;
			}
			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					counter = LOWER_BOUND;
				countDown10s = STANDBY;
			}
			if (isButtonPressed(BUTTON3)==1){
				counter -= 1;
				if (counter < LOWER_BOUND)
					counter = UPPER_BOUND;
				countDown10s = STANDBY;
			}
			if (isButtonPressedLong(BUTTON3)==1){
				counter -= 1;
				if (counter < LOWER_BOUND)
					counter = UPPER_BOUND;
				countDown10s = STANDBY;
			}
			break;
		default:
			break;
	}
	display7SEG(counter);
}


