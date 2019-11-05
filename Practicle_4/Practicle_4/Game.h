#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "SFML/Graphics.hpp" 
#include "Animation.h"

class Game
{
public:
	Game();
	void run();
	void update();
	void draw();

	Animation fsm;

	sf::RenderWindow window;

};

