#include "global.h"

int status1 = 0;
int status2 = 0;
int counter = 0;

void initCounter(){
	counter = 2;
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
}
