
#include "reveil.hpp"

Reveil::Reveil(Screen* scr, Sound* snd)
	: m_scr(scr), m_snd(snd), m_edit(false), m_beep(false)
{}

Reveil::~Reveil()
{}

void Reveil::update()
{
}

void upButtonClic()
{
}

void downButtonClic()
{
}

void Reveil::print() const
{
	if( m_edit )
		m_scr->print("E");
	if( m_beep )
		m_scr->print("B", 0, 1);

	if( m_date.getH() < 10 )
	{
		m_scr->print("0", 4);
		m_scr->print(m_date.getH(), 5);
	}
	else
		m_scr->print(m_date.getH(), 4);
	m_scr->print(":", 6);

	if( m_date.getM() < 10 )
	{
		m_scr->print("0", 7);
		m_scr->print(m_date.getM(), 8);
	}
	else
		m_scr->print(m_date.getM(), 7);
	m_scr->print(":", 9);

	if( m_date.getS() < 10 )
	{
		m_scr->print("0", 10);
		m_scr->print(m_date.getS(), 11);
	}
	else
		m_scr->print(m_date.getS(), 10);
}

