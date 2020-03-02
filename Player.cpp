#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player()
{
	this->rect.setSize(sf::Vector2f(100.f,100.f));
	this->rect.setFillColor(sf::Color::Green);

	this->rect.setPosition(0.f, 0.f);
}
Player::Player(float w, float h, sf::Color color) 
{
	this->rect.setSize(sf::Vector2f(w, h));
	this->rect.setFillColor(color);

	this->rect.setPosition(0.f, 0.f);
}
float Player::getSpeed() 
{
	return speed;
}
sf::RectangleShape Player::getRect() 
{
	return rect;
}
void Player::Move(sf::Keyboard::Key key)
{
	std::cout << key;
}

