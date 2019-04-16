#include "../include/rocket.h"

Rocket::Rocket()
{
	trigger_age = std::numeric_limits<int>::max();
	position.x = COLS / 2;
	position.y = 0;
	force = {0.5, 4.0};
}
Rocket::~Rocket()
{
	log->close();
}

void Rocket::Draw()
{
	*log << position.x << ", " << position.y << std::endl;
	mvaddch(LINES - position.y, position.x, '*');
}
//The Step() method foes forward one frame and does the necessary physics calculations
//and checks of we have reached the trigger age, at which point it will call the trigger
//method, passing by reference a vector of rockets
void Rocket::Step()
{
	if (IsTriggered())
	{
		Trigger();
	}
	(*log) << "Force: " << force.x << ", " << force.y << std::endl;
	(*log) << "Pos: " << position.x << ", " << position.y << std::endl;

	age++;
	position.y += force.y;
	position.x += force.x;
	force.y += gravity;
}
void Rocket::SetAgeLimit(int i)
{
	this->age_limit = i;
}
void Rocket::Trigger()
{
}
//setters
void Rocket::SetGravity(float g)
{
	gravity = g;
}
void Rocket::SetFrame(int f)
{
	frame = f;
}

void Rocket::SetTriggerAge(int i)
{
	trigger_age = i;
}
void Rocket::SetPosition(float x, float y)
{
	position = {x, y};
}
void Rocket::SetForce(float x, float y)
{
	force = {x, y};
}
int Rocket::GetAge()
{
	return age;
}
//bools
bool Rocket::IsAlive()
{
	return age < age_limit;
}
bool Rocket::IsTriggered()
{
	return age >= trigger_age;
}
void Rocket::Log(const std::stringstream &message)
{
	(*log) << message.str();
}
void Rocket::SetLog(std::ofstream *_log)
{
	Rocket::log = _log;
}