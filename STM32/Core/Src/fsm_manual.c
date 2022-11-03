/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2022
 *      Author: acer
 */

#include "fsm_manual.h"


void fsm_manual_run(){
	 ////////////////////////////////////////////////////////
	/*--------------------- MODE2 ------------------------*/
   ////////////////////////////////////////////////////////
	if (mode == MODE2){

		//Blink LEDs
		switch (statusMODE2_1){
			case INIT:
				statusMODE2_1 = TOGGLE;
				setTimer4(1);
				break;
			case TOGGLE:
				if (timer4_flag == 1){
					toggleREDs();
					setTimer4(25);
				}
				break;
			default:
				break;
		}

		//Show mode and value
		switch (statusMODE2_2){
			case INIT:
				statusMODE2_2 = DOZEN;
				setTimer5(1);
				break;
			case DOZEN:
				if (timer5_flag == 1){
					blinkDigit1(mode, AUTO_RED);
					statusMODE2_2 = UNIT;
					setTimer5(25);
				}
				break;
			case UNIT:
				if (timer5_flag == 1){
					blinkDigit2(mode, AUTO_RED);
					statusMODE2_2 = DOZEN;
					setTimer5(25);
				}
				break;
			default:
				break;
		}

		// Changing Red Light Waiting Time
		switch(statusMODE2_3){
			case INIT:
				if (isButtonPressed(BUTTON2)==1){
					statusMODE2_3 = INCREASE;
					AUTO_RED+=1;
				}

				if (isButtonPressed(BUTTON3)==1){
					statusMODE2_3 = DECREASE;
					AUTO_RED-=1;
				}
				break;
			case INCREASE:
				if (isButtonPressed(BUTTON2)==1){
					AUTO_RED += 1;
					if (AUTO_RED > UPPER_BOUND) AUTO_RED = UPPER_BOUND;
				}
				if (isButtonPressed(BUTTON3)==1){
					AUTO_RED -= 1;
					if (AUTO_RED < LOWER_BOUND) AUTO_RED = LOWER_BOUND;
					statusMODE2_3 = DECREASE;
				}
				if (isButtonPressed(BUTTON4)==1) statusMODE2_3 = SAVE;
				break;
			case DECREASE:
				if (isButtonPressed(BUTTON2)==1){
					AUTO_RED += 1;
					if (AUTO_RED > UPPER_BOUND) AUTO_RED = UPPER_BOUND;
					statusMODE2_3 = INCREASE;
				}

				if (isButtonPressed(BUTTON3)==1){
					AUTO_RED -= 1;
					if (AUTO_RED < LOWER_BOUND) AUTO_RED = LOWER_BOUND;
				}
				if (isButtonPressed(BUTTON4)==1) statusMODE2_3 = SAVE;
				break;
			case SAVE:
				mode = MODE1;
				initVar();
				break;
			default:
				break;
		}

		if (isButtonPressed(BUTTON1)==1){
			mode = MODE3;
		}
	}

	 ////////////////////////////////////////////////////////
	/*--------------------- MODE3 ------------------------*/
   ////////////////////////////////////////////////////////
	if (mode == MODE3){
		//Blink LEDs
		switch (statusMODE3_1){
			case INIT:
				statusMODE3_1 = TOGGLE;
				setTimer6(1);
				break;
			case TOGGLE:
				if (timer6_flag == 1){
					toggleGREENs();
					setTimer6(25);
				}
				break;
			default:
				break;
		}

		//Show mode and value
		switch (statusMODE3_2){
			case INIT:
				statusMODE3_2 = DOZEN;
				setTimer7(1);
				break;
			case DOZEN:
				if (timer7_flag == 1){
					blinkDigit1(mode, AUTO_GREEN);
					statusMODE3_2 = UNIT;
					setTimer7(25);
				}
				break;
			case UNIT:
				if (timer7_flag == 1){
					blinkDigit2(mode, AUTO_GREEN);
					statusMODE3_2 = DOZEN;
					setTimer7(25);
				}
				break;
			default:
				break;
		}

		// Changing Green Light Waiting Time
		switch(statusMODE3_3){
			case INIT:
				if (isButtonPressed(BUTTON2)==1){
					statusMODE3_3 = INCREASE;
					AUTO_GREEN+=1;
				}

				if (isButtonPressed(BUTTON3)==1){
					statusMODE3_3 = DECREASE;
					AUTO_GREEN-=1;
				}
				break;
			case INCREASE:
				if (isButtonPressed(BUTTON2)==1){
					AUTO_GREEN += 1;
					if (AUTO_GREEN > UPPER_BOUND) AUTO_GREEN = UPPER_BOUND;
				}

				if (isButtonPressed(BUTTON3)==1){
					AUTO_GREEN -= 1;
					if (AUTO_GREEN < LOWER_BOUND) AUTO_GREEN = LOWER_BOUND;
					statusMODE3_3 = DECREASE;
				}

				if (isButtonPressed(BUTTON4)==1) statusMODE3_3 = SAVE;
				break;

			case DECREASE:
				if (isButtonPressed(BUTTON2)==1){
					AUTO_GREEN += 1;
					if (AUTO_GREEN > UPPER_BOUND) AUTO_GREEN = UPPER_BOUND;
					statusMODE3_3 = INCREASE;
				}

				if (isButtonPressed(BUTTON3)==1){
					AUTO_GREEN -= 1;
					if (AUTO_GREEN < LOWER_BOUND) AUTO_GREEN = LOWER_BOUND;
				}

				if (isButtonPressed(BUTTON4)==1) statusMODE3_3 = SAVE;
				break;
			case SAVE:
				mode = MODE1;
				initVar();
				break;
			default:
				break;
		}

		if (isButtonPressed(BUTTON1)==1){
			mode = MODE4;
		}
	}

	 ////////////////////////////////////////////////////////
	/*--------------------- MODE4 ------------------------*/
   ////////////////////////////////////////////////////////
	if (mode == MODE4){

		//Blink LEDs
		switch (statusMODE4_1){
			case INIT:
				statusMODE4_1 = TOGGLE;
				setTimer8(1);
				break;
			case TOGGLE:
				if (timer8_flag == 1){
					toggleYELLOWs();
					setTimer8(25);
				}
				break;
			default:
				break;
		}

		//Show mode and value
		switch (statusMODE4_2){
			case INIT:
				statusMODE4_2 = DOZEN;
				setTimer9(1);
				break;
			case DOZEN:
				if (timer9_flag == 1){
					blinkDigit1(mode, AUTO_YELLOW);
					statusMODE4_2 = UNIT;
					setTimer9(25);
				}
				break;
			case UNIT:
				if (timer9_flag == 1){
					blinkDigit2(mode, AUTO_YELLOW);
					statusMODE4_2 = DOZEN;
					setTimer9(25);
				}
				break;
			default:
				break;
		}

		// Changing YELLOW Light Waiting Time
		switch(statusMODE4_3){
			case INIT:
				if (isButtonPressed(BUTTON2)==1){
					statusMODE4_3 = INCREASE;
					AUTO_YELLOW+=1;
				}

				if (isButtonPressed(BUTTON3)==1){
					statusMODE4_3 = DECREASE;
					AUTO_YELLOW-=1;
				}
				break;
			case INCREASE:
				if (isButtonPressed(BUTTON2)==1){
					AUTO_YELLOW += 1;
					if (AUTO_YELLOW > UPPER_BOUND) AUTO_YELLOW = UPPER_BOUND;
				}

				if (isButtonPressed(BUTTON3)==1){
					AUTO_YELLOW -= 1;
					if (AUTO_YELLOW < LOWER_BOUND) AUTO_YELLOW = LOWER_BOUND;
					statusMODE4_3 = DECREASE;
				}

				if (isButtonPressed(BUTTON4)==1) statusMODE4_3 = SAVE;
				break;
			case DECREASE:
				if (isButtonPressed(BUTTON2)==1){
					AUTO_YELLOW += 1;
					if (AUTO_YELLOW > UPPER_BOUND) AUTO_YELLOW = UPPER_BOUND;
					statusMODE4_3 = INCREASE;
				}

				if (isButtonPressed(BUTTON3)==1){
					AUTO_YELLOW -= 1;
					if (AUTO_YELLOW < LOWER_BOUND) AUTO_YELLOW = LOWER_BOUND;
				}

				if (isButtonPressed(BUTTON4)==1) statusMODE4_3 = SAVE;
				break;
			case SAVE:
				mode = MODE1;
				initVar();
				break;
			default:
				break;
		}

		if (isButtonPressed(BUTTON1)==1){
			mode = MODE1;
			initVar();
		}
	}
}
