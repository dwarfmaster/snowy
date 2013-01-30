
#include "screen.hpp"
#include "pins.hpp"

Screen::Screen()
	: m_lcd(pinScrRS, pinScrEn, pinScr1, pinScr2, pinScr3, pinScr4)
{
	m_lcd.begin(16,2); // TODO vérifier
}

Screen::~Screen()
{}

void Screen::print(const char* txt, unsigned int x, unsigned int y)
{
	m_lcd.clear();
	m_lcd.setCursor(x, y);
	m_lcd.print(txt);
}

void Screen::refresh()
{}

