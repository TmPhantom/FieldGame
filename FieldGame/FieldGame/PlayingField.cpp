#include "PlayingField.hpp"

PlayingField::PlayingField()
{

}

void PlayingField::showField()
{
	std::cout << "\n";

	//Einrückung
	std::cout << "   ";

	for (int x = 0; x < length; x++)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;

	for (int y = 0; y < height; y++)
	{
		std::cout << y << " ";

		for (int x = 0; x < length; x++)
		{
			switch (playingField[x][y].myState)
			{
			case Field::FREE:
				std::cout << " .";
				break;

			case Field::BUSY:
				std::cout << " #";
				break;

			case Field::HIT:
				std::cout << " X";
				break;

			case Field::BESIDES:
				std::cout << " o";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void PlayingField::showEnemiesField()
{
	std::cout << "\n\n\n";

	//Einrückung
	std::cout << "   ";

	for (int x = 0; x < length; x++)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;

	for (int y = 0; y < height; y++)
	{
		std::cout << y << " ";

		for (int x = 0; x < length; x++)
		{
			switch (playingField[x][y].myState)
			{
			case 1:
				std::cout << " .";
				break;

			case 2:
				std::cout << " .";
				break;

			case 3:
				std::cout << " X";
				break;

			case 4:
				std::cout << " o";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void PlayingField::occupyField(int xPos, int yPos)
{
	if (xPos < length && xPos >= 0)
	{
		if (yPos < height && yPos >= 0)
		{
			playingField[xPos][yPos].setState(Field::BUSY);
		}
	}
}

void PlayingField::createField()
{
	for (int x = 0; x < length; x++)
	{
		for (int y = 0; y < height; y++)
		{
			playingField[x][y].setState(Field::FREE);
		}
	}
}

Field::State PlayingField::getFieldState(int xPos, int yPos)
{
	return playingField[xPos][yPos].myState;
}

void PlayingField::setFieldState(Field::State newState, int xPos, int yPos)
{
	playingField[xPos][yPos].setState(newState);
}

int PlayingField::getHeight()
{
	return height;
}

int PlayingField::getLength()
{
	return length;
}