#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <typeinfo>

#include "Objects.h"
#include "Chunk.h"
#include "LevelLoader.h"
#include "Player.h"
#include "Tower.h"
#include "SpriteRenderer.h"
#include "SpritesMapper.h"



//		Общий TODO:

//	Механика "Присасывания" пули к врагу
//	Механика поиска противника башней по радиусу
//	Коллизия пуль с врагами
//	Враги (Дописать)
//	Спавнер (Дописать)
//	Механика поворота врагов при встрече тайла с поворотом
//	Подчистить ненужные функции и файлы
//	Звук
//	Класс для игрока (Деньги, выбранная вышка)
//	Шрифты
//	Меню
//	Визуальные эффекты и тематический тайлсет
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

	//std::vector<Object*> objects; // Move to Singleton class, and reference to it using define

	//objects.reserve(50);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tower Defence", sf::Style::Close);

	window.setFramerateLimit(60);

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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
			for (auto a : ObjectsVector)
			{
				if (dynamic_cast<Tower*>(a)) {
					auto t = dynamic_cast<Tower*>(a);
					t->RotateTo((sf::Vector2f)sf::Mouse::getPosition(window));
				}
			}
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { 

			bool flag = false;

			for (auto c : ObjectsVector)
			{
				if (c->getSprite().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))) 
				{
					flag = true;
					break;
				}
			}
			if (!flag) 
			{

				ObjectsVector.push_back(new Chunk((sf::Vector2f)sf::Mouse::getPosition(window)));
			}
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

		window.clear();

		 //Move to Objects and sort to be at start
		
		for (auto a : ObjectsVector) 
		{
			if (dynamic_cast<Tower*>(a)) 
			{
				a->Draw(window);
			}
			if (dynamic_cast<Chunk*>(a))
			{
				a->Draw(window);
			}
		}
		window.display();
	}

	return 0;
}