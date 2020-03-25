#pragma once
#include "Object.h"

class Bullet 
{

private:
	// Check
	float xDir;
	float yDir;

	float speed;
	float direction;
	sf::CircleShape shape;

public:
	Bullet();
	Bullet(int _x, int _y, float rotation);
	void Draw(sf::RenderWindow& window);
	void Move();
	sf::CircleShape &getShape();
};

