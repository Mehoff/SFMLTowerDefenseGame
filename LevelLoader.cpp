#include "LevelLoader.h"
#include <fstream>

LevelLoader* LevelLoader::_instance = 0;

LevelLoader::LevelLoader(int number) 
{
	LoadLevel(number);
}


char LevelLoader::GetTextureChar(const char& c) 
{
	return SMapper->getTextureCharByTextFileChar(c);
}

int LevelLoader::GetRotateDirectionInt(const char& c)
{
	// 1 - UP , 2 - DOWN, 3 - LEFT, 4 - RIGHT   0 - default
	switch (c)
	{
	case 'a': return 1;
		break;
	case 'b': return 2;
		break;
	case 'c': return 1;
		break;
	case 'd': return 3;
		break;
	case 'e': return 4;
		break;
	case 'f': return 4;
		break;
	case 'g': return 3;
		break;
	case 'h': return 2;
		break;
	case 'z': return 0;
		break;
	case 'i': return 4;
		break;
	case 'j': return 3;
		break;
	case 'k': return 1;
		break;
	case 'l': return 2;
		break;
	default:
		return 0;
	}

}

void LevelLoader::LoadLevel(int number) 
{
	// Clear Towers, Bullet, Chunks
	// Open file for read and Load Level

	ObjectsVector.clear();

	char FileChar = NULL;
	char _TextureChar = NULL;
	int  _RotateDirectionInt = NULL;

	int _x = 0;
	int _y = 0;
	
	std::ifstream mapFile(path + std::to_string(number) + ".txt");

	
	while ((FileChar = mapFile.get()) != EOF)
	{ 
		if (FileChar != '\n') // Достали символ, обработать, нарисовать нужную текстуру, и указать направление
		{
			_TextureChar = GetTextureChar(FileChar);
			_RotateDirectionInt = GetRotateDirectionInt(FileChar);

			ObjectsVector.push_back(new Chunk(_x, _y, _TextureChar, _RotateDirectionInt));
			_x += 50;
		}
		else				  // Переход на некст строку 
		{
			_x = 0;
			_y += 50;
		}
	}
	mapFile.close();
	
}

void LevelLoader::Clear()
{
	//... Возможно понадобится чистить отдельно пули и отдельно вышки
}

//  Tower -> Vector Bullet