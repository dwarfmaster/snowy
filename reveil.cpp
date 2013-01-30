
#include "reveil.hpp"

Reveil::Reveil(Screen* scr, Sound* snd)
	: m_scr(scr), m_snd(snd), m_used(&m_date), m_edit(false), m_beep(false)
{}

Reveil::~Reveil()
{}

void Reveil::update()
{
}

void upButtonClic()
{
	if( m_edit )
		m_used->addM();
}

void downButtonClic()
{
	if( m_edit )
		m_used->sudM();
}

void Reveil::print() const
{
	if( m_edit )
		m_scr->print("E");
	if( m_beep )
		m_scr->print("B", 0, 1);

	if( m_used->getH() < 10 )
	{
		m_scr->print("0", 4);
		m_scr->print(m_used->getH(), 5);
	}
	else
		m_scr->print(m_used->getH(), 4);
	m_scr->print(":", 6);

	if( m_used->getM() < 10 )
	{
		m_scr->print("0", 7);
		m_scr->print(m_used->getM(), 8);
	}
	else
		m_scr->print(m_used->getM(), 7);
	m_scr->print(":", 9);

	if( m_used->getS() < 10 )
	{
		m_scr->print("0", 10);
		m_scr->print(m_used->getS(), 11);
	}
	else
		m_scr->print(m_used->getS(), 10);
}

