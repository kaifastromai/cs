#pragma once
#include "rocket.h"
#include "../include/grid.h"
#include "../include/streamer.h"
#include "../include/palm_tree.h"
class Finale
{
	//This is hopefully epic!
public:
	Finale();
	void Run();
	~Finale();
	Grid *grid;
	std::deque<Rocket *> rockets;

	void Step();
};
