
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

	public:
		Reveil(Screen* scr, Sound* snd);
		~Reveil();

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
};

extern volatile Reveil* instance;

#endif//DEF_REVEIL

