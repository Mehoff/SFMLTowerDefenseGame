#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "MyText.h"

class UI
{
private:

	sf::Texture topUI_txt;
	sf::Sprite topUI_sprite;

	static UI* _instance;
	MyText hp_text;
	MyText money_text;
	bool toDraw;
	
public:

	UI();

	static UI* getInstance()
	{
		if (!_instance)
		{
			_instance = new UI();
		}
		return _instance;
	}

	bool& isDrawing();
	void UpdateUI();
	void Draw(sf::RenderWindow& window);

};


#define UIManager UI::getInstance()