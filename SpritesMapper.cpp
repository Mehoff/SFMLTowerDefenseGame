#include "SpritesMapper.h"
#include <iostream>

SpritesMapper* SpritesMapper::_instance = 0;



void SpritesMapper::Load() 
{
/*
	_instance->mapper.push_back(path_sprite_struct(1, "./images/tower.png"));
	*/

	sf::Texture txt;

	auto it = _instance->textureMap.begin();



	sf::Texture tower_t;
	if (!tower_t.loadFromFile("./images/tower.png")) {
		std::cout << "Error while loading texture\n";
	}

	_instance->textureMap.insert(it, std::pair<std::string,sf::Texture>("tower",tower_t));

	std::cout << "Sprites are loaded to memory\n MapSize: " << textureMap.size() << "\n";
}

//std::string SpritesMapper::getPathById(int _id)
//{
//	for (int i = 0; i < mapper.size(); i++)
//	{
//		if (mapper[i].id == _id) { return mapper[i].path; }
//	}
//	std::cout << "Wrong mapper id(" << _id << ")" << std::endl;
//	return "null";
//}

sf::Texture SpritesMapper::getTexture(const std::string& _id) const
{
	auto it = textureMap.find(_id);
	if (it != textureMap.end()) 
	{
		return it->second; //¬озвращаем текстуру в зависимости от ID
	}
	else { return sf::Texture(); }
}