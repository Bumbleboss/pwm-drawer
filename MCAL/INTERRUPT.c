/*
 * ISR.c
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */


#include "avr/interrupt.h"
#include <stdlib.h>

#include "TIMERS.h"
#include "../HALL/LCD.h"

ISR(TIMER1_CAPT_vect) {
	double high = 0, period = 0;
	static uint8  count = 0;

	if (count == 0) {
		edge1 = ICR1;
		TCCR1 = 0X0001;
		count = 1;
	} else if (count == 1) {
		fallingEdge = ICR1;
		TCCR1 = 0X0041;
		count = 2;
	} else if (count == 2) {
		edge2 = ICR1;
		TCCR1 = 0x0000;
		count = 3;

		high = (fallingEdge + (counter * 65536)) - edge1;
		period = (edge2 + (counter * 65536))  - edge1;

		double duty = (high) / (period + (256 * counter));
		double freq = 16000000.0 / period;

		char output[16] = " ";
		dtostrf(freq, 16, 2, output);
		LCD_WriteString(output);

		LCD_GoTo(1, 0);

		char output2[16] = " ";
		dtostrf(duty, 16, 2, output2);
		LCD_WriteString(output2);
	}
}

ISR(TIMER1_OVF_vect) {
	counter++;
}
