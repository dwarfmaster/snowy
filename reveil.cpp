
#include "reveil.hpp"

Reveil* instance;

void Reveil::load(Screen* scr, Sound* snd)
{
	m_scr = scr;
	m_snd = snd;
	m_date.load();
	m_rev.load();
	m_used = &m_date;
	m_edit = false;
	m_beep = false;

	// attachInterrupt(0, upButtonClic, RISING);
	// attachInterrupt(1, downButtonClic, RISING);

	pinMode(pinREye, OUTPUT);
	pinMode(pinLEye, OUTPUT);
	for(int i = 0; i < 3; ++i)
		pinMode(pinLeds[i], OUTPUT);
}

void Reveil::update()
{
	// m_edit = (digitalRead(pinEdit) == HIGH);
	m_edit = false;
	// m_beep = (digitalRead(pinBeep) == HIGH);
	m_beep = true;

	if( m_beep )
		m_used = &m_rev;
	else
		m_used = &m_date;

	m_date.update();
	print();

	if( m_beep
			&& m_rev == m_date )
		buzz();
}

void upButtonClic()
{
	if( instance->m_edit )
		instance->m_used->addM();
}

void downButtonClic()
{
	if( instance->m_edit )
		instance->m_used->subM();
}

void Reveil::print()
{
	if( m_edit )
		m_scr->print("E");
	if( m_beep )
		m_scr->print("B", 0, 1);

	if( m_used->getH() < 10 )
	{
		m_scr->print("0", 4);
		m_scr->print(m_used->getH(), 5);
	}
	else
		m_scr->print(m_used->getH(), 4);
	m_scr->print(":", 6);

	if( m_used->getM() < 10 )
	{
		m_scr->print("0", 7);
		m_scr->print(m_used->getM(), 8);
	}
	else
		m_scr->print(m_used->getM(), 7);
	m_scr->print(":", 9);

	if( m_used->getS() < 10 )
	{
		m_scr->print("0", 10);
		m_scr->print(m_used->getS(), 11);
	}
	else
		m_scr->print(m_used->getS(), 10);
}

void Reveil::buzz()
{
	// detachInterrupt(0);
	// detachInterrupt(1);

	m_snd->setCb(toggleLeds);
	m_snd->play();
	unsigned long ltime = millis();
	while( digitalRead(pinStop) != HIGH )
		m_snd->update();

	m_snd->stop();
	m_snd->setCb(NULL);
	// attachInterrupt(0, upButtonClic, RISING);
	// attachInterrupt(1, downButtonClic, RISING);
}

void toggleLeds()
{
	static int step = 0;

	// Les yeux
	analogWrite(pinREye, 255);
	analogWrite(pinLEye, 255);

	// Les leds
	for(int i = 0; i < 3; ++i)
		analogWrite(pinLeds[i], 0);
	Serial.println(pinLeds[step]);
	analogWrite(pinLeds[step], 255);

	++step;
	step %= 3; // Pour éviter qu'il ne grandisse trop, ne fausse ni % 3, ni % 4
}

