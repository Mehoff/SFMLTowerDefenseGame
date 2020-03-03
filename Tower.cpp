#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tower.h"
#include "SpriteRenderer.h"


Tower::Tower()
{
	// dont forget about id
	if (!texture.loadFromFile(t_path))
	{
		std::cout << "err" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);

	Renderer::getInstance()->Add(this->getSprite());
}
Tower::Tower(sf::Vector2f pos) 
{
	if (!texture.loadFromFile(t_path))
	{
		std::cout << "err" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);


	Renderer::getInstance()->Add(this->getSprite());

}

sf::Sprite Tower::getSprite() { return sprite; }


void Tower::MoveTo(sf::Vector2f coords) 
{
	this->pos = sf::Vector2f(coords.x - (texture.getSize().x / 2), coords.y - (texture.getSize().y / 2));
	sprite.setPosition(pos);
}