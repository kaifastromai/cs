#include <thread>
#include <math.h>
#include <iostream>
#include "drop.hpp"
#include "curses.h"

Drop::Drop()
{
	age = 0;
	center.l = LINES / 2;
	center.c = COLS / 2;
	offsetx = 0;
	offsety = 0;
}

void Drop::Draw()
{
	//mvaddstr(center.l - 4, center.c + 4, std::to_string(age).c_str());
	
	if (age != MAXIMUM_AGE)
	{

		if (age == 0)
		{
			//std::cout << "we ran this line ";
			age = age + 1;
			offsetx = (rand() % (center.c - 4) + 1) * (int)pow(-1.0, (float)(rand() % 3));
			offsety = (rand() % (center.l - 10) + 1) * (int)pow(-1.0, (float)(rand() % 3));
			mvaddstr(center.l + offsety, center.c + offsetx, "o");
		}
		else if (age == 1)
		{
			//std::cout << "we ran this line for age =1 ";

			mvaddstr(center.l + -2 + offsety, center.c + offsetx, "-");
			mvaddstr(center.l + 0 + offsety, center.c + offsetx - 1, ("( )"));
			mvaddstr(center.l + 2 + offsety, center.c + offsetx, ("-"));
			age++;
		}
		else if (age == 2)
		{
			mvaddstr(center.l + -4 + offsety, center.c + offsetx, "-");
			mvaddstr(center.l + -2 + offsety, center.c + offsetx - 1, ("/ \\"));
			mvaddstr(center.l + 0 + offsety, center.c + offsetx - 2, ("(   )"));
			mvaddstr(center.l + 2 + offsety, center.c + offsetx - 1, ("\\ /"));
			mvaddstr(center.l + 4 + offsety, center.c + offsetx, ("-"));
			age++;
		}
	}
}
bool Drop::TimeToDie()
{
	if (age == MAXIMUM_AGE)
	{
		return true;
	}
	else
		return false;
}
void Storm::Birth()
{
	int drop_count = rand() % (12) + 1;
	for (int i = 0; i <= drop_count; i++)
	{
		Drop *d = new Drop;
		drops.push_back(*d);
		//mvaddstr(d.center.l + 2, d.center.c, (std::to_string(drop_count).c_str()));
	}
}
void Storm::Draw()
{
	//std::cout << drops.at(0).age << std::endl;
	for (size_t i = 0; i < drops.size(); i++)
	{
		drops.at(i).Draw();
	}
}
void Storm::Cull()
{
	if (drops.size() > 1)
	{
		for (Drop d : drops)
		{
			if (d.TimeToDie())
			{
				drops.pop_front();
			}
		}
	}
}