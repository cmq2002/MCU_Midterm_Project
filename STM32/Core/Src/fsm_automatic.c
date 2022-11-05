/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "fsm_automatic.h"

//System will be ready after 1s
void fsm_simple_buttons_run(void){

	//Blink Led
	switch (status1){
		case INIT:
			status1 = TOGGLE;
			setTimer1(100);
			break;
		case TOGGLE:
			if (timer1_flag == 1){
				toggleRED();
				setTimer1(50);
			}
			break;
		default:
			break;
	}

	//Modify counter
	switch (status2){
		case INIT:
			if (isButtonPressed(BUTTON1)==1)
				status2 = RESET;
			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					resetCounter();
			}
			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					setCounter();
			}
			break;
		case RESET:
			resetCounter();
			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					resetCounter();
			}
			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					setCounter();
			}
			break;
		case INCREASE:
			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					resetCounter();
			}
			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					setCounter();
			}
			break;
		case DECREASE:
			if (isButtonPressed(BUTTON2)==1){
				status2 = INCREASE;
				counter += 1;
				if (counter > UPPER_BOUND)
					resetCounter();
			}
			if (isButtonPressed(BUTTON3)==1){
				status2 = DECREASE;
				counter -= 1;
				if (counter < LOWER_BOUND)
					setCounter();
			}
			break;
		default:
			break;
	}

	// Display counter
	switch (status3){
		case INIT:
			status3 = DISP;
			setTimer2(100);
			break;
		case DISP:
			if (timer2_flag == 1){
				display7SEG(counter);
				setTimer2(50);
			}
			break;
		default:
			break;
	}
}
