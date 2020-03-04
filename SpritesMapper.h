#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>


struct path_sprite_struct 
{
public:
	int id;
	std::string path;

	// test
	sf::Texture txt;


	path_sprite_struct(int _id, std::string _path)
		:id(_id), path(_path)
	{
		txt.loadFromFile(_path);
	}
};

class SpritesMapper 
{
private:

	static SpritesMapper* _instance;
	SpritesMapper() { }
	SpritesMapper(const SpritesMapper&) {}
	std::vector<path_sprite_struct> mapper;
	void Add(int _id, std::string _path);
public:

	
	void Load();
	std::string getPathById(int _id);

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