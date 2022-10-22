/*
 * DIO.c
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#include "DIO.h"

void DIO_SetPortDir(uint8 port, uint8 dir) {
	switch(port) {
		case DIO_PORTA:
			DDRA = dir;
			break;
		case DIO_PORTB:
			DDRB = dir;
			break;
		case DIO_PORTC:
			DDRC = dir;
			break;
		case DIO_PORTD:
			DDRD = dir;
			break;
	}
}

void DIO_SetPinDir(uint8 port, uint8 pin, uint8 dir) {
	if (dir == HIGH) {
		switch(port) {
			case DIO_PORTA:
				SET_PIN(DDRA, pin);
				break;
			case DIO_PORTB:
				SET_PIN(DDRB, pin);
				break;
			case DIO_PORTC:
				SET_PIN(DDRC, pin);
				break;
			case DIO_PORTD:
				SET_PIN(DDRD, pin);
				break;
		}
	} else if (dir == LOW) {
		switch(port) {
			case DIO_PORTA:
				CLR_PIN(DDRA, pin);
				break;
			case DIO_PORTB:
				CLR_PIN(DDRB, pin);
				break;
			case DIO_PORTC:
				CLR_PIN(DDRC, pin);
				break;
			case DIO_PORTD:
				CLR_PIN(DDRD, pin);
				break;
		}
	}
}

void DIO_SetPortValue(uint8 port, uint8 value) {
	switch(port) {
		case DIO_PORTA:
			PORTA = value;
			break;
		case DIO_PORTB:
			PORTB = value;
			break;
		case DIO_PORTC:
			PORTC = value;
			break;
		case DIO_PORTD:
			PORTD = value;
			break;
	}
}

void DIO_SetPinValue(uint8 port, uint8 pin, uint8 value) {
	if (value == HIGH) {
		switch(port) {
			case DIO_PORTA:
				SET_PIN(PORTA,pin);
				break;
			case DIO_PORTB:
				SET_PIN(PORTB,pin);
				break;
			case DIO_PORTC:
				SET_PIN(PORTC,pin);
				break;
			case DIO_PORTD:
				SET_PIN(PORTD,pin);
				break;
		}
	} else if (value == LOW) {
		switch(port) {
			case DIO_PORTA:
				CLR_PIN(PORTA, pin);
				break;
			case DIO_PORTB:
				CLR_PIN(PORTB, pin);
				break;
			case DIO_PORTC:
				CLR_PIN(PORTC, pin);
				break;
			case DIO_PORTD:
				CLR_PIN(PORTD, pin);
				break;
		}
	}
}

uint8 DIO_GetPort(uint8 port) {
	switch(port) {
		case DIO_PORTA:
			return PINA;
			break;
		case DIO_PORTB:
			return PINB;
			break;
		case DIO_PORTC:
			return PINC;
			break;
		case DIO_PORTD:
			return PIND;
			break;
	}

	return -1;
}

uint8 DIO_GetPin(uint8 port, uint8 pin) {
	switch(port) {
		case DIO_PORTA:
			return GET_PIN(PINA, pin);
			break;
		case DIO_PORTB:
			return GET_PIN(PINB, pin);
			break;
		case DIO_PORTC:
			return GET_PIN(PINC, pin);
			break;
		case DIO_PORTD:
			return GET_PIN(PIND, pin);
			break;
	}

	return -1;
}

uint8 DIO_GetPortValue(uint8 port) {
	switch(port) {
		case DIO_PORTA:
			return PORTA;
			break;
		case DIO_PORTB:
			return PORTB;
			break;
		case DIO_PORTC:
			return PORTC;
			break;
		case DIO_PORTD:
			return PORTD;
			break;
		default:
			break;
	}

	return -1;
}

void DIO_TogglePin(uint8 port, uint8 pin) {
	switch(port) {
		case DIO_PORTA:
			TOGGLE_PIN(PORTA, pin);
			break;
		case DIO_PORTB:
			TOGGLE_PIN(PORTB, pin);
			break;
		case DIO_PORTC:
			TOGGLE_PIN(PORTC, pin);
			break;
		case DIO_PORTD:
			TOGGLE_PIN(PORTD, pin);
			break;
	}
}

void DIO_SetPullUpRes(uint8 port, uint8 pin) {
	switch(port) {
		case DIO_PORTA :
			SET_PIN(PORTA,pin);
			break;
		case DIO_PORTB :
			SET_PIN(PORTB,pin);
			break;
		case DIO_PORTC :
			SET_PIN(PORTC,pin);
			break;
		case DIO_PORTD :
			SET_PIN(PORTD,pin);
			break;
		default:
			break;
	}
}
