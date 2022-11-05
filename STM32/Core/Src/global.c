#include "global.h"

int status1 = 0;
int status2 = 0;
int counter = 0;
int countDown10s = 0;

void initCounter(){
	counter = 6;
	countDown10s = STANDBY;
}

void initVar(void){
	status1 = INIT;
	status2 = INIT;
}
