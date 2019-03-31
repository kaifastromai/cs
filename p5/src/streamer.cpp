#include "../include/streamer.h"
#include <cmath>
#define TAU (M_PI * 2)

void Streamer::Trigger()
{
}
void Streamer::Draw()
{
	*log << "LINES/COLS: " << (float)LINES / COLS << std::endl;
	*log << "COLS/LINES:" << (float)COLS / LINES << std::endl;

	for (size_t i = 1; i <= 16; i++)
	{
		float lc_ratio = (float)LINES / COLS;
		float cl_ratio = (float)COLS / LINES;
		float y = 5 * std::sin(TAU * (1.0f / 8.0f) * i);
		*log << i << std::endl;
		float x = 5 * std::cos(TAU * (1.0f / 8.0f) * i); //I think we need to give this a scale factor..
		std::stringstream ss;
		//*log << "Coords: " << x << ", " << y << std::endl;
	/* 	Rocket r;
		r.SetForce(static_cast<float>(1 / 12 * sin(TAU * (1.0f / 8.0f) * i)), static_cast<float>(-1 / 12 * cos(TAU * (1.0f / 8.0f) * i)));
		*log << r.force.x << ", " << r.force.y << std::endl;
		r.Draw();
		r.Step(); */

		//mvaddch(LINES - i, i, '*');
	}
}
