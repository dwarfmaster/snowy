
#ifndef DEF_REVEIL
#define DEF_REVEIL

#include "pins.hpp"
#include "screen.hpp"
#include "sound.hpp"
#include "date.hpp"

void upButtonClic();
void downButtonClic();

class Reveil
{
	friend void upButtonClic();
	friend void downButtonClic();

	const int pinEdit = 4;
	const int pinBeep = 5;

	const int pinREye = 14;
	const int pinLEye = 15;
	const int pinLeds[3] = {16,17,18};

	const int pinStop = 19;

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

		void print() const;
		void buzz();
		void toggleLeds();
};

extern Reveil* instance;

#endif//DEF_REVEIL

