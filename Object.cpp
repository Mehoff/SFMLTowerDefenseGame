#include "Object.h"

Object::Object() 
{
	toDraw = true;
}

Object::Object(sf::Vector2f _position)
: position(_position)
{
	toDraw = true;
}

Object::Object(const Object& other)
{
	this->texture = other.texture;
	this->sprite.setTexture(this->texture);
	this->position = other.position;
	this->sprite.setPosition(this->position);
}

//Getters
char & Object::getId()   { return id; }
sf::Vector2f  & Object::getPosition()  { return position; }
sf::Sprite & Object::getSprite()   { return sprite; }
sf::Texture & Object::getTexture()  { return texture; }

void Object::Draw(sf::RenderWindow& window) {if(toDraw) window.draw(sprite);}
void Object::UpdateSpritePosition() 
{
	sprite.setPosition(position);
}
void Object::UpdateSpritePosition(sf::Vector2f _position) 
{ 
	this->position = _position;
	UpdateSpritePosition();
}
//void Object::RotateTo(sf::Vector2f _position)
//{
//	const float pi = 3.14159265;
//
//		//set a proper origin for sprite
//
//		//rotate to mouse position
//	
//
//	float dx = this->position.x - _position.x;
//	float dy = this->position.y - _position.y;
//
//	float rotation = (atan2(dy, dx) * 180 / pi);
//
//	this->sprite.setRotation(rotation + 270);
//}