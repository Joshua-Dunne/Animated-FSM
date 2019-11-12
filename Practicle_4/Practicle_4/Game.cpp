/// <summary>
/// Joshua Dunne
/// C00241588
/// Date(s): 04/11/19, 05/11/19, 10/11/19, 12/11/19
/// Time Taken: ~7 hours
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
			if (event.key.code == sf::Keyboard::X)
			{
				fsm.jumping(); // jump if X is pressed
			}
			
			if (event.key.code == sf::Keyboard::Right
				|| event.key.code == sf::Keyboard::Left)
			{
				fsm.walking(); // walk if Left or Right is pressed
			}

			if (event.key.code == sf::Keyboard::Up)
			{
				fsm.climbing(); // climb if Up is pressed
			}
			break;
		default:
			fsm.idle(); // if nothing else is currently happening, idle
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
