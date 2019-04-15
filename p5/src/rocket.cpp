#include "../include/rocket.h"

Rocket::Rocket()
{
	position.x = COLS / 2;
}
Rocket::~Rocket()
{
}
void Rocket::Draw()
{
	mvaddch(LINES - position.y, COLS - position.x, '*');
}
void Rocket::Step(std::vector<Rocket *> &v)
{
	age++;
	position.y + force.y - gravity;
}
void Rocket::SetAgeLimit(int i)
{
	this->age_limit = i;
}
void Rocket::Trigger(std::vector<Rocket *> &v)
{
}
