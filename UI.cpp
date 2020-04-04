#include "UI.h"


UI* UI::_instance = 0;



UI::UI() 
{

	topUI_txt.loadFromFile("./images/topUI.jpg");
	topUI_sprite.setTexture(topUI_txt);
	topUI_sprite.setPosition(0, 0);

	hp_text.setPosition(15, 15);
	hp_text.setCharacterSize(16);
	hp_text.setOutlineColor(sf::Color::Black);
	hp_text.setOutlineThickness(2);


	money_text.setPosition(125, 15);
	money_text.setCharacterSize(16);
	money_text.setOutlineColor(sf::Color::Black);
	money_text.setOutlineThickness(2);

	toDraw = true;
	UpdateUI();
}

void UI::Draw(sf::RenderWindow& window) 
{
	if (toDraw) 
	{
		window.draw(topUI_sprite);
		window.draw(hp_text);
		window.draw(money_text);
	}
}

void UI::UpdateUI()
{
	hp_text.setString("Health: " + std::to_string(GManager->getPlayer().getHealth()));
	money_text.setString("Money: " + std::to_string(GManager->getPlayer().getMoney()));
}

bool& UI::isDrawing() { return toDraw; }