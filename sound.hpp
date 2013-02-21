
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

#ifndef DEF_SOUND
#define DEF_SOUND

#include "Arduino.h"
#include "pins.hpp"
#include "music.hpp"

class Sound
{
	public:
		typedef void (*cb_t)();

		void load();

		void play();
		void update();
		void stop();
		void setvolume(int vol);
		void setCb(cb_t cb);

	private:
		int m_vol;
		bool m_paused;
		bool m_mute;
		cb_t m_cb;

		unsigned long m_lastTime;
		unsigned long m_firstTime;
		unsigned int m_pos;
		unsigned int m_subPos;
		unsigned int m_timeStay;

		void playNote(Notes note, unsigned int duration);
};

#endif//DEF_SOUND

