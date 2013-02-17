
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

