#pragma once
#include <SFML/Graphics.hpp>


class Player 
{
private:
	sf::Texture t;
	sf::Sprite s;

public:
	Player();
	Player(float w, float h, sf::Color color);
};