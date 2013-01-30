
#include "date.hpp"
#include "Arduino.h"

Date::Date()
	: m_houre(0), m_min(0), m_sec(0), m_lastTime(millis())
{}

Date::~Date()
{}

unsigned short Date::addM()
{
	++m_min;
	m_houre += m_min / 60;
	m_houre %= 24;
	m_min %= 60;

	return m_min;
}

unsigned short Date::subM()
{
	if( m_min == 0 )
	{
		m_min = 59;
		if( m_houre == 0 )
			m_houre = 23;
	}
	--m_min;

	return m_min;
}

unsigned short Date::addH()
{
	++m_houre;
	m_houre %= 24;

	return m_houre;
}

unsigned short Date::subH()
{
	if( m_houre == 0 )
		m_houre = 23;
	else
		--m_houre;

	return m_houre;
}

unsigned short Date::getH() const
{
	return m_houre;
}

unsigned short Date::getM() const
{
	return m_min;
}

unsigned short Date::getS() const
{
	return m_sec;
}

void Date::update()
{
	unsigned long time = millis();
	unsigned long timeE = m_lastTime - time;

	m_sec = timeE / 1000;
	m_min = m_sec / 60;
	m_sec %= 60;
	m_houre = m_min / 60;
	m_min %= 60;
	m_houre %= 24;

	m_lastTime = time - timeE % 1000;
}

