#include "GameWithNumber.h"

//////////////////////////////////////////////////////////////////////////// Constructors

GameWithNumber::GameWithNumber(const std::uint16_t hiddenLenght)
	:m_hiddenLenght{ hiddenLenght }
{
	m_numberPC = new std::int16_t[hiddenLenght];
	m_numberPlayer = new std::int16_t[hiddenLenght];
}

GameWithNumber::~GameWithNumber()
{
	if (m_numberPC)
		delete[]m_numberPC;
	if (m_numberPlayer)
		delete[]m_numberPlayer;
}

/////////////////////////////////////////////////////////////////////////// Getters

const std::int16_t* GameWithNumber::getPC()
{
	return m_numberPC;
}

const std::int16_t* GameWithNumber::getPlayer()
{
	return m_numberPlayer;
}

std::int16_t GameWithNumber::getHiddenLenght()
{
	return m_hiddenLenght;
}

////////////////////////////////////////////////////////////////////////// Methods

void GameWithNumber::thinkPcNumber()
{
	for (int i = 0; i < m_hiddenLenght; ++i)
	{
		do
		{
			m_numberPC[i] = rand() % 10;
		} while (*m_numberPC == 0);
	}
}

void GameWithNumber::enterPlayerNumber()
{
	std::int32_t tempNumber;
	while (true)
	{
		std::cout << "Enter number of " << m_hiddenLenght << " digits: ";
		std::cin >> tempNumber;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::system("cls");
			std::cout << "Error, unvaliable value, try again!\n";
		}
		else if ((m_hiddenLenght == 4 && (tempNumber > 9999 || tempNumber < 1000)) || (m_hiddenLenght == 5 && (tempNumber > 99999 
			|| tempNumber < 10000)) || (m_hiddenLenght == 6 && (tempNumber > 999999 || tempNumber < 100000)))
		{
			std::system("cls");
			std::cout << "Error, unvaliable value, try again!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}	
	}

	for (int i = m_hiddenLenght - 1; i >= 0; --i)
	{
		m_numberPlayer[i] = tempNumber % 10;
		tempNumber /= 10;
	}
}

////////////////////////////////////////////////////////////////////////// Test

void GameWithNumber::printPcNumber()
{
	std::cout << "NumberPc: ";
	for (int i = 0; i < m_hiddenLenght; ++i)
		std::cout << m_numberPC[i];
}

void GameWithNumber::printPlayerNumber()
{
	std::cout << "NumberPlayer: ";
	for (int i = 0; i < m_hiddenLenght; ++i)
		std::cout << m_numberPlayer[i];
}
