/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"
#include "software_timer.h"

#define LANE1_INIT 1
#define LANE1_RED 2
#define LANE1_GREEN 3
#define LANE1_YELLOW 4
//
//#define LANE2_INIT 11
//#define LANE2_RED 12
//#define LANE2_GREEN 13
//#define LANE2_YELLOW 14

//extern int led_duration[3];
extern uint8_t segmentNumber[10];

extern int status; //variable for changing state of fsm

void setTrafficGreen1();
void setTrafficRed1();
void setTrafficYellow1();
void setTrafficGreen2();
void setTrafficRed2();
void setTrafficYellow2();
void initTrafficLight1();
void initTrafficLight2();

#endif /* INC_GLOBAL_H_ */
