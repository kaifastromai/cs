#pragma once
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include "curses.h"
#include <sstream>

/*	frand() is defined in main.cpp.
*/

float frand();

class Rocket
{
public:
  Rocket();
  virtual ~Rocket();
  void SetTriggerAge(int i);
  void SetAgeLimit(int i);
  void SetPosition(Rocket &other);
  void SetPosition(float x, float y);
  void SetForce(float x, float y);
  void SetFrame(int f);
  virtual void Draw();
  //virtual void Step(std::vector<Rocket *> &v);
  virtual void Step();

  //virtual void Trigger(std::vector<Rocket *> &v);
  virtual void Trigger();

  int GetAge();
  bool IsAlive();
  bool IsTriggered();

  static void SetGravity(float g);
  static void SetLog(std::ofstream *_log);
  static void Log(const std::stringstream &message);
  inline static std::ofstream *log;

public:
  int age;
  int age_limit;
  int trigger_age;

  struct
  {
    float x, y;
  } position;

  struct forces
  {
    float x, y;
  } force;

  inline static float gravity;
  inline static int frame;
};