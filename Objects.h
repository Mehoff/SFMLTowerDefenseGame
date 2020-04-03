#pragma once
#include "Enemy.h"
#include "Object.h"


class Objects 
{

private:
	std::vector<Object*> objects;
	//std::vector<Enemy*> enemies;
	
	static Objects* _instance;

public:
	Objects() 
	{
	
		objects.reserve(100);
		//enemies.reserve(30);
		
	}

	static Objects* getInstance()
	{
		if (!_instance)
		{
			_instance = new Objects();
		}
		return _instance;
	}

	std::vector<Object*> & getObjects();
	//std::vector<Enemy*>  & getEnemies();
};

#define ObjectsVector Objects::getInstance()->getObjects()



//#define EnemiesVector Objects::getInstance()->getEnemies()

