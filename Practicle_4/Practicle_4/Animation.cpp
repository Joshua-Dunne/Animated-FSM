#include "Animation.h"

Animation::Animation() : m_current{ new Idle() }, m_previous{ new Idle() }
{
}

void Animation::idle()
{
	if(!startedJump)
	m_current->idle(this);
}

void Animation::jumping()
{
	if (!startedJump)
	{
		m_previous = m_current;
		m_current->jumping(this);
		fallingTimer = 180;
		startedJump = true;
	}
}

void Animation::climbing()
{
	m_current->climbing(this);
}

void Animation::falling()
{
	m_current->falling(this);
}

void Animation::walking()
{
	m_current->walking(this);
}

void Animation::landing()
{
	m_current->landing(this);
}

void Animation::update()
{
	if (fallingTimer > 0)
	{
		fallingTimer--;
	}

	if (landingTimer > 0)
	{
		landingTimer--;
	}

	if (idleTimer > 0)
	{
		idleTimer--;
	}

	if (fallingTimer == 1)
	{
		m_current->falling(this);
		fallingTimer = 0;
		landingTimer = 180;
	}

	if (landingTimer == 1)
	{
		m_current->landing(this);
		//m_current = m_previous;
		landingTimer = 0;
		idleTimer = 90;
		startedJump = false;
	}

	if (idleTimer == 1)
	{
		m_current->idle(this);
		idleTimer = 0;
	}
}
