#include "SpriteRenderer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tower.h"


Renderer* Renderer::_instance = 0;


void Renderer::Draw(sf::RenderWindow& window) {
	for (sf::Sprite& item : toDraw)
	{
		window.draw(item);
	}
}

void Renderer::Add(sf::Sprite & s)
{
	_instance->toDraw.push_back(s);
}



