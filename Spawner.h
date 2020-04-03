#pragma once
#include "Object.h"
#include <iostream>

// Начальное движение только вправо!

class Spawner : public Object 
{
private:
	int SpawnRatio;
	sf::Clock SpawnRatioClock;
public:
	Spawner();
	Spawner(int _x, int _y, int s_ratio);
	void Draw(sf::RenderWindow& window);
	void SpawnEnemy();
};