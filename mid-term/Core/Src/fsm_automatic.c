/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch(status) { //for lane 1
		case LANE1_INIT:
			initTrafficLight1();
			status = LANE1_GREEN;
			setTimer1(3000);
			break;
		case LANE1_GREEN:
			setTrafficGreen1();
			display7SEG(segmentNumber[3]);
			if (timer1_flag == 1) {
				setTimer1(2000);
				status = LANE1_YELLOW;
			}
			break;
		case LANE1_YELLOW:
			display7SEG(segmentNumber[2]);
			setTrafficYellow1();
			if (timer1_flag == 1) {
				setTimer1(5000);
				status = LANE1_RED;
			}
			break;
		case LANE1_RED:
			display7SEG(segmentNumber[5]);
			setTrafficRed1();
			if (timer1_flag == 1) {
				setTimer1(3000);
				status = LANE1_GREEN;
			}
			break;
		default:
			break;
	}
}



