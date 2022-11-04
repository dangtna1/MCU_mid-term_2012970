/*
 * led7seg.h
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "main.h"

//LED7SEG
extern uint8_t segmentNumber[10];
void display7SEG(uint8_t number);

void unEnableAll();
void enableLed7Seg1();
void enableLed7Seg2();
void enableLed7Seg3();
void enableLed7Seg4();

//LED ĐƠN
void setTrafficGreen1();
void setTrafficRed1();
void setTrafficYellow1();
void setTrafficGreen2();
void setTrafficRed2();
void setTrafficYellow2();
void initTrafficLight1();
void initTrafficLight2();

#endif /* INC_LED_CONTROL_H_ */
