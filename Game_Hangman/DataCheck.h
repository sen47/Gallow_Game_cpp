#pragma once

#include<cstdint>
#include<iostream>

enum DIFFICULTY
{
	EASY = 1,
	MEDIUM,
	HARD
};

class DataCheck
{
public:

	DataCheck(const std::int16_t* const numberPC, const std::int16_t lenght, const std::int16_t difficulty);

	~DataCheck();

	bool isEquals(const std::int16_t* const numberPlayer);

	void printCheck(const std::int16_t* const numberPlayer, const std::int16_t mistakes);

private:

	char* m_guessDigits;
	const std::int16_t* m_numberPC;
	std::int16_t m_lenght;
	std::int16_t m_difficulty;

protected:
	void easyCheck(const std::int16_t* const numberPlayer);
	void mediumCheck(const std::int16_t* const numberPlayer);
	void hardCheck(const std::int16_t* const numberPlayer);
};