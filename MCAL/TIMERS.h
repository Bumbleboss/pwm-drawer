/*
 * TIMERS.h
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#ifndef MCAL_TIMERS_H_
#define MCAL_TIMERS_H_

#include "../ETC/TYPES.h"
#include "../ETC/MACROS.h"
#include "../ETC/REGISTERS.h"

/**
	Initializes Timer 1 with mode as a parameter.
	Currently defaults to Normal mode per project requisite.
*/
void Ti1_Init();

/**
	Initializes Timer 2 with mode as a parameter.
	Currently defaults to PWM mode (not to be confused with fast PWM mode) per project requisite.

	As it initializes timer, interrupt is triggered. 
*/
void Ti2_Init();

/**
	Starts Timer 2 with PRESCALER code.
*/
void Ti2_Start();

/**
	Provides Timer 2 with duty as a parameter
*/
void Ti2_PWM(uint8 duty);

/**
	Initializes Input Capture Unit (ICU).
*/
void ICU_Init();

extern volatile uint16 edge1;
extern volatile uint16 edge2;
extern volatile uint16 fallingEdge;
extern volatile uint8 counter;

#endif /* MCAL_TIMERS_H_ */
