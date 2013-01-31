
#include "screen.hpp"
#include "pins.hpp"

Screen::Screen()
	: m_lcd(pinScrRS, pinScrEn, pinScr1, pinScr2, pinScr3, pinScr4)
{
	m_lcd.begin(16,2); // TODO vérifier
}

