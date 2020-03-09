#pragma once
#include "Object.h"

class Tower : public Object 
{
public:
	Tower();
	Tower(sf::Vector2f _position);
	void RotateTo(sf::Vector2f);
};

