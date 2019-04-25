#pragma once
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include "curses.h"
#include <sstream>
#include <cmath>
#include <algorithm>
#include <tuple>
#include "../include/util.storm.h"

/*	frand() is defined in main.cpp.
*/

float frand();
enum Rocket_Type
{
  IE_Rocket,
  IE_Palm_Tree,
  IE_Streamer,
  IE_DoubleStreamer
};
class Rocket
{
public:
  inline static bool IS_DEBUG_MODE;

public:
  Rocket();
  virtual ~Rocket();
  /**
    Set the age at which the Rocket will trigger
    @param i The age to set the trigger  to
  */
  void SetTriggerAge(int i);
  void SetAgeLimit(int i);
  void SetPosition(Rocket &other);
  void SetPosition(float x, float y);
  void SetForce(float x, float y);
  void SetColor(int cc);
  int GetColor();
  static float GetGravity();
  std::tuple<float, float> GetForce();

  static void SetFrame(int f);
  virtual void Draw();
  virtual void Step(std::vector<Rocket *> &v);
  //virtual void Step();

  virtual void Trigger(std::vector<Rocket *> &v);
  //virtual void Trigger();

  int GetAge();
  bool IsAlive();
  bool IsTriggered();

  static void SetGravity(float g);
  static void SetLog(std::ofstream *_log);
  //Log to output file
  static void Log()
  {
    *log << std::endl;
  }

  template <typename First, typename... Strings>
  static void Log(First arg, const Strings &... rest)
  {
    if (IS_DEBUG_MODE)
    {
      *log << arg;
      Log(rest...);
    }
  }

  inline static std::ofstream *log;

protected:
  int age;
  int age_limit;
  int trigger_age;
  bool isTriggered;
  static int log_max_lines;
  int color_code;

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