#include "reveil.hpp"
#include "Arduino.h"
#include "sound.hpp"
#include "screen.hpp"

void setup();
void loop();

Screen scr;
Sound snd;
Reveil reveil;

void setup()
{
	scr.load();
	snd.load();
	reveil.load(&scr, &snd);
	instance = &reveil;
}

void loop()
{
	reveil.update();
}


