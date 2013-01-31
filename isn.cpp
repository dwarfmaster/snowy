#include "Arduino.h"
#include "reveil.hpp"
#include "sound.hpp"
#include "screen.hpp"

void setup();
void loop();

Screen scr;
Sound snd;
Reveil reveil(&scr, &snd);

void setup()
{
	instance = &reveil;
}

void loop()
{
	reveil.update();
}


