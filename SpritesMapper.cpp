#include "SpritesMapper.h"
#include <iostream>

SpritesMapper* SpritesMapper::_instance = 0;



void SpritesMapper::Load() 
{
	Add("./images/tower.png",		      't');
	Add("./images/grass.png",		      'a');
	Add("./images/corner_down_left.jpg",  'b');
	Add("./images/corner_down_right.jpg", 'c');
	Add("./images/corner_top_left.jpg",	  'd');
	Add("./images/corner_top_right.jpg",  'e');
	Add("./images/Spawner.jpg",           's');
	Add("./images/enemy.png",			  'x');
	Add("./images/Horizontal.jpg",		  'h');
	Add("./images/Vertical.jpg",		  'v');

}


void SpritesMapper::Add(std::string path, char id) 
{
	auto it = _instance->textureMap.begin();

	sf::Texture txt;
	if (!txt.loadFromFile(path)) 
	{
		std::cout << "<!> Error while loading texture " << path << "\n";
	}
	_instance->textureMap.insert(it, std::pair<char, sf::Texture>(id, txt));
	std::cout << "<!> Loaded (" << path << ")\n";
}

sf::Texture SpritesMapper::getTexture(const char & _id) const
{
	auto it = textureMap.find(_id);
	if (it != textureMap.end()) 
	{
		return it->second; //¬озвращаем текстуру в зависимости от ID
	}
	else 
	{
		std::cout << "<!> Returned Blank Texture\n";
		return sf::Texture(); 
	}
}

char SpritesMapper::getTextureCharByTextFileChar(const char& c) const 
{
	switch (c)
	{
	case 'a': return 'd';
		break;
	case 'b': return 'b';
		break;
	case 'c': return 'e';
		break;
	case 'd': return 'd';
		break;
	case 'e': return 'e';
		break;
	case 'f': return 'c';
		break;
	case 'g': return 'b';
		break;
	case 'h': return 'c';
		break;
	case 'z': return 'a';
		break;
	case 'i': return 'h';
		break;
	case 'j': return 'h';
		break;
	case 'k': return 'v';
		break;
	case 'l': return 'v';
		break;
	case 's': return 's';
		break;
	default:
		return 'a';
	}
}