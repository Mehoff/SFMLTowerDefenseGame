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

	void CheckDirection(); //��������� ��� ����� ������ �� �����, ���� ��� dir_id �� ����� moveDirection -> �������� ChangeDirection(dir_id)
	
	void setDirection(int dir_id); //������ ����������� �������� ������ � ��������� (������� � moveRotation)

	void Draw(sf::RenderWindow& window);

};