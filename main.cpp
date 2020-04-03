#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <typeinfo>

#include "Enemy.h"
#include "Objects.h"
#include "Chunk.h"
#include "LevelLoader.h"
#include "Player.h"
#include "Tower.h"
#include "SpriteRenderer.h"
#include "SpritesMapper.h"



//		Общий TODO:


//	Нарисовать тайл для замка куда летят враги
//	Класс для игрока (Деньги, выбранная вышка, здоровье)
//	Визуальные эффекты и тематический тайлсет
//	Подчистить ненужные функции и файлы
//	Звук
//	Шрифты
//	Меню



//	Больше Уровней
//	Редактор Уровней


bool isSpaceEmpty(sf::Vector2f coords) // Rework to check 'Object' objects
{
	for (auto o : ObjectsVector)
	{
		if (dynamic_cast<Tower*>(o)) 
		{
			if (o->getSprite().getGlobalBounds().contains(coords)) { return false; }
		}
	}
	return true;
}

void SpawnTower(sf::Vector2f coords) // Rework to check 'Object' objects
{
	ObjectsVector.push_back(new Tower(coords));
}

int main()
{

	SMapper->Load();
	LevelManager->LoadLevel(1);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tower Defence", sf::Style::Close);

	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (isSpaceEmpty((sf::Vector2f)sf::Mouse::getPosition(window)))
			{
				SpawnTower((sf::Vector2f)sf::Mouse::getPosition(window));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			for (auto a : ObjectsVector)
			{
				if (dynamic_cast<Tower*>(a)) {
					auto t = dynamic_cast<Tower*>(a);
					t->setRadius(t->getRadius().getRadius() + 1);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			for (auto a : ObjectsVector)
			{
				if (dynamic_cast<Tower*>(a)) {
					auto t = dynamic_cast<Tower*>(a);
					t->setRadius(t->getRadius().getRadius() - 1);
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

		window.clear();

		
		for (auto & a : ObjectsVector) 
		{
			if (dynamic_cast<Tower*>(a)) 
			{
				a->Draw(window);
			}
			if (dynamic_cast<Chunk*>(a))
			{
				a->Draw(window);
			}
			if(dynamic_cast<Enemy*>(a))
			{
				a->Draw(window);
			}
			else { a->Draw(window); }
			
		}
		window.display();
	}

	return 0;
}

