
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

