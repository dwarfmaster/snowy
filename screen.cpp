
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

