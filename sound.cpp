
#include "sound.hpp"

// Internal functions
struct NoteLink{ Notes n; int freq; };
NoteLink links[] = {
	{DO, 2093},
	{RE, 0},
	{MI, 0},
	{FA, 1397},
	{SOL, 1568},
	{LA, 1760},
	{SI, 1865},
};

int freqFromNote(Notes n)
{
	for(unsigned int i = 0; i < NO; ++i)
	{
		if( n == links[i].n )
			return links[i].freq;
	}
	return 0;
}

void Sound::playNote(Notes note, unsigned int duration)
{
	tone(pinMus, freqFromNote(note));
}

// Interface functions
void Sound::load()
{
	m_vol = 5;
	m_paused = true;
	m_pos = 0;
	m_subPos = 1;
	m_mute = false;
	pinMode(pinMus, OUTPUT);
}

void Sound::play()
{
	m_paused = false;
	m_mute = false;
	m_firstTime = millis();
	m_lastTime = millis();
	m_vol = 125;
	m_pos = 0;
	m_subPos = 1;

	m_timeStay = music[0].duration * tempo;
	playNote(music[0].note, m_timeStay);
}

void Sound::update()
{
	if( m_paused )
		return;
	
	if( m_pos >= sizeMus )
	{
		noTone(pinMus);
		delay(tempo);
		play();
		return;
	}

	m_vol = (millis() - m_firstTime) * (130/10000);
	m_vol += 125;
	if( m_vol > 255 ) m_vol = 255;

	unsigned int timeSpent = millis() - m_lastTime;
	if( timeSpent > m_timeStay )
	{
		if( m_mute )
		{
			if( m_subPos >= music[m_pos].repeat )
			{
				++m_pos;
				m_subPos = 1;
			}
			else
				++m_subPos;

			m_timeStay = music[m_pos].duration * tempo;
			playNote(music[m_pos].note, m_timeStay);
			m_mute = false;
		}
		else
		{
			noTone(pinMus);
			m_timeStay = 50;
			m_mute = true;
		}
		m_lastTime = millis();
	}
}

void Sound::stop()
{
	m_paused = true;
	m_firstTime = 0;
	m_pos = 0;
	m_subPos = 0;

	noTone(pinMus);
}

void Sound::setvolume(int vol)
{
	m_vol = vol;
}


