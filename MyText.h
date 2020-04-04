#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum MyFonts {JediFont};


//TODO: move realizations to MyText.cpp

class MyText : public sf::Text 
{
public:

	MyText() 
	{
		this->setPosition(0, 0);
		SetFont(JediFont);
		this->setFillColor(sf::Color::White);
		this->setCharacterSize(12);
		this->setString("undefined");
	}

	MyText(std::string str, sf::Color c_color, sf::Color o_color, int x, int y, int font_size, int thickness, MyFonts _font)
	{
		SetValues(str, c_color, o_color, x, y, font_size, thickness, _font);
	}



	void SetValues(std::string& str, sf::Color& c_color, sf::Color& o_color, int x, int y, int font_size, int thickness, MyFonts _font) 
	{
		this->setPosition(x, y);
		this->setString(str);
		this->setOutlineThickness(thickness);
		this->setFillColor(c_color);
		this->setOutlineColor(o_color);
		this->setCharacterSize(font_size);
		SetFont(_font);
	}


private:
	sf::Font font;

	void SetFont(MyFonts f)
	{
		switch (f)
		{
		case JediFont: font.loadFromFile("./fonts/StarJedi.ttf"); 
			break;
		default:
			break;
		}

		this->setFont(font);
	}
};