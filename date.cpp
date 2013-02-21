
/*
 * Copyright (C) 2013 Chabassier Luc
 * Copyright (C) 2013 Héloïse Badaroux
 * Copyright (C) 2013 Marie Qiu
 * Copyright (C) 2013 Marie Elisabelar
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "date.hpp"
#include "Arduino.h"

void Date::load()
{
	m_houre = 0;
	m_min = 0;
	m_sec = 0;
	m_lastTime = millis();
}

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
	unsigned long timeE = time - m_lastTime;

	m_sec += (timeE / 1000);
	m_min += (m_sec / 60);
	m_sec %= 60;
	m_houre += (m_min / 60);
	m_min %= 60;
	m_houre %= 24;

	m_lastTime = time - (timeE % 1000);
}

bool Date::operator==(const Date& d) const
{
	return (d.m_houre == m_houre) && (d.m_min == m_min) && (d.m_sec == m_sec);
}

