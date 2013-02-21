
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

#ifndef DEF_DATE
#define DEF_DATE

class Date
{
	public:
		void load();

		unsigned short addM();
		unsigned short subM();
		unsigned short addH();
		unsigned short subH();

		unsigned short getH() const;
		unsigned short getM() const;
		unsigned short getS() const;

		void update();
		bool operator==(const Date& d) const;

	private:
		unsigned short m_houre;
		unsigned short m_min;
		unsigned short m_sec;
		long m_lastTime;
};

#endif
