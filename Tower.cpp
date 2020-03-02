#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <iostream>
Tower::Tower()
{
	rect.setPosition(pos);
	rect.setSize(sf::Vector2f(50.f, 50.f));
	rect.setFillColor(sf::Color::Red);
}
Tower::Tower(sf::Vector2f pos) 
{
	rect.setPosition(pos);
	rect.setSize(sf::Vector2f(50.f, 50.f));
	rect.setFillColor(sf::Color::Red);
}



sf::RectangleShape Tower::getRect() { return rect; }
void Tower::Shoot()
{
	//...
}
void Tower::MoveTo(sf::Vector2f coords) 
{
	this->pos = sf::Vector2f(coords.x - (rect.getSize().x / 2), coords.y - (rect.getSize().y / 2));
	std::cout << "X: " << pos.x << "  Y: " << pos.y << std::endl;
	rect.setPosition(pos);

}