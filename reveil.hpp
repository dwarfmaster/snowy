
#ifndef DEF_REVEIL
#define DEF_REVEIL

#include "pins.hpp"
#include "screen.hpp"
#include "sound.hpp"
#include "date.hpp"

void upButtonClic();
void downButtonClic();
void toggleLeds();

class Reveil
{
	friend void upButtonClic();
	friend void downButtonClic();

	public:
		void load(Screen* scr, Sound* snd);

		void update(); // Lance la sonnerie si l'heure est arrivée

	private:
		Screen* m_scr;
		Sound* m_snd; 
		Date* m_used;
		Date m_date;
		Date m_rev;

		bool m_edit;
		bool m_beep;

		void print();
		void buzz();
};

extern Reveil* instance;

#endif//DEF_REVEIL

