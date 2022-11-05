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

#define INIT 1
#define RESET_BUTTON_PRESSED 2
#define INC_BUTTON_PRESSED 3
#define DEC_BUTTON_PRESSED 4
#define AUTO_COUNTDOWN 5


extern uint8_t segmentNumber[10];

extern int status; //variable for changing state of fsm

extern int counter;
#endif /* INC_GLOBAL_H_ */
