#pragma once
#include <iostream>
#include "Object.h"
#include "Objects.h"
#include "Chunk.h"

class Enemy : public Object 
{
private:
	int speed;
	int moveDirection; // 1,2,3,4 ?
	int moveRotation;  // 0-360

public:
	Enemy(sf::Vector2f position);

	void CheckDirection(); //Проверяем над каким Чанком мы летим, если его dir_id не равен moveDirection -> Вызываем ChangeDirection(dir_id)
	
	void setDirection(int dir_id); //Меняем направление движения вместе с поворотом (градусы в moveRotation)

	void Draw(sf::RenderWindow& window);

};