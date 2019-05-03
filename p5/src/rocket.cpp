#include "../include/rocket.h"
Rocket::Rocket()
{
	trigger_age = std::numeric_limits<int>::max();
	age = 0;
	age_limit = 5;
	position.x = COLS / 2;
	position.y = 0;
	force = {0.5, 2.0};
	isTriggered = false;
	color_code = 5;
	//mvaddstr(LINES/2, COLS/2, "how does this not work?");
}
Rocket::Rocket(Vector p, Vector f)
{
	trigger_age = std::numeric_limits<int>::max();
	age = 0;
	age_limit = 5;
	force = {0.5, 2.0};
	isTriggered = false;
	color_code = 5;
	position = p;
	force = f;
}
Rocket::~Rocket()
{
}

void Rocket::Draw()
{
	attron(COLOR_PAIR(color_code));
	mvaddch(LINES - std::round(position.y), std::round(position.x), '*');
}
//The Step() method foes forward one frame and does the necessary physics calculations
//and checks of we have reached the trigger age, at which point it will call the trigger
//method, passing by reference a vector of rockets
void Rocket::Step(std::deque<Rocket *> &v)
{
if (age == trigger_age)
	{
		Trigger(v);
	}
	/* 	(*log) << "Force: " << force.x << ", " << force.y << std::endl;
	(*log) << "Pos: " << position.x << ", " << position.y << std::endl; */

	age++;
	position.y = position.y + force.y;
	position.x = position.x + force.x;
	force.y += gravity;
}

void Rocket::Step()
{
	age++;
	position += force;
	force.y += gravity;
}

void Rocket::SetAgeLimit(int i)
{
	this->age_limit = i;
	
}
void Rocket::Trigger(std::deque<Rocket *> &v)
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
	return age <= age_limit;
}
bool Rocket::IsTriggered()
{
	return age >= trigger_age;
}

void Rocket::SetLog(std::ofstream *_log)
{
	Rocket::log = _log;
}
int Rocket::GetColor()
{
	return color_code;
}
void Rocket::SetColor(int cc)
{
	color_code = cc;
}
std::tuple<float, float> Rocket::GetForce()
{
	return {force.x, force.y};
}

/*Rocket::forces Rocket::GetForce(Rocket::forces force)

{
	return force;
}*/
float Rocket::GetGravity()
{
	return gravity;
}