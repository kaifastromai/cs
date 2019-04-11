#pragma once
#include "rocket.h"
class Streamer : public Rocket
{
  public:
	~Streamer();
	void Draw();

	static std::vector<std::pair<float, float>> v1;
	virtual void Trigger();
};