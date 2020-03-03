#pragma once
#include <string>
#include <iostream>
#include <map>

class SpritesMapper 
{
private:

	static SpritesMapper* _instance;
	SpritesMapper();
	SpritesMapper(const SpritesMapper&) {}


public:

	std::map<int, std::string> id_path_map;
	void Add(int _id, std::string _path);
	static SpritesMapper* getInstance() 
	{
		if (!_instance)
		{
			_instance = new SpritesMapper();
			std::cout << "<!>" << std::endl;
		}
		return _instance;
	}

};