
#ifndef DEf_SOUND
#define DEF_SOUND

#include "pins.hpp"

class Sound
{
	public:
		Sound();
		~Sound();

		void play();
		void stop();
		void setvolume(int vol);

	private:
		int m_vol;
};

#endif//DEF_SOUND

