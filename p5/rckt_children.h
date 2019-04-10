#include "rocket.h"
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
class Sparkler : public Rocket
{
public:
  void Draw();
};

class PalmTree : public Rocket
{
public:
  ~PalmTree();
  static std::vector<std::pair<float, float>> v1;
  virtual void Trigger();
};
class Spectacle : public Rocket
{
public:
  ~Spectacle();
}