
#include "screen.hpp"

LiquidCrystal _lcd(pinScrRS, pinScrEn, pinScr1, pinScr2, pinScr3, pinScr4);

void Screen::load()
{
	_lcd.begin(16,2);
}

