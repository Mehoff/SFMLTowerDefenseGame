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
#include "UI.h"
#include "MyText.h"



//		Общий TODO:


//	Нарисовать тайл для замка куда летят враги
//	Класс для игрока (Деньги, здоровье, уровень, номер волны (Время игры)) (почти готов)
//	Визуальные эффекты и тематический тайлсет
//	Подчистить ненужные функции и файлы
//	Звук
//	Меню



//	Больше Уровней
//	Редактор Уровней

class UpgradeButton 
{
private:
	bool isVisible;
	sf::RectangleShape shape;
	MyText text;
public:
	UpgradeButton() 
	{
		isVisible = false;

		shape.setFillColor(sf::Color(255,255,255,120));
		shape.setSize(sf::Vector2f(120, 40));
		shape.setPosition(400, 5);

		text.setFillColor(sf::Color::White);
		text.setOutlineThickness(2);
		text.setOutlineColor(sf::Color::Black);
		text.setCharacterSize(16);
		text.setString("upgrade");
		text.setPosition(415, 15);
	}

	void Disable() { isVisible = false; }
	void Enable() {  isVisible = true; }
	void Draw(sf::RenderWindow& window) 
	{
		if (isVisible) {
			window.draw(shape);
			window.draw(text);
		}
	}
	bool Clicked(sf::Vector2f pos) 
	{
		if (shape.getGlobalBounds().contains(pos)) 
		{
			return true;
		}
		else { return false; }
	}
};

void ResetChosen() 
{
	for(auto & o : ObjectsVector)
	{
		if (dynamic_cast<Tower*>(o)) 
		{
			Tower* t = dynamic_cast<Tower*>(o);
			t->isChosen() = false;
		}
	}
}

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
	if (GManager->getPlayer().getMoney() >= Tower::Price) 
	{
		GManager->getPlayer().getMoney() -= Tower::Price;
		UIManager->UpdateUI();
		ObjectsVector.push_back(new Tower(coords));
	}
}

int main()
{

	UpgradeButton u_button;

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

			//Left Mouse Click
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				u_button.Disable();

				if (isSpaceEmpty((sf::Vector2f)sf::Mouse::getPosition(window)))
				{
					if (sf::Mouse::getPosition(window).y > 50) 
					{ 
						SpawnTower((sf::Vector2f)sf::Mouse::getPosition(window));
						ResetChosen();
						break;
					}
				}
				if (u_button.Clicked((sf::Vector2f)sf::Mouse::getPosition(window))) 
				{
					for (auto& o : ObjectsVector) 
					{
						if (dynamic_cast<Tower*>(o)) 
						{
							Tower* t = dynamic_cast<Tower*>(o);
							if (t->isChosen()) 
							{ 
								t->Upgrade();
								ResetChosen();
								break;
							}
						}
					}
				}
				for (auto& o : ObjectsVector)
				{
					if (dynamic_cast<Tower*>(o))
					{
						if (o->getSprite().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
						{
							Tower* t = dynamic_cast<Tower*>(o);
							ResetChosen();
							t->Choose();
							u_button.Enable();
							break;
						}
					}
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

		UIManager->Draw(window);
		u_button.Draw(window);
		window.display();
	}

	return 0;
}

