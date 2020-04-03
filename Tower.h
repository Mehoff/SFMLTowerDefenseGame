#pragma once
#include "Object.h"
#include "Bullet.h"
#include "Enemy.h"

class Tower : public Object
{
private:


	Enemy * target;
	sf::CircleShape radius;
	void constructRadiusShape();


	sf::Clock ratioClock;
	int ratio;

	sf::Clock turnClock;
	float turnRatio;

	int damage;
	bool toShoot;
	std::vector<Bullet> bulletVector;

	void Place(sf::Vector2f _position);
	void CheckForEnemy();

public:
	
	Tower();
	Tower(sf::Vector2f _position);
	bool drawRadius;
	
	//set to private
	void Shoot();


//
	// ~ Setters:
//
	void RotateTo(sf::Vector2f);
	void setPosition(sf::Vector2f _position);
	void setRadius(float _radius);
//
	// ~ Getters:
//
	std::vector<Bullet> & getBulletVector();
	sf::CircleShape& getRadius();

	void Draw(sf::RenderWindow& window);
	void DestroyTaggedBullets();



	static void RemapTargets();
};

