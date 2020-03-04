#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tower 
{
private:
	int id = 1;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f pos;
public:
	Tower();
	Tower(sf::Vector2f pos);
	Tower(const Tower& other);
	Tower& operator=(const Tower& other);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void MoveRight();
	void Shoot();
	void MoveTo(sf::Vector2f coords);
	int getId();
};