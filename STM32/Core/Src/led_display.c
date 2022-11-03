#include "led_display.h"

void enableRed1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
}

void enableYellow1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
}
void enableGreen1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
}

void enableRed2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
}
void enableYellow2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
}
void enableGreen2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
}

void toggleREDs(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
}
void toggleGREENs(){
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
}
void toggleYELLOWs(){
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
}

//Transfer sequence: gfedcba
//MSB=g, LSB=a <- Active low
//Ex: To display 0 -> sequence = 1000000
const uint8_t sevenSegTable[10] = {
		  0x40 //0
		, 0x79 //1
		, 0x24 //2
		, 0x30 //3
		, 0x19 //4
		, 0x12 //5
		, 0x02 //6
		, 0x78 //7
		, 0x00 //8
		, 0x10 /*9*/};

void display7SEG1(int num){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, ((sevenSegTable[num]>>0)&0x01));
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, ((sevenSegTable[num]>>1)&0x01));
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, ((sevenSegTable[num]>>2)&0x01));
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, ((sevenSegTable[num]>>3)&0x01));
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, ((sevenSegTable[num]>>4)&0x01));
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, ((sevenSegTable[num]>>5)&0x01));
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, ((sevenSegTable[num]>>6)&0x01));
}

void display7SEG2(int num){
	HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ((sevenSegTable[num]>>0)&0x01));
	HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ((sevenSegTable[num]>>1)&0x01));
	HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ((sevenSegTable[num]>>2)&0x01));
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ((sevenSegTable[num]>>3)&0x01));
	HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ((sevenSegTable[num]>>4)&0x01));
	HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ((sevenSegTable[num]>>5)&0x01));
	HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ((sevenSegTable[num]>>6)&0x01));
}

void blinkDigit1(int num1, int num2){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	display7SEG1(num1/10);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	display7SEG2(num2/10);
}

void blinkDigit2(int num1, int num2){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	display7SEG1(num1%10);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	display7SEG2(num2%10);
}
