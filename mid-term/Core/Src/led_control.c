/*
 * led_control.c
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#include "led_control.h"

//LED7SEG
uint8_t segmentNumber[10] = {
        0x3f,
        0x06,
        0x5b,
        0x4f,
        0x66,
        0x6d,
        0x7d,
        0x07,
        0x7f,
        0x67
};
void display7SEG(uint8_t number){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, ((number>>0)&0x01)^0x01);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, ((number>>1)&0x01)^0x01);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, ((number>>2)&0x01)^0x01);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, ((number>>3)&0x01)^0x01);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, ((number>>4)&0x01)^0x01);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, ((number>>5)&0x01)^0x01);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, ((number>>6)&0x01)^0x01);
}



