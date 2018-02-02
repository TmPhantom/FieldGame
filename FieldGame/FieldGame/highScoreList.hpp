#pragma once
#include <map>
#include <string>
#include "Player.hpp"

class HighScoreList {

private:
	std::map<int, std::string> highScoreList;
	std::pair<int, std::string> player;
	int countEntries = 0;					//zählt Anzahl Einträge
	int maxEntries = 10;

public:
	HighScoreList();
	std::map<int, std::string> getHighScoreList();
	int addPlayer(Player *pPlayer);
	void deleteHighScoreList();
	void showHighScoreList();
	void initHighScoreList();
};