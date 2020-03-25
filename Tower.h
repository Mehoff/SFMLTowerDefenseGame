#pragma once
#include "Object.h"
#include "Bullet.h"

class Tower : public Object
{
private:
	sf::Clock ratioClock;
	int ratio;
	int damage;
	std::vector<Bullet> bulletVector;


	void Place(sf::Vector2f _position);
public:
	
	Tower();
	Tower(sf::Vector2f _position);
	void RotateTo(sf::Vector2f);
	void Draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f _position);
	std::vector<Bullet> & getBulletVector();
	void Shoot();
};

