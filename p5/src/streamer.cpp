#include "../include/streamer.h"
#include <cmath>
#define TAU (M_PI * 2)

void Streamer::Trigger()
{
}
void Streamer::Draw()
{

	for (size_t i = 1; i <= 8; i++)
	{
		float x = std::sin(TAU * (1 / 8) * i);
		float y = 5 * std::cos(2 * M_PIf32 * (1 / 8) * i);
		std::stringstream ss;
		ss << "Coords: " << (1 / i) << ", " << y << std::endl;
		*log<<ss.str();
		/*
		mvaddch(LINES - 5 * std::sin(2 * M_PIf32 * (1 / 8) * i) - 10,
				COLS / 2 + 5 * std::cos(2 * M_PIf32 * (1 / 8) * i), '*');
		mvaddch(LINES - i, i, '*'); */
	}
}