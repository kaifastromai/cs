#include "../include/rocket.h"

Rocket::Rocket()
{
}
Rocket::~Rocket()
{
}
void Rocket::Draw()
{
}
void Rocket::Step()
{
}
void Rocket::SetAgeLimit(int i)
{
	this->age_limit = i;
}
void Rocket::Trigger()
{
}
void Rocket::SetLogFile(std::ofstream *log_file)
{
	Rocket::log_file = log_file;
}