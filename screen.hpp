
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

#ifndef DEF_SCREEN
#define DEF_SCREEN

#include "pins.hpp"
#include "Arduino.h"
#include "LiquidCrystal.h"

extern LiquidCrystal _lcd;

class Screen
{
	public:
		void load();
		void printE(unsigned int x = 0, unsigned int y = 0);
		void printB(unsigned int x = 0, unsigned int y = 0);
		template<typename T>
			void print(T txt, unsigned int x = 0, unsigned int y = 0)
			{
				_lcd.setCursor(x, y);
				_lcd.print(txt);
			}
};

#endif//DEF_SCREEN

