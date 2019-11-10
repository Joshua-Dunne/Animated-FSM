/// <summary>
/// Joshua Dunne
/// C00241588
/// Date(s): 04/11/19, 05/11/19
/// Time Taken: ~2 hours
/// Estimated time: 6 hours
/// </summary>

#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Practicle 4")
{
	window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	while (window.isOpen())
	{
		update();
		draw();
	}
}

void Game::update()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			// Close window : exit
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Left)
			{
				fsm.jumping();
			}
			
			if (event.key.code == sf::Keyboard::Right)
			{
				fsm.walking();
			}

			if (event.key.code == sf::Keyboard::Up)
			{
				fsm.climbing();
			}
			break;
		default:
			fsm.idle();
			break;
		}

	}

	if (m_clock.getElapsedTime() > seconds(0.5f))
	{
		fsm.update();
		m_clock.restart();
	}
	
}

void Game::draw()
{
	window.clear(sf::Color::White);
	fsm.drawAnim(window);
	window.display();
}
