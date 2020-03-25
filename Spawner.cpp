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

	// Origin?...

}

void Spawner::Draw(sf::RenderWindow& window) 
{
	if (SpawnRatioClock.getElapsedTime().asSeconds() >= 5) { SpawnEnemy(); SpawnRatioClock.restart(); }
}

void Spawner::SpawnEnemy() 
{	
	ObjectsVector.push_back(new Enemy(sprite.getPosition())); 
}


