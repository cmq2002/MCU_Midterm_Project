#include "led_display.h"

void toggleRED(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
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

void display7SEG(int num){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, ((sevenSegTable[num]>>0)&0x01));
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, ((sevenSegTable[num]>>1)&0x01));
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, ((sevenSegTable[num]>>2)&0x01));
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, ((sevenSegTable[num]>>3)&0x01));
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, ((sevenSegTable[num]>>4)&0x01));
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, ((sevenSegTable[num]>>5)&0x01));
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, ((sevenSegTable[num]>>6)&0x01));
}

