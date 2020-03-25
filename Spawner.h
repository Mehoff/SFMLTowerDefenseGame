#pragma once
#include "Object.h"

// Начальное движение только вправо!

class Spawner : public Object 
{
private:
	int SpawnRatio;
	sf::Clock SpawnRatioClock;
public:
	Spawner();
	void Draw(sf::RenderWindow& window);
	void SpawnEnemy();
};