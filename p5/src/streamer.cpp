#include "../include/streamer.h"
#include <cmath>
#define TAU (M_PI * 2)

void Streamer::Trigger()
{
}
void Streamer::Draw()
{
	*log << "Ratio lines/cols: " << LINES / COLS << std::endl;
	*log << "Ratio cols/lines:" << COLS / LINES << std::endl;

	for (size_t i = 1; i <= 16; i++)
	{
		float lc_ratio = LINES / COLS;
		float cl_ratio = COLS / LINES;
		float x = 10 * std::sin(TAU * (1.0f / 16.0f) * i); //I think we need to give this a scale factor..
		float y = 5 * std::cos(TAU * (1.0f / 16.0f) * i);
		std::stringstream ss;
		//*log << "Coords: " << x << ", " << y << std::endl;

		mvaddch(LINES / 2 - y, COLS / 2 + x, '*');
		//mvaddch(LINES - i, i, '*');
	}
}
