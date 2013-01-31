
#ifndef DEF_SCREEN
#define DEF_SCREEN

#include "Arduino.h"
#include "LiquidCrystal.h"

class Screen
{
	public:
		Screen();

		template<typename T>
		void print(T txt, unsigned int x = 0, unsigned int y = 0)
		{
			m_lcd.setCursor(x, y);
			m_lcd.print(txt);
		}

	private:
		LiquidCrystal m_lcd;
};

#endif//DEF_SCREEN

