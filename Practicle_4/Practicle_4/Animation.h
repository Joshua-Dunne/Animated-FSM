#pragma once

#include "State.h"
#include "Idle.h"
#include "Climbing.h"
#include "Jumping.h"
#include "Falling.h"
#include "Walking.h"
#include "Landing.h"
#include <SFML/Graphics.hpp>


class Animation
{
	class State* m_current;
	class State* m_previous;
public:
	Animation();
	void setCurrent(State* s) { m_current = s; };
	void setPrevious(State* s) { m_previous = s; };
	State* getCurrent(){ return m_current; };
	State* getPrevious() { return m_previous; };
	void idle();
	void jumping();
	void climbing();
	void falling();
	void walking();
	void landing();

	void update();
	void drawAnim(sf::RenderWindow & t_window);

	const int STARTING_TIME = 60;

	int fallingTimer{ 0 };
	int landingTimer{ 0 };
	int idleTimer{ 0 };
	bool startedJump{ false };

	sf::Sprite m_playerSprite;
	sf::Texture m_playerTex;

	sf::IntRect m_idleRect{ 0,0,100,200 };
	sf::IntRect m_walkRect{ 100,0,100,200 };
	sf::IntRect m_jumpRect{ 200,0,100,200 };
	sf::IntRect m_fallRect{ 300,0,100,200 };
	sf::IntRect m_landRect{ 400,0,100,200 };
	sf::IntRect m_climbRect{ 500,0,100,200 };
};

