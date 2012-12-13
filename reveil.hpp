
#ifndef DEF_REVEIL
#define DEF_REVEIL

#include "pins.hpp"
#include "screen.hpp"
#include "sound.hpp"

class Reveil
{
	public:
		Reveil(Screen* scr, Sound* snd);
		~Reveil();

		void update(); // Lance la sonnerie si l'heure est arrivée
		void reglage(); // Interface de réglage de l'heure de son

	private:
		Screen* m_scr;
		Sound* m_snd; 
};

#endif//DEF_REVEIL

