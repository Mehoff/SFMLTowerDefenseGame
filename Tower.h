#pragma once
#include "Object.h"
#include "Bullet.h"

class Tower : public Object
{
private:
	float ratio;
	int damage;
	std::vector<Bullet> bulletVector;
public:
	
	Tower();
	Tower(sf::Vector2f _position);
	void RotateTo(sf::Vector2f);
	void Draw(sf::RenderWindow& window);
};

