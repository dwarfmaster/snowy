
/*
 * Copyright (C) 2013 Chabassier Luc
 * Copyright (C) 2013 Héloïse Badaroux
 * Copyright (C) 2013 Marie Qiu
 * Copyright (C) 2013 Marie Elisabelar
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "screen.hpp"

LiquidCrystal _lcd(pinScrRS, pinScrEn, pinScr1, pinScr2, pinScr3, pinScr4);

void Screen::load()
{
	// Lettre cloche (0)
	byte cloche[8] = {
		B00100,
		B01110,
		B01010,
		B11011,
		B10001,
		B10101,
		B00100,
	};
	_lcd.createChar(0, cloche);

	// Lettre config (1)
	byte cfg[8] = {
		B01110,
		B01110,
		B01110,
		B01110,
		B01110,
		B00110,
		B00100,
	};
	_lcd.createChar(1, cfg);

	_lcd.begin(16,2);
}

void Screen::printE(unsigned int x, unsigned int y)
{
	_lcd.setCursor(x, y);
	_lcd.write((uint8_t)1);
}

void Screen::printB(unsigned int x, unsigned int y)
{
	_lcd.setCursor(x, y);
	_lcd.write((uint8_t)0);
}

