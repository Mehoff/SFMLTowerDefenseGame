#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpritesMapper.h"

class Object abstract
{
protected:
	int id = 0;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
public:

	Object();

	Object(sf::Vector2f _position);

	Object(const Object& other);

	~Object() { std::cout << "'Object' destroyed"; }

	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::Texture getTexture();
	int getId();

	void Draw(sf::RenderWindow& window);
	void UpdateSpritePosition();
	void UpdateSpritePosition(sf::Vector2f _position);
};