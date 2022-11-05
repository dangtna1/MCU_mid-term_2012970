/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#include "fsm_automatic.h"

void fsm_simple_buttons_run() {
	switch(status) {
		case INIT:
			status = RESET_BUTTON_PRESSED;
			timer3_flag = 1; //used for auto-count down after 10s in every 1s
			break;
		case RESET_BUTTON_PRESSED:
			counter = 0;
			display7SEG(segmentNumber[counter]);
			if (isButtonPressed(1) == 1) {
				status = INC_BUTTON_PRESSED;
				counter++;
				setTimer2(11000); //used for time-out and count down continually
			}
			if (isButtonPressed(2) == 1) {
				status = DEC_BUTTON_PRESSED;
				counter = 9;
				setTimer2(11000); //used for time-out and count down continually
			}
			break;
		case INC_BUTTON_PRESSED:
			if (counter > 9) counter = 0;
			if (isButtonPressed(1) == 1) { //press the button1 again or keep pressing more than 3s
				counter++;
				if (counter > 9) counter = 0;
				setTimer2(11000); //update time-out
			}
			display7SEG(segmentNumber[counter]);
			if (isButtonPressed(0) == 1) status = RESET_BUTTON_PRESSED;
			if (isButtonPressed(2) == 1) {
				status = DEC_BUTTON_PRESSED;
				counter--;
				setTimer2(11000); //update time-out
			}
			if (timer2_flag == 1) {
//				if (timer3_flag == 1) {
//					setTimer3(1000);
//					counter--;
//					if (counter == 0) status = RESET_BUTTON_PRESSED;
//					display7SEG(segmentNumber[counter]);
//				}
				status = AUTO_COUNTDOWN;
			}
			break;
		case DEC_BUTTON_PRESSED:
			if (counter < 0) counter = 9;
			if (isButtonPressed(2) == 1) { //press the button2 again or keep pressing more than 3s
				counter--;
				if (counter < 0) counter = 9;
				setTimer2(11000); //update time-out
			}
			display7SEG(segmentNumber[counter]);
			if (isButtonPressed(0) == 1) status = RESET_BUTTON_PRESSED;
			if (isButtonPressed(1) == 1) {
				status = INC_BUTTON_PRESSED;
				counter++;
				setTimer2(11000); //update time-out
			}
			if (timer2_flag == 1) {
//				if (timer3_flag == 1) {
//					setTimer3(1000);
//					counter--;
//					if (counter == 0) status = RESET_BUTTON_PRESSED;
//					display7SEG(segmentNumber[counter]);
//				}
				status = AUTO_COUNTDOWN;
			}
			break;
		case AUTO_COUNTDOWN:
			//todo
			if (timer3_flag == 1) {
				setTimer3(1000);
				counter--;
				if (counter == 0) status = RESET_BUTTON_PRESSED;
				display7SEG(segmentNumber[counter]);
			}
			if (isButtonPressed(1) == 1) {
				status = INC_BUTTON_PRESSED;
				counter++;
				setTimer2(11000); //used for time-out and count down continually
				timer3_flag = 1;
			}
			if (isButtonPressed(2) == 1) {
				status = DEC_BUTTON_PRESSED;
				counter--;
				setTimer2(11000); //used for time-out and count down continually
				timer3_flag = 1;
			}
			break;
		default:
			//todo
			break;
	}
}



