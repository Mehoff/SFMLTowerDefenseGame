#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpritesMapper.h"


// TRY inherit from sf::Sprite mybe its a lot of fun

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

	sf::Sprite getSprite() const;
	sf::Vector2f getPosition() const;
	sf::Texture getTexture() const;
	int getId() const;

	void Draw(sf::RenderWindow& window);
	void UpdateSpritePosition();
	void UpdateSpritePosition(sf::Vector2f _position);
};