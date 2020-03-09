#include "Tower.h"

Tower::Tower() 
{
	std::cout << "Tower()";
    id = "tower";
	toDraw = true;
	ratio = 1.f;
	damage = 10;
}
Tower::Tower(sf::Vector2f _position) 
{
	ratio = 1.f;
	damage = 10;

	std::cout << "Tower(position)";

	toDraw = true;
    id = "tower"; 

	texture = SMapper->getTexture(id);
	
	//if (!texture.loadFromFile(SpritesMapper::getInstance()->getPathById(id)))
    //{
    //    std::cout << "err" << std::endl;
    //}
    
	sprite.setTexture(texture);
    position = _position; 
    sprite.setPosition(position);


	sf::Vector2f newOrigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
	sprite.setOrigin(newOrigin);

}

// IMPLEMENT 

 void Tower::Draw(sf::RenderWindow& window) 
 {
	for (auto a : bulletVector) { a.Draw(window); }
 }

