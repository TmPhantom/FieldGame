#include "Game.hpp"

//Konstruktor
Game::Game()
{
	p_player = new Player(maxCountShips);
	p_pcPlayer = new PC_Player(maxCountShips);

	countShipsPCPlayer = p_pcPlayer->getCountShips();
	countShipsPlayer = p_player->getCountShips();
}

//
//run-Funktion
// Spiellogik

void Game::run()
{
	PlayingField playersField;
	PlayingField pcPlayersField;
	std::string name;

	//Neues Spielfeld wird erstellt
	playersField.createField();
	pcPlayersField.createField();

	std::cout << "\n\n<<<<<<<<<<< GAME >>>>>>>>>>>" << std::endl;

	//Computer und Spieler erzeugen ihre Spielfelder
	p_pcPlayer->setUp();
	p_player->setUp();

	//Holen der Spielfelder zu Beginn des Spiels
	playersField = p_player->playersField;
	pcPlayersField = p_pcPlayer->pcPlayersField;

	std::cout << "\n\n--------------------------------" << std::endl;
	std::cout << "\nThe game has started and your enemy is prepared !" << std::endl;
	std::cout << "\n-------------------------------" << std::endl;
	std::cout << "\n";

	//Spielverlauf
	//

	while (p_player->getCountShips() > 0 && p_pcPlayer->getCountShips() > 0)
	{
		//Anzeigen des gegnerischen Spielfeldes
		pcPlayersField.showEnemiesField();

		std::cout << "\n###################" << std::endl;
		std::cout << "\n";

		//Anzeigen des eigenen Spielfeldes
		playersField.showField();

		//Spieler führt Angriff aus
		p_player->attackPCPlayer(pcPlayersField, countShipsPCPlayer);

		//Computer führt Angriff aus
		p_pcPlayer->attackPlayer(playersField, countShipsPlayer);

		std::cout << "countShipsPCPlayer: " << countShipsPCPlayer << std::endl;

		p_player->setCountShips(countShipsPlayer);
		p_pcPlayer->setCountShips(countShipsPCPlayer);

		std::cout << "countShisPCPlayer: " << p_pcPlayer->getCountShips() << std::endl;

		//Anzahl Spielzüge erhoehen
		cntPlayersRound++;
	}

	evaluate();
}

void Game::evaluate()
{
	if (p_player->getCountShips() == 0)
	{
		std::cout << "Captain " << p_player->getName() << ", we lost !" << std::endl;
		std::cout << "\n";
	}

	if (p_pcPlayer->getCountShips() == 0)
	{
		std::cout << "Captain " << p_player->getName() << ", that's our VICTORY !!!" << std::endl;
		std::cout << "\n";
	}

	//Berechnung der Punkte
	p_player->calculatePoints(cntPlayersRound);
}