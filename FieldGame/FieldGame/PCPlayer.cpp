#include "PCPlayer.hpp"

PC_Player::PC_Player(int countShips)
{
	maxCountShips = countShips;
	this->countShips = countShips;
}

void PC_Player::setUp()
{
	srand(static_cast<unsigned int>(time(NULL)));

	//Zufallszahlen generiert
	int guessingCountX = rand() % length;
	int guessingCountY = (rand() + 5) % height;

	int count = 1;

	while (count <= maxCountShips)
	{
		guessingCountX = (guessingCountX + count * 5) % length;
		guessingCountY = (guessingCountY + count * 5) % height;

		if (pcPlayersField.getFieldState(guessingCountX, guessingCountY) == 2)
		{
			while (pcPlayersField.getFieldState(guessingCountX, guessingCountY) == 2)
			{
				guessingCountX = (guessingCountX + 1) % length;
				guessingCountY = (guessingCountY + 1) % height;
			}
		}

		//Feld setzen
		pcPlayersField.occupyField(guessingCountX, guessingCountY);
		count++;
	}
}

void PC_Player::attackPlayer(PlayingField &playersField, int &countShips)
{
	srand(static_cast<unsigned int>(time(NULL)));
	std::list< std::pair<int, int> >::iterator it;

	//Zufallszahlen generiert und auf shotEntry geschrieben
	shotEntry.first = rand() % length;
	shotEntry.second = (rand() + 5) % height;

	//Überprüfen, ob Eintrag bereits in Liste enthalten ist
	for (it = shotList.begin(); it != shotList.end(); it++)
	{
		if (*it == shotEntry)
		{
			shotEntry.first = rand() % length;
			shotEntry.second = (rand() + 5) % height;

			//Iterator auf Anfang zurücksetzen
			it = shotList.begin();
		}
	}

	shotList.push_back(shotEntry);

	Field::State actualState = playersField.getFieldState(shotEntry.first, shotEntry.second);
	Field::State newState = Field::BESIDES;

	switch (actualState)
	{
	case Field::BUSY:
		newState = Field::HIT;
		countShips--;
		break;

	default:
		newState = Field::BESIDES;
		break;
	}

	//Setzen des Status...Funktion leitet den neuen Feldstatus an das spezielle Feld weiter
	playersField.setFieldState(newState, shotEntry.first, shotEntry.second);
}

int PC_Player::getCountShips()
{
	return countShips;
}

void PC_Player::setCountShips(int newCountShips)
{
	countShips = newCountShips;
}