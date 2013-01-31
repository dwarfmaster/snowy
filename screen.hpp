
#ifndef DEF_SCREEN
#define DEF_SCREEN

#include "pins.hpp"
#include "Arduino.h"
#include "LiquidCrystal.h"

class Screen
{
	public:
		void load();
		template<typename T>
		void print(T txt, unsigned int x = 0, unsigned int y = 0)
		{
			m_lcd.setCursor(x, y);
			m_lcd.print(txt);
		}

	private:
		LiquidCrystal m_lcd(pinScrRS, pinScrEn, pinScr1, pinScr2, pinScr3, pinScr4);
};

#endif//DEF_SCREEN

