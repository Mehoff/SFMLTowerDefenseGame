#include "Object.h"

Object::Object() 
{
	std::cout << "Object()" << std::endl;
	if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
	{
		std::cout << "err" << std::endl;
	}
	sprite.setTexture(texture);
}

Object::Object(sf::Vector2f _position)
: position(_position)
{
	if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
	{
		std::cout << "err" << std::endl;
	}
	sprite.setTexture(texture);
	std::cout << "Object(Vector2f)" << std::endl;
}

Object::Object(const Object& other)
{

	std::cout << "Object(const Object&)" << std::endl;

	this->texture = other.texture;
	this->sprite.setTexture(this->texture);
	this->position = other.position;
	this->sprite.setPosition(this->position);
}

//Getters
int Object::getId() const  { return id; }
sf::Vector2f Object::getPosition() const { return position; }
sf::Sprite Object::getSprite()  const { return sprite; }
sf::Texture Object::getTexture() const { return texture; }

void Object::Draw(sf::RenderWindow& window) { window.draw(sprite); }
void Object::UpdateSpritePosition() { sprite.setPosition(position); }
void Object::UpdateSpritePosition(sf::Vector2f _position) 
{ 
	this->position = _position;
	UpdateSpritePosition();
}
