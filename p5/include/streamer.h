#pragma once
#include "../include/sparkler.h"

class Streamer : public Rocket
{
public:
	//void Draw();
	virtual void Trigger(std::deque<Rocket *> &v);
};
class DoubleStreamer : public Streamer
{
public:
	virtual void Trigger(std::deque<Rocket *> &v);
};
