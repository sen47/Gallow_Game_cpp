#pragma once

#include<iostream>
#include<cstdlib>
#include<cstdint>

#define NL std::cout<<std::endl;

enum class Picture
{
	GALLOW_1 = 179,
	GALLOW_2 = 196,
	GALLOW_3 = 179,
	MAN_HEAD = 79,
	MAN_BODY = 179,
	MAN_HAND = 196,
	MAN_RightLEG = 92,
	MAN_LeftLEG = 47,
	DEFAULT = static_cast<int>(' ')
};

enum Elements
{
	GALLOW_1,
	GALLOW_2,
	GALLOW_3,
	MAN_HEAD,
	MAN_BODY,
	MAN_HAND,
	MAN_RightLEG,
	MAN_LeftLEG
};

class Gallow
{
public:

	static void printGallow(const int mistakesCount);

private:
	static const int m_CHARS_COUNT{ 8 };
};