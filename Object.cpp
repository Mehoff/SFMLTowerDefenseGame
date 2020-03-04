#include "Object.h"

Object::Object() 
{
	std::cout << "Object()" << std::endl;
}

Object::Object(sf::Vector2f _position)
: position(_position)
{
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
int Object::getId() { return id; }
sf::Vector2f Object::getPosition() { return position; }
sf::Sprite Object::getSprite() { return sprite; }
sf::Texture Object::getTexture() { return texture; }

void Object::Draw(sf::RenderWindow& window) { window.draw(sprite); }
void Object::UpdateSpritePosition() { sprite.setPosition(position); }
void Object::UpdateSpritePosition(sf::Vector2f _position) 
{ 
	this->position = _position;
	UpdateSpritePosition();
}
