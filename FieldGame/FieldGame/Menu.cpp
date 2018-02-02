#include "Menu.hpp"

Menu::Menu()
{
	pHighScoreList = new HighScoreList();
}

void Menu::callMenu()
{
	int enter = 0;

	std::cout << "\n<<<<<<< MAIN MENU >>>>>>>>" << std::endl;
	std::cout << "\n[1] - START GAME" << std::endl;
	std::cout << "[2] - SHOW HIGHSCORELIST" << std::endl;
	std::cout << "[3] - SHOW INFO" << std::endl;
	std::cout << "[4] - EXIT" << std::endl;

	do {
		std::cout << "\n Your Enter: ";
		std::cin >> enter;

		switch (enter)
		{
		case 1:
			game.run();
			break;

		case 2:
			highScoreListMenu();
			break;

		case 3:
			showInfo();
			break;
		}

	} while (enter != 4);
}

void Menu::showInfo()
{
	std::cout << "\n\n <<<<<<<<<< GAME INFO >>>>>>>>>>" << std::endl;
	std::cout << "\nThis game is equals to the game \"Ship sinking\"." << std::endl;
	std::cout << "At the beginning of each game you have to prepare your own field." << std::endl;
	std::cout << "You can do it on the enter of your chosen coordinates. The program will ask you for each of them" << std::endl;
	std::cout << "\n You will find following important symbols: " << std::endl;
	std::cout << "\" . \" - Free field" << std::endl;
	std::cout << "\" # \" - Your chosen field" << std::endl;
	std::cout << "\" X \" - An occupied field was hit" << std::endl;
	std::cout << "\" o \" - A free field was atttacked" << std::endl;
	std::cout << "\n Created by Tom-M S";
	std::cout << "\n\n";
}

void Menu::highScoreListMenu()
{
	int enter = 0;

	pHighScoreList->showHighScoreList();

	do {
		std::cout << "\n\nDelete HighScoreList ?" << std::endl;
		std::cout << "1 - NO" << std::endl;
		std::cout << "2 - DELETE" << std::endl;
		std::cout << "\nEnter: ";

		std::cin >> enter;

		if (enter == 2)
		{
			pHighScoreList->deleteHighScoreList();
		}

	} while (enter != 1 && enter != 2);
}