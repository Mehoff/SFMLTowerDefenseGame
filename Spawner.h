#pragma once
#include "Object.h"

// ��������� �������� ������ ������!

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