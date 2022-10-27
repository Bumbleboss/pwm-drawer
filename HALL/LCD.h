/*
 * LCD.h
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#ifndef HALL_LCD_H_
#define HALL_LCD_H_

#include <util/delay.h>
#include <stdlib.h>

#include "../MCAL/DIO.h"
#include "LCD_Cfg.h"

/**
	Initialize LCD with default config.
*/
void LCD_Init();

/**
	Trigger commands accepted from LCD datasheet.
*/
void LCD_WriteCommand(uint8 cmd);

/**
	Changes position of the LCD caret.
*/
void LCD_GoTo(uint8 row , uint8 col);

/**
	Writes single char values on LCD.
*/
void LCD_WriteChar(uint8 chr);

/**
	Writes multiple char values (String) on LCD.
*/
void LCD_WriteString(uint8* str);

/**
	Writes numeric values in LCD.
	Parameters are the value, the width of the value, and its precision.
*/
void LCD_WriteDouble(double nbr, uint8 width, uint8 prec);

#endif /* HALL_LCD_H_ */
