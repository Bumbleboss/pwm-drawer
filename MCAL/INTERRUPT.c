/*
 * ISR.c
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#include "avr/interrupt.h"

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

		LCD_WriteString("F=");
		LCD_WriteDouble(16000000.0 / period);

		LCD_WriteString(" D=");
		LCD_WriteDouble(duty * 100);

		LCD_GoTo(1, 0);
		for (int i = 0; i < 16; i++) {
			LCD_WriteChar(i < (duty * 10) ? '-' : '_');
		}
	}
}

ISR(TIMER1_OVF_vect) {
	counter++;
}
