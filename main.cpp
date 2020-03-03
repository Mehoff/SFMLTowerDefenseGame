#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Tower.h"
#include "SpriteRenderer.h"
#include "SpritesMapper.h"

bool isSpaceEmpty(sf::Vector2f coords, std::vector<Tower> &vec) 
{
	for (Tower t : vec) 
	{
		if (t.getSprite().getGlobalBounds().contains(coords))
			return false;
	}
	return true;
}

void SpawnTower(std::vector<Tower> &t, sf::Vector2f coords) 
{
	t.push_back(Tower(coords));
}


int main()
{

	std::vector<Tower> towers;
	towers.reserve(50);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tower Defence", sf::Style::Close);

	window.setFramerateLimit(60);

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
			if (isSpaceEmpty((sf::Vector2f)sf::Mouse::getPosition(window), towers))
			{
				SpawnTower(towers, (sf::Vector2f)sf::Mouse::getPosition(window));
			}

			//t.MoveTo((sf::Vector2f)sf::Mouse::getPosition(window));
		}

		//Closes game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

		

		window.clear();
		//My class to handle all drawable objects
		Renderer::getInstance()->Draw(window);
		
		window.display();
	}

	return 0;
}