#pragma once
#include "rocket.h"
class PalmTree : public Rocket
{
  public:
	~PalmTree();
	static std::vector<std::pair<float, float>> v1;
	virtual void Trigger();
};