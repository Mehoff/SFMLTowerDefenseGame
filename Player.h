#pragma once
#include <SFML/Graphics.hpp>


class Player 
{
private:
	sf::RectangleShape rect;
	sf::Vector2f size;
	float speed;

public:
	Player();
	Player(float w, float h, sf::Color color);
	float getSpeed();
	void Move(sf::Keyboard::Key key);
	sf::RectangleShape getRect();
};