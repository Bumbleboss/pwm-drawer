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

void Ti1_Init(uint16 mode) {
	SREG &= ~(1 << 7);
	TCNT1 = 0;
	TCCR1 = mode;

	TIMSK |= 4;
	TIMSK &= ~(8);
	TIMSK &= ~(16);
	TIMSK &= ~(32);
	SREG |= (1 << 7);
}

void Ti2_Init(uint8 mode) {
	SREG &= ~(1 << 7);
	TCNT2 = 0x00;
	TCCR2 = mode;

	SET_PIN(DDRD, 7);
}

void Ti2_Start() {
	TCCR2 |= T2_PRESCALER_CODE;
}

void Ti2_PWM(uint8 duty) {
	OCR2 = (duty * 255) / 100.0;
}

void ICU_Init() {
	Ti1_Init(T1_NORMAL);
	TCCR1 = 0x0041;
	TIMSK |= (1 << 5);
}
