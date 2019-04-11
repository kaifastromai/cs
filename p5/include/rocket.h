#include <iostream>
#include <vector>
#include "math.h"
#include <fstream>
#include "../include/trn_axis.h"

class Rocket
{
public:
  Rocket();
  virtual ~Rocket();
  void SetTriggerAge(int i);
  void SetAgeLimit(int i);
  void SetPosition(Rocket &other);
  void SetForce(float x, float y);
  virtual void Draw();
  virtual void Step();

  int GetAge();
  bool IsAlive();
  bool IsTriggered();

  static void SetGravity(float g);
  static void SetLogFile(std::ofstream *log_file);
  static void SetVector(std::vector<Rocket *> *);

  virtual void Trigger();

protected:
  int age;
  int age_limit;
  int trigger_age;

  // Nameless structs - see specification
  struct
  {
    float x, y;
  } position;

  struct
  {
    float x, y;
  } force;

  static float gravity;
  static std::ofstream *log_file;
  static std::vector<Rocket *> *rockets;
};