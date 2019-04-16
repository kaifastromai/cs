#include "../include/sparkler.h"
void Sparkler::Draw()
{
	if (frame % 2 == 0)
	{
		mvaddch(LINES - position.y, position.x, '*');
	}
	else
	{
		mvaddch(LINES - position.y, position.x, 'x');
	}
}