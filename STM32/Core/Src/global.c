#include "global.h"

int status1 = 0;
int status2 = 0;
int status3 = 0;
int counter = 0;

void initCounter(){
	counter = DISP;
}

void resetCounter(){
	counter = LOWER_BOUND;
}

void setCounter(){
	counter = UPPER_BOUND;
}

void initVar(void){
	status1 = INIT;
	status2 = INIT;
	status3 = INIT;
}
