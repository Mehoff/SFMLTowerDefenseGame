#include "GameManager.h"
#include "LevelLoader.h"

GameManager* GameManager::_instance = 0;

void GameManager::LoadLevel(int _id) 
{
	LevelManager->LoadLevel(_id);
}
void GameManager::ShowUI(bool val) 
{
	if (val) 
	{
	//	Что-то вроде UI.toDraw = true;
	//	
	//
	//
	//
	}
}

