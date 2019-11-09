#include "Animation.h"

Animation::Animation() : m_current{ new Idle() }, m_previous{ new Idle() }
{
	if (!m_playerTex.loadFromFile("animations.png"))
	{
		std::cerr << "error loading animation png" << std::endl;
	}

	m_playerSprite.setTexture(m_playerTex);
	m_playerSprite.setPosition(400.0f, 300.0f);
	m_playerSprite.setTextureRect(m_idleRect);
}

void Animation::idle()
{
	if (!startedJump)
	{
		m_current->idle(this);
		m_playerSprite.setTextureRect(m_idleRect);
	}
	
}

void Animation::jumping()
{
	if (!startedJump)
	{
		m_previous = m_current;
		m_current->jumping(this);
		fallingTimer = STARTING_TIME;
		startedJump = true;
		m_playerSprite.setTextureRect(m_jumpRect);
	}
}

void Animation::climbing()
{
	m_current->climbing(this);
	m_playerSprite.setTextureRect(m_climbRect);
}

void Animation::falling()
{
	m_current->falling(this);
	m_playerSprite.setTextureRect(m_fallRect);
}

void Animation::walking()
{
	m_current->walking(this);
	m_playerSprite.setTextureRect(m_walkRect);
}

void Animation::landing()
{
	m_current->landing(this);
	m_playerSprite.setTextureRect(m_landRect);
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
		falling();
		fallingTimer = 0;
		landingTimer = STARTING_TIME;
	}

	if (landingTimer == 1)
	{
		landing();
		//m_current = m_previous;
		landingTimer = 0;
		idleTimer = STARTING_TIME;
		startedJump = false;
	}

	if (idleTimer == 1)
	{
		idle();
		idleTimer = 0;
	}
}

void Animation::drawAnim(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}
