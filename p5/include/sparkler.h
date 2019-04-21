#pragma once
#include "rocket.h"
class Sparkler : public Rocket
{
public:
  void Draw();

private:
  bool isStar = true;
};