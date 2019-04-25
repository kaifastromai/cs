#include "../include/sparkler.h"
void Sparkler::Draw()
{
	attron(COLOR_PAIR(color_code));
	if (isStar)
	{
		mvaddch(LINES - position.y, position.x, '*');
		isStar = false;
	}
	else
	{
		mvaddch(LINES - position.y, position.x, 'x');
		isStar = true;
	}
}