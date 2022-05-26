#include "DataCheck.h"

//////////////////////////////////////////////////////////////////////////////// Constructors

DataCheck::DataCheck(const std::int16_t* const numberPC, const std::int16_t lenght, const std::int16_t difficulty)
	:m_numberPC{ numberPC }, m_lenght(lenght), m_difficulty(difficulty)
{
	m_guessDigits = new char[lenght];
	for (int i = 0; i < lenght; ++i)
		m_guessDigits[i] = '_';
}

DataCheck::~DataCheck()
{
	if (m_guessDigits)
		delete[]m_guessDigits;
}

//////////////////////////////////////////////////////////////////////////////// Methods

bool DataCheck::isEquals(const std::int16_t* const numberPlayer)
{
	int pc(0), player(0), temp(1);
	for (int i = m_lenght - 1; i >= 0; --i, temp *= 10)
	{
		pc += m_numberPC[i] * temp;
		player += numberPlayer[i] * temp;
	}

	return pc == player;
}

void DataCheck::printCheck(const std::int16_t* const numberPlayer, const std::int16_t mistakes)
{
	if (!mistakes)
	{
		std::cout << "\nUse your firs try!";
	}
	else
	{
		switch (m_difficulty)
		{
		case EASY:
			easyCheck(numberPlayer);
			break;
		case MEDIUM:
			mediumCheck(numberPlayer);
			break;
		case HARD:
			hardCheck(numberPlayer);
			break;
		}
	}
}

void DataCheck::easyCheck(const std::int16_t* const numberPlayer)
{
	std::int16_t onTheirPosition(0), matches(0);
	std::cout << std::endl;
	for (int i = 0; i < m_lenght; ++i)
	{
		if (m_numberPC[i] == numberPlayer[i])
		{
			switch (m_numberPC[i])
			{
			case 1:
				m_guessDigits[i] = '1';
				break;
			case 2:
				m_guessDigits[i] = '2';
				break;
			case 3:
				m_guessDigits[i] = '3';
				break;
			case 4:
				m_guessDigits[i] = '4';
				break;
			case 5:
				m_guessDigits[i] = '5';
				break;
			case 6:
				m_guessDigits[i] = '6';
				break;
			case 7:
				m_guessDigits[i] = '7';
				break;
			case 8:
				m_guessDigits[i] = '8';
				break;
			case 9:
				m_guessDigits[i] = '9';
				break;
			case 0:
				m_guessDigits[i] = '0';
				break;
			}
			++onTheirPosition;
		}

		for (int j = 0; j < m_lenght; ++j)
			if (m_numberPC[i] == numberPlayer[j])
			{
				++matches;
				break;
			}

		std::cout << m_guessDigits[i];
	}
	std::cout << "\nMatches found: " << matches << ", on their positions: " << onTheirPosition;
}

void DataCheck::mediumCheck(const std::int16_t* const numberPlayer)
{
	std::int16_t onTheirPosition(0), matches(0);
	std::cout << std::endl;
	for (int i = 0; i < m_lenght; ++i)
	{
		if (m_numberPC[i] == numberPlayer[i])
		{
			++onTheirPosition;
		}

		for (int j = 0; j < m_lenght; ++j)
			if (m_numberPC[i] == numberPlayer[j])
			{
				++matches;
				break;
			}
	}
	std::cout << "\nMatches found: " << matches << ", on their positions: " << onTheirPosition;
}

void DataCheck::hardCheck(const std::int16_t* const numberPlayer)
{
	std::int16_t matches(0);
	std::cout << std::endl;
	for (int i = 0; i < m_lenght; ++i)
	{
		for (int j = 0; j < m_lenght; ++j)
			if (m_numberPC[i] == numberPlayer[j])
			{
				++matches;
				break;
			}
	}
	std::cout << "\nMatches found: " << matches;
}
