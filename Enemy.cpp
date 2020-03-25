#include "Enemy.h"


Enemy::Enemy(sf::Vector2f position) 
{
	toDraw = true;
	id = 'x';
	texture = SMapper->getTexture(id);
	

	sprite.setTexture(texture);

	this->position = position;
	sprite.setPosition(this->position);

	// ??
	sf::Vector2f newOrigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
	sprite.setOrigin(newOrigin);
}


// NOT TESTED :

void Enemy::CheckDirection()
{
	for(int i = 0; i < ObjectsVector.size() - 1; i++)
	{
		if (dynamic_cast<Chunk*>(ObjectsVector[i]))
		{
			auto chunk = dynamic_cast<Chunk*>(ObjectsVector[i]);
			this->setDirection(chunk->getTurnDirection());

			delete chunk;
		}
	}
}

void Enemy::setDirection(int _dir_id) 
{
	this->moveDirection = _dir_id;

	// Простенькая логика поворота на 360* в зависимости от dir_id
}

// 1 - UP , 2 - DOWN, 3 - LEFT, 4 - RIGHT   0 - default

void Enemy::Draw(sf::RenderWindow& window) 
{

	//Хочу вынести логику перемещения в отдельную функцию, чтобы делать проверку только когда позиция (pos % 25 == true)

	int toX = 0;
	int toY = 0;

	switch (this->moveDirection)
	{
	case 1: {toX = 0; toY = speed * -1; }
		  break;
	case 2: {toX = 0; toY = speed; }
		  break;
	case 3: {toX = speed*-1; toY = 0; }
		  break;
	case 4: {toX = speed; toY = 0; }
		  break;
	default: 
		toX = speed;
		toY = 0;
		break;
	}

	this->sprite.move(toX, toY);
	window.draw(this->sprite);
}