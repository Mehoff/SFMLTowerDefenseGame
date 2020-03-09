#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpritesMapper.h"


// TRY inherit from sf::Sprite mybe its a lot of fun

class Object abstract
{
protected:
	std::string id = "object";
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	bool toDraw;
public:

	Object();

	Object(sf::Vector2f _position);

	Object(const Object& other);

	~Object() { std::cout << "'Object' destroyed"; }

	sf::Sprite getSprite() const;
	sf::Vector2f getPosition() const;
	sf::Texture getTexture() const;
	std::string getId() const;

	void Draw(sf::RenderWindow& window);
	void UpdateSpritePosition();
	void UpdateSpritePosition(sf::Vector2f _position);
	void RotateTo(sf::Vector2f _position);
};