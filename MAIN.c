/*
 * main.c
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#include "ETC/MACROS.h"
#include "HALL/LCD.h"
#include "MCAL/TIMERS.h"
#include <stdlib.h>

int main() {
	LCD_Init();
	Ti2_Init(T2_PWM);
	Ti2_PWM(30);
	ICU_Init();
	Ti2_Start();

	while(1) {}
}
