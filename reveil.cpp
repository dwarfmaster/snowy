
#include "reveil.hpp"

volatile Reveil* instance;

Reveil::Reveil(Screen* scr, Sound* snd)
	: m_scr(scr), m_snd(snd), m_used(&m_date), m_edit(false), m_beep(false)
{
	attachInterupt(0, upButtonClic, RISING);
	attachInterupt(1, downButtonClic, RISING);
}

Reveil::~Reveil()
{}

void Reveil::update()
{
}

void upButtonClic()
{
	if( instance->m_edit )
		instance->m_used->addM();
}

void downButtonClic()
{
	if( instance->m_edit )
		instance->m_used->subM();
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

