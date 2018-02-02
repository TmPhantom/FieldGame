#pragma once
#include <iostream>
#include "Player.hpp"
#include "PlayingField.hpp"
#include "PCPlayer.hpp"
#include "highScoreList.hpp"

class Game {

private:
	int maxCountShips = 5;
	int cntPlayersRound = 0;
	int countShipsPlayer;
	int countShipsPCPlayer;

	Player *p_player;
	PC_Player *p_pcPlayer;

public:
	Game();
	void run();
	void evaluate();
};
