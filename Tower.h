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
	std::string t_path = "./images/tower.png";
public:
	Tower();
	Tower(sf::Vector2f pos);
	sf::Sprite getSprite();
	void Shoot();
	void MoveTo(sf::Vector2f coords);
	int getId();
};