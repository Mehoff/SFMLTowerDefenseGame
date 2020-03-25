#include <SFML/Graphics.hpp>
#include <iostream>
#include "Chunk.h"
#include "SpritesMapper.h"

//Переделать ID с string на Char, для универсальности архитектуры

Chunk::Chunk(sf::Vector2f mousePosition)
{
	id = 'a';

	texture = SMapper->getTexture(id);
	sprite.setTexture(texture);

	Place(mousePosition);
}

Chunk::Chunk(int x, int y, char c) //Этот конструктор нам больше не понадобится, потом удалить
{
	texture = SMapper->getTexture(c); 
	sprite.setTexture(texture);
	Place(sf::Vector2f(x, y));
}

Chunk::Chunk(int x, int y, char c, int d)
{
	texture = SMapper->getTexture(c);
	sprite.setTexture(texture);
	Place(sf::Vector2f(x, y));

	turnDirection = d;
}



void Chunk::Place(sf::Vector2f mousePosition) 
{
	sf::Vector2f newPosition;
	mousePosition.x = (int)(mousePosition.x / 50) * 50;
	mousePosition.y = (int)(mousePosition.y / 50) * 50;

	newPosition = mousePosition;

	this->sprite.setPosition(newPosition);
}

void Chunk::Draw(sf::RenderWindow& window) 
{
	window.draw(sprite);
}

sf::Sprite & Chunk::getSprite()
{
	return sprite;
}

int Chunk::getTurnDirection() { return turnDirection; }