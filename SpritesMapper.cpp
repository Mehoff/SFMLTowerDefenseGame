#include "SpritesMapper.h"
#include <iostream>

SpritesMapper* SpritesMapper::_instance = 0;

void SpritesMapper::Add(int _id, std::string _path) 
{
	this->_instance->mapper.push_back(path_sprite_struct(_id,_path));
}

void SpritesMapper::Load() 
{

	_instance->mapper.push_back(path_sprite_struct(1, "./images/tower.png"));
	
	std::cout << "Sprites are loaded to memory\n";
}

std::string SpritesMapper::getPathById(int _id)
{
	for (int i = 0; i < mapper.size(); i++)
	{
		if (mapper[i].id == _id) { return mapper[i].path; }
	}
	std::cout << "Wrong mapper id(" << _id << ")" << std::endl;
	return "null";
}

sf::Texture SpritesMapper::getTexture(const std::string& _id) const
{
	auto it = textureMap.find(_id);
	if (it != textureMap.end()) 
	{
		return it->second;
	}
	else { return sf::Texture(); }
}