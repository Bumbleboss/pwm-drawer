/*
 * LCD.h
 *
 *  Created on: 22 Oct 2022
 *      Author: Bumbleboss
 */

#ifndef HALL_LCD_H_
#define HALL_LCD_H_

#include <util/delay.h>

#include "../MCAL/DIO.h"
#include "LCD_Cfg.h"

void LCD_Init();
void LCD_WriteCommand(uint8 cmd);
void LCD_GoTo(uint8 row , uint8 col);

void LCD_WriteChar(uint8 chr);
void LCD_WriteString(uint8* str);

#endif /* HALL_LCD_H_ */
