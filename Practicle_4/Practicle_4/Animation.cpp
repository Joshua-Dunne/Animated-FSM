#include "Animation.h"

Animation::Animation() : m_current{ new Idle() }, m_previous{ new Idle() }
{
	if (!m_playerTex.loadFromFile("animations.png"))
	{
		std::cerr << "error loading animation png" << std::endl;
	}

	initAnimations();

}

/// <summary>
/// Initialize Animation frames
/// </summary>
void Animation::initAnimations()
{
	sf::IntRect m_idleRect{ 0,0,100,200 };
	sf::IntRect m_idleRectTwo{ 0,200,100,200 };

	sf::IntRect m_walkRect{ 100,0,100,200 };
	sf::IntRect m_walkRectTwo{ 100,200,100,200 };

	sf::IntRect m_jumpRect{ 200,0,100,200 };
	sf::IntRect m_jumpRectTwo{ 200,200,100,200 };

	sf::IntRect m_fallRect{ 300,0,100,200 };
	sf::IntRect m_fallRectTwo{ 300,200,100,200 };

	sf::IntRect m_landRect{ 400,0,100,200 };
	sf::IntRect m_landRectTwo{ 400,200,100,200 };

	sf::IntRect m_climbRect{ 500,0,100,200 };
	sf::IntRect m_climbRectTwo{ 500,200,100,200 };


	m_idleAnim.setTexture(m_playerTex);
	m_idleAnim.addFrame(m_idleRect);
	m_idleAnim.addFrame(m_idleRectTwo);

	m_walkAnim.setTexture(m_playerTex);
	m_walkAnim.addFrame(m_walkRect);
	m_walkAnim.addFrame(m_walkRectTwo);

	m_jumpAnim.setTexture(m_playerTex);
	m_jumpAnim.addFrame(m_jumpRect);
	m_jumpAnim.addFrame(m_jumpRectTwo);

	m_fallAnim.setTexture(m_playerTex);
	m_fallAnim.addFrame(m_fallRect);
	m_fallAnim.addFrame(m_fallRectTwo);

	m_landAnim.setTexture(m_playerTex);
	m_landAnim.addFrame(m_landRect);
	m_landAnim.addFrame(m_landRectTwo);

	m_climbAnim.setTexture(m_playerTex);
	
	m_climbAnim.addFrame(m_climbRect);
	m_climbAnim.addFrame(m_climbRectTwo);

	m_currentAnim = &m_idleAnim;
}

/// <summary>
/// Move to Idle state
/// </summary>
void Animation::idle()
{
	if (!startedJump) // as long as a jump hasn't started, we can go to idle
	{
		m_current->idle(this);
		m_currentAnim = &m_idleAnim;
	}
	
}

/// <summary>
/// Move to jumping state
/// </summary>
void Animation::jumping()
{
	if (!startedJump) // as long as a jump hasn't already started, we can jump
	{
		m_previous = m_current;
		m_current->jumping(this);
		fallingTimer = STARTING_TIME;
		startedJump = true;
		m_currentAnim = &m_jumpAnim;
	}
}

/// <summary>
/// Move to climbing state
/// </summary>
void Animation::climbing()
{
	m_current->climbing(this);
	m_currentAnim = &m_climbAnim;
}

/// <summary>
/// Move to falling state
/// </summary>
void Animation::falling()
{
	m_current->falling(this);
	m_currentAnim = &m_fallAnim;
}

/// <summary>
/// Move to walking state
/// </summary>
void Animation::walking()
{
	m_current->walking(this);
	m_currentAnim = &m_walkAnim;
}

/// <summary>
/// Move to landing state
/// </summary>
void Animation::landing()
{
	m_current->landing(this);
	m_currentAnim = &m_landAnim;
}

/// <summary>
/// Control timers for falling, landing and waiting to go to idle
/// </summary>
void Animation::update()
{
	if (fallingTimer > 0)
	{
		fallingTimer--; // decrease falling timer
	}

	if (landingTimer > 0)
	{
		landingTimer--; // decrease landing timer
	}

	if (idleTimer > 0)
	{
		idleTimer--; // decrease idle timer
	}

	if (fallingTimer == 0) // go to falling when finished jumping
	{
		falling();
		fallingTimer = -1;
		landingTimer = STARTING_TIME;
	}

	if (landingTimer == 0) // go to landing when finished falling
	{
		landing();
		landingTimer = -1;
		idleTimer = STARTING_TIME;
		startedJump = false;
	}

	if (idleTimer == 0) // go back to idle whe finished landing
	{
		idleTimer = -1;
		idle();
	}

	m_currentAnim->update(); // update frames
}

/// <summary>
/// Draws the animation
/// </summary>
/// <param name="t_window">Window to draw</param>
void Animation::drawAnim(sf::RenderWindow& t_window)
{
	t_window.draw(*m_currentAnim);
}
