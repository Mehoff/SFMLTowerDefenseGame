#pragma once
#include "Object.h"
#include "Enemy.h"

class Bullet 
{

private:


	Enemy * target;
	int damage;
	float speed;
	int lifeTime;

	bool toDieFlag;
	float direction;
	sf::CircleShape shape;
	sf::Clock lifeTimeClock;

public:

	Bullet();
	Bullet(int _x, int _y, float rotation);
	Bullet(int _x, int _y, Enemy * target);



	void Draw(sf::RenderWindow& window);
	void Move();
	void MoveTo(sf::Vector2f& position);
	bool hasTarget();
	void CheckEnemyCollision();

	//
		// ~ Setters:
	//

	void setTarget(Enemy * _target);

	//
		// ~ Getters:
	//

	sf::Clock & getClock();
	sf::Vector2f & getTargetPosition();
	sf::CircleShape & getShape();
	bool& isDying();
	int & getLifeTime();
};

