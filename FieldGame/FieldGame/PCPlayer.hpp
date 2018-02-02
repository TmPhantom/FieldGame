#pragma once
#include <Windows.h>
#include <ctime>
#include <list>
#include "PlayingField.hpp"
#include "Player.hpp"

class PC_Player {

private:
	int maxCountShips;
	int countShips;
	std::pair<int, int> shotEntry;
	std::list< std::pair<int, int> > shotList;

public:
	PlayingField pcPlayersField;
	PC_Player(int countShips);
	void setUp();
	void attackPlayer(PlayingField &playersField, int &countShips);
	int getCountShips();
	void setCountShips(int newCountShips);
};
