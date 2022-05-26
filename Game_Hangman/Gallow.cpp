#include "Gallow.h"

void Gallow::printGallow(const int mistakesCount)
{	
	std::system("cls");

	std::int16_t chars[m_CHARS_COUNT];
	for (int i = 0; i < m_CHARS_COUNT; ++i)
		chars[i] = static_cast<int>(' ');
	
	// Chose symbols for drawing gallow's parts 
	switch (mistakesCount)
	{
	case 7:
		chars[MAN_RightLEG] = static_cast<int>(Picture::MAN_RightLEG);
		chars[MAN_LeftLEG] = static_cast<int>(Picture::MAN_LeftLEG);
	case 6:
		chars[MAN_HAND] = static_cast<int>(Picture::MAN_HAND);
	case 5:
		chars[MAN_BODY] = static_cast<int>(Picture::MAN_BODY);
	case 4:
		chars[MAN_HEAD] = static_cast<int>(Picture::MAN_HEAD);
	case 3:
		chars[GALLOW_3] = static_cast<int>(Picture::GALLOW_3);
	case 2:
		chars[GALLOW_2] = static_cast<int>(Picture::GALLOW_2);
	case 1:
		chars[GALLOW_1] = static_cast<int>(Picture::GALLOW_1);
	}
	
	// Main drawing loop
	NL;
	std::cout << '\t' << static_cast<char>(chars[Elements::GALLOW_1]);
	
	for (int i = 0; i < 16; ++i)
		std::cout << static_cast<char>(chars[Elements::GALLOW_2]);
	std::cout << static_cast<char>(chars[Elements::GALLOW_1]) << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		std::cout << '\t' << static_cast<char>(chars[Elements::GALLOW_1]) << '\t';
		if (i < 1)
			std::cout << ' ' << static_cast<char>(chars[Elements::GALLOW_3]);
		if (i == 1)
			std::cout << ' ' << static_cast<char>(chars[Elements::MAN_HEAD]);
		if (i == 2)
			std::cout << static_cast<char>(chars[Elements::MAN_HAND]) << static_cast<char>(chars[Elements::MAN_BODY]) << static_cast<char>(chars[Elements::MAN_HAND]);
		if (i == 3)
			std::cout << static_cast<char>(chars[Elements::MAN_LeftLEG]) << ' ' << static_cast<char>(chars[Elements::MAN_RightLEG]);

		std::cout << '\t' << ' ' << static_cast<char>(chars[Elements::GALLOW_1]) << std::endl;
	}
}