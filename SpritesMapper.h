#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>


class SpritesMapper 
{
private:
	std::map<char, sf::Texture> textureMap;
	static SpritesMapper* _instance;
	SpritesMapper() { }
	SpritesMapper(const SpritesMapper&) {}
	void Add(std::string path, char id);

public:

	sf::Texture getTexture(const char & _id) const;
	char getTextureCharByTextFileChar(const char& c) const;
	
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