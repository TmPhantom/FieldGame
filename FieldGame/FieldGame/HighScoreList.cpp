#include "highScoreList.hpp"

HighScoreList::HighScoreList()
{
	initHighScoreList();
}

int HighScoreList::addPlayer(Player *pPlayer)
{
	//pair<> player initialisieren
	player.second = pPlayer->getName();
	player.first = pPlayer->getPoints();

	//player hinzufügen
	highScoreList.insert(player);

	//Letzter Spieler wird von Liste gestrichen
	highScoreList.erase(11);

	if (countEntries < maxEntries)
	{
		countEntries++;
	}

	return 0;
}

void HighScoreList::deleteHighScoreList()
{
	initHighScoreList();
}

void HighScoreList::showHighScoreList()
{
	std::map<int, std::string>::iterator it;

	int count = maxEntries;

	std::cout << "\n";
	std::cout << "<<<<<<<<<< HIGHSCORELIST >>>>>>>>>>>" << std::endl;
	std::cout << "\n";

	for (it = highScoreList.begin(); it != highScoreList.end(); it++)
	{
		if (it->second == "XXX")
		{
			std::cout << count-- << ". ---------" << "----------" << std::endl;
		}

		if (it->second != "XXX")
		{
			std::cout << count-- << ". " << it->second << " " << it->first << " Punkte";
			std::cout << "\n";
		}
	}
}

std::map<int, std::string> HighScoreList::getHighScoreList()
{
	return highScoreList;
}

void HighScoreList::initHighScoreList()
{
	highScoreList.clear();

	for (int i = 1; i <= maxEntries; i++)
	{
		//"BoB"-Initialisierung
		player.first = i;
		player.second = "XXX";

		highScoreList.insert(player);
	}
}