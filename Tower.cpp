#include "Tower.h"

Tower::Tower() 
{
    std::cout << "Tower()" << std::endl;

    id = 1;
    if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
    {
	    std::cout << "err" << std::endl;
    }
    sprite.setTexture(texture);
   
}
Tower::Tower(sf::Vector2f _position) 
{
    std::cout << "Tower(Vector2f)" << std::endl;

    id = 1; 
    if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
    {
        std::cout << "err" << std::endl;
    }
    sprite.setTexture(texture);
    position = _position; 
    sprite.setPosition(position);
}