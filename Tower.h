#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tower 
{
private:
	sf::RectangleShape rect;
	sf::Vector2f pos;
public:
	Tower();
	Tower(sf::Vector2f pos);
	sf::RectangleShape getRect();
	void Shoot();
	void MoveTo(sf::Vector2f coords);
};