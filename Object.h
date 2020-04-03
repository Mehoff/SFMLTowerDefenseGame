#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpritesMapper.h"

class Object abstract
{
protected:
	char id = 'o';
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	bool toDraw;
public:

	Object();

	Object(sf::Vector2f _position);

	Object(const Object& other);

	~Object() { std::cout << "'Object' destroyed"; }

	virtual sf::Sprite & getSprite() ;
	virtual sf::Vector2f &  getPosition() ;
	virtual sf::Texture & getTexture() ;
	virtual char & getId() ;

	virtual void Draw(sf::RenderWindow& window);
	virtual void UpdateSpritePosition();
	virtual void UpdateSpritePosition(sf::Vector2f _position);
	//virtual void RotateTo(sf::Vector2f _position);
};