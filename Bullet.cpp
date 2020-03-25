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

	this->speed = 5;
	shape.setPosition(_x, _y);

	shape.setFillColor(sf::Color::Green);
	shape.setRadius(5.f);

	direction = rotation;

	// Setting Origin;

	sf::Vector2f newOrigin((shape.getGlobalBounds().width / 2), (shape.getGlobalBounds().height / 2));
	shape.setOrigin(newOrigin);
}

sf::CircleShape & Bullet::getShape() { return shape; }

void Bullet::Draw(sf::RenderWindow& window) 
{
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


