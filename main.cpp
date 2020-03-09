#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Tower.h"
#include "SpriteRenderer.h"
#include "SpritesMapper.h"






bool isSpaceEmpty(sf::Vector2f coords, std::vector<Object*> &vec) 
{

	for (auto o : vec) 
	{
		if (o->getSprite().getGlobalBounds().contains(coords)) { return false; }	
	}
	return true;
}

void SpawnTower(std::vector<Object*> &vec, sf::Vector2f coords)
{
	vec.push_back(new Tower(coords));
}


int main()
{
	SMapper->Load();


	std::vector<Object*> objects;
	objects.reserve(50);

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
			if (isSpaceEmpty((sf::Vector2f)sf::Mouse::getPosition(window), objects))
			{
				//Manager::Spawn(...)
				SpawnTower(objects, (sf::Vector2f)sf::Mouse::getPosition(window));
			}
		}

		//Closes game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

		window.clear();
		for (auto a : objects) { a->Draw(window); }
		window.display();
	}

	return 0;
}