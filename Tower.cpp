#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tower.h"
#include "SpriteRenderer.h"
#include "SpritesMapper.h"


Tower::Tower()
{
	// dont forget about id
	this->id = 1;
	if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
	{
		std::cout << "err" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);

	Renderer::getInstance()->Add(sprite);
}
Tower::Tower(sf::Vector2f pos) 
{
	this->pos = pos;

	if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
	{
		std::cout << "err" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(this->pos);

	Renderer::getInstance()->Add(sprite);

}
Tower::Tower(const Tower& other) 
{
	std::cout << "cpy";

	this->texture = other.texture;
	this->sprite.setTexture(this->texture);
	this->pos = other.pos;
	this->sprite.setPosition(other.pos);
}

sf::Sprite Tower::getSprite() { return sprite; }


void Tower::MoveTo(sf::Vector2f coords) 
{
	this->pos = sf::Vector2f(coords.x - (texture.getSize().x / 2), coords.y - (texture.getSize().y / 2));
	sprite.setPosition(pos);
}

void Tower::MoveRight() 
{
	this->pos = sf::Vector2f(pos.x + 5, pos.y);
}

sf::Vector2f Tower::getPosition() { return pos; }