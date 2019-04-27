#include "../include/streamer.h"
#include "../include/util.storm.h"
#include <cmath>
#define TAU (M_PI * 2)

void Streamer::Trigger(std::deque<Rocket *> &v)
{
	//*log << "I am triggered!" << std::endl;
	for (size_t i = 1; i <= 8; i++)
	{
		//*log << i << std::endl;
		//*log << "Coords: " << x << ", " << y << std::endl;
		//*Rocket::log << "Force x: " << r.force.x << ", " << r.force.y << std::endl;
		//*log << "Pos: x" << r.position.x << ", y:" << r.position.y << std::endl;
		//mvaddch(LINES - i, i, '*');
		float posx = (float)cos(TAU * (1.0f / 8.0f) * i) + position.x;
		float posy = (float)sin(TAU * (1.0f / 8.0f) * i) + position.y;
		float fx = 2 * (float)cos(TAU * (1.0f / 8.0f) * i);
		float fy = 2 * (float)sin(TAU * (1.0f / 8.0f) * i);
		/* float posx = this->position.x+i;
		float posy = this->position.y+i; */
		Sparkler *spk = new Sparkler();
		spk->SetColor(1);
		spk->SetAgeLimit(csl::utils::Jiggle(20, 40));
		spk->SetPosition(posx, posy);
		/* r->SetForce(1.0f / (1.0f * (float)sin(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f),
					-1.0f / (1.0f * (float)cos(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f)); */
		spk->SetForce(fx, fy);
		v.push_back(spk);
	}
}
void DoubleStreamer::Trigger(std::deque<Rocket *> &v)
{
	for (size_t i = 1; i <= 16; i++)
	{
		//*log << i << std::endl;
		//*log << "Coords: " << x << ", " << y << std::endl;
		//*Rocket::log << "Force x: " << r.force.x << ", " << r.force.y << std::endl;
		//*log << "Pos: x" << r.position.x << ", y:" << r.position.y << std::endl;
		//mvaddch(LINES - i, i, '*');
		float posx = 5 * (float)cos(TAU * (1.0f / 16.0f) * i) + position.x;
		float posy = 5 * (float)sin(TAU * (1.0f / 16.0f) * i) + position.y;
		float fx = (float)cos(TAU * (1.0f / 16.0f) * i);
		float fy = (float)sin(TAU * (1.0f / 16.0f) * i);
		/* float posx = this->position.x+i;
		float posy = this->position.y+i; */
		Sparkler *spk = new Sparkler();
		spk->SetColor(2);
		spk->SetAgeLimit(csl::utils::Jiggle(20, 40));
		spk->SetPosition(posx, posy);
		/* r->SetForce(1.0f / (1.0f * (float)sin(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f),
					-1.0f / (1.0f * (float)cos(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f)); */
		spk->SetForce(0.4 * fx, 0.4 * fy);
		v.push_back(spk);
	}
}