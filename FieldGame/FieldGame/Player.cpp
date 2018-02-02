#include "Player.hpp"

Player::Player(int countShips)
{
	maxCountShips = countShips;
	this->countShips = countShips;
}

Player::~Player()
{

}

void Player::setUp()
{
	std::cout << "\n\n----- Please, enter your name -----" << std::endl;
	std::cout << "Name : ";

	std::cin >> name;

	std::cout << "\n\nNow it's time to place your \"Ships\", Captain " << name << "!\n";

	int xEnter = 0;
	int yEnter = 0;
	int count = 1;

	while (count <= maxCountShips)
	{
		playersField.showField();

		do {
			do {
				std::cout << "\nX-KOORDINATE [0 - " << length - 1 << "]: ";
				std::cin >> xEnter;

				if (xEnter < 0 || xEnter >= length)
				{
					std::cout << "Your chosen coordinates are not part of the given value range !\n";
				}

			} while (xEnter < 0 || xEnter >= length);

			std::cout << "\n";

			do
			{
				std::cout << "Y-KOORDINATE [0 - " << height - 1 << "]: ";
				std::cin >> yEnter;

				if (yEnter < 0 || yEnter >= height)
				{
					std::cout << "Your chosen coordinates are not part of the given value range !\n";
				}
			} while (yEnter < 0 || yEnter >= height);

			if (playersField.getFieldState(xEnter, yEnter) == Field::BUSY)
			{
				std::cout << "\n";
				std::cout << "This field is already occupied !" << std::endl;
				std::cout << "Please, select another field !" << std::endl;
				std::cout << "\n";
			}
		} while (playersField.getFieldState(xEnter, yEnter) == Field::BUSY);

		std::cout << "\n";

		//Feld setzen
		playersField.occupyField(xEnter, yEnter);
		count++;
	}
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string Player::getName()
{
	return name;
}

void Player::setPoints(int points)
{
	this->points = points;
}

int Player::getPoints()
{
	return points;
}

void Player::attackPCPlayer(PlayingField &pcPlayersField, int &countShips)
{
	int xEnter = 0;
	int yEnter = 0;

	Field::State actualState;
	//Abfrage der Eingabe
	do
	{
		std::cout << std::endl;
		do
		{
			std::cout << "X-KOORDINATE [0 - " << length - 1 << "] : ";
			std::cin >> xEnter;
		} while (xEnter < 0 || xEnter >= length);

		std::cout << std::endl;

		do
		{
			std::cout << "Y-KOORDINATE [0 - " << height - 1 << "] : ";
			std::cin >> yEnter;
		} while (yEnter < 0 || yEnter >= height);

		//Holen des akteullen Zustands
		actualState = pcPlayersField.getFieldState(xEnter, yEnter);

		if (actualState == Field::HIT || actualState == Field::BESIDES)
		{
			std::cout << "You already attacked this field! Please select another field." << std::endl;
		}
	} while (actualState == Field::HIT || actualState == Field::BESIDES);

	Field::State newState;

	//vorherigen Status überprüfen  
	switch (actualState)
	{
	case Field::FREE:
		newState = Field::BESIDES;
		break;

	case Field::BUSY:
		newState = Field::HIT;
		countShips--;
		break;
	}

	//Neuen Status setzen
	pcPlayersField.setFieldState(newState, xEnter, yEnter);
}

int Player::getCountShips()
{
	return countShips;
}

void Player::setCountShips(int countShips)
{
	this->countShips = countShips;
}

void Player::calculatePoints(int playersRounds)
{
	int maxRounds = playersField.getHeight() * playersField.getLength();

	if (countShips == 0)
	{
		points = 0;
	}
	if (countShips > 0)
	{
		points = countShips * 10 * (maxRounds - playersRounds);
	}

	std::cout << "\nThe Player " << name << " got " << points << " points." << std::endl;
	std::cout << "\n";
}