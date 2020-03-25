#include "Objects.h"
#include "Chunk.h"


class LevelLoader 
{
private:
	const std::string path = "./levels/";
	const int width = 26;
	const int height = 14;

	static LevelLoader* _instance;
	LevelLoader() { }

	char GetTextureChar(const char& c);
	int GetRotateDirectionInt(const char& c);

public:
	
	LevelLoader(int number);
	void LoadLevel(int number);
	void Clear();
	static LevelLoader* getInstance()
	{
		if (!_instance)
		{
			_instance = new LevelLoader();
		}
		return _instance;
	}
};

#define LevelManager LevelLoader::getInstance()