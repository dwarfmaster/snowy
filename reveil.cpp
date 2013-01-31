
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

	attachInterrupt(0, upButtonClic, RISING);
	attachInterrupt(1, downButtonClic, RISING);
}

void Reveil::update()
{
	if( digitalRead(pinEdit) == HIGH )
		m_edit = true;
	else
		m_edit = false;
	
	if( digitalRead(pinBeep) == HIGH )
		m_beep = true;
	else
		m_beep = false;

	if( m_beep )
		m_used = &m_rev;
	else
		m_used = &m_date;

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

void Reveil::print() const
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
	detachInterrupt(0);
	detachInterrupt(1);

	m_snd->play();
	unsigned long ltime = millis();
	while( digitalRead(pinStop) != HIGH )
	{
		unsigned long time = millis();
		if( time - ltime > 500 )
		{
			toggleLeds();
			ltime = time;
		}
		m_snd->update();
	}

	m_snd->stop();
	attachInterrupt(0, upButtonClic, RISING);
	attachInterrupt(1, downButtonClic, RISING);
}

void Reveil::toggleLeds()
{
	static int step = 0;

	// Les yeux
	int eyeStep = step % 4;
	if( eyeStep == 0
			|| eyeStep == 2 )
	{
		digitalWrite(pinREye, HIGH);
		digitalWrite(pinLEye, HIGH);
	}
	else if( eyeStep == 1 )
	{
		digitalWrite(pinREye, HIGH);
		digitalWrite(pinLEye, LOW);
	}
	else if( eyeStep == 3 )
	{
		digitalWrite(pinREye, LOW);
		digitalWrite(pinLEye, HIGH);
	}

	// Les leds
	for(int i = 0; i < 3; ++i)
		digitalWrite(pinLeds[i], LOW);
	digitalWrite(pinLeds[step % 3], HIGH);

	++step;
	step %= 12; // Pour éviter qu'il ne grandisse trop, ne fausse ni % 3, ni % 4
}

