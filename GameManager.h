#pragma once


struct PlayerStats 
{
private:
	int HP;
	int Money;
public:
	PlayerStats() : HP(3),Money(100)
	{}
	void SetValues(int _hp, int _money) { HP = _hp, Money = _money; }

	int& getHealth() { return HP; }
	int& getMoney() { return Money; }
};

class GameManager 
{
private:
	static GameManager * _instance;
	PlayerStats playerStats;

public:

	static GameManager * getInstance()
	{
		if (!_instance)
		{
			_instance = new GameManager();
		}
		return _instance;
	}

	PlayerStats& getPlayer() { return playerStats; }
	void LoadLevel(int id);
	void ShowUI(bool value);

};

#define GManager GameManager::getInstance()