#include "Bullet.h"


Bullet::Bullet() 
{
	direction = 0;
	this->speed = 5;
	shape.setFillColor(sf::Color::Green);
	shape.setRadius(5.f);

}
Bullet::Bullet(int _x, int _y, float rotation)
{
	toDieFlag = false;
	this->speed = 5;
	shape.setPosition(_x, _y);

	shape.setFillColor(sf::Color::Green);
	shape.setRadius(5.f);

	direction = rotation;

	// Setting Origin;

	sf::Vector2f newOrigin((shape.getGlobalBounds().width / 2), (shape.getGlobalBounds().height / 2));
	shape.setOrigin(newOrigin);
}
Bullet::Bullet(int _x, int _y, Enemy* target) 
{
	lifeTime = 5;
	toDieFlag = false;
	damage = 10;
	speed = 5;

	shape.setPosition(_x, _y);
	shape.setFillColor(sf::Color::Green);
	shape.setRadius(5.f);

	setTarget(target);

	sf::Vector2f newOrigin((shape.getGlobalBounds().width / 2), (shape.getGlobalBounds().height / 2));
	shape.setOrigin(newOrigin);
}


void Bullet::Draw(sf::RenderWindow& window) 
{
	CheckEnemyCollision();
	window.draw(shape);
}
void Bullet::Move() 
{
	const float pi = 3.1415926536;
	auto radians = ((2 * pi / 360) * ((direction - 90) * -1)); //or ((pi / 180) * direction);

	float x = 0.5f * cos(radians);
	float y = 0.5f * -sin(radians);
	shape.move(x, y);

}
void Bullet::MoveTo(sf::Vector2f& position)
{
	if (target != nullptr) {
		const float pi = 3.14159265;

		float dx = this->shape.getPosition().x - position.x;
		float dy = this->shape.getPosition().y - position.y;

		float rotation = (atan2(dy, dx) * 180 / pi);

		this->shape.setRotation(rotation);

		auto radians = ((2 * pi / 360) * ((rotation - 180) * -1));

		float x = 0.5f * cos(radians);
		float y = 0.5f * -sin(radians);
		shape.move(x, y);
	}

	else
	{
		Move();
	}

	//shape.move(x, y)
}
void Bullet::CheckEnemyCollision() 
{
	if (hasTarget()) 
	{
		if (this->shape.getGlobalBounds().intersects(target->getSprite().getGlobalBounds()))
		{
			//If Collide...
			toDieFlag = true;
			target->getDamage(this->damage);
		}
	}
}


//
	// ~ Setters:
//

void Bullet::setTarget(Enemy* _target)
{
	if (_target != nullptr) {
		this->target = _target;
	}
}

//
	// ~ Getters:
//

sf::Clock& Bullet::getClock() { return lifeTimeClock; }
sf::CircleShape& Bullet::getShape() { return shape; }
sf::Vector2f& Bullet::getTargetPosition()
{
	if (target != nullptr) { return target->getPosition(); }
	else { Move(); }
}
bool& Bullet::isDying() { return toDieFlag; }
bool Bullet::hasTarget() { if (target == nullptr) { return false; } else { return true; } }
int & Bullet::getLifeTime()  { return lifeTime; }

