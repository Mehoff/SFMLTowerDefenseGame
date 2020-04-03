#include "Spawner.h"
#include "Objects.h"
#include "Chunk.h"
#include "Enemy.h"



// ѕодумать над наследоваением от Chunk и кастом в Spawner 


Spawner::Spawner() 
{
	SpawnRatio = 5;
	this->id = 's';
	this->texture = SMapper->getTexture(this->id);
	sprite.setTexture(this->texture);
}

Spawner::Spawner(int _x, int _y, int s_ratio) 
{
	SpawnRatio = s_ratio;
	this->id = 's';
	this->texture = SMapper->getTexture(this->id);
	sprite.setTexture(this->texture);

	position.x = _x;
	position.y = _y;

	sprite.setPosition(position);
}

void Spawner::Draw(sf::RenderWindow& window) 
{
	if (SpawnRatioClock.getElapsedTime().asSeconds() >= SpawnRatio)
	{
		SpawnEnemy(); 
		SpawnRatioClock.restart(); 
	}
	window.draw(this->sprite);
}

void Spawner::SpawnEnemy() 
{	
	sf::Vector2f newPos = sf::Vector2f(sprite.getPosition().x + 25, sprite.getPosition().y + 25);

	ObjectsVector.push_back(new Enemy(newPos)); 


}


