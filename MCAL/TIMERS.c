/*
 * TIMERS.c
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#include "TIMERS.h"

volatile uint16 edge1;
volatile uint16 edge2;
volatile uint16 fallingEdge;
volatile uint8 counter = 0;

void Ti1_Init() {
	SREG &= ~(1 << 7);
	TCNT1 = 0;
	TCCR1 = 0x0000;

	TIMSK |= 4;
	TIMSK &= ~(8);
	TIMSK &= ~(16);
	TIMSK &= ~(32);
	SREG |= (1 << 7);
}

void Ti2_Init() {
	SREG &= ~(1 << 7);
	TCNT2 = 0x00;
	TCCR2 = 0x60;

	SET_PIN(DDRD, 7);
}

void Ti2_Start() {
	TCCR2 |= 4;
}

void Ti2_PWM(uint8 duty) {
	OCR2 = (duty * 255) / 100.0;
}

void ICU_Init() {
	Ti1_Init();
	TCCR1 = 0x0041;
	TIMSK |= (1 << 5);
}
