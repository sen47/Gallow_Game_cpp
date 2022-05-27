// Hangman game with words or numbers

#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>

#include"Games.h"
#include"Gallow.h"
#include"GameWithNumber.h"
#include"DataCheck.h"

//#define DEBUG_PC
//#define DEBUG_PLAYER

enum class Game
{
	NUMBERS = 1,
	WORDS
};

Game choosingGame();
int choosingDifficulty();

int main()
{
	srand(static_cast<std::uint32_t>(time(NULL)));
	
	static const std::int16_t MAX_TRYES(7);
	Game chooseGame(choosingGame());
	std::int16_t mistakes(0), difficulty(choosingDifficulty());
	std::int16_t hiddenLenght(difficulty + 3);

	Games* game{ nullptr };

	switch (chooseGame)
	{
	case Game::NUMBERS:
		game = new GameWithNumber(hiddenLenght);
		break;
	case Game::WORDS:

		break;
	}



	do
	{
		game->playRound();
		if (check.isEquals(numberGame.getPlayer()))
		{
			break;
		}
		else
			++mistakes;

	} while (mistakes < MAX_TRYES);
	

//	// This obj draw gallow
//	Gallow gallow;
//
//	if (game == Game::NUMBERS)
//	{
//		GameWithNumber numberGame(hiddenLenght);
//		numberGame.thinkPcNumber();
//		DataCheck check(numberGame.getPC(), numberGame.getHiddenLenght(), difficulty);
//
//		do
//		{
//			gallow.printGallow(mistakes);
//
//#ifdef DEBUG_PC
//			std::cout << "\nTEST\t";
//			numberGame.printPcNumber();
//#endif // DEBUG_PC
//
//			check.printCheck(numberGame.getPlayer(), mistakes);
//
//			std::cout << "\n\nYou have " << MAX_TRYES - mistakes << " tryes" << std::endl;
//			numberGame.enterPlayerNumber();
//
//			if (check.isEquals(numberGame.getPlayer()))
//			{
//				break;
//			}
//			else
//				++mistakes;
//
//		} while (mistakes < 7);
//	}
//	else if (game == Game::WORDS)
//	{
//
//	}
	
	system("cls");

	if (mistakes < 7)
		std::cout << "\n\n\n\tCongratulations mortal, you saved your worthless live!\n\tGet out of here, before i change my mind!" << std::endl;
	else
	{
		//gallow.printGallow(mistakes);
		std::cout << "\n\n\tYou lose mortal!\n\tNow your soul is mine!" << std::endl;
	}

	delete game;

	return 0;
}

Game choosingGame()
{
	std::int16_t game(0);
	while(true)
	{
		std::cout << "You need to choose game"
			<< "\nif you want to play with numbers - enter 1"
			<< "\nif you want to play with words   - enter 2"
			<< "\nEnter: ";
		std::cin >> game;
		std::cin.ignore(32767, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::system("cls");
			std::cout << "Error, unvaliable value, try again!\n";
		}
		else if (game != 1 && game != 2)
		{
			std::system("cls");
			std::cout << "Error, unvaliable value, try again!\n";
		}
		else
		{
			std::system("cls");
			return static_cast<Game>(game);
		}
	}
}

int choosingDifficulty()
{
	while (true)
	{
		int number;

		std::cout << "Select level difficulty"
			<< "\nfor easy\t(4 symbols) - enter 1"
			<< "\nfor medium\t(5 symbols) - enter 2"
			<< "\nfor hard\t(6 symbols) - enter 3"
			<< "\nEnter: ";

		std::cin >> number;
		std::cin.ignore(32767, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::system("cls");
			std::cout << "Error, unvaliable value, try again!\n";
		}
		else if (number < 1 || number>3)
		{
			std::cin.ignore(32767, '\n');
			std::system("cls");
			std::cout << "Error, unvaliable value, try again!\n";
		}
		else
		{
			std::system("cls");
			return number;
		}
	}
}