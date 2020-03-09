#include "Tower.h"

Tower::Tower() 
{
	std::cout << "Tower()";
    id = "tower";
}
Tower::Tower(sf::Vector2f _position) 
{

	std::cout << "Tower(position)";

    id = "tower"; 

	texture = SMapper->getTexture(id);
	
	//if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
    //{
    //    std::cout << "err" << std::endl;
    //}
    
	sprite.setTexture(texture);
    position = _position; 
    sprite.setPosition(position);
}