#pragma once

#include<cstdlib>
#include<cstdint>
#include<iostream>

class GameWithNumber
{
public:
	GameWithNumber(const std::uint16_t hiddenLenght);
	~GameWithNumber();

	const std::int16_t* getPC();
	const std::int16_t* getPlayer();
	std::int16_t getHiddenLenght();

	void thinkPcNumber();
	void enterPlayerNumber();
	
	void printPcNumber();
	void printPlayerNumber();

private:
	std::int16_t* m_numberPC{ nullptr };
	std::int16_t* m_numberPlayer{ nullptr };
	const std::uint16_t m_hiddenLenght;
};