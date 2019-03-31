#pragma once
#include "../include/rocket.h"
class Streamer : public Rocket
{
public:
	void Draw();
	virtual void Trigger();
};
class DoubleStreamer : public Streamer
{
public:
	virtual void Trigger();
};
