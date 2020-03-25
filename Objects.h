#pragma once
#include "Object.h"


class Objects 
{

private:
	std::vector<Object*> objects;
	static Objects* _instance;

public:
	Objects() 
	{
		objects.reserve(100);
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
};

#define ObjectsVector Objects::getInstance()->getObjects()


