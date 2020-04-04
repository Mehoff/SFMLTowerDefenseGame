#pragma once
#include "Object.h"
#include "Bullet.h"
#include "Enemy.h"

class Tower : public Object
{
private:


	bool chosen;

	Enemy * target;
	sf::CircleShape radius;
	void constructRadiusShape();


	sf::Clock ratioClock;
	float ratio;

	sf::Clock turnClock;
	float turnRatio;

	int damage;
	bool toShoot;
	std::vector<Bullet> bulletVector;

	void Place(sf::Vector2f _position);
	void CheckForEnemy();

	

public:
	static const int Price = 50;
	static const int UpgradePrice = 30;

	
	Tower(sf::Vector2f _position);
	bool drawRadius;

	

	//set to private
	void Shoot();
	void Upgrade();

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
	void Choose() { chosen = true; }

	bool& isChosen() { return chosen; }
	static void RemapTargets();
};

