#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>



class SpritesMapper 
{
private:
	std::map<std::string, sf::Texture> textureMap;
	static SpritesMapper* _instance;
	SpritesMapper() { }
	SpritesMapper(const SpritesMapper&) {}
public:

	sf::Texture getTexture(const std::string& _id) const;
	void Load();


	static SpritesMapper* getInstance() 
	{
		if (!_instance)
		{
			_instance = new SpritesMapper();
			std::cout << "Mapper created" << std::endl;
		}
		return _instance;
	}

};

#define SMapper SpritesMapper::getInstance()
// <3