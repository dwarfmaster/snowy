
#include "sound.hpp"
#include "music.hpp"

// Internal functions
void Sound::playNote(Notes note, unsigned int duration)
{
}

// Interface functions
Sound::Sound()
	: m_vol(5), m_paused(true), m_pos(0)
{
	// TODO initaliser beeper
}

Sound::~Sound()
{
	// TODO libérer beeper
}

void Sound::play()
{
	m_paused = false;
	m_firstTime = millis();
	m_lastTime = millis()
	m_vol = 125;
	// TODO lancer musique
}

void Sound::update()
{
	if( m_paused )
		return;

	m_vol = (millis() - m_firstTime()) * (130/10000);
	m_vol += 125;
	if( m_vol > 255 ) m_vol = 255;

	unsigned int timeSpent = millis() - m_lastTime;
	while( timeSpent <= timeStay )
	{
	}
}

void Sound::stop()
{
	m_paused = true;
	m_firsttime = 0;
	// TODO stopper musique
}

void Sound::setvolume(int vol)
{
	m_vol = vol;
}


