#pragma once
#include <string>
#include "PlayingField.hpp"

class Player {

private:
	int maxCountShips;
	int countShips;
	std::string name;
	int points = 0;

public:
	PlayingField playersField;

	//Konstruktor
	Player(int countShips);

	~Player();

	void setUp();
	void attackPCPlayer(PlayingField &pcPlayersField, int &countShips);
	void calculatePoints(int playersRounds);

	//Getter und Setter
	void setName(std::string name);
	std::string getName();
	void setPoints(int points);
	int getPoints();
	int getCountShips();
	void setCountShips(int countShips);
};
