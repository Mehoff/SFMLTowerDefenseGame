#pragma once
#include <iostream>
#include "Object.h"
#include "Objects.h"
#include "Chunk.h"

class Enemy : public Object 
{
private:
	sf::RectangleShape collisionRect;
	float speed;
	int health;
	int moveDirection; // 1,2,3,4 ?
	int moveRotation;  // 0-360
	bool toDie;

public:

	Enemy(sf::Vector2f position);
	~Enemy() {}

	void CheckDirection(); //��������� ��� ����� ������ �� �����, ���� ��� dir_id �� ����� moveDirection -> �������� ChangeDirection(dir_id)
	
	void setDirection(int dir_id); //������ ����������� �������� ������ � ��������� (������� � moveRotation)

	void getDamage(int _damage);

	void updateRotation();

	void updateMoveDirection();

	void Draw(sf::RenderWindow& window);

	void Die();

	void DeleteTagged();

};