#pragma once
#include "rocket.h"
#include "streamer.h"

class Streamer : public Rocket
{
public:
	~Streamer();
	void Draw();

	static std::vector<std::pair<float, float>> v1;
	virtual void Trigger();
};
class DoubleStreamer : public Streamer
{
public:
	virtual void Trigger();
};