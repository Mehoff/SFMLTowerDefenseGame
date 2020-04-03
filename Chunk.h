#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

class Chunk : public Object
{
private:
	sf::RectangleShape collisionRect;
	int turnDirection;  // 1 - UP , 2 - DOWN, 3 - LEFT, 4 - RIGHT
	void Place(sf::Vector2f mousePosition);
public:
	Chunk();
	Chunk(sf::Vector2f mousePosition);
	Chunk(int x, int y, char c, int d);
	void Draw(sf::RenderWindow& window);
	sf::Sprite & getSprite();
	sf::RectangleShape& getCollisionRect();
	int getTurnDirection();

};