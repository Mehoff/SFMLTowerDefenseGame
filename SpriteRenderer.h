#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Renderer 
{
private:
	
	static Renderer* _instance;
	std::vector<sf::Sprite> toDraw;

	Renderer() { }
	Renderer(const Renderer&);

public:

	void Add(sf::Sprite); //change to Sprite
	void Draw(sf::RenderWindow& window);

	static Renderer* getInstance()
	{
		if (!_instance)
		{
			_instance = new Renderer();
			std::cout << "New Renderer" << std::endl;
		}
		return _instance;
	}

	
};