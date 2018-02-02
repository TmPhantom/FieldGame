#pragma once
#include "Game.hpp"
#include "highScoreList.hpp"
#include <iostream>

class Menu {

private:
	Game game;
	HighScoreList *pHighScoreList = NULL;

public:
	Menu();
	void callMenu();
	void showInfo();
	void deleteHighScoreList();
	void highScoreListMenu();
};
