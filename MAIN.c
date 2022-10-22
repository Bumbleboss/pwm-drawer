/*
 * main.c
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#include "HALL/LCD.h"

int main() {
	LCD_Init();
	LCD_WriteString("Hello!");

	while(1) {}
}
