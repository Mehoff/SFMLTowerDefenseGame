#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Tower.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Close);

	Tower t;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
		{
			t.MoveTo((sf::Vector2f)sf::Mouse::getPosition(window));
		}

		//Closes game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

		

		window.clear();
		window.draw(t.getRect());
		window.display();
	}

	return 0;
}