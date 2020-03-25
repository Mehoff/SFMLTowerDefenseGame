#include "Tower.h"

Tower::Tower() 
{
    id = 't';
	toDraw = true;
	ratio = 5;
	damage = 10;
}
Tower::Tower(sf::Vector2f _position) 
{
	ratio = 1;
	damage = 10;
	toDraw = true;

    id = 't'; 
	texture = SMapper->getTexture(id);
	sprite.setTexture(texture);

	Place(_position);

	sf::Vector2f newOrigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
	sprite.setOrigin(newOrigin);

}

void Tower::Place(sf::Vector2f _position)
{
	_position.x = (int)(_position.x / 50) * 50;
	_position.y = (int)(_position.y / 50) * 50;


	//Костыль, из-за отличия в origin Chank`a и Tower`а

	_position.x += 25;
	_position.y += 25;

	position = _position;
	sprite.setPosition(position);

}

void Tower::setPosition(sf::Vector2f _position)
{
	position = _position;
	this->sprite.setPosition(position);
}

// IMPLEMENT 

 void Tower::Draw(sf::RenderWindow& window) 
 {
	 //Draw Self
	 window.draw(sprite);



	 //Draw and Move Self Bullets
	 
	 for (int i = 0; i < bulletVector.size(); i++) 
	 {
		 bulletVector[i].Move();
		 bulletVector[i].Draw(window);

	 }
	

	 //for (Bullet b : bulletVector) 
	 //{
		//b.Move();
		//b.Draw(window);
	 //}

	 if (ratioClock.getElapsedTime().asSeconds() >= ratio) 
	 {
		 this->Shoot();
	 }
 }

 void Tower::Shoot() 
 {
	 ratioClock.restart();			
	 bulletVector.push_back(Bullet(this->position.x,this->position.y, sprite.getRotation()));
 }


 void Tower::RotateTo(sf::Vector2f _position)
 {
	const float pi = 3.14159265;

		//set a proper origin for sprite

		//rotate to mouse position
	float dx = this->position.x - _position.x;
	float dy = this->position.y - _position.y;

	float rotation = (atan2(dy, dx) * 180 / pi);

	this->sprite.setRotation(rotation + 270);
}


 std::vector<Bullet>& Tower::getBulletVector() { return bulletVector; }